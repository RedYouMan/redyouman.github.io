#include <iostream>
#include <string.h>
#include <string>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/miller_rabin.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>

#include "proto.h"
using namespace boost::multiprecision;

extern bool StartSave;         // in sistema.cpp
extern cpp_int InputValues[5]; // in parser.cpp

extern cpp_int recursiveOutput; // in parser.cpp
extern cpp_int countCommand;
int executeCommand(int command)
{
    int status = 0;
    std::string msg;
    cpp_int num1 = 0, numRecursive = 0;
    cpp_int res = 0;
    cpp_dec_float_50 vf, inf;
    long double ad = 0, bd = 0, cd = 0, dd = 0;
    double a = 0, b = 0, c = 0, d = 0;
    int e = 0;
    // Declare variables for case 24 (find zeros)
    double a_ = 0, b_ = 0, c_ = 0, d_ = 0;
    int e_ = 0;

    switch (command)
    {

    case 0:
        // clearr
        std::cout << "I start the cleaning of the screen\n";
        system("cls");
        break;
    case 1:
        exit(1);
        break;
    case 2:
        help();
        break;

    case 3:
        // save

        if (StartSave == true)
        {
            StartSave = false;
            printf("Unsave the writing on the file\n");
        }
        else
        {
            if (diskControl(true) == 1)
            {
                StartSave = true;
                printf("Data will be written on the file saveToFile.txt\n");
            }
            else
            {
                StartSave = false;
            }
        }
        break;

    case 4:
        // gcd
        std::cout << "gcd(" << InputValues[0] << "," << InputValues[1] << ")=" << gcd(InputValues[0], InputValues[1]) << std::endl;
        recursiveOutput = gcd(InputValues[0], InputValues[1]);
        break;

    case 5:
        // pow
        recursiveOutput = myPow(InputValues[0], InputValues[1]);

        std::cout << "pow(" << InputValues[0] << "," << InputValues[1] << ")=" << recursiveOutput << std::endl;
        if (StartSave)
        {
            msg.clear();
            msg = "pow(" + InputValues[0].str() + "," + InputValues[1].str() + ")=" + recursiveOutput.str();
            (void)saveToFile("saveToFile.txt", msg, false);
        }
        break;

    case 6:
        // module

        num1 = InputValues[0] % InputValues[1];
        std::cout << "module()" << InputValues[0] << "," << InputValues[1] << ")=" << num1 << std::endl;
        recursiveOutput = num1;
        break;
    case 7:
        // log2

        recursiveOutput = log_cpp_int(2, InputValues[0]);
        if (recursiveOutput != -1)
        {
            std::cout << "log2()" << InputValues[0] << ")=" << recursiveOutput << std::endl;
        }
        break;

    case 8:
        // log10
        recursiveOutput = log_cpp_int(10, InputValues[0]);
        if (recursiveOutput != -1)
        {
            std::cout << "log10(" << InputValues[0] << ")=" << recursiveOutput << std::endl;
        }
        break;
    case 9:
        // sqrtint
        recursiveOutput = boost::multiprecision::sqrt(InputValues[0]);

        std::cout << "sqrtint(" << InputValues[0] << ")=" << recursiveOutput << std::endl;

        break;

    case 10:
        // primeR
        if (boost::multiprecision::miller_rabin_test(InputValues[0], 25))
        {
            std::cout << "The number " << InputValues[0] << " is prime." << std::endl;
        }
        else
        {
            std::cout << "The number " << InputValues[0] << " isn't prime." << std::endl;
        }
        break;
    case 11:
        // primeG
        if (gcdPrime(InputValues[0]) == 1)
        {
            std::cout << "The number " << InputValues[0] << " is prime." << std::endl;
        }
        else
        {
            std::cout << "The number " << InputValues[0] << " isn't prime." << std::endl;
        }
        break;
    case 12:
        // primeM
        if (isPrime(InputValues[0]) == 1)
        {
            std::cout << "The number " << InputValues[0] << " is prime." << std::endl;
        }
        else
        {
            std::cout << "The number " << InputValues[0] << " isn't prime." << std::endl;
        }
        break;

    case 13:
        // perfect

        if (perfectNumber(InputValues[0]) == 1)
        {
            std::cout << "The number " << InputValues[0] << " is perfect." << std::endl;
        }
        else
        {
            std::cout << "The number " << InputValues[0] << " isn't perfect." << std::endl;
        }
        break;

    case 14:
        // perfectsList
        (void)findPerfectNumbersList(InputValues[0], InputValues[1]);
        break;
    case 15:
        // mersenne
        if (MersenneNumber(InputValues[0]) == 1)
        {
            std::cout << "The number " << InputValues[0] << " is a mersenne prime number." << std::endl;
        }
        else
        {
            std::cout << "The number " << InputValues[0] << " isn't a mersenne prime number." << std::endl;
        }
        break;
    case 16:
        // mersennelist
        (void)findMersenneNumbersList(InputValues[0], InputValues[1]);
        break;
    case 17:
        // divisors
        divisors(InputValues[0], true, true

        );
        break;
    case 18:
        // factors
        factors(InputValues[0], true);
        break;
    case 19:
        // primeslist
        (void)findPrimeNumbersList(InputValues[0], InputValues[1]);

        break;

    case 20:
        num1 = series(InputValues[0], InputValues[1], InputValues[2], InputValues[3]);
        std::cout << "The sum of the series is: " << num1 << std::endl;
        recursiveOutput = num1;
        break;

    case 21:
        res = factorial(InputValues[0], InputValues[1]);
        recursiveOutput = res;
        std::cout << "The product of the elements is: " << res << std::endl;

        break;

    case 22:
        // collatz
        collatz(InputValues[0]);
        break;
    case 23:
        // ifibonacci
        num1 = fibonacci(InputValues[0]);
        recursiveOutput = num1;
        std::cout << "fibonacci()" << InputValues[0] << ")=" << num1 << std::endl;
        break;

    case 24:
        // find zeros
        {
            a_ = static_cast<double>(InputValues[0]);
            b_ = static_cast<double>(InputValues[1]);
            c_ = static_cast<double>(InputValues[2]);
            d_ = static_cast<double>(InputValues[3]);
            e_ = static_cast<int>(InputValues[4]);
            find_zeros(a_, b_, c_, d_, e_);
        }
        break;

    case 25:
        // nroot

        vf = nRoot(InputValues[0], InputValues[1]);
        std::cout << "nroot(" << InputValues[0] << "," << InputValues[1] << ")=" << vf << std::endl;
        recursiveOutput = cpp_int(vf);

        break;
    case 26:
        // exp
        vf = static_cast<cpp_dec_float_50>(InputValues[0]);
        inf = exp(vf);
        recursiveOutput = cpp_int(inf);
        std::cout << "exp(" << vf << ")=" << inf << std::endl;
        break;
    case 27:
        // bin
        num1 = DecToBin(InputValues[0]);
        if (num1 != 0)
        {
            std::cout << "bin(" << InputValues[0] << ")=" << num1 << std::endl;
            recursiveOutput = num1;
        }
        else
        {
            std::cout << "Abort creation bin!\n";
        }
        break;

    case 28:
        // dec
        num1 = BinToDec(InputValues[0]);

        if (num1 != 0)
        {
            recursiveOutput = num1;
            std::cout << "dec()" << InputValues[0] << ")=" << num1 << std::endl;
        }
        else
        {
            std::cout << "Abort creation decimal!\n";
        }
        break;

    case 29:
        // reponelist
        findRepOneNumbersList(InputValues[0], InputValues[1]);
        break;
    case 30:
        // stronglist
        findStrongPrimeNumbersList(InputValues[0], InputValues[1]);
        break;

    case 31:
        // seqcunn
        {
            int forma = static_cast<int>(InputValues[0]);
            int nseq = static_cast<int>(InputValues[1]);
            (void)createSeqCunningham(forma, nseq, InputValues[2]);
        }
        break;

    case 32:
        // rsakey
        msg.clear();
        num1 = createRSAkey(InputValues[0]);

        if (num1 != -1)
        {
            std::cout << "rsakey(" << InputValues[0] << ")=" << num1 << std::endl;
            if (StartSave)
            {
                msg = "rsakey(" + InputValues[0].str() + ")=" + num1.str();
                (void)saveToFile("saveToFile.txt", msg, false);
            }
        }

        if (num1 != -1)
        {
            recursiveOutput = num1;
        }
        break;

    case 33:
        // repone
        num1 = repone(InputValues[0]);
        if (num1 != 0)
        {
            std::cout << "repone(" << InputValues[0] << ")=" << num1 << std::endl;
            recursiveOutput = num1;
        }
        else
        {
            std::cout << "Abort creation of repone!\n";
        }
        break;

    case 34:
        num1 = myadd(InputValues[0], InputValues[1]);
        if (num1 == cpp_int(-1))
        {
            return (-1);
        }
        recursiveOutput = num1;
        std::cout << "add(" << InputValues[0] << "," << InputValues[1] << ")=" << num1 << std::endl;
        break;

    case 35:
        num1 = mysubstracte(InputValues[0], InputValues[1]);
        if (num1 == cpp_int(-1))
        {
            return (-1);
        }
        std::cout << "subt(" << InputValues[0] << "," << InputValues[1] << ")=" << num1 << std::endl;
        recursiveOutput = num1;
        break;
    case 36:

        cd = static_cast<long double>(InputValues[0]);
        dd = static_cast<long double>(InputValues[1]);
        ad = mydivide(cd, dd);
        if (ad == -1)
        {
            return (-1);
        }
        std::cout << "divide(" << InputValues[0] << "," << InputValues[1] << ")=" << ad << std::endl;
        recursiveOutput = static_cast<cpp_int>(ad);
        break;
    case 37:
        num1 = mymult(InputValues[0], InputValues[1]);
        if (num1 == cpp_int(-1))
        {
            return (-1);
        }
        std::cout << "mul(" << InputValues[0] << "," << InputValues[1] << ")=" << num1 << std::endl;
        recursiveOutput = num1;
        break;

    case 38:

        num1 = primeLastOp();
        if (num1 == 1)
        {
            std::cout << "The number" << recursiveOutput << " is a prime number\n";
        }
        else
        {
            std::cout << "The number " << recursiveOutput << " isn't a prime number\n";
        }
        break;

    case 39:

        num1 = lastValue();
        std::cout << "lastV()=" << num1 << std::endl;
        recursiveOutput = num1;
        break;

    case 40:

        numRecursive = recursiveOutput;
        num1 = nDigits(InputValues[0]);
        std::cout << "The number has " << num1 << "digits\n";
        recursiveOutput = numRecursive;
        break;

    case 41:
        num1 = genPrime(InputValues[0]);
        if (num1 != 0)
        {
            std::cout << "It creates prime number " << num1 << std::endl;
            recursiveOutput = num1;
        }
        else
        {
            std::cout << "Abort creation of the prime number!\n";
        }
        break;

    case 42:
        // assign
        recursiveOutput = assignVal(InputValues[0]);
        break;

    case 43:
        // countP
        countP();
        break;

    case 44:
        // pushM
        pushMem();
        break;

    case 45:
        // popM
        popMem();
        break;
    case 46:
        // readM

        num1 = readMem();
        std::cout << "readM()=" << num1 << std::endl;
        recursiveOutput = num1;
        break;
    case 47:
        // plprimes
        (void)searchPrimes(InputValues[0], InputValues[1]);
        break;
    case 48:
        // plperfect
        (void)searchPerfect(InputValues[0], InputValues[1]);
        break;
    default:
        // so it cycles
        break;
    }

    if (command != 39)
    {
        countCommand++;
    }
    return (1);
}