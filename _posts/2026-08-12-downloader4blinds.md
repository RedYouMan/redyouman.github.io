---
title: "Semantic Engine for Blinds - Downloader - accessibilità digitale per non vedenti "
description: "Un semplice e utile downloader per non vedenti "
categories: "Blog"
---

## Semantic Engine for Blinds- Downloader

by Rosario Turco

### 1. Cos'è

SE4B-Downloader è un programmino da console per scaricare file e documentazione tecnica.
Pensato per NVDA/JAWS. Legge tutto ad alta voce.
Utilizza il comando curl già presente sulle piattaforme Windows.

SE4B = Semantic Engine for Blinds.
Prima scarica e dopo guarda gli esempi dopo il link.

[Scarica il downloader](https://github.com/RedYouMan/redyouman.github.io/raw/main/_posts/repolc/se4b-downloader.exe)

### 2. Semantica, Intento e Feedback

Ogni comando ha 3 parti:

1.  _INTENTO_: tu scrivi "scarica manuale nvda". L'intento è scaricare.
2.  _SEMANTICA_: il programma capisce "scarica" = azione, "manuale nvda" = nome scorciatoia.
3.  _FEEDBACK_: il programma ti risponde SEMPRE con "Inizio download..." e poi "Download completato" o "Errore".
    Per questo diciamo sempre "fatto". Senza feedback con NVDA non sapresti se è andato o no.

### 3. Installazione e avvio

1.  Salva il file in una directory
2.  Apri "Prompt dei comandi "
3.  Avvia con: `se4b.exe`

### 4. Comandi Base

Comando | Cosa fa
`scarica aiuto` | Legge tutti i comandi
`scarica lista` | Legge le 25 scorciatoie disponibili
`scarica nome` | Scarica la scorciatoia nella cartella corrente
`scarica nome in cartella` | Scarica nella cartella che dici tu
`scarica url link` | Scarica qualsiasi url diretto
`scarica url link in cartella` | Scarica url nella cartella
`esci` | Chiude il programma

### 5. Esempi Scorciatoie

`scarica manuale nvda`  
`scarica wcag 22 in documentazione`  
`scarica tesseract setup in tools`

### 6. Download Libero con URL

Ora puoi scaricare qualsiasi file da internet.  
`scarica url https://sito.com/file.zip`  
`scarica url https://sito.com/file.zip in downloads`

### 7. Se devi scaricare file pgn dal sito pgnMentor

Guarda prima sul sito https://pgnmentor.com/files.html e scegli il file dell'apertura.

Comando per scaricare ad esempio la Francese:

se4b.exe
scarica url https://www.pgnmentor.com/files/French.zip

### 8. ATTENZIONE: Anti-Redirect per GitHub

Questo è importante. Il programma ora controlla la dimensione.

_Il Problema:_  
Su GitHub molti link tipo `/latest/download/file.exe` sono dei redirect da 9 byte.

_Esempio Sbagliato:_
SE4B-Downloader> scarica url https://github.com/tesseract-ocr/tesseract/releases/latest/download/tesseract.exe
SE4B-Downloader> Attenzione: file molto piccolo. 9 byte. Potrebbe essere un redirect di GitHub

_La Soluzione - 3 Passi:_

1.  Vai su `github.com/tesseract-ocr/tesseract`
2.  Clicca su `Releases` a destra
3.  Tasto destro sul file `.exe` più grande -> `Copia indirizzo link`

_Esempio Corretto:_
SE4B-Downloader> Download completato in .\tools\tesseract-ocr-w64-setup-5.5.0.20241111.exe. Dimensione: 62341 KB
_Regola d'oro:_ Se il file pesa meno di 50KB, il programma te lo dice. Cancellalo e prendi il link diretto.

### 9. Errori Comuni

Errore | Causa | Soluzione
`undefined reference to InternetOpenA` | Dimenticata libreria | Compila con `-lwininet`
`Errore creazione file` | Cartella non esiste | Crea prima la cartella o usa `.`
`Attenzione: file 9 byte` | Link redirect GitHub | Prendi link diretto da Releases
`Scorciatoia non trovata` | Nome sbagliato o trattini | Usa spazi. Es: `manual nvda`
`NVDA non legge output` | Console non UTF8 | Il programma imposta UTF8 da solo
