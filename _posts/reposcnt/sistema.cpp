#include <iostream>
#include <filesystem>
#include <fstream>
#include <string.h>
#include <string>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <sstream>
bool StartSave;
const int insufficientSpace = 30;
void saveToFile(const char *nome, std::string msg, bool toVideo);
double secureQuota();

// implementation
int diskControl(bool toVideo)
{
    namespace fs = std::filesystem;

    double total = 0, used = 0, available = 0;

    int status = -1;
    try
    {
        fs::space_info space_info = fs::space(fs::current_path());
        total = space_info.capacity / (1024 * 1024 * 1024);
        available = space_info.available / (1024 * 1024 * 1024);
        used = total - available;
        if (toVideo)
        {
            std::cout << "Available space: " << available << " GB" << std::endl;
        }
        if (available >= insufficientSpace)
        {
            status = 1;
            if (toVideo)
            {
                std::cout << "Please use a smaller search interval to avoid running out of space.\n";
            }
        }
        else
        {
            status = 0;
            StartSave = false;
            if (toVideo)
            {
                std::cout << "Warning: Insufficient disk space (<" << insufficientSpace << " GB) to save the file.\n";
                std::cout << "Saving to file has been stopped!\n";
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return status;
}

void saveToFile(const char *nome, std::string msg, bool toVideo)
{
    double quota = 0;
    quota = secureQuota();
    if (msg.length() / (1024 * 1024 * 1024) > quota)
    {
        // The amount of data exceeds the available space
        StartSave = false; // Stop writing

        std::cout << "Insufficient space to save the file.\n";
        return;
    }

    // secure redondant control
    if (diskControl(false) == 1)
    {
        std::ofstream file(nome, std::ios::app); // Apri il file in modaplità append
        if (file.is_open())
        {
            file << msg << std::endl; // Scrivi il messaggio nel file
            file.close();             // Chiudi il file
            if (toVideo)
            {
                std::cout << "Message saved to the file: " << nome << std::endl;
            }
        }
        else
        {
            if (toVideo)
            {
                std::cout << "Problems to open of the file: " << nome << std::endl;
            }
        }
    }
    else
    {
        std::cout << "Insufficient space to save on the file/n";
    }
    return;
}

double secureQuota()
{
    namespace fs = std::filesystem;

    double totale = 0, utilizzato = 0, disponibile = 0, disponibileSicuro = 0;

    try
    {
        fs::space_info space_info = fs::space(fs::current_path());
        totale = space_info.capacity / (1024 * 1024 * 1024);
        disponibile = space_info.available / (1024 * 1024 * 1024);

        disponibileSicuro = disponibile - insufficientSpace;
        utilizzato = totale - disponibile;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Errore: " << e.what() << std::endl;
        disponibileSicuro = 0;
    }
    return (disponibileSicuro);
}

// rilevamento data ora e minuti

int myTime()
{
    // Ottieni il tempo corrente
    auto now = std::chrono::system_clock::now();

    // Converti il tempo in un tempo epoch (secondi dal 1970)
    auto epoch = now.time_since_epoch();

    // Estrai il numero di secondi
    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(epoch).count();

    // Converti il tempo epoch in una struttura tm (data e ora)
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::tm tm = *std::localtime(&t);

    // Crea uno stringstream per costruire la stringa
    std::stringstream ss;

    // Formatta la data e l'ora
    ss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");

    // Ottieni la stringa risultante

    std::string timestamp;
    timestamp = ss.str();

    // Stampa i risultati
    std::cout << "Date , hours and minutes: " << timestamp << std::endl;

    if (StartSave)
    {
        (void)saveToFile("saveToFile.txt", timestamp, false);
    }
    return 1;
}