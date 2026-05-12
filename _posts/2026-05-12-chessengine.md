---
title: "Scacchi: Cosa è un chess engine"
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

# **Cosa è un chess engine**

Un chess engine è un programma realizzato per giocare a scacchi, costituito da quattro parti essenzialmente:

- una rappresentazione in memoria della scacchiera
- una strategia per produrrre mosse legali o valide per regolamento
- una strategia per valutare una posizione a partire da una posizione data
  -una interfaccia per interagire con esso

Di solito le interfacce per interagire col chess engine utilizzano il protocollo standard user chess interface (uci).
Per quanto riguarda la strategia per produrre mosse a partiire da una posizione data e con un dato colore di gioco, ci sono tre modalità di cui le prime due furono proposte da Shannon nel suo classico articolo del 1950 :
• Strategia A: o "forza bruta". Il programma deve valutare tutte le possibile mosse e tutte le possibili risposte fino a una profondità prefissata.
• Strategie B: o "selettiva". È un modo per eliminare eventuali mosse poco interessanti che fanno perdere solo tempo. Per fare questo, ci si concentra solo sulle posizioni di tipo "statico", nelle quali nessuna delle mosse possibili implica la presa di materiale. Questa strategia richiede lo sviluppo di procedure adeguate per l'ordinamento e lo scarto intelligente delle mosse.
• Strategia C: dovuta a Herbert E. Bruderer. Consiste nella implementazione dei principi di valutazione strategica del
La prima strategia è stata quella che, probabilmente, ha dato finora i migliori risultati, prima dell'avvento della Intelligenza Artificiale (AI).

Ci sono moltissimi chess engine, sia open source che a pagamento.

Tra i più famosi nel settore open source troviamo:

- stockfish
  -Lc0 (Leela Chess Zero)

  Quelli citati sopra sono due motori di gioco molto interessannti, i migliori del settore e basati su reti neurali.
  Tuttavia esistono molti altri in ambito open source e a pagamento.

Solitamente ogni anno si fa un torneo dove i giocatori sono i chess engine e alla fine del torneo si decreta il vincitore. Finora il vincitore degli ultimi anni è stato stockfish, tallonato da Lc0.
Stockfish è davvero un potente motore di gioco con forza di almeno 3500 elo o anche più, ovvero stiamo parlando di una forza paragonabile ad un campione del mondo umano.

Il nome stravagante di stockfish ha un suo perchè. il progetto iniziale open source fu dovuto al norvegese Tord Romstad, ideatore originale del motore che ha preceduto Stockfish, chiamato Glaurung. Successivamente l'italiano Marco Costalba, che ha collaborato attivamente allo sviluppo nelle prime fasi, prendendo in mano il progetto dopo Romstad, lo ha chiamato stockfish perchè "nato in Norvegia e cucinato in Italia".

Il team di stockfish è molto attivo e produce molti miglioramenti. Stockfish è stato realizzato con un algoritmo di rete neurale alph0, il che vuol dire che si tratta di una rete addestrata ma che può autoapprendere.
AlphaZero è un rivoluzionario algoritmo di intelligenza artificiale sviluppato da Google DeepMind, progettato per imparare a padroneggiare giochi complessi (come scacchi, Go e shogi) partendo da zero, ovvero conoscendo esclusivamente le regole del gioco, senza alcun intervento o conoscenza pregressa umana.
Diversi giochi online utilizzano stockfish.
Il motore stockfish è libberamente scaricabile e cisi può giocare offline sul proprio pc. Tuttavia anche se esiste una interfaccia con cui interagire non è comodo dovere usare i comandi uci, per questo sono nati vari motori grafici per poterlo utilizzare comodamente.
