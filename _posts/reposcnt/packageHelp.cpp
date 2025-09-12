#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
// Semplice XOR per cifrare/decifrare (chiave hardcoded)
const char XOR_KEY = 0x5A;

// Cripta il fileName (sovrascrive il file)
int crypt(std::string fileName)
{
    std::ifstream in(fileName, std::ios::binary);
    if (!in)
        return -1;
    std::vector<char> buffer((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
    in.close();

    for (auto &c : buffer)
        c ^= XOR_KEY;

    std::ofstream out(fileName, std::ios::binary | std::ios::trunc);
    if (!out)
        return -1; // prima era -2
    out.write(buffer.data(), buffer.size());
    out.close();
    return 1;
}

// Decifra il fileName (ritorna il contenuto in chiaro come stringa)
std::string decrypt(std::string fileName)
{
    std::ifstream in(fileName, std::ios::binary);
    if (!in)
        return "";
    std::vector<char> buffer((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
    in.close();

    for (auto &c : buffer)
        c ^= XOR_KEY;

    return std::string(buffer.begin(), buffer.end());
}

// Esempio di utilizzo in help()
int help()
{
    std::string filename = "help.pkg";
    int linesPerPage = 10; // Numero di linee per pagina

    std::vector<std::string> lines;
    std::string line;
    std::string content = decrypt(filename);
    std::istringstream iss(content);
    while (std::getline(iss, line))
    {
        lines.push_back(line);
    }
    if (lines.empty())
    {
        std::cout << "Error: no help content found." << std::endl;
        return 1;
    }

    // Paginare il contenuto
    std::vector<std::vector<std::string>> pages;
    for (int i = 0; i < static_cast<int>(lines.size()); i += linesPerPage)
    {
        pages.push_back(std::vector<std::string>(lines.begin() + i,
                                                 (i + linesPerPage < static_cast<int>(lines.size())) ? lines.begin() + i + linesPerPage : lines.end()));
    }

    // Sistema di navigazione
    int currentPage = 0;

    while (true)
    {
        std::cout << "\nPages available: " << pages.size() << "\n";
        std::cout << "Page: " << currentPage + 1 << std::endl;
        for (const std::string &line : pages[currentPage])
        {
            std::cout << line << std::endl;
        }

        std::cout << "\nPress a letter with return : 'n' for next page, 'p' for previous page, 'q' for exit." << std::endl;
        char choice;
        std::cin >> choice;

        switch (choice)
        {
        case 'n':
            if (currentPage < static_cast<int>(pages.size()) - 1)
            {
                currentPage++;
            }
            else
            {
                std::cout << "Nothing next page." << std::endl;
            }
            break;
        case 'p':
            if (currentPage > 0)
            {
                currentPage--;
            }
            else
            {
                std::cout << "Nothing previous page." << std::endl;
            }
            break;
        case 'q':
            std::cout << "exit from 'help()'." << std::endl;
            return 0;
        default:
            std::cout << "Choice not valid." << std::endl;
        }
    }
    return 0;
}
