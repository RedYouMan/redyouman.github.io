#include <iostream>
#include <cmath>
#include <time.h>
#include <iomanip>
#include "synchapi.h"
#include <string>
#include <random>
#include <algorithm>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/miller_rabin.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <vector>
#include <thread>
#include <algorithm>
#include <mutex>
#include "proto.h"
using namespace boost::multiprecision;
// calc.cpp

// Mutex per la sincronizzazione dell'accesso alla variabile 'factors' nel parallelo
std::mutex mtx;
std::vector<cpp_int> primi;
std::vector<cpp_int> perfetti;

extern bool StartSave;
extern cpp_int recursiveOutput; // in parser.cpp
extern bool inCount;
extern cpp_int countPrimes;
extern bool inFor;
extern std::vector<cpp_int> Primes;
// Funzioni per calcolo numeri primi, numeri perfetti e numeri di Mersenne
cpp_int gcd(cpp_int a, cpp_int b)
{
    // Find Minimum of a and b
    cpp_int res = min(a, b);

    // Testing divisibility with all numbers starting from min(a, b) to 1
    while (res > 1)
    {
        // If any number divides both a and b, so we got the answer
        if (a % res == 0 && b % res == 0)
            break;
        res--;
    }
    return res;
}

// Checks if a number is prime
int isPrime(cpp_int p)
{
    if (p <= 1)
    {
        printf("Insert a positive number greater than 1\n");
        return (-1);
    }
    if (p == 2)
    {
        return (1);
    }
    if (p % 2 == 0)
    {
        return (0);
    }
    cpp_int i = 0;
    // module test
    for (i = 3; i * i <= p; i += 2)
    {
        if (p % i == 0)
        {
            return (0);
        }
    }
    return (1); // prime
}

// Checks if a number is a prime using gcd
int gcdPrime(cpp_int p)
{
    cpp_int i = 3;
    if (p <= 1)
    {
        printf("\nInsert a positive number greater than 1 \n");
        return (-1);
    }
    if (p == 2)
    {
        return (1);
    }
    if (gcd(p, 2) != 1)
    {
        return (0);
    }
    for (i = 3; i * i <= p; i += 2)
    {
        if (gcd(p, i) != 1)
        {
            return (0);
        }
    }
    return (1);
}

// Returns all divisors of a number
std::vector<cpp_int> divisors(cpp_int num, bool toVideo, bool trace)
{
    std::vector<cpp_int> v;
    cpp_int i = 0;
    std::string msg;
    msg.clear();
    if (num <= 0)
    {
        std::cout << "The number hasn't got divisors\n";
        return (v);
    }
    if (num == 1)
    {
        v.push_back(1);
        if (toVideo)
        {
            std::cout << "divisors(1)=[1]\n";
        }

        if (trace)
        {
            msg.clear();
            msg = "divisors(" + num.str() + ")=[1]";
            (void)saveToFile("saveToFile.txt", msg, false);
        }
        return (v);
    }

    if (boost::multiprecision::miller_rabin_test(num, 25))
    {
        v.push_back(1);
        v.push_back(num);
        if (toVideo)
        {
            std::cout << "divisors(" << num << ")= [1," << num << "]" << std::endl;
        }

        if (trace)
        {
            msg.clear();
            msg = "divisors(" + num.str() + ")=[1," + num.str() + "]";
            (void)saveToFile("saveToFile.txt", msg, false);
        }
        return v;
    }
    if (StartSave == true && trace == true)
    {
        msg = "divisors(" + num.str() + ")=[";
        (void)saveToFile("saveToFile.txt", msg, false);
    }
    if (toVideo)
    {
        std::cout << "divisors(" << num << ")=[" << std::endl;
    }
    for (i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            if (StartSave == true && trace == true)
            {
                msg.clear();
                msg = " " + i.str();
                (void)saveToFile("saveToFile.txt", msg, false);
            }
            if (toVideo)
            {
                std::cout << i << " " << std::endl;
                ;
            }
            else
            {
                v.push_back(i);
            }
        }
    }

    if (toVideo)
    {
        printf("]\n");
    }
    if (StartSave == true && trace == true)
    {
        msg.clear();
        msg = "]\n";
        (void)saveToFile("saveToFile.txt", msg, false);
    }
    return (v);
}

std::vector<std::string> factors(cpp_int num, bool toVideo)
{
    std::vector<std::string> v;
    cpp_int i = 0;
    std::string msg;
    msg.clear();

    if (num <= 0)
    {
        std::cout << "Error - Values <=0 aren't possible\n";
        return v;
    }

    if (num == 1)
    {
        v.push_back("1");
        std::cout << "factors(1)=1\n";
        return v;
    }

    if (boost::multiprecision::miller_rabin_test(num, 25))
    {
        v.push_back(num.str());
        std::cout << "factors(" << num << ")=" << num << std::endl;
        return v;
    }
    if (StartSave)
    {
        msg = "factors(" + num.str() + ")=[";
        (void)saveToFile("saveToFile.txt", msg, false);
    }
    if (toVideo)
    {
        std::cout << "factors(" << num << ")=[" << std::endl;
    }
    cpp_int count = 0;
    while (num % 2 == 0)
    {
        // gestione 2
        num /= 2;
        count++;
    }

    if (count == 1)
    {
        v.push_back("2");
    }
    else if (count > 1)
    {
        v.push_back("2^" + count.str());
    }
    if (StartSave)
    {
        msg.clear();
        if (count == 1)
        {
            msg = "2 ";
        }
        else if (count > 1)
        {
            msg = "2^" + count.str() + " ";
        }
        (void)saveToFile("saveToFile.txt", msg, false);
    }
    if (toVideo)
    {
        if (count == 1)
        {
            std::cout << "2 " << std::endl;
        }
        else if (count > 1)
        {
            std::cout << "2^" + count.str() + " " << std::endl;
        }
    }
    for (i = 3; i * i <= num; i = i + 2)
    {
        count = 0;

        while (num % i == 0)
        {
            num /= i;
            count++;
        }
        if (count == 1)
        {
            v.push_back(i.str());
        }
        else if (count > 1)
        {
            v.push_back(i.str() + "^" + count.str());
        }
        if (StartSave)
        {
            msg.clear();
            if (count == 1)
            {
                msg = i.str() + " ";
            }
            else if (count > 1)
            {
                msg = i.str() + "^" + count.str() + " ";
            }

            if (count > 0)
            {
                (void)saveToFile("saveToFile.txt", msg, false);
            }
        }
        if (toVideo)
        {
            if (count == 1)
            {
                std::cout << " " << i << " " << std::endl;
            }
            else if (count > 1)
            {
                std::cout << " " << i.str() << "^" << count.str() << " " << std::endl;
            }
        }
    }
    if (num > 2)
    {
        // numero primo rimasto

        v.push_back(num.str());
        if (StartSave)
        {
            msg.clear();
            msg = num.str() + " ";
            (void)saveToFile("saveToFile.txt", msg, false);
        }
        if (toVideo)
        {
            std::cout << " " << num.str() << " " << std::endl;
        }
    }
    if (toVideo)
    {
        printf("]\n");
    }

    if (StartSave)
    {
        msg.clear();
        msg = "]\n";
        (void)saveToFile("saveToFile.txt", msg, false);
    }
    return (v);
}

// Checks if a number is perfect
int perfectNumber(cpp_int num)
{
    cpp_int sum = 0;
    std::vector<cpp_int> v;

    if (num == 0)
    {
        return 0;
    }
    cpp_int a = 0;
    v = divisors(num, false, false);
    if (v.size() <= 2)
    {
        return 0;
    }
    for (size_t i = 0; i < v.size(); i++)
    {
        a = v[i];
        sum = sum + a;
    }
    if (sum == num * 2)
    {
        return (1);
    }
    return (0);
}
std::vector<cpp_int> perfectNumbersList(cpp_int minInterv, cpp_int maxInterv)
{
    std::vector<cpp_int> v;
    cpp_int i = 0, m = 0;
    if (maxInterv < 1 || minInterv < 1 || maxInterv <= minInterv)
    {
        printf("The interval is wrong\n");
        return (v);
    }

    std::cout << "Start of the job..." << std::endl;
    for (i = minInterv; i <= maxInterv; i++)
    {
        if (perfectNumber(i) == 1)
        {
            v.push_back(i);
        }
    }
    return (v);
}
std::vector<cpp_int> MersenneNumbersList(cpp_int minInterv, cpp_int maxInterv)
{
    std::vector<cpp_int> v;
    cpp_int i = 0;
    cpp_int m = 0;
    cpp_int base = 2;
    if (maxInterv < 1 || minInterv < 1 || maxInterv <= minInterv)
    {
        printf("The interval is wrong\n");
        return (v);
    }

    if (minInterv == 1)
    {
        minInterv = 2;
    }

    std::cout << "Start of the job..." << std::endl;
    for (i = minInterv; i <= maxInterv; i++)
    {
        if (boost::multiprecision::miller_rabin_test(i, 25))
        {
            m = myPow(base, i);
            m = m - 1;
        }
        else
        {
            continue;
        }
        if (boost::multiprecision::miller_rabin_test(m, 25))
        {
            v.push_back(m);
        }
    }
    return (v);
}
int MersenneNumber(cpp_int num)
{
    cpp_int i = 0, a = 0;
    cpp_int m = 0;
    cpp_int base = 2;
    if (num <= 1)
    {
        return (-1);
    }
    if (num == 2)
    {
        return (0);
    }
    for (i = 1; i < num; i++)
    {
        m = myPow(base, i);
        m = m - 1;
        if (boost::multiprecision::miller_rabin_test(num, 25) && i > 1)
        {
            return (1);
        }
        if (m > num + 2)
        {
            break;
        }
    }
    return (0);
}

void findPerfectNumbersList(cpp_int minInterv, cpp_int maxInterv)
{

    if (maxInterv - minInterv <= 0)
    {
        printf("The interval is wrong\n");
        return;
    }

    std::vector<cpp_int> v = perfectNumbersList(minInterv, maxInterv);

    if (v.size() == 0)
    {
        printf("Thera aren't perfect numbers\n");
        return;
    }
    cpp_int cont = 0;
    std::string msg;
    msg.clear();
    std::cout << "List of perfect Numbers in (" << minInterv << "," << maxInterv << ")" << std::endl;
    if (StartSave)
    {
        msg = "list of perfect numbers in (" + minInterv.str() + "," + maxInterv.str() + "):\n";
        (void)saveToFile("saveToFile.txt", msg, false);
    }
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
        if (StartSave)
        {
            msg.clear();
            msg = v[i].str() + " ";
            (void)saveToFile("saveToFile.txt", msg, false);
        }
        cont++;
    }
    printf("\n");
    std::cout << "Total perfect numbers " << cont << std::endl;
    if (StartSave)
    {
        msg.clear();
        msg = "n. Total of perfect Numbers = " + cont.str() + "\n";
        (void)saveToFile("saveToFile.txt", msg, false);
    }
}

void findMersenneNumbersList(cpp_int minInterv, cpp_int maxInterv)
{
    if (maxInterv - minInterv <= 0)
    {
        printf("The interval is wrong\n");
        return;
    }

    std::vector<cpp_int> v = MersenneNumbersList(minInterv, maxInterv);

    if (v.size() == 0)
    {
        printf("Thera aren't mersenne numbers \n");
        return;
    }
    cpp_int cont = 0;
    std::string msg;
    msg.clear();
    std::cout << "List of mersenne numbers in (" << minInterv << "," << maxInterv << "):\n";
    if (StartSave)
    {
        msg = "list of mersenne numbers in (" + minInterv.str() + "," + maxInterv.str() + "):\n";
        (void)saveToFile("saveToFile.txt", msg, false);
    }
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
        ;
        if (StartSave)
        {
            msg.clear();
            msg = v[i].str() + " ";
            (void)saveToFile("saveToFile.txt", msg, false);
        }
        cont++;
    }
    printf("\n");
    std::cout << "Total of mersenne numbers " << cont << std::endl;
    if (StartSave)
    {
        msg.clear();
        msg = "n. Total mersenne numbers: " + cont.str() + "\n";
        (void)saveToFile("saveToFile.txt", msg, false);
    }
}

void findPrimeNumbersList(cpp_int minInterv, cpp_int maxInterv)
{
    cpp_int i = 0, cont = 0;

    if (maxInterv < 1 || minInterv < 1 || maxInterv <= minInterv)
    {
        printf("The interval is wrong\n");
        printf("Thera aren't prime numbers\n");
        return;
    }
    if (minInterv == 1)
    {
        minInterv = 2;
    }
    std::cout << "Start the job..." << std::endl;
    std::vector<cpp_int> v;
    std::string msg;

    msg.clear();
    std::cout << "List of prime numbers in (" << minInterv << "," << maxInterv << "):\n";
    if (StartSave)
    {
        msg = "list of prime numbers in (" + minInterv.str() + "," + maxInterv.str() + "):\n";
        (void)saveToFile("saveToFile.txt", msg, false);
    }

    for (i = minInterv; i < maxInterv; i++)
    {
        if (boost::multiprecision::miller_rabin_test(i, 25))
        {
            v.push_back(i);
            cont++;
        }
    }
    if (v.size() > 0)
    {
        for (size_t i = 0; i < v.size(); i++)
        {
            std::cout << v[i] << " ";
            if (StartSave)
            {
                msg.clear();
                msg = v[i].str() + " ";
                (void)saveToFile("saveToFile.txt", msg, false);
            }
            if (i % 10000 == 0)
            {
                Sleep(1); // per non sovraccaricare la console
            }
        }
    }
    printf("\n");
    if (cont > 0)
    {
        std::cout << "Total prime numbers " << cont << std::endl;
        if (StartSave)
        {
            msg.clear();
            msg = "n. Total of prime numbers = " + cont.str() + "\n";
            (void)saveToFile("saveToFile.txt", msg, false);
        }
    }
    else
    {
        printf("There aren't prime numbers in the interval\n");
    }
}
cpp_int series(cpp_int start, cpp_int end, cpp_int val, cpp_int incr)
{
    cpp_int i = 0, s = 0;
    for (i = start; i <= end; i += incr)
    {
        s = s + i + val;
    }
    return (s);
}

cpp_int factorial(cpp_int start, cpp_int end)
{
    cpp_int i = 0, s = 1;

    if (start == 0)
    {
        start = 1;
        std::cout << "The minimum start must be 1, i must set it to 1\n";
    }

    if (end <= start)
    {
        std::cout << "The interval is wrong.\n";
        return 0;
    }
    for (i = start; i <= end; i++)
    {
        s = s * i;
    }
    return (s);
}

cpp_int BinToDec(cpp_int bin)
{
    // dec
    cpp_int valore = 0, a = 0;
    std::string bin2;
    cpp_int base = 2;

    bin2 = bin.str();
    size_t lun = bin2.length();
    for (int i = static_cast<int>(lun) - 1, j = 0; i >= 0; i--, j++)
    {
        if (bin2[i] == '1')
        {
            a = myPow(base, j);
            valore = valore + a;
        }
    }
    return (valore);
}

cpp_int DecToBin(cpp_int val)
{
    // bin
    cpp_int quoziente = 0, res = 0, resto = 0;
    char c;
    std::string buffer;
    buffer.clear();

    quoziente = val;
    while (quoziente > 1)
    {
        resto = quoziente % 2;
        c = static_cast<char>(static_cast<int>(resto.convert_to<int>()) + '0');
        buffer.push_back(c);
        quoziente = quoziente / 2;
    }

    if (quoziente == 1)
    {
        c = '1';
        buffer.push_back(c);
    }

    // inversione di buffer
    std::reverse(buffer.begin(), buffer.end());
    // Conversione da stringa binaria a cpp_int
    res = 0;
    for (size_t i = 0; i < buffer.size(); ++i)
    {
        res = res * 10 + (buffer[i] - '0');
    }
    return (res);
}

void findRepOneNumbersList(cpp_int minInterv, cpp_int maxInterv)
{
    cpp_int i = 0, j = 0, cont = 0;

    if (maxInterv < 1 || minInterv < 1 || maxInterv <= minInterv)
    {
        printf("The interval is wrong\n");
        printf("There aren't prime numbers rep-one\n");
        return;
    }
    if (minInterv != 1)
    {
        std::string buffer = minInterv.str();
        std::string buffer2 = "";
        cpp_int len = buffer.length();
        for (j = 1; j <= len; j++)
        {
            buffer2.push_back('1');
        }

        cpp_int calc = cpp_int(buffer2);
        std::cout << "minInterv of start for rep-ones  must be  almost " << calc << std::endl;

        minInterv = calc;
    }

    std::cout << "Start of the job.." << std::endl;
    std::vector<cpp_int> v;
    std::string msg;
    msg.clear();

    std::cout << "List of Prime Numbers rep-one  in [" << minInterv << "," << maxInterv << "]:\n";
    for (i = minInterv; i < maxInterv; i = i * 10 + 1)
    {
        std::cout << "Number to examine " << i << std::endl;
        if (boost::multiprecision::miller_rabin_test(i, 25))
        {
            v.push_back(i);
            cont++;
        }
    }
    if (v.size() > 0)
    {
        std::cout << "List of the prime rep-one :\n";
        for (size_t i = 0; i < v.size(); i++)
        {
            std::cout << v[i] << std::endl;
            if (StartSave)
            {

                msg.clear();
                msg = "list of prime numbers rep-one in (" + minInterv.str() + "," + maxInterv.str() + "):\n";
                (void)saveToFile("saveToFile.txt", msg, false);
                msg.clear();
                msg = v[i].str() + " ";
                (void)saveToFile("saveToFile.txt", msg, false);
            }
        }
    }
    if (cont > 0)
    {
        std::cout << "Total  numbers " << cont << std::endl;
        if (StartSave)
        {
            msg.clear();
            msg = "n. Total  of prime numbers rep-one =" + cont.str() + "\n";
            (void)saveToFile("saveToFile.txt", msg, false);
        }
    }
    else
    {
        std::cout << "There aren't prime rep-one \n";
        if (StartSave)
        {
            msg.clear();
            msg = "n. Total prime numbers rep-one = 0\n";
            (void)saveToFile("saveToFile.txt", msg, false);
        }
    }
    return;
}
// strong primes numbers list

void findStrongPrimeNumbersList(cpp_int minInterv, cpp_int maxInterv)
{
    cpp_int i = 0, cont = 0;

    if (maxInterv < 1 || minInterv < 1 || maxInterv <= minInterv)
    {
        printf("The interval is wrong\n");
        printf("There aren't strong prime numbers\n");
        return;
    }
    if (minInterv <= 2)
    {
        minInterv = 3;
    }
    std::cout << "Start of the job..." << std::endl;
    std::vector<cpp_int> v;
    std::string msg;
    msg.clear();
    std::cout << "List of strong prime numbers in [" << minInterv << "," << maxInterv << "]:\n";
    if (StartSave)
    {
        msg = "list of strong  prime numbers in (" + minInterv.str() + "," + maxInterv.str() + "):\n";
        (void)saveToFile("saveToFile.txt", msg, false);
    }
    cpp_int precPrime = -1;
    for (i = minInterv; i < maxInterv; i++)
    {
        if (boost::multiprecision::miller_rabin_test(i, 25) == 1 && i - precPrime != 2)
        {
            v.push_back(i);
            cont++;
            precPrime = i;
        }
    }
    if (v.size() > 0)
    {
        for (size_t i = 0; i < v.size(); i++)
        {
            std::cout << v[i] << " ";
            if (StartSave)
            {
                msg.clear();
                msg = v[i].str() + " ";
                (void)saveToFile("saveToFile.txt", msg, false);
            }
            if (i % 10000 == 0)
            {
                Sleep(1); // per non sovRabinccaricare la console
            }
        }
    }
    printf("\n");
    if (cont > 0)
    {
        std::cout << "Total strong prime numbers " << cont << std::endl;
        if (StartSave)
        {
            msg.clear();
            msg = "n. Total of strong prime numbers = " + cont.str() + "\n";
            (void)saveToFile("saveToFile.txt", msg, false);
        }
    }
    else
    {
        printf("There aren't strong prime numbers in the interval\n");
    }
}

int createSeqCunningham(int form, int len, cpp_int digits)
{
    srand((unsigned)time(NULL));
    cpp_int primeNum;
    bool trovato = false;
    std::vector<cpp_int> v;
    std::string msg;
    cpp_int cun = 0, incr = 0;
    while (!trovato)
    {
        cpp_int randomNum = createRandomNumber(digits);
        if (boost::multiprecision::miller_rabin_test(randomNum, 25))
        {
            primeNum = randomNum;
            trovato = true;
        }
    }
    std::cout << "We start fron the number " << digits << " of digits: " << primeNum << std::endl;

    if (form < 1 || form > 2)
    {
        std::cout << "Form selected is wrong. Deve essere 1 o 2\n";
        return (-1);
    }
    // genero sequenza di len numeri di Cunningham

    std::cout << "Cunningham's sequence: \n";
    std::cout << "n. 1  " << primeNum << std::endl;

    v.push_back(primeNum);

    incr = (form == 1 ? incr = 1 : incr = -1);
    for (int i = 1; i < len; i++)
    {
        cun = primeNum * 2 + incr;
        if (boost::multiprecision::miller_rabin_test(cun, 25))
        {

            v.push_back(cun);
            std::cout << "n. " << i + 1 << "  " << cun << std::endl;
        }
        else
        {

            do
            {
                cun = (form == 1 ? cun += 2 : cun -= 2);
            } while (boost::multiprecision::miller_rabin_test(cun, 25) != true);
            v.push_back(cun);
            std::cout << "n. " << i + 1 << "  " << cun << std::endl;
        }
        primeNum = cun;
    }

    if (StartSave)
    {
        if (v.size() > 0)
        {
            msg.clear();
            msg = "sequence of Cunningham:\n";
            (void)saveToFile("saveToFile.txt", msg, false);
            for (size_t i = 0; i < v.size(); i++)
            {
                msg.clear();
                msg = v[i].str() + " ";
                (void)saveToFile("saveToFile.txt", msg, false);
            }
        }
    }
    return (1);
}

// Funzione per generare un numero casuale di n cifre
cpp_int createRandomNumber(cpp_int digits)
{
    // Generates a random cpp_int with the specified number of digits
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 9);

    std::string num_str;
    num_str += std::to_string(dist(gen)); // first digit non-zero
    std::uniform_int_distribution<int> dist0(0, 9);
    for (cpp_int i = 1; i < digits; ++i)
    {
        num_str += std::to_string(dist0(gen));
    }
    cpp_int n(num_str);

    return n;
}

cpp_int createRSAkey(cpp_int digits)
{

    // We must generate two strong prime numbers not twin numbers
    cpp_int primenum1 = 0, primenum2 = 0, key = 0;

    srand(time(NULL));
    primenum1 = genPrime(digits);
    std::cout << "The first prime number is " << primenum1 << std::endl;
    // secondo primo
    digits = digits + rand() % 100;
    primenum2 = genPrime(digits);
    std::cout << "The second prime number is  " << primenum2 << std::endl;
    key = primenum1 * primenum2;
    return (key);
}

cpp_int repone(cpp_int digits)
{
    std::string buffer;
    cpp_int repone = 0;

    for (cpp_int i = 1; i <= digits; i++)
    {
        buffer.push_back('1');
    }
    repone = cpp_int(buffer);
    return (repone);
}

cpp_int myadd(cpp_int x, cpp_int y)
{

    if (x + y < 0)
    {
        std::cout << "For Number Theory a negative result can be not valid\n";
        return (-1);
    }
    return (x + y);
}

cpp_int mysubstracte(cpp_int x, cpp_int y)
{

    if (x - y < 0)
    {
        std::cout << "For Number Theory a negative result can be not valid\n";
        return (-1);
    }
    return (x - y);
}

cpp_int mymult(cpp_int x, cpp_int y)
{

    if (x * y < 0)
    {
        std::cout << "For Number Theory a negative result can be not valid\n";
        return (-1);
    }
    return (x * y);
}

long double mydivide(long double x, long double y)
{
    if (y == 0)
    {
        std::cout << "y=0 the result is infinity \n";
        return (-1);
    }
    if (x / y < 0)
    {
        std::cout << "For Number Theory a negative result can be not valid \n";
        return (-1);
    }

    return (x / y);
}
cpp_int nDigits(cpp_int num)
{

    cpp_int logaritmo10 = 0;
    cpp_int base = 10;
    logaritmo10 = log_cpp_int(base, num);
    return (logaritmo10 + 1);
}
cpp_int genPrime(cpp_int digits)
{

    cpp_int randomNum = 0;
    cpp_int primenum = 0;

    bool trovato = false;

    srand((unsigned)time(NULL));
    std::cout << "It starts,you must wait\n";
    while (!trovato)
    {
        randomNum = createRandomNumber(digits);

        if (boost::multiprecision::miller_rabin_test(randomNum, 25))
        {
            trovato = true;
            primenum = randomNum;
        }
    }
    return (primenum);
}

cpp_int fibonacci(cpp_int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

cpp_int assignVal(cpp_int val)
{
    return (val);
}
void countP(void)
{
    if (inFor)
    {
        if (boost::multiprecision::miller_rabin_test(recursiveOutput, 25))
        {
            countPrimes++;
            Primes.push_back(recursiveOutput);
            inCount = true;
        }
    }
}

// Funzione per calcolare la potenza intera    // Funzione per calcolare la potenza intera
cpp_int myPow(cpp_int base, cpp_int exponent)
{
    cpp_int result = 0;
    result = boost::multiprecision::pow(base, static_cast<unsigned long long>(exponent));
    return (result);
}

// Il risultato è l'intero più vicino al logaritmo
cpp_int log_cpp_int(cpp_int baseLog, cpp_int n)
{
    cpp_int x = 0, testP = 0;
    if (n <= 0)
    {
        std::cout << "log of n <=0 isn't defined.\n";
    }
    testP = myPow(baseLog, x);
    while (testP < n)
    {
        x++;
        testP = myPow(baseLog, x);
    }

    if (testP > n)
    {
        x = x - 1;
    }
    return x;
}

cpp_dec_float_50 nRoot(cpp_int num, cpp_int esp)
{
    // Calcola la radice esp-esima di num usando pow di boost con esponente cpp_dec_float_50

    cpp_dec_float_50 ex = cpp_dec_float_50(1) / cpp_dec_float_50(esp);
    cpp_dec_float_50 result = boost::multiprecision::pow(static_cast<cpp_dec_float_50>(num), ex);
    return result;
}

// ricerca primi con 4 thread
void trovaPrimi(cpp_int start, cpp_int end)
{

    for (cpp_int i = start; i <= end; i++)
    {
        if (boost::multiprecision::miller_rabin_test(i, 25))
        {
            std::lock_guard<std::mutex> lock(mtx); // Blocco del mutex per la sezione critica
            primi.push_back(i);
        }
    }
}

int searchPrimes(cpp_int minInterv, cpp_int maxInterv)
{

    if (maxInterv - minInterv <= 0)
    {
        std::cout << "Wrong Interval\n";
        return (-1);
    }

    printf("Start of the job.Wait.\n");
    int numThreads = 4;
    cpp_int range = (maxInterv - minInterv) / numThreads; // Calcola la dimensione del range per ogni thread

    std::vector<std::thread> threads;

    // Creazione e avvio dei thread
    for (int i = 0; i < numThreads; ++i)
    {
        cpp_int start = i * range + (i == 0 ? minInterv : 0);              // Il primo thread inizia da minInterv
        cpp_int end = (i == numThreads - 1) ? maxInterv : (i + 1) * range; // L'ultimo thread arriva fino a maxInterv
        threads.push_back(std::thread(trovaPrimi, start, end));
    }

    // Attesa della terminazione dei thread
    for (auto &thread : threads)
    {
        thread.join();
    }
    std::sort(primi.begin(), primi.end());
    primi.erase(unique(primi.begin(), primi.end()), primi.end());
    // Stampa dei primi
    std::string msg;

    std::cout << "parallel_primeslist(" << minInterv << "," << maxInterv << ")=";
    for (cpp_int primo : primi)
    {
        msg.clear();
        msg = primo.str();
        if (StartSave)
        {
            (void)saveToFile("saveToFile.txt", msg, false);
        }
        std::cout << primo << " ";
    }
    std::cout << std::endl;
    std::cout << "Numbers of primes found : " << primi.size() << std::endl;
    msg.clear();
    cpp_int n = primi.size();
    msg = "Numbers of primes found :" + n.str();
    if (StartSave)
    {
        (void)saveToFile("saveToFile.txt", msg, false);
    }

    return 1;
}

// ricerca perfetti con 4 thread
void trovaPerfetti(cpp_int start, cpp_int end)
{

    for (cpp_int i = start; i <= end; i++)
    {
        if (perfectNumber(i))
        {
            std::lock_guard<std::mutex> lock(mtx); // Blocco del mutex per la sezione critica
            perfetti.push_back(i);
        }
    }
}

int searchPerfect(cpp_int minInterv, cpp_int maxInterv)
{

    if (maxInterv - minInterv <= 0)
    {
        std::cout << "Wrong Interval\n";
        return (-1);
    }

    printf("Start of the job. Wait.\n");
    int numThreads = 4;
    cpp_int range = (maxInterv - minInterv) / numThreads; // Calcola la dimensione del range per ogni thread

    std::vector<std::thread> threads;

    // Creazione e avvio dei thread
    for (int i = 0; i < numThreads; ++i)
    {
        cpp_int start = i * range + (i == 0 ? minInterv : 0);              // Il primo thread inizia da minInterv
        cpp_int end = (i == numThreads - 1) ? maxInterv : (i + 1) * range; // L'ultimo thread arriva fino a maxInterv
        threads.push_back(std::thread(trovaPerfetti, start, end));
    }

    // Attesa della terminazione dei thread
    for (auto &thread : threads)
    {
        thread.join();
    }
    std::sort(perfetti.begin(), perfetti.end());
    perfetti.erase(unique(perfetti.begin(), perfetti.end()), perfetti.end());
    // Stampa dei perfetti
    std::string msg;

    std::cout << "parallel_perfectlist(" << minInterv << "," << maxInterv << ")=";
    for (cpp_int perfetto : perfetti)
    {
        msg.clear();
        msg = perfetto.str();
        if (StartSave)
        {
            (void)saveToFile("saveToFile.txt", msg, false);
        }
        std::cout << perfetto << " ";
    }
    std::cout << std::endl;
    std::cout << "Numbers of perfect numbers found : " << perfetti.size() << std::endl;
    msg.clear();
    cpp_int n = perfetti.size();
    msg = "Numbers of perfect numbers found :" + n.str();
    if (StartSave)
    {
        (void)saveToFile("saveToFile.txt", msg, false);
    }

    return 1;
}
