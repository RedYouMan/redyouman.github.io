
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> // Per std::next
#include <boost/multiprecision/cpp_int.hpp>
#include <vector>
#include "proto.h"
using namespace boost::multiprecision;
/*
Author:Rosario Turco
Version: 2.0con boost 1.88.0
Creation Date: 4/5/2025
*/

int main()
{

    std::cout << "Welcome to SCNT - Simple calculator of Number Theory !" << std::endl;
    std::cout << "Author: Rosario Turco" << std::endl;
    std::cout << "opensource: MIT licence\n";
    std::string input;
    int status = 0;
    do
    {
        std::cout
            << "Please enter a command (or type 'help()' for assistance): ";
        input.clear();
        getline(std::cin, input); // Legge l'input dell'utente

        input = trim(input);
        status = 0;
        status = otherCommand(input);
        if (status == 1)
        {
            input.clear();
        }

        if (status == 0 && input.length() > 0)
        {
            // std::cout << "non me lo aspettavo\n";
            status = extractFor(input);
        }
        if (status == 0 && input.length() > 0)
        {

            status = extractRecursiveCommand(input);
            if (status == -1 || status == 1)
            {
                continue; // it jumps thhe cycle
            }
            int command = extractCommand(input);
            if (command == -1)
            {
                std::cout << "I don't understand the command\n";
                continue; // to jump the cycle
            }
            if (command != -1)
            { // parameters control
                int numPar = extractValues(input, command);
                if (numPar == -1)
                {
                    continue; // to jump the cycle
                }
            }
            (void)executeCommand(command);
        }
    } while (1);

    return 0;
}
