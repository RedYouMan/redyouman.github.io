---
title: "Scacchi: Cosa è e cosa fa Scacchi-it"
description: "blog di Rosario Turco con downloads di giochi gratuiti per ciechi"
keywords:
  [
    "tutorials for chess ",
    "giochi",
    "gratuiti",
    "gratis",
    "non vedenti",
    "ciechi",
    "ipovedenti",
  ]
categories: Blog
---

# **Scacchi-it: cosa è e cosa fa**

Scacchi-it è un progetto italiano, sviluppato da Rosario Turco.
Esso costituisce una piattaforma per il gioco degli scacchi con interfaccia vocale, online&offline e gratuito, con licenza MIT e open data. Le sue dimensioni sono tali da poter stare comodamente su una pen drive.

Vediamo cosa vuol dire questa definizione. Il programma non fornisce sorgenti, quindi non è open source, ma ha una MIT licenza, che permette di distribuire liberamente gli eseguibili, conservando la paternità di Scacchi-it all'autore. Inoltre è open data, grazie alla rot notation ideata, che permette di interagire con il programma per produrre o caricare la posizione dei pezzi nelle seguenti funzionalità:

- sospensione momentanea della partita con ripresa di essa
- soluzione di un problema da soli o con l'aiuto del chess engine stockfish
- cambio del punto di vista di gioco
- produzione di file di registrazione di una partita con notazione algebrica

Inoltre la modalità open data si evidenzia anche con la "portable game notation" (pgn) che in Scacchi-it è sfruttata dalla funzionalità Openings Trainer, che permette di addestrarsi sulle aperture desiderate e scaricate da un sito come PGN mentor.

Scacchi-it ha un motore grafico che si interfaccia con il chess engine stockfish ed è costituito dalle seguenti parti:

- parte grafica (scacchiera e pezzi)
- parte caricamento rot notation
- parte di controllo delle mosse valide
- parte gestione scacco matto, stallo, patta elementare, scacco al re
- parte gestione registrazione partita su log con notazione algebrica italiana
- parte sospensione e ripresa partita
- parte rotazione scacchiera
- parte gestione stockfish
- parte vocaleper i non vedenti, segnalando tutti gli aiuti necessari
- parte verbosa su console, utile per vedenti e non vedenti, per comprendere i controlli di gioco del motore grafico edeventuali suggerimenti
- parte Openings Trainer con file pgn
- parte server per gioco in rete o in vpn(multiplayers)
- parte utility: fenpos, validaFEN, incolla-fen, coachFEN.
- parte orologio di gioco

Il vantaggio di Scacchi-it è di interfacciarsi con stockfish rendendo semplici e trasparenti tutte le problematiche di comandi uci, posizione fen, pgn,configurazioni e altro ancora che richiederebbe una maggiore conoscenza informatica che esula dal gioco stesso.

Scacchi-it permette di studiare aperture, fare analisi con o senza stockfish, giocare con stockfish o amici e anche fare lezioni di scacchi.La funzionalità coachFEN, ad esempio, a fronte di una FEN trovata, consiglia la migliore mossa.

Per le lezioni di scacchi sono forniti utili comandi di undo delle mosse e la reimpostazione della scacchiera nella posizione iniziale.

I non vedenti utilizzeranno un screen reader come NVDA o JAWS che permetterà loro sia di usare il computer che usare Scacchi-it.

La rot notation ideata, risulta più semplice a capirla e ricordarla rispetto alla fen o rispetto alle immagini che un non vedente non sarebbe in grado di usufruire.
La rot notation è una estensione della notazione algebrica, che rende un applicativo scacchistico open data. Ha il vantaggio per il non vedente che producendola su un file si può caricare la posizione corrispondente su Scacchi-it per poterla esaminare navigando sulla scacchiera.
La ROTN ha altri vantaggi:

- costituisce la lingua interna, per interscambio dati, con altri formati provenienti da altre piattaforme.
- aumenta la velocità dei test nel descrivere posizioni semplici e complesse, risparmiando moltissimo tempo

Scacchi-it permette di giocare online sia su stessa rete che su reti Hamachi.

Il gioco è un utile e leggero modo, anche divertente, per integrare e far avere ai vedenti maggiore coscienza e consapevolezza sul mondo dei non vedenti , utilizzando lo stesso gioco abbattendo le barriere digitali e giocare alla pari.

Scacchi-it è stato ideato seguendo tale filosofia.

La community attorno a tutti i giochi , contribuisce e apprezza molto il lavoro compiuto dal gruppo NV&V.

La definizione della Specifica ufficiale ROTN completa, ISO 14977 è disponibile a:[Leggi specifica](https://redyouman.github.io/blog/2026/07/02/specifica-rotn.html)

Se siete interessati a scaricare Scacchi-it e il manuale, utilizzare i link:

[scarica Scacchi-it](https://github.com/RedYouMan/redyouman.github.io/raw/main/_posts/repo/scacchiGr.7z)

[Manuale Scacchi-it](https://github.com/RedYouMan/redyouman.github.io/raw/main/_posts/tutorials/scacchiGr.txt)
