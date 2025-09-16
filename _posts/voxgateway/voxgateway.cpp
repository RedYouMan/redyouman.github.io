#include <iostream>
#include <string>
#include "proto.h"
int main(int argc, char* argv[])
{
    // Controlla che sia stato fornito almeno un argomento dopo il nome del programma
    if (argc < 2) {
        std::cerr << "Uso: " << argv[0] << " \"Testo da pronunciare\"" << std::endl;
        return 1;
    }
    std::string stringaDaPassare;
    stringaDaPassare.append(argv[1]);
    if(callTextToSpeech(stringaDaPassare)==1){
        std::cerr << "Errore callTextToSpeech()" << std::endl;
        return 1;
    }

    return 0; // Successo
}