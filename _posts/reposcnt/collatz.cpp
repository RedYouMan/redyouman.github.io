// dato un numero n positivo> 1
// se n è pari si dimezza e si prosegue sul nuovo n
// se n è dispari si ricava il nuovo n=3n+1 e si prosegue su n

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

#include <string.h>
#include <boost/multiprecision/cpp_int.hpp>
#include "proto.h"
using namespace boost::multiprecision;
extern bool StartSave;
int collatz(cpp_int n)
{

    std::string str = n.str();

    cpp_int num = n, cont = 0, precmag = 0;
    std::string msg;
    msg.clear();

    if (num <= 1)
    {
        printf("\nYou must insert a positive number greater than 1\n");
        return (0);
    }

    std::cout << num << "," << std::endl;
    if (StartSave)
    {

        msg.clear();
        msg = "Collatz's sequence:\n";
        (void)saveToFile("saveToFile.txt", msg, false);

        msg.clear();
        msg = num.str() + ",";
        (void)saveToFile("saveToFile.txt", msg, false);
    }
    while (num > 1)
    {

        precmag = max(precmag, num);
        if (num % 2 == 0)
        {
            num = num / 2;
        }
        else if (num % 2 != 0)
        {
            num = 3 * num + 1;
        }

        if (num > 1)
        {
            std::cout << num << ",";
        }
        else
        {
            std::cout << num;
        }
        if (StartSave)
        {
            msg.clear();
            msg = num.str();
            if (num > 1)
                msg += ",";
            else
                msg += "\n";
            (void)saveToFile("saveToFile.txt", msg, false);
        }
        cont++;
    }

    std::cout << "\nTotal steps " << cont << " to 1\n";
    if (StartSave)
    {
        msg.clear();
        msg = "n. Total steps " + cont.str() + " to 1\n";
        (void)saveToFile("saveToFile.txt", msg, false);
        msg.clear();
        msg = "n. Max value we have had in Collatz's sequence is " + precmag.str() + "\n";
        (void)saveToFile("saveToFile.txt", msg, false);
    }
    std::cout << "Max value we have had in Collatz's sequence is " << precmag << "\n";
    return 0;
}
