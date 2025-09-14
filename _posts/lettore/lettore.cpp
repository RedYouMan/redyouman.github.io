#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include "proto.h"
#include "tasti.h"
#include <sapi.h> // Header SAPI
#include <atlbase.h> // Per COM
#include <vector>

using namespace std;


/*
 Lettore di file testuali con sintesi vocale (Text to speech)
  Autore: Rosario Turco
  (C) 2025
Ifiles di questo progetto  possono essere riusati in propri progetti ma devono contenere il nome dell'autore originale
  Uso: lettore nomefile.estensione

  */


int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: lettore nomeFile.estensione" << endl;
        return 1;
    }
    std::vector <std::string> tutte_le_righe;
    int ritardo = 0, nrec = 10, countRec = 0, indice_corrente = 0, tasto = 0,totRighe=0;  
    std::string riga,rigaDaPassare;
    std::ifstream file(argv[1],std::ios::in); // Apri il file in lettura
    // Controlla se il file è stato aperto correttamente
    if (file.is_open())
    {
        leggiConfig(&ritardo, &nrec);
        char msg[100];
        memset(msg, '\0', sizeof(msg));
        strcpy_s(msg , "Lettura configurazione lettore.ini");
        callTextToSpeech(msg);
        memset(msg, '\0', sizeof(msg));
        sprintf_s(msg, "Ritardo configurato: %d", ritardo);
        callTextToSpeech(msg);
        memset(msg, '\0', sizeof(msg));
        sprintf_s(msg, "max numero di record da leggere: %d", nrec);
        callTextToSpeech(msg);


        // Ciclo per leggere il file 
        while (std::getline(file, riga))
        {
            tutte_le_righe.push_back(riga);
        }
        totRighe = (int) tutte_le_righe.size();
        file.close();
    }else{
        std::cerr << "Impossibile aprire il file " << argv[1] << std::endl;
        return(1);
    }

    while (indice_corrente<totRighe ) {
        rigaDaPassare.clear();
        rigaDaPassare = tutte_le_righe[indice_corrente];
        if (callTextToSpeech(rigaDaPassare) == 1)
        {
            return 1;
        }
        Sleep(ritardo);
        indice_corrente++;
        countRec++;
        if (countRec == nrec)
        {
            countRec = 0;
            callTextToSpeech("Premi Barra spaziatrice per continuare, freccia su per riascoltare , ESC per uscire");
            
                tasto = attendiTasti();
            if (tasto == ESC)
            {
                return 0;
            }
            else if (tasto == UP) {
                indice_corrente = indice_corrente - nrec;
                callTextToSpeech("Riascoltiamo il precedente\n");
            }
            else
            {
                continue;
            }

        }
    }
    return 0;
}

void leggiConfig(int *ritardo, int *numrecords)
{

    std::ifstream file("lettore.ini"); // Apri il file in lettura
    if (file.is_open())
    {
        file >> *ritardo;
        file >> *numrecords;
    }
    else
    {
        std::cerr << "Uso valori di default - file lettore.ini non trovato" << std::endl;
    }
    return;
}
// parte della sintesi
// Definizione della funzione per pronunciare la stringa
HRESULT SpeakString(const WCHAR* pszText)
{
    HRESULT hr = S_OK;
    CComPtr<ISpVoice> pVoice; // Puntatore all'interfaccia del sintetizzatore

    // Inizializza l'ambiente COM (necessario per usare SAPI)
    hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
    if (FAILED(hr)) {
        std::cerr << "Errore nell'inizializzazione di COM: " << hr << std::endl;
        return hr;
    }

    // Crea l'istanza del sintetizzatore
    hr = pVoice.CoCreateInstance(CLSID_SpVoice);
    if (FAILED(hr)) {
        std::cerr << "Errore nella creazione di IS SpVoice: " << hr << std::endl;
        CoUninitialize();
        return hr;
    }

    // Pronuncia la stringa
    hr = pVoice->Speak(pszText, 0, NULL);
    if (FAILED(hr)) {
        //std::cerr << "Errore durante la pronuncia: " << hr << std::endl;
    }

    // Disattiva l'ambiente COM
    CoUninitialize();
    return hr;
}

int callTextToSpeech(std::string stringaInput)
{
    std::string textToSpeak_str = stringaInput;
    std::wstring textToSpeak(textToSpeak_str.begin(), textToSpeak_str.end());

    // Chiama la funzione per pronunciare la stringa
    HRESULT hr = SpeakString(textToSpeak.c_str());

    if (FAILED(hr)) {
        return 1; // Errore nella sintesi
    }

    return 0; // Successo
}

