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

Scacchi-it è un programma di gioco degli scacchi, con interfaccia vocale, offline e gratuito, con licenza MIT e open data.
Vediamo cosa vuol dire questa definizione. Il programma non fornisce sorgenti, quindi non è open source, ma ha una MIT licenza, che permette di distribuire liberamente gli eseguibili, conservando la paternità di Scacchi-it all'autore. Inoltre è open data, grazie alla rot notation ideata, che permette
di interagire tramite file con il programma per produrre o caricare la posizione dei pezzi nelle seguenti funzionalità:

- sospensione momentanea della partita con ripresa di essa
- soluzione di un problema da soli o con l'aiuto del chess engine stockfish
- cambio del punto di vista di gioco
- produzione di file di registrazione di una partita con notazione algebrica

Per la notazione algebrica è anche risolta la possibilità che due pezzi simili dello stesso colore possano andare nella stessa casa. Tale problema solitamente è solo per le torri o per i cavalli, dato che gli alfieri sono su case di colore diverso e non potranno andare su una casa dello stesso colore. Ad esempio se abbiamo una torre in a1 ed una torre in f1 ed entrambe potrebbero andare in d1, ma ci interessa che sia la torre in a1 che vada in d1, nella notazione algebrica dovrà risultare la mossa Tad1.

Inoltre la modalità open data si evidenzia anche con la "portable game notation" (pgn) che in Scacchi-it è sfruttata dalla funzionalità Openings Trainer, che permette di addestrarsi sulle aperture desiderate e scaricate da un sito come PGN mentor.

Sostanzialmente Scacchi-it è un motore grafico che si interfaccia con il chess engine stockfish ed è costituito dalle seguenti parti:

- parte grafica (scacchiera e pezzi)
- parte caricamento rot notation
- parte di controllo delle mosse valide
- parte vocaleper i non vedenti, segnalando tutti gli aiuti necessari
- parte verbosa su console, utile per vedenti e non vedenti, per comprendere i controlli di gioco del motore grafico edeventuali suggerimenti

Il vantaggio di Scacchi-it è di interfacciarsi con stockfish rendendo semplici e trasparenti tutte le problematiche di comandi uci, posizione fen, pgn,configurazioni e altro ancora che richiederebbe una maggiore conoscenza informatica che esula dal gioco stesso.

I non vedenti utilizzeranno un screen reader come NVDA che permetterà loro sia di usare il computer che usare Scacchi-it.

La rot notation ideata, risulta più semplice a capirla e ricordarla rispetto alla fen o rispetto alle immagini che un non vedente non sarebbe in grado di usufruire. La rot notation è basata, se si guarda il tutorial di Scacchi-it, sulla notazione algebrica italiana ed ha il vantaggio per il non vedente che producendola su un file si può caricare la posizione corrispondente su Scacchi-it per poterla esaminare navigando sulla scacchiera.

Il gioco è un utile e leggero modo, anche divertente, per integrare e far avere ai vedenti maggiore coscienza e consapevolezza sul mondo dei non vedenti , utilizzando lo stesso gioco abbattendo le barriere digitali e giocare alla pari.

Scacchi-it è stato ideato seguendo tale filosofia.

La community attorno a tutti i giochi , contribuisce e apprezza molto il lavoro compiuto dal gruppo NV&V.
Alla prossima
