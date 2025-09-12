#include <iostream>
#include <fstream>
#include <string>
#include "proto.h"
using namespace std;
// Dichiara la funzione parser, che dovresti aver definito in parser.cpp
int parser(const std::string &comando)
{
    std::string input = comando;

    input = trim(input);
    int status = 0;

    status = otherCommand(input);
    if (status == 1)
    {
        input.clear();
    }

    if (status == 0 && input.length() > 0)
    {
        status = extractFor(input);
    }
    if (status == 0 && input.length() > 0)
    {
        status = extractRecursiveCommand(input);
        if (status == 1)
        {
            return (1); // salta il ciclo
        }
        if (status == -1)
        {
            std::cout << "There is a problem with a recursive command\n";
            return (-1);
        }
        int command = extractCommand(input);
        if (command == -1)
        {
            std::cout << "There is a problem on extraction of the command\n";
            return (-1);
        }
        if (command != -1)
        { // controllo parametri
            int numPar = extractValues(input, command);
            if (numPar == -1)
            {
                std::cout << "There is a problem on parameters\n";
                return (-1);
            }
            (void)executeCommand(command);

            return 1;
        }
    }
    return 0;
}

// Funzione per eseguire i comandi da file
int execute(const std::string &nomeFile)
{
    std::ifstream file(nomeFile);
    if (!file.is_open())
    {
        std::cerr << "Error: impossible to open the script " << nomeFile << std::endl;
        return -1;
    }

    std::string linea;
    int risultato = 0;
    while (std::getline(file, linea))
    {
        // Ignora righe vuote o commenti (opzionale)

        if (linea.substr(0, 4) == "#end")
        {
            std::cout << "end of script\n";
            return (1);
        }
        if (linea[0] == '#')
        {
            std::cout << "comment " << linea << std::endl;
        }
        if (linea.empty())
        {
            std::cout << "blank line\n";
        }
        if (linea.empty() || linea[0] == '#')
        {
            continue;
        }
        risultato = 1;
        risultato = parser(linea);
        if (risultato == -1)
        {
            std::cerr << "Errore nell'esecuzione del comando: " << linea << std::endl;
            break;
        }
    }

    file.close();
    return risultato;
}