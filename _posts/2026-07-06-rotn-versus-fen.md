---
title: "Scacchi: Cosa è la rotn"
description: "blog di Rosario Turco con downloads di giochi gratuiti per ciechi"
keywords:
  [
    "Articoli per scacchi ",
    "giochi",
    "gratuiti",
    "gratis",
    "non vedenti",
    "ciechi",
    "ipovedenti",
  ]
categories: Blog
---

# **Cosa è la ROTN**

di Rosario Turco

Innanzitutto è una specifica per chisviluppa software scacchistico compatibile con screen reader (come NVDA e simili), ma che consente di utilizzare il software anche ai vedenti, in un concetto a me caro di integrazione dei due mondi: non vedenti e vedenti (NV&V).
Il gioco diventa un momento sociale di integrazione e di possibilità alla pari tra vedente e non vedente.

La RoTN è un file testuale fatto di descrittori seguiti da valori. Tutti i campi descrittori sono obbligatori e V: va messo dopo T: e prima degli altri rimanenti.

_Esempio RoTN_
T:Matto in una mossa
V:N;
B:Rh8;
N:Rf7;Dg1;
M:N
P:34;

- T: descrive la posizione che verrà letta anche con sintesi vocale
- V: descrive da che punto di vista si vuole che il programma carichi la posizione (Bianco o Nero usando B; o N;)
- B: descrive l'elenco separato da punti e virgole dei pezzi con notazione algebrica italiana (es: Ag5;Re2;)
- N: descrive l'insieme dei pezzi neri come sopra
- M: descrive a chi tocca la mossa (Bianco o Nero usando B o N)
- P: descrive il numero di mossa di partenza

In particolare P: va diminuito di 1 se a giocare per prima è il Bianco (M:B) oppure rimane uguale se gioca per prima il Nero (M:N).

Il motivo è che un applicativo di scacchi (es: Scacchi-it) incrementa la mossa quando gioca in bianco e non lo fa in nero, proprio perchè la mossa è costituita da due semimosse: quella del bianco e poi quella del nero.

# **Vantaggi della RoTN**

La RoTN unisce i vantaggi di una immagine con quelli della notazione algebrica più sintetica rispetto alla FEN.
Infatti aggiunge il testo (T:) che valorizza il momento artistico e clou della posizione, inoltre aggiunge il punto di vista da cui guardare e giocare la partita. L'applicativo, difatti, carica la posizione dal punto di vista dichiarato nella ROTN.
Un applicativo che rispetta la ROTN può attraverso essa: sospendere una partita, riprendere una partita, ruotare la scacchiera, caricare un problema scritto con Notepad, creato da noi o copiato da internet o da un e-book.

La sinteticità della notazione algebrica rende più rapidamente intuibile la posizione.

Scacchi-it è stato il prodotto creato da me e centrato sulla ROTN, per un costo di 8 mesi/uomo.

Per comprendere meglio i limiti di una fen esaminiamo come è fatta.

fu ideata da Steven J. Edwards estendendo il Forsyth's system ideato per l'uso del calcolatore. La sua forma,inizialmente, era dovuta al tentativo di risparmiare la quantità di memoria nel registrare delle informazioni.
Difatti i componenti di una stringa FEN (6 parti) sono:

1. Posizione dei pezzi: Fila per fila (dall'8a alla 1a), lettere minuscole per il nero, maiuscole per il bianco, numeri per le case vuote.
2. Turno: w (bianco) o b (nero).
3. Arrocco: Kqkq (disponibilità arrocco lato re/donna) oppure valorizzati ognuno con -.
4. Cattura en passant: Casa in cui un pedone avversario potrebbe andare dopo la cattura , o -.
   C'è da aggiungere che, per standard, all'atto della fotografia della posizione, essa contiene il valore della casa di cattura dovuta allo spostamento di due passi di un pedone, anche se non esiste nessun pedone avversario che possa usufruire dell'enpassant.
   Ad esempio se si muove un pedone da b2 a b4 la casa indicata è b3, ovvero la casa di cattura in cui si metterebbe un pedone avversario in caso di cattura enpassant.
5. Semi-mosse: Numero per la regola delle 50 mosse.
6. Mosse totali: Numero di mosse della partita.

   Per la semimossa nella fen (quinto campo della stringa), come recita Wikipedia, è un contatore del numero di mezzi turni (mosse del Bianco
   o del Nero) effettuati dall'ultima cattura o spinta di pedone. Viene utilizzato per determinare la regola delle 50 mosse: se arriva a 100 (50 mosse complete), la partita può essere dichiarata patta.

Esempi FEN:
• Posizione iniziale: rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1.
• Dopo 1. e4 c5 2.Ch8f3:
rnbqkbnr/pp1ppppp/8/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R b KQkq - 1 2.

Ad esempio la fen seguente mostra i suoi limiti:
7K/5k2/8/8/8/8/8/6q1 B ---- - 0 34

Tutto questo per dire che il nero ha due pezzi: re e regina e il bianco solo il re, con la mossa al nero; Ma non dice cosa occorre fare e da che punto di vista mettersi per valutare meglio la posizione.
Nella RoTN troveremo semplicemente e in maniera chiara senza doversi fare i conti:

T:Matto in una mossa
V:N;
B:Rh8;
N:Rf7;Dg1;
M:N
P:34;
Come si nota la fen ha anche altre due barriere invisibili all'accessibilità:

- la lingua: K, k, Q, q, B, b etc.
- la non immediata comprensione: occorre farsi dei calcoli per capire la posizione dei pezzi

Inoltre per un umano non serve sapere la situazione degli arrocchi, lo vede da se, e anche il computer è in grado di analizzarlo e settarlo, nè gli serve la segnalazione delle 50 mosse o dell'enpassant.

Scacchi-it , ideato per vedenti e non vedenti, nelle sospensioni si segna l'enpassant per comunicare la possibilità di esso alla ripresa, ma solo se esiste tale possibilità, diversamente dallo standard fen.

In un e-book per non vedenti se ci sono immagini, esse non sono fruibili dal non vedente; per cui, generalmente, viene descritta la posizione con la notazione algebrica, che ha il vantaggio di far comprendere la posizione dei pezzi rapidamente.
La RoTN fa un passo ulteriore, consentendo l'ascolto e l'immediato utilizzo su scacchiera e non solo.

Se in un e-book viene mostrata la RoTN, col copia e incolla si può rapidamente trasferirla in un file e caricarla in Scacchi-it. In tal modo si può ascoltare, con sintesi vocale, il testo e navigare sulla scacchiera esplorando la posizione, apprezzando meglio quanto descritto nel e-book.

La RoTN, inoltre, rende open data l'applicativo Scacchi-it in modo bidirezionale: consente di sospendere una partita e di riprenderla più tardi, come pure scrivere o copiare problemi e caricarli per la loro soluzione.
Per cui la giusta definizione della rot notation è che essa estende la notazione algebrica e rende open data un applicativo di scacchi, consentendo di interagire con esso in due direzioni e aggiungendo la sintesi vocale e i vantaggi di una immagine.

# **Specifica formalizzata per non vedenti**

Come sempre accade, chi ha delle necessità, realizza una specifica e un applicativo di scacchi (Scacchi-it) che ne dimostra i vantaggi in modo pratico.Un applicativo innovativo, per giocare offline e online, con stockfish, studiare le aperture con un Openings Trainer, poter fare lezioni con undo delle mosse e con una facile reinizializzazione della scacchiera.

La definizione della Specifica ufficiale ROTN completa, ISO 14977 è disponibile a:
https://redyouman.github.io/blog/2026/07/02/Spec-ROTN.html
