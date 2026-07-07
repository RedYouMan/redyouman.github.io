---
title: "ROTN in azione: come vincere un finale apparentemente patto in 3 mosse"
author: Rosario
date: 2026-04-29
tags: [ROTN, Scacchi, Finali, Scacchi-it, Accessibilità]
summary: "Un finale simmetrico ispirato a Carlsen-Caruana 2018. Con la ROTN vediamo come 3 mosse bastano per vincere una posizione che sembra patta."
---

# come vincere un finale apparentemente patto in 3 mosse

## Intro

Quante volte hai guardato un finale e pensato "qui è patta"?  
Anche i SuperGM ci cascano. Al Mondiale 2018 tra Carlsen e Caruana è successa una cosa simile: posizione simmetrica, tutti tranquilli... e invece c’era un’idea.  
Con la ROTN non serve vedere la scacchiera. Basta ascoltare la posizione. Oggi analizziamo quel concetto.

## La posizione

Finale ispirato al match Carlsen-Caruana, Mondiale 2018.  
Materiale pari, simmetria totale. Tratto al Bianco. All’apparenza nulla da fare.

## Codice ROTN da copiare su Scacchi-it

Copia le 6 righe qui sotto in un file di testo e salvalo come finale.txt

T:Mondiale 2018 - Carlsen vs Caruana - Il concetto di Zugzwang
V:B;
B:Re1;Ta1;Th1;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;
N:Re8;Ta8;Th8;Pa7;Pb7;Pc7;Pf7;Pg7;Ph7;
M:B;
P:0;

Nota: Posizione didattica ispirata al finale Carlsen-Caruana, Mondiale 2018. P:0; indica posizione iniziale di esempio. Ricorda: se la mossa è n e tocca al Bianco metti P:n-1;, se tocca al Nero metti P:n;

## Opzione B: L’analisi passo-passo

**1. Cosa senti con ROTN?**  
V:B; guardiamo dal Bianco.  
Re in e1 contro Re in e8. Torri agli angoli. Pedoni tutti sulle ali a,b,c,f,g,h.  
M:B; tocca a noi. Sembra di ghiaccio.

**2. Il piano**  
Il segreto è il tempo e l’opposizione. Proprio come nei finali di alto livello.  
Mossa 1: Re2 - prendiamo l’opposizione.  
Mossa 2: Re3 - penetriamo nel territorio nero.  
Mossa 3: f4 - rottura. Il Nero è in zugzwang e perde un tempo decisivo.

**3. Perché funziona con ROTN?**  
Perché la descrizione ti costringe a pensare per "Re, relazioni, chi ha il tratto" e non per coordinate.  
Con NVDA è immediato: senti che i Re si guardano e che il Bianco può fare la differenza.

## Provala tu

Copia le 6 righe ROTN qui sopra e metti il file nella cartella problemi di Scacchi-it.  
Poi fai Ctrl+P, Alt-Tab sulla console e scrivi il nome del file senza estensione.  
Metti le cuffie e prova a giocare Re2, Re3, f4. Ascolta come la valutazione esplode dopo la terza mossa.

## Conclusione

La ROTN non è solo "scrivere le mosse". È il modo in cui un cieco pensa agli scacchi: per piani, non per caselle.  
Proprio come Carlsen e Caruana al Mondiale, la differenza la fa 1 solo tempo.

Se ti è piaciuto, condividi l’articolo con i tuoi amici e prova la posizione.
