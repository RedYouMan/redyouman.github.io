// tts

#include <iostream>
#include <windows.h>
#include <string>
#include <sapi.h> // Header SAPI
#include <atlbase.h> 
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

