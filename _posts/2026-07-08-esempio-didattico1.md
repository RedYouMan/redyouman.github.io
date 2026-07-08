---
title: "la ROTN in azione - esempio didattico 1"
description: "blog di Rosario Turco con downloads di giochi gratuiti per non vedenti"
keywords:
  [
    "downloads",
    "scacchi",
    "gratuiti",
    "gratis",
    "non vedenti",
    "ciechi",
    "ipovedenti",
  ]
categories: Blog
---

# come vincere un finale apparentemente patto in 3 mosse

di Rosario Turco

## Intro

Quante volte hai guardato un finale e pensato "qui è patta"?  
Anche i SuperGM ci cascano. Al Mondiale 2018 tra Carlsen e Caruana è successa una cosa simile: posizione simmetrica, tutti tranquilli... e invece c’era un’idea.  
Con la ROTN non serve vedere la scacchiera. Basta ascoltare la posizione. e i consigli tecnici. Oggi analizziamo proprio questo concetto .

## La posizione

Finale ispirato al match Carlsen-Caruana, Mondiale 2018.  
Materiale pari, simmetria totale. Tratto al Bianco. All’apparenza nulla da fare.

## Codice ROTN da copiare su Scacchi-it

Suggerimento furbo: prima di copiare e incollare in un file, leggi dove sono i due re. Altro consiglio: se sei tu a compilare i campi dei pezzi, metti sempre prima i re degli altri pezzi.

Nota: Posizione didattica ispirata al finale Carlsen-Caruana, Mondiale 2018.
Se scrivi la ROTN in un file markdown md usa gli asterischi (** avanti e dietro ogni campo spaziando la coppia di 1 dal testo**), questo per far comprendere a NVDA i separatori. Se usi, invece, ebook o html non servono gli asterischi e la ROTN è scrivibile su 6 righe in modo chiaro (metodo consigliato).
Se copi la rotn di sotto con gli asterischi, probabilmente tutta la ROTN è su una sola riga: incolla essa in un file con nome ad esempio finale.txt. Togli gli asterischi, fai in modo che ogni descrittore è su una riga propria col suo valore, e metti il file nella cartella problemi di Scacchi-it.  
Poi fai Ctrl+P, Alt-Tab sulla console e scrivi il nome del file senza estensione.

** T:metti il nero in Zugzwang **
** V:B **
** B:Re1;Ta1;Th1;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2**

** N:Re8;Ta8;Th8;Pa7;Pb7;Pc7;Pf7;Pg7;Ph7 **

** M:B **
** P:0 **

## L’analisi passo-passo

**1. Cosa senti con ROTN?**

**2. naviga sulla scacchiera per esplorare la scachiera?**

Re in e1 contro Re in e8. Torri agli angoli. Pedoni tutti sulle ali a,b,c,f,g,h.  
**3. Il piano**  
Il segreto per lo Zugzwang è il tempo e l’opposizione. Proprio come nei finali di alto livello.  
Mossa 1: Re2 - prendiamo l’opposizione.  
Mossa 2: Re3 - penetriamo nel territorio nero.  
Mossa 3: f4 - rottura. Il Nero è in zugzwang e perde un tempo decisivo.

**3. Perché funziona con ROTN?**  
Perché la descrizione ti costringe a pensare per "Re, relazioni, chi ha il tratto" e non per coordinate.  
Con NVDA è immediato: senti che i Re si guardano e che il Bianco può fare la differenza.

## Provala tu

prova a giocare Re2, Re3, f4. Nota come la posizione del nero è peggiorata dopo la terza mossa.

## Conclusione

La ROTN non è solo "scrivere le mosse". È il modo in cui un cieco pensa agli scacchi: per piani, non per caselle.  
Proprio come Carlsen e Caruana al Mondiale, la differenza la fa 1 solo tempo.

\*Suggerisco la Variante principale

_1. Re2 Re7_  
_2. Re3 Re8_  
_3. f4_

### Spiegazione rapida

1. _Re2_ Prendiamo l'opposizione
   1..._Re7_ L'unica del Nero per tenere l'opposizione

2. _Re3_ Avanziamo ancora
   2..._Re8_ Torna indietro per non perdere l'opposizione

3. _f4_ Rottura. Ora il Nero è in zugzwang

Dopo 3...qualsiasi mossa di pedone nero, il Bianco sfonda con g4 e vince.
Se ti è piaciuto, condividi l’articolo con i tuoi amici e prova la posizione. 
