// comDiff.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//
#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include <thread> // Necessario per std::this_thread::sleep_for
#include <cstdlib> // Necessario per system()
#include <windows.h>
#include "proto.h"
#pragma warning(disable:4996)

/*
  AUTORE: Rosario Turco
  (C) 2025

    comDiff permette di attivare un comando in differita
    su windows. Utilizzabile anche come Alert ad una certa ora se sulla directory si pone un audio di una sveglia. 
*/
// Funzione per eseguire il comando al prompt di Windows
void eseguiComando(const std::string& comando) {
    std::cout << "Eseguo il comando: " << comando << std::endl;
    // Esegue il comando nel prompt dei comandi di Windows
    // system() è bloccante, aspetta il termine del comando
    int risultato = std::system(comando.c_str());

    if (risultato == 0) {
        std::cout << "Comando eseguito con successo." << std::endl;
    }
    else {
        std::cerr << "Errore durante l'esecuzione del comando (codice di uscita: " << risultato << ")" << std::endl;
    }
}

int main() {
    std::string inputComando;
    int ore, minuti, secondi;

    // Chiedi all'utente di inserire il comando da eseguire
    callTextToSpeech("Inserisci il comando da eseguire in differita (esempio  dir o wav o altro)");
    std::getline(std::cin, inputComando);
    // prelevo ora attuale
    time_t now1 = time(0); // time(0) restituisce il tempo attuale    std::cout << "Ora attuale  :  " << ltm->tm_hour << ":"<< eltm->tm_minutes<< std::endl;
    tm* ltm = localtime(&now1); // localtime converte time_t in un puntatore a struct tm
    char msg[100];
    memset(msg,'\0',sizeof(msg));
    sprintf_s(msg,"Ora attuale %d:%d",ltm->tm_hour,ltm->tm_min);
    callTextToSpeech(msg);
    
    // Chiedi all'utente di inserire l'orario
    callTextToSpeech("Inserisci l'orario nel formato ora spazio minuti spazio secondi");
    std::cin >> ore >> minuti >> secondi;

    // Calcola l'orario di esecuzione
    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);
    std::tm now_tm = *std::localtime(&now_c);
    now_tm.tm_hour = ore;
    now_tm.tm_min = minuti;
    now_tm.tm_sec = secondi;

    auto target_time = std::chrono::system_clock::from_time_t(std::mktime(&now_tm));

    // Calcola il tempo di attesa in millisecondi
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(target_time - std::chrono::system_clock::now());

    // Gestione del caso in cui l'orario inserito sia nel passato
    if (duration.count() < 0) {
        callTextToSpeech("L'orario inserito è nel passato. Impossibile eseguire il comando.");
        return 1;
    }

    memset(msg,'\0',sizeof(msg));
    sprintf_s(msg, "Il comando parte tra %d secondi", (int)duration.count()/1000);
    callTextToSpeech(msg);
    //Attendi l'orario specificato
    std::this_thread::sleep_for(duration);
    callTextToSpeech("Scaduto il timer : attivo il comando in differita");
    // Esegui il comando
    eseguiComando(inputComando);

    return 0;
}
