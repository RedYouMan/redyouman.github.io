// prototipi
#ifndef header_proto
#define header_proto
#include <iostream>
#include <string>
#include <boost/multiprecision/cpp_int.hpp>
#include <vector>
using namespace boost::multiprecision;

cpp_int gcd(cpp_int a, cpp_int b);
int isPrime(cpp_int p);
int gcdPrime(cpp_int p);
std::vector<cpp_int> divisors(cpp_int num, bool toVideo, bool trace);
std::vector<std::string> factors(cpp_int num, bool toVideo);
int perfectNumber(cpp_int num);
std::vector<cpp_int> perfectNumbersList(cpp_int minInterv, cpp_int maxInterv);
std::vector<cpp_int> MersenneNumbersList(cpp_int minInterv, cpp_int maxInterv);
int MersenneNumber(cpp_int num);
void findPerfectNumbersList(cpp_int minInterv, cpp_int maxInterv);
void findMersenneNumbersList(cpp_int minInterv, cpp_int maxInterv);
void findPrimeNumbersList(cpp_int minInterv, cpp_int maxInterv);
cpp_int series(cpp_int start, cpp_int end, cpp_int val, cpp_int incr);
cpp_int factorial(cpp_int start, cpp_int end);
int collatz(cpp_int n);
cpp_int fibonacci(cpp_int n);
void find_zeros(double real_start, double real_end, double imaginary_start, double imaginary_end, int iterations);
int help();
int diskControl(bool toVideo);
void saveToFile(const char *nome, std::string msg, bool toVideo);
int extractCommand(const std::string input);
int findStackCommand(const std::string sottostr);
int extractValues(const std::string input, int comando);
int numericOk(const std::string &str);
int countCommas(const std::string input);
std::string trim(const std::string s);
cpp_dec_float_50 nRoot(cpp_int valore, cpp_int esp);
cpp_int DecToBin(cpp_int val);
cpp_int BinToDec(cpp_int bin);
void findRepOneNumbersList(cpp_int minInterv, cpp_int maxInterv);
void findStrongPrimeNumbersList(cpp_int minInterv, cpp_int maxInterv);
int createSeqCunningham(int forma, int len, cpp_int ncifre);
cpp_int createRandomNumber(cpp_int n);
cpp_int createRSAkey(cpp_int digits);
int executeCommand(int command);
double secureQuota();
int countOpenBrackets(const std::string input);
int countCloseBrackets(const std::string input);
int extractRecursiveCommand(const std::string input);
cpp_int repone(cpp_int digits);
cpp_int myadd(cpp_int x, cpp_int y);
cpp_int mysubstracte(cpp_int x, cpp_int y);
long double mydivide(long double x, long double y);
cpp_int mymult(cpp_int x, cpp_int y);
int excludeCommand(int command);
int primeLastOp();
cpp_int lastValue();
cpp_int nDigits(cpp_int value);
cpp_int genPrime(cpp_int digits);
int extractFor(const std::string input);
int replaceCommand(const std::string str, cpp_int ind, std::string &newCommand);
int countSemicolon(const std::string input);
cpp_int assignVal(cpp_int val);
void countP(void);
void pushMem();
void popMem();
cpp_int readMem();
cpp_int log_cpp_int(cpp_int base, cpp_int n);
cpp_int myPow(cpp_int base, cpp_int exp);
int otherCommand(const std::string &input);
int myMatrix();
int myEquations();
int myPolynomials();
int mySolEq();
int execute(const std::string &nomeFile);
int parser(const std::string &comando);
int crypt(std::string filename);
int decrypt(std::string filename);
int myComplex();
int myCalcSim();
int myTime();
int searchPrimes(cpp_int minInterv, cpp_int maxInterv);
int searchPerfect(cpp_int minInterv, cpp_int maxInterv);
#endif