---
title: "Semantic Engine for Blinds - Downloader - accessibilità digitale per non vedenti "
description: "Un semplice e utile downloader per non vedenti "
keywords:
  [
    "downloader",
    "SE4B",
    accessibilità"autonomia",
    "inclusione",
    "non vedenti",
    "software",
  ]
categories: Blog
---

## Semantic Engine for Blinds- Downloader

by Rosario Turco

### 1. Cos'è

SE4B-Downloader è un programmino da console per scaricare file e documentazione tecnica.
Pensato per NVDA/JAWS. Legge tutto ad alta voce.
Utilizza il comando curl già presente sulle piattaforme Windows.

SE4B = Semantic Engine for Blinds.

[Scarica il downloader](https://github.com/RedYouMan/redyouman.github.io/raw/main/_posts/repolc/se4b-downloader.exe)

### 1. Semantica, Intento e Feedback

Ogni comando ha 3 parti:

1.  **INTENTO**: tu scrivi "scarica manuale nvda". L'intento è scaricare.
2.  **SEMANTICA**: il programma capisce "scarica" = azione, "manuale nvda" = nome scorciatoia.
3.  **FEEDBACK**: il programma ti risponde SEMPRE con "Inizio download..." e poi "Download completato" o "Errore".
    Per questo diciamo sempre "fatto". Senza feedback con NVDA non sapresti se è andato o no.

### 2. Installazione e avvio

1.  Salva il file in una directory
2.  Apri "Prompt dei comandi "
3.  Avvia con: `se4b.exe`

### 3. Comandi Base

| Comando                        | Cosa fa                                        |
| ------------------------------ | ---------------------------------------------- |
| `scarica aiuto`                | Legge tutti i comandi                          |
| `scarica lista`                | Legge le 25 scorciatoie disponibili            |
| `scarica nome`                 | Scarica la scorciatoia nella cartella corrente |
| `scarica nome in cartella`     | Scarica nella cartella che dici tu             |
| `scarica url link`             | Scarica qualsiasi url diretto                  |
| `scarica url link in cartella` | Scarica url nella cartella                     |
| `esci`                         | Chiude il programma                            |

### 4. Esempi Scorciatoie

`scarica manuale nvda`  
`scarica wcag 22 in documentazione`  
`scarica tesseract setup in tools`

### 5. Download Libero con URL

Ora puoi scaricare qualsiasi file da internet.  
`scarica url https://sito.com/file.zip`  
`scarica url https://sito.com/file.zip in downloads`

### 6. ATTENZIONE: Anti-Redirect per GitHub

Questo è importante. Il programma ora controlla la dimensione.

**Il Problema:**  
Su GitHub molti link tipo `/latest/download/file.exe` sono dei redirect da 9 byte.

**Esempio Sbagliato:**
SE4B-Downloader> scarica url https://github.com/tesseract-ocr/tesseract/releases/latest/download/tesseract.exe
SE4B-Downloader> Attenzione: file molto piccolo. 9 byte. Potrebbe essere un redirect di GitHub

**La Soluzione - 3 Passi:**

1.  Vai su `github.com/tesseract-ocr/tesseract`
2.  Clicca su `Releases` a destra
3.  Tasto destro sul file `.exe` più grande -> `Copia indirizzo link`

**Esempio Corretto:**
SE4B-Downloader> Download completato in .\tools\tesseract-ocr-w64-setup-5.5.0.20241111.exe. Dimensione: 62341 KB

**Regola d'oro:** Se il file pesa meno di 50KB, il programma te lo dice. Cancellalo e prendi il link diretto.

### 7. Errori Comuni

| Errore                                 | Causa                     | Soluzione                         |
| -------------------------------------- | ------------------------- | --------------------------------- |
| `undefined reference to InternetOpenA` | Dimenticata libreria      | Compila con `-lwininet`           |
| `Errore creazione file`                | Cartella non esiste       | Crea prima la cartella o usa `.`  |
| `Attenzione: file 9 byte`              | Link redirect GitHub      | Prendi link diretto da Releases   |
| `Scorciatoia non trovata`              | Nome sbagliato o trattini | Usa spazi. Es: `manual nvda`      |
| `NVDA non legge output`                | Console non UTF8          | Il programma imposta UTF8 da solo |
