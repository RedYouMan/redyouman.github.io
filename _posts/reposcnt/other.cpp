#include <iostream>
#include <string>
#include <thread>
#include "proto.h"
using namespace std;
int otherCommand(const std::string &input)
{
    int status = 0;

    if (input == "matrix")
    {
        // call of algebra.cpp
        status = myMatrix();
    }
    if (input == "equations")
    {
        status = myEquations();
    }
    if (input == "divpol")
    {
        status = myPolynomials();
    }
    if (input == "soleq")
    {
        status = mySolEq();
    }
    if (input.substr(0, 7) == "execute")
    {

        std::string nome;
        nome.clear();
        nome = input.substr(8, input.length() - 9);
        status = execute(nome);
    }

    if (input == "crypt")
    {
        status = crypt("help.pkg");
    }

    if (input == "complex")
    {
        status = myComplex();
    }

    if (input.substr(0, 5) == "backg")
    {
        std::string nome;
        nome.clear();
        nome = input.substr(6, input.length() - 7);
        std::thread t(execute, nome);
        t.detach();
        std::cout << "Command strted in background\n";
        status = 1;
    }

    if (input == "symcalc")
    {
        status = myCalcSim();
    }
    if (input == "time()")
    {
        status = myTime();
    }
    if (input == "read()")
    {
        system("more/c/p SaveToFile.txt");
        status = 1;
    }
    if (input == "del()")
    {
        system("del SaveToFile.txt");
        status = 1;
    }
    return (status);
}