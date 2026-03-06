---
title: "Scacchi: FEN E RoT notation:problems Collection per ciechi "
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

# **Chess: One Hundred chess problems forblinds**
100 Problemi di scacchi per non vedenti
Rosario Turco

Nel seguito indicheremo 100 posizioni di scacchi, attraverso sia la fe notation che la rot notation, dove  quest'ultima è maggiormente adatta ai ciechi che non possono usufruire delle immagini e la fen è poco intuitiva.

Mai più bloccati davanti ad una immagine di scacchi o ad una fen!

#**La fe notation (fen)**
fu ideata daSteven J. Edwards estendendo il sistema Forsyth's ideato per l'uso del calcolatore. La sua forma,inizialmente, era dovuta al tentativo di risparmiare la quantità di memoria nel registrare delle informazioni.
Difatti i componenti di una stringa FEN (6 parti) sono:
1. Posizione dei pezzi: Fila per fila (dall'8a alla 1a), lettere minuscole per il nero, maiuscole per il bianco, numeri per le case vuote.
2. Turno: w (bianco) o b (nero).
3. Arrocco: Kqkq (disponibilità arrocco lato re/donna) oppure valorizzati ognuno con -.
4. Cattura en passant: Casa in cui un pedone avversario potrebbe andare dopo la cattura , o -.
C'è da aggiungere che, per standard, all'atto della fotografia della posizione, essa contiene il valore della casa di cattura dovuta allo spostamento di due passi di un pedone, anche se non esiste nessun pedone avversario che possa usufruire dell'enpassant. 
5. Semi-mosse: Numero per la regola delle 50 mosse.
6. Mosse totali: Numero di mosse della partita.
Esempi FEN:
• Posizione iniziale: rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1.
• Dopo 1.e4 c5 2.Ch8f3: 
rnbqkbnr/pp1ppppp/8/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R b KQkq - 1 2.

#**La rot nottation**
Il nome rotn discende dal nome dell'autore del programma di scacchi su questo sito (Rosario Turco. In particolare per il programma scacchi vedi pagina di download sezione grafica.) 
Essa è costituita dai campi descritti di seguito nella tabella.

|campo da scrivere|posizione |significato| 
|---:|---:|---:| 
|T:|1|campo descrittivo della posizione|
|V:|2|Punto di vista da cui guardare la partita|
|B:|3|elenco separato da ; delle posizioni dei pezzi bianchi in italiano|
|N:|4|elenco separato da ; delle posizioni dei pezzi neri italiano| 
|U:|5 opzionale|elenco delle case dei pedoni 
|M:|6 |turno di mossa : B o N
|P:|7 |numero di mossa ricavato dalla fen diminuito di 1

L'utilità del campo U: nasce dall'esigenza che, alla ripresa della partita, viene segnalato al cieco la possibilità dell'enpassant.
Sul campo U:, inoltre, occorre una precisazione, meglio fare due esempi.
Se ci sono due pedoni neri nelle case b4 e d4 e il bianco muove c4, allora entrambi i pedoni neri potrebbero usufruire dell'enpassant, per cui:
U:b4d4c4;
Sono elencate prima le case dei pedoni che possono fare la cattura e, poi, la casa del pedone da catturare per enpassant
Se ci fosse un pedone bianco in h5 e il nero giocasse g5 allora
U:h5g5;

#**Come tradurre una fen in rotn?**
Se avete una fen position, per ottenere il file del problema, potreste scaricare fenpos.exe. Vedi download sezione a linea di comando. 
Per lo usage consultare il programma stesso lanciandolo.Usage
Nel file problem<num>.txt otterrrete il risultato. 

#**Come usare la rotn ottenuta?** Ad esempio scrivendola in un file per caricarlo col nostro programma scacchi e risolvere il problema da soli o con l'aiuto del computer.


#**Problems Collection**
Segue ora l'elenco dei problemi della presente collezione.
Non sbirciate la soluzione!

1. r1bqkb1r/pppp1ppp/2n2n2/4p3/2B1P3/5N2/PPPP1PPP/RNBQK2R w KQkq - 4 4
Problema: Matto in 2 mosse. Bianco muove. Soluzione: 1.Bxf7+ Ke7 (o Kh8) 2.Nd5# (o 2.Ng5#). Tratto da partita classica, tema della scoperta.
T:Problema: Matto in 2 mosse. Bianco muove
V:B;
B:Ac4;Pe4;Cf3;Pa2;Pb2;Pc2;Pd2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Th1;
N:Ta8;Ac8;Dd8;Re8;Af8;Th8;Pa7;Pb7;Pc7;Pd7;Pf7;Pg7;Ph7;Cc6;Cf6;Pe5
M:B;
P:3;

2. r1bqkbnr/pppp1ppp/2n5/4p3/4P3/5N2/PPPP1PPP/RNBQKB1R w KQkq - 2 4
Problema: Matto in 2 mosse. Bianco muove. Soluzione: 1.Nxe5 d6 2.Nf7#. Problema compositivo anonimo, XIX secolo.
T:Problema: Matto in 2 mosse. Bianco muove
V:B;
B:Pe4;Cf3;Pa2;Pb2;Pc2;Pd2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Af1;Th1;
N:Ta8;Ac8;Dd8;Re8;Af8;Cg8;Th8;Pa7;Pb7;Pc7;Pd7;Pf7;Pg7;Ph7;Cc6;Pe5
M:B;
P:3;

3. rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq - 0 1
Problema: Matto in 3 mosse. Nero muove. Soluzione: 1...e5 2.d4 exd4 3.Qxd4 e poi matto. Studio di posizione, problema didattico.
T:Problema: Matto in 3 mosse. Nero muove
V:N;
B:Ta8;Cb8;Ac8;Dd8;Re8;Af8;Cg8;Th8;
N:
M:N;
P:0;

4. 6k1/5ppp/8/8/8/8/5PPP/6K1 w - - 0 1
Problema: Matto in 2 mosse. Bianco muove. Soluzione: 1.h4 h6 2.h5#. Problema semplice, tema della forza bruta.
T:Problema: Matto in 2 mosse. Bianco muove. 
V:B;
B:Pf2;Pg2;Ph2;Rg1;
N:Rg8;Pf7;Pg7;Ph7
M:B;
P:0;

5. r1bqkb1r/pppp1ppp/2n2n2/4p3/3PP3/2N2N2/PPP2PPP/R1BQKB1R w KQkq - 0 5
Problema: Matto in 4 mosse. Bianco muove. Tema: attacco coordinato dei pezzi. Studio compositivo anonimo, XX secolo.
T:Problema: Matto in 4 mosse. Bianco muove. 
V:B;
B:Pd4;Pe4;Cc3;Cf3;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Ac1;Dd1;Re1;Af1;Th1;
N:Ta8;Ac8;Dd8;Re8;Af8;Th8;Pa7;Pb7;Pc7;Pd7;Pf7;Pg7;Ph7;Cc6;Cf6;Pe5
M:B;
P:4;

6. rnbqkb1r/pppppppp/5n2/8/3PP3/8/PPP2PPP/RNBQKBNR w KQkq - 1 3
Problema: Matto in 3 mosse. Bianco muove. Soluzione: 1.dxe5 Ng4 2.h3 Nxe5 3.Qxd8#. Estrazione di posizione dal Caro-Kann difesa.
T:Problema: Matto in 3 mosse. Bianco muove. 
V:B:
B:Pd4;Pe4;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Af1;Cg1;Th1;
N:Ta8;Cb8;Ac8;Dd8;Re8;Af8;Th8;Pa7;Pb7;Pc7;Pd7;Pe7;Pf7;Pg7;Ph7;Cf6
M:B;
P:2;

7. 1rbqkb1r/pppp1ppp/2n2n2/4p3/2B1P3/3P1N2/PPP2PPP/RNBQK2R w KQkq - 0 5
Problema: Matto in 2 mosse. Bianco muove. Soluzione: 1.Bxf7+ Nxf7 2.Ng5#. Tema della combinazione tattica.
T:Problema: Matto in 2 mosse. Bianco muove. 
V:B;
B:Ac4;Pe4;Pd3;Cf3;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Th1;
N:Tb8;Ac8;Dd8;Re8;Af8;Th8;Pa7;Pb7;Pc7;Pd7;Pf7;Pg7;Ph7;Cc6;Cf6;Pe5
M:B;
P:4;

8. rnbqkbnr/pppppppp/8/8/3PP3/8/PPP2PPP/RNBQKBNR b KQkq d3 0 2
Problema: Matto in 5 mosse. Nero muove. Studio lungo di posizione iniziale modificata, problema inventato XX secolo.
T:Problema: Matto in 5 mosse. Nero muove. 
V:N;
B:Pd4;Pe4;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Af1;Cg1;Th1;
N:Ta8;Cb8;Ac8;Dd8;Re8;Af8;Cg8;Th8;Pa7;Pb7;Pc7;Pd7;Pe7;Pf7;Pg7;Ph7
M:N;
P:1;

9. 6k1/6pp/8/8/8/8/6PP/6K1 w - - 0 1
Problema: Matto in 2 mosse. Bianco muove. Soluzione: 1.h4 g5 2.h5#. Problema elementare di tecnica.
T:Problema: Matto in 2 mosse. Bianco muove. 
V:B;
B:Pg2;Ph2;Rg1;
N:Rg8;Pg7;Ph7
M:B
P:1;

10. r1bqkb1r/pppp1ppp/2n2n2/4p3/3PP3/2N1BN2/PPP2PPP/R2QKB1R w KQkq - 1 5
Problema: Matto in 4 mosse. Bianco muove. Tema tattico combinativo. Analisi da apertura italiana.
T:Problema: Matto in 4 mosse. Bianco muove. 
V:B;
B:Pd4;Pe4;Cc3;Ae3;Cf3;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Dd1;Re1;Af1;Th1;
N:Ta8;Ac8;Dd8;Re8;Af8;Th8;Pa7;Pb7;Pc7;Pd7;Pf7;Pg7;Ph7;Cc6;Cf6;Pe5
M:B;
P:4;

11. 7k/5ppp/8/8/8/8/5PPP/7K w - - 0 1
Problema: Matto in 2 mosse. Bianco muove. Soluzione: 1.g4 h5 2.g5#. Problema didattico.
T:Matto in due mosse
V:B;
B:Pf2;Pg2;Ph2;Rh1
N:Rh8;Pf7;Pg7;Ph7
M:B;
P:0;

12. rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1
Problema: Matto in 5 mosse. Bianco muove. Tema: sviluppo veloce e attacco coordinato. Esercizio teorico.
T:Matto in 5 mosse
V:B;
B:Pa2;Pb2;Pc2;Pd2;Pe2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Af1;Cg1;Th1
N:Ta8;Cb8;Ac8;Dd8;Re8;Af8;Cg8;Th8;Pa7;Pb7;Pc7;Pd7;Pe7;Pf7;Pg7;Ph7
M:B;
P:0;

13. r1bqkb1r/pppp1ppp/2n2n2/4p3/2B1P3/5N2/PPPP1PPP/RNBQ1RK1 w kq - 3 5
Problema: Matto in 2 mosse. Bianco muove. Soluzione: 1.Bxf7+ Ke7 2.Nd5#. Arrocco bianco anticipato.
T:Matto in due mosse
V:B;
B:Ac4;Pe4;Cf3;Pa2;Pb2;Pc2;Pd2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Tf1;Rg1
N:Ta8;Ac8;Dd8;Re8;Af8;Th8;Pa7;Pb7;Pc7;Pd7;Pf7;Pg7;Ph7;Cc6;Cf6;Pe5
M:B;
P:4;

14. 6k1/5ppp/8/8/8/8/5PPP/R5K w - - 0 1
Problema: Matto in 3 mosse. Bianco muove. Tema della forza bruta con torre. Problema compositivo.
T:Matto in tre mosse
V:B;
B:Pf2;Pg2;Ph2;Ta1;Rg1
N:Rg8;Pf7;Pg7;Ph7
M:B;
P:0;

15. rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1
Problema: Matto in 4 mosse. Nero muove. Studio di apertura con tema tattico.
T:Matto in quattro mosse
V:N;
B:Pe4;Pa2;Pb2;Pc2;Pd2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Af1;Cg1;Th1
N:Ta8;Cb8;Ac8;Dd8;Re8;Af8;Cg8;Th8;Pa7;Pb7;Pc7;Pd7;Pe7;Pf7;Pg7;Ph7
M:N;
P:0;

16. r1bqkbnr/pppp1ppp/2n5/4p3/2B1P3/5N2/PPPP1PPP/RNBQK2R w KQkq - 2 5
Problema: Matto in 2 mosse. Bianco muove. Soluzione tattica con il vescovo. Tratto da Fried Liver Attack.
T:Matto in due mosse
V:B;
B:Ac4;Pe4;Cf3;Pa2;Pb2;Pc2;Pd2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Th1
N:Ta8;Ac8;Dd8;Re8;Af8;Cg8;Th8;Pa7;Pb7;Pc7;Pd7;Pf7;Pg7;Ph7;Cc6;Pe5
M:B;
P:4;

17. 7k/6pp/8/8/8/8/6PP/R5K w - - 0 1
Problema: Matto in 3 mosse. Bianco muove. Tema della torre e spinta di pedone.
T:Matto in tre mosse
V:B;
B:Pg2;Ph2;Ta1;Rg1
N:Rh8;Pg7;Ph7
M:B;
P:0;

18. rnbqkbnr/pppppppp/8/8/3PP3/8/PPP2PPP/RNBQKBNR b KQkq d3 0 2
Problema: Matto in 5 mosse. Nero muove. Studio su posizione centrale. XX secolo.
T:Matto in cinque mosse
V:N;
B:Pd4;Pe4;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Af1;Cg1;Th1
N:Ta8;Cb8;Ac8;Dd8;Re8;Af8;Cg8;Th8;Pa7;Pb7;Pc7;Pd7;Pe7;Pf7;Pg7;Ph7
M:N;
P:1;

19. r1bqkb1r/pppp1ppp/2n2n2/4p3/3PP3/3P1N2/PPP2PPP/RNBQKB1R w KQkq - 0 5
Problema: Matto in 3 mosse. Bianco muove. Tema tattico nei Quattro Cavalli.
T:Matto in tre mosse
V:B;
B:Pd4;Pe4;Pd3;Cf3;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Af1;Th1
N:Ta8;Ac8;Dd8;Re8;Af8;Th8;Pa7;Pb7;Pc7;Pd7;Pf7;Pg7;Ph7;Cc6;Cf6;Pe5
M:B;
P:4;

20. 6k1/5ppp/8/8/8/8/5PPP/6K1 w - - 0 1
Problema: Matto in 2 mosse. Bianco muove. Soluzione minimalista. Problema base.
T:Matto in due mosse
V:B;
B:Pf2;Pg2;Ph2;Rg1
N:Rg8;Pf7;Pg7;Ph7
M:B;
P:0;

21. r1bqkbnr/pppppppp/2n5/8/3PP3/8/PPP2PPP/RNBQKBNR w KQkq - 1 3
Problema: Matto in 3 mosse. Bianco muove. Studio sulla Difesa Caro-Kann.
T:Matto in tre mosse
V:B;
B:Pd4;Pe4;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Af1;Cg1;Th1
N:Ta8;Ac8;Dd8;Re8;Af8;Cg8;Th8;Pa7;Pb7;Pc7;Pd7;Pe7;Pf7;Pg7;Ph7;Cc6
M:B;
P:2;

22. 7k/5ppp/8/8/8/8/5PPP/R5K w - - 0 1
Problema: Matto in 2 mosse. Bianco muove. Soluzione: 1.Ra8# o 1.Rh6#. Problema con torre.
T:Matto in due mosse
V:B;
B:Pf2;Pg2;Ph2;Ta1;Rg1
N:Rh8;Pf7;Pg7;Ph7
M:B;
P:0;

23. rnbqkbnr/pppppppp/8/8/4P3/3P4/PPP2PPP/RNBQKBNR b KQkq - 1 2
Problema: Matto in 4 mosse. Nero muove. Studio su Slava e spinte centrali.
T:Matto in quattro mosse
V:N;
B:Pe4;Pd3;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Af1;Cg1;Th1
N:Ta8;Cb8;Ac8;Dd8;Re8;Af8;Cg8;Th8;Pa7;Pb7;Pc7;Pd7;Pe7;Pf7;Pg7;Ph7
M:N;
P:1;

24. r1bqkb1r/pppp1ppp/2n2n2/4p3/2BPP3/5N2/PPP2PPP/RNBQK2R w KQkq - 1 5
Problema: Matto in 2 mosse. Bianco muove. Tema tattico nel Gioco Italiano.
T:Matto in due mosse
V:B;
B:Ac4;Pd4;Pe4;Cf3;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Th1
N:Ta8;Ac8;Dd8;Re8;Af8;Th8;Pa7;Pb7;Pc7;Pd7;Pf7;Pg7;Ph7;Cc6;Cf6;Pe5
M:B;
P:4;

25. 6k1/6pp/8/8/8/8/6PP/R5K w - - 0 1
Problema: Matto in 3 mosse. Bianco muove. Tema elementare con torre e pedoni.
T:Matto in tre mosse
V:B;
B:Pg2;Ph2;Ta1;Rg1
N:Rg8;Pg7;Ph7
M:B;
P:0;

26. rnbqkbnr/pppppppp/8/8/3PP3/3P4/PPP2PPP/RNBQKBNR b KQkq - 1 2
Problema: Matto in 5 mosse. Nero muove. Studio su aperture di pedone.
T:Matto in cinque mosse
V:N;
B:Pd4;Pe4;Pd3;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Af1;Cg1;Th1
N:Ta8;Cb8;Ac8;Dd8;Re8;Af8;Cg8;Th8;Pa7;Pb7;Pc7;Pd7;Pe7;Pf7;Pg7;Ph7
M:N;
P:1;

27. r1bqkb1r/pppp1ppp/2n2n2/4p3/2BPP3/5N2/PPP2PPP/RNBQK2R b KQkq - 2 5
Problema: Matto in 3 mosse. Nero muove. Tema della controffesa.
T:Matto in tre mosse
V:N;
B:Ac4;Pd4;Pe4;Cf3;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Th1
N:Ta8;Ac8;Dd8;Re8;Af8;Th8;Pa7;Pb7;Pc7;Pd7;Pf7;Pg7;Ph7;Cc6;Cf6;Pe5
M:N;
P:4;

28. 7k/5ppp/8/8/8/8/6PP/R5K w - - 0 1
Problema: Matto in 2 mosse. Bianco muove. Soluzione semplice con torre. Didattico.
T:Matto in due mosse
V:B;
B:Pg2;Ph2;Ta1;Rg1
N:Rh8;Pf7;Pg7;Ph7
M:B;
P:0;

29. rnbqkbnr/pppppppp/8/8/4P3/2P5/PPP2PPP/RNBQKBNR b KQkq - 0 2
Problema: Matto in 4 mosse. Nero muove. Inglese inversata, tema tattico.
T:Matto in quattro mosse
V:N;
B:Pe4;Pc3;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Af1;Cg1;Th1
N:Ta8;Cb8;Ac8;Dd8;Re8;Af8;Cg8;Th8;Pa7;Pb7;Pc7;Pd7;Pe7;Pf7;Pg7;Ph7
M:N;
P:1;

30. r1bqkb1r/pppp1ppp/2n2n2/4p3/3PP3/2N2N2/PPP2PPP/R1BQKB1R b KQkq - 1 5
Problema: Matto in 3 mosse. Nero muove. Tema della scoperta nella posizione centrale.
T:Matto in tre mosse
V:N;
B:Pd4;Pe4;Cc3;Cf3;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Ac1;Dd1;Re1;Af1;Th1
N:Ta8;Ac8;Dd8;Re8;Af8;Th8;Pa7;Pb7;Pc7;Pd7;Pf7;Pg7;Ph7;Cc6;Cf6;Pe5
M:N;
P:4;

31. 6k1/5ppp/8/8/8/2R5/5PPP/6K1 w - - 0 1
Problema: Matto in 2 mosse. Bianco muove. Tema della torre sulla sesta traversa.
T:Matto in due mosse
V:B;
B:Tc3;Pf2;Pg2;Ph2;Rg1
N:Rg8;Pf7;Pg7;Ph7
M:B;
P:0;

32. rnbqkbnr/pppppppp/8/8/3PP3/2P5/PPP2PPP/RNBQKBNR b KQkq - 0 2
Problema: Matto in 5 mosse. Nero muove. Studio di apertura. Invenzione modernista.
T:Matto in cinque mosse
V:N;
B:Pd4;Pe4;Pc3;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Af1;Cg1;Th1
N:Ta8;Cb8;Ac8;Dd8;Re8;Af8;Cg8;Th8;Pa7;Pb7;Pc7;Pd7;Pe7;Pf7;Pg7;Ph7
M:N;
P:1;

33. r1bqkb1r/pppp1ppp/2n2n2/4p3/2BPP3/5N2/PPP2PPP/RNBQK2R b KQkq - 2 5
Problema: Matto in 2 mosse. Nero muove. Tema della tacca difensiva nel Gioco Italiano.
T:Matto in due mosse
V:N;
B:Ac4;Pd4;Pe4;Cf3;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Th1
N:Ta8;Ac8;Dd8;Re8;Af8;Th8;Pa7;Pb7;Pc7;Pd7;Pf7;Pg7;Ph7;Cc6;Cf6;Pe5
M:N;
P:4;

34. 7k/6pp/8/8/8/1R6/6PP/6K1 w - - 0 1
Problema: Matto in 2 mosse. Bianco muove. Posizionamento tattico della torre.
T:Matto in due mossebianco
V:1;
B:
N:
M:1;
P:6;

35. rnbqkbnr/pppppppp/8/8/2P1P3/8/PPP2PPP/RNBQKBNR b KQkq c3 0 2
Problema: Matto in 4 mosse. Nero muove. Tema della lotta centrale. XX secolo.
T:Matto in quattro mosse
V:N;
B:Pc4;Pe4;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Af1;Cg1;Th1
N:Ta8;Cb8;Ac8;Dd8;Re8;Af8;Cg8;Th8;Pa7;Pb7;Pc7;Pd7;Pe7;Pf7;Pg7;Ph7
M:N;
P:1;

36. r1bqkb1r/pppp1ppp/2n2n2/4p3/2PEP3/5N2/PPP2PPP/RNBQK2R w KQkq - 1 5
Problema: Matto in 3 mosse. Bianco muove. Birmingham gambit, tema tattico.
T:Matto in tre mosse
V:B;
B:Pc4;Pd4;Cf3;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Th1
N:Ta8;Ac8;Dd8;Re8;Af8;Th8;Pa7;Pb7;Pc7;Pd7;Pf7;Pg7;Ph7;Cc6;Cf6;Pe5
M:B;
P:4;

37. 7k/5ppp/8/8/8/2B5/5PPP/6K1 w - - 0 1
Problema: Matto in 2 mosse. Bianco muove. Tema del vescovo sulla diagonale lunga.
T:Matto in due mosse
V:B;
B:Ac3;Pf2;Pg2;Ph2;Rg1
N:Rh8;Pf7;Pg7;Ph7
M:B;
P:0;

38. rnbqkbnr/pppppppp/8/8/2P1P3/8/PPP2PPP/RNBQKBNR b KQkq - 1 2
Problema: Matto in 5 mosse. Nero muove. Studio teorico su aperture di avanzata.
T:Matto in cinque mosse
V:N;
B:Pc4;Pe4;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Af1;Cg1;Th1
N:Ta8;Cb8;Ac8;Dd8;Re8;Af8;Cg8;Th8;Pa7;Pb7;Pc7;Pd7;Pe7;Pf7;Pg7;Ph7
M:N;
P:1;

39. r1bqkb1r/pppp1ppp/2n2n2/4p3/2PEP3/5N2/PPP2PPP/RNBQK2R b KQkq - 2 5
Problema: Matto in 3 mosse. Nero muove. Controgiocare nel Gioco Italiano con gambit.
T:Matto in tre mosse
V:N;
B:Pc4;Pd4;Cf3;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Th1
N:Ta8;Ac8;Dd8;Re8;Af8;Th8;Pa7;Pb7;Pc7;Pd7;Pf7;Pg7;Ph7;Cc6;Cf6;Pe5
M:N;
P:4;

40. 6k1/6pp/8/8/8/6B1/5PPP/6K1 w - - 0 1
Problema: Matto in 2 mosse. Bianco muove. Tema minimalista con vescovo.
T:Matto in due mosse
V:B;
B:Ag3;Pf2;Pg2;Ph2;Rg1
N:Rg8;Pg7;Ph7
M:B;
P:0;

41. rnbqkbnr/pppppppp/8/8/1PP1P3/8/PPP2PPP/RNBQKBNR b KQkq b3 0 2
Problema: Matto in 4 mosse. Nero muove. Gioco di gambit su entrambi i lati.
T:Matto in quattro mosse
V:N;
B:Pb4;Pc4;Pe4;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Af1;Cg1;Th1
N:Ta8;Cb8;Ac8;Dd8;Re8;Af8;Cg8;Th8;Pa7;Pb7;Pc7;Pd7;Pe7;Pf7;Pg7;Ph7
M:N;
P:1;

42. r1bqkb1r/pppp1ppp/2n2n2/4p3/1PPep3/5N2/PPP2PPP/RNBQKB1R w KQkq e3 0 6
Problema: Matto in 2 mosse. Bianco muove. Tema tattico complesso nel gambit.
T:Matto in due mosse
V:B;
B:Pb4;Pc4;Cf3;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Af1;Th1
N:Ta8;Ac8;Dd8;Re8;Af8;Th8;Pa7;Pb7;Pc7;Pd7;Pf7;Pg7;Ph7;Cc6;Cf6;Pe5;Pd4
M:B;
P:5;

43. 7k/6pp/8/8/8/5N2/5PPP/6K1 w - - 0 1
Problema: Matto in 3 mosse. Bianco muove. Tema del cavallo sulla settima traversa.
T:Matto in tre mosse
V:B;
B:Cf3;Pf2;Pg2;Ph2;Rg1
N:Rh8;Pg7;Ph7
M:B;
P:0;

44. rnbqkbnr/pppppppp/8/8/1PP1P3/8/PPP2PPP/RNBQKBNR b KQkq - 1 2
Problema: Matto in 5 mosse. Nero muove. Studio di posizione sui gambit doppi.
T:Matto in cinque mosse
V:N;
B:Pb4;Pc4;Pe4;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Af1;Cg1;Th1
N:Ta8;Cb8;Ac8;Dd8;Re8;Af8;Cg8;Th8;Pa7;Pb7;Pc7;Pd7;Pe7;Pf7;Pg7;Ph7
M:N;
P:1;

45. r1bqkb1r/pppp1ppp/2n2n2/4p3/1PPEP3/5N2/PPP2PPP/RNBQKB1R b KQkq - 1 6
Problema: Matto in 3 mosse. Nero muove. Controspinta nel gambit di donna.
T:Matto in tre mosse
V:N;
B:Pb4;Pc4;Pd4;Cf3;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Af1;Th1
N:Ta8;Ac8;Dd8;Re8;Af8;Th8;Pa7;Pb7;Pc7;Pd7;Pf7;Pg7;Ph7;Cc6;Cf6;Pe5
M:N;
P:5;

46. 6k1/6pp/8/8/8/3N4/5PPP/6K1 w - - 0 1
Problema: Matto in 2 mosse. Bianco muove. Cavallo centralizzato e minaccia.
T:Matto in due mosse
V:B;
B:Cd3;Pf2;Pg2;Ph2;Rg1
N:Rg8;Pg7;Ph7
M:B;
P:1;

enpassant
47. rnbqkbnr/pppppppp/8/8/1PPep3/5N2/PPP2PPP/RNBQKB1R w KQkq e3 0 3
Problema: Matto in 4 mosse. Bianco muove. Tema tattico nel gambit di donna accettato.
T:Matto in quattro mosse
V:B;
B:Pb4;Pc4;Cf3;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Af1;Th1
N:Ta8;Cb8;Ac8;Dd8;Re8;Af8;Cg8;Th8;Pa7;Pb7;Pc7;Pd7;Pe7;Pf7;Pg7;Ph7;Pd4
M:B;
P:2;

48. r1bqkb1r/pppp1ppp/2n2n2/4p3/1PPEP3/5N2/PPP2PPP/RNBQKB1R w KQkq - 2 6
Problema: Matto in 2 mosse. Bianco muove. Scoperta tattica nel gambit di donna.
T:Matto in due mosse
V:B;
B:Cd3;Pf2;Pg2;Ph2;Rg1
N:Rg8;Pg7;Ph7
M:B;
P:1;

49. 7k/6pp/8/8/8/4Q3/5PPP/6K1 w - - 0 1
Problema: Matto in 2 mosse. Bianco muove. Tema della regina attiva su tavola aperta. Compositivo anonimo.
T:Matto in due mosse
V:B;
B:Cd3;Pf2;Pg2;Ph2;Rg1
N:Rg8;Pg7;Ph7
M:B;
P:0;

enpassant
50. rnbqkbnr/pppppppp/8/8/1CPep3/5N2/PPP2PPP/RNBQKB1R w KQkq e3 0 3
Problema: Matto in 5 mosse. Bianco muove. Estensione tattica dal gambit di donna. XX secolo, studi moderni.
T:Matto in cinque mosse
V:B;
B:Pb4;Cf3;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Af1;Th1
N:Ta8;Cb8;Ac8;Dd8;Re8;Af8;Cg8;Th8;Pa7;Pb7;Pc7;Pd7;Pe7;Pf7;Pg7;Ph7;Pc4
M:B;
P:2;

51. 6k1/5ppp/8/8/8/4B3/5PPP/6K1 w - - 0 1
Problema: Matto in 2 mosse. Bianco muove. Tema del vescovo e spinta di pedone.
T:Matto in due mosse
V:B;
B:Cd3;Pf2;Pg2;Ph2;Rg1
N:Rg8;Pg7;Ph7
M:B;
P:0;

52. rnbqkbnr/pppppppp/8/8/1CPep3/3P1N2/PPP2PPP/RNBQKB1R b KQkq - 0 4
Problema: Matto in 4 mosse. Nero muove. Studio su sviluppo e centro nel gambit.
T:Matto in quattro mosse
V:N;
B:Pb4;Pd3;Cf3;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Af1;Th1
N:Ta8;Cb8;Ac8;Dd8;Re8;Af8;Cg8;Th8;Pa7;Pb7;Pc7;Pd7;Pe7;Pf7;Pg7;Ph7;Pc4
M:N;
P:3;

53. r1bqkb1r/pppp1ppp/2n2n2/4p3/1PPEP3/3P1N2/PPP2PPP/RNBQKB1R b KQkq - 0 6
Problema: Matto in 3 mosse. Nero muove. Tema della contrattacco nel sistema di donna.
T:Matto in tre mosse
V:N;
B:Pb4;Pc4;Pd4;Pd3;Cf3;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Af1;Th1
N:Ta8;Ac8;Dd8;Re8;Af8;Th8;Pa7;Pb7;Pc7;Pd7;Pf7;Pg7;Ph7;Cc6;Cf6;Pe5
M:N;
P:5;

54. 7k/6pp/8/8/8/5Q2/5PPP/6K1 w - - 0 1
Problema: Matto in 2 mosse. Bianco muove. Regina attiva su diagonale.
T:Matto in due mosse
V:B;
B:Df3;Pf2;Pg2;Ph2;Rg1
N:Rh8;Pg7;Ph7
M:B;
P:0;

55. rnbqkbnr/pppppppp/8/8/2P1P3/3P1N2/PPP2PPP/RNBQKB1R b KQkq - 0 3
Problema: Matto in 5 mosse. Nero muove. Studio di apertura su spinte centrali triple.
T:Matto in cinque mosse
V:N;
B:Pc4;Pe4;Pd3;Cf3;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Af1;Th1
N:Ta8;Cb8;Ac8;Dd8;Re8;Af8;Cg8;Th8;Pa7;Pb7;Pc7;Pd7;Pe7;Pf7;Pg7;Ph7
M:N;
P:2;

56. r1bqkb1r/pppp1ppp/2n2n2/4p3/2PEP3/3P1N2/PPP2PPP/RNBQKB1R w KQkq - 1 6
Problema: Matto in 2 mosse. Bianco muove. Tema tattico su casa debole.
T:Matto in due mosse
V:B;
B:Pc4;Pd4;Pd3;Cf3;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Af1;Th1
N:Ta8;Ac8;Dd8;Re8;Af8;Th8;Pa7;Pb7;Pc7;Pd7;Pf7;Pg7;Ph7;Cc6;Cf6;Pe5
M:B;
P:5;

57. 6k1/5ppp/8/8/8/3Q4/5PPP/6K1 w - - 0 1
Problema: Matto in 3 mosse. Bianco muove. Regina e pedone coordinati.
T:Matto in tre mosse
V:B;
B:Dd3;Pf2;Pg2;Ph2;Rg1
N:Rg8;Pf7;Pg7;Ph7
M:B;
P:0;

58. rnbqkbnr/pppppppp/8/8/2P1P3/3P4/PPP2PPP/RNBQKBNR b KQkq - 0 2
Problema: Matto in 4 mosse. Nero muove. Studio teorico su aperture di spinta.
T:Matto in quattro mosse
V:N;
B:Pc4;Pe4;Pd3;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Af1;Cg1;Th1
N:Ta8;Cb8;Ac8;Dd8;Re8;Af8;Cg8;Th8;Pa7;Pb7;Pc7;Pd7;Pe7;Pf7;Pg7;Ph7
M:N;
P:1;

59. r1bqkb1r/pppp1ppp/2n2n2/4p3/2PEP3/3P4/PPP2PPP/RNBQKB1R b KQkq - 1 5
Problema: Matto in 2 mosse. Nero muove. Tema della fuga e contrattacco.
T:Matto in due mosse
V:N;
B:Pc4;Pd4;Pd3;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Af1;Th1
N:Ta8;Ac8;Dd8;Re8;Af8;Th8;Pa7;Pb7;Pc7;Pd7;Pf7;Pg7;Ph7;Cc6;Cf6;Pe5
M:N;
P:4;

60. 7k/6pp/8/8/8/2Q5/5PPP/6K1 w - - 0 1
Problema: Matto in 2 mosse. Bianco muove. Regina centralizzata.
T:Matto in due mosse
V:B;
B:Dc3;Pf2;Pg2;Ph2;Rg1
N:Rh8;Pg7;Ph7
M:B;
P:0;

61. rnbqkbnr/pppppppp/8/8/3PP3/3P4/PPP2PPP/RNBQKBNR b KQkq - 0 3
Problema: Matto in 5 mosse. Nero muove. Studio su aperture di pedone doppio centrale.
T:Matto in cinque mosse
V:N;
B:Pd4;Pe4;Pd3;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Af1;Cg1;Th1
N:Ta8;Cb8;Ac8;Dd8;Re8;Af8;Cg8;Th8;Pa7;Pb7;Pc7;Pd7;Pe7;Pf7;Pg7;Ph7
M:N;
P:2;

62. r1bqkb1r/pppp1ppp/2n2n2/4p3/3PP3/3P1N2/PPP2PPP/RNBQKB1R w KQkq - 1 5
Problema: Matto in 3 mosse. Bianco muove. Tema nei Quattro Cavalli con spinta centrale.
T:Matto in tre mosse
V:B;
B:Pd4;Pe4;Pd3;Cf3;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Af1;Th1
N:Ta8;Ac8;Dd8;Re8;Af8;Th8;Pa7;Pb7;Pc7;Pd7;Pf7;Pg7;Ph7;Cc6;Cf6;Pe5
M:B;
P:4;

63. 6k1/6pp/8/8/8/1Q6/5PPP/6K1 w - - 0 1
Problema: Matto in 2 mosse. Bianco muove. Regina laterale e pedone.
T:matto in due mosse
V:B;
B:Db3;Pf2;Pg2;Ph2;Rg1
N:Rg8;Pg7;Ph7
M:B;
P:0;

64. rnbqkbnr/pppppppp/8/8/4P3/3P4/PPP2PPP/RNBQKBNR b KQkq - 1 3
Problema: Matto in 4 mosse. Nero muove. Studio su difesa Scandinavica.
T:Matto in quattro mosse
V:N;
B:
N:
M:N;
P:2;

65. r1bqkb1r/pppp1ppp/2n2n2/4p3/3PP3/3P4/PPP2PPP/RNBQKB1R b KQkq - 1 5
Problema: Matto in 2 mosse. Nero muove. Tema della scoperta difensiva.
T:Matto in due mosse
V:N;
B:Pd4;Pe4;Pd3;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Af1;Th1
N:Ta8;Ac8;Dd8;Re8;Af8;Th8;Pa7;Pb7;Pc7;Pd7;Pf7;Pg7;Ph7;Cc6;Cf6;Pe5
M:N;
P:4;

66. 7k/6pp/8/8/8/6Q1/5PPP/6K1 w - - 0 1
Problema: Matto in 3 mosse. Bianco muove. Regina sul fianco e pedone.
T:Matto in tre mosse
V:B;
B:Dg3;Pf2;Pg2;Ph2;Rg1
N:Rh8;Pg7;Ph7
M:B;
P:0;

67. rnbqkbnr/pppppppp/8/8/4P3/3P1N2/PPP2PPP/RNBQKB1R b KQkq - 0 4
Problema: Matto in 5 mosse. Nero muove. Studio sullo sviluppo nel sistema principali.
T:Matto in cinque mosse
V:N;
B:Pe4;Pd3;Cf3;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Af1;Th1
N:Ta8;Cb8;Ac8;Dd8;Re8;Af8;Cg8;Th8;Pa7;Pb7;Pc7;Pd7;Pe7;Pf7;Pg7;Ph7
M:N;
P:3;

68. r1bqkb1r/pppp1ppp/2n2n2/4p3/3PP3/3PBN2/PPP2PPP/RNBQK2R w KQkq - 2 5
Problema: Matto in 2 mosse. Bianco muove. Tema del vescovo e cavallo coordinati.
T:Matto in due mosse
V:B;
B:Pd4;Pe4;Pd3;Ae3;Cf3;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Th1
N:Ta8;Ac8;Dd8;Re8;Af8;Th8;Pa7;Pb7;Pc7;Pd7;Pf7;Pg7;Ph7;Cc6;Cf6;Pe5
M:B;
P:4;

69. 6k1/6pp/8/8/8/Q7/5PPP/6K1 w - - 0 1
Problema: Matto in 2 mosse. Bianco muove. Regina all'angolo.
T:Matto in due mosse
V:B;
B:Da3;Pf2;Pg2;Ph2;Rg1
N:Rg8;Pg7;Ph7
M:B;
P:0;

70. rnbqkbnr/pppppppp/8/8/3PP3/3P1N2/PPP2PPP/RNBQKB1R b KQkq - 0 5
Problema: Matto in 4 mosse. Nero muove. Studio su posizione centrale modificata.
T:Matto in quattro mosse
V:N;
B:Pd4;Pe4;Pd3;Cf3;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Af1;Th1
N:Ta8;Cb8;Ac8;Dd8;Re8;Af8;Cg8;Th8;Pa7;Pb7;Pc7;Pd7;Pe7;Pf7;Pg7;Ph7
M:N;
P:4;

71. r1bqkb1r/pppp1ppp/2n2n2/4p3/3PP3/3PBNN2/PPP2PPP/RNBQK2R w KQkq - 1 6
Problema: Matto in 3 mosse. Bianco muove. Tema della pressione su f7.
T:Matto in tre mosse
V:B;
B:Pd4;Pe4;Pd3;Ae3;Cf3;Cg3;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Th1
N:Ta8;Ac8;Dd8;Re8;Af8;Th8;Pa7;Pb7;Pc7;Pd7;Pf7;Pg7;Ph7;Cc6;Cf6;Pe5
M:B;
P:5;

72. 7k/6pp/8/8/8/7Q/5PPP/6K1 w - - 0 1
Problema: Matto in 2 mosse. Bianco muove. Regina in angolo remoto.
T:Matto in due mosse
V:B;
B:Dh3;Pf2;Pg2;Ph2;Rg1
N:Rh8;Pg7;Ph7
M:B;
P:0;

73. rnbqkbnr/pppppppp/8/8/3PP3/3P4/PPP2PPP/RNBQKBNR b KQkq - 0 4
Problema: Matto in 4 mosse. Nero muove. Studio teorico su doppia spinta centrale.
T:Matto in quattro mosse
V:N;
B:Pd4;Pe4;Pd3;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Af1;Cg1;Th1
N:Ta8;Cb8;Ac8;Dd8;Re8;Af8;Cg8;Th8;Pa7;Pb7;Pc7;Pd7;Pe7;Pf7;Pg7;Ph7
M:N;
P:3;

74. r1bqkb1r/pppp1ppp/2n2n2/4p3/3PP3/2NPBN2/PPP2PPP/RNBQK2R b KQkq - 1 5
Problema: Matto in 2 mosse. Nero muove. Tema della fuga verticale.
T:Matto in due mosse
V:N;
B:Pd4;Pe4;Cc3;Pd3;Ae3;Cf3;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Th1
N:Ta8;Ac8;Dd8;Re8;Af8;Th8;Pa7;Pb7;Pc7;Pd7;Pf7;Pg7;Ph7;Cc6;Cf6;Pe5
M:N;
P:4;

75. 6k1/6pp/8/8/8/1R6/5PPP/6K1 w - - 0 1
Problema: Matto in 3 mosse. Bianco muove. Torre centralizzata e pedone.
T:Matto in tre mosse
V:B;
B:Tb3;Pf2;Pg2;Ph2;Rg1
N:Rg8;Pg7;Ph7
M:B;
P:0;

enpassant?
76. rnbqkbnr/pppppppp/8/8/2PPP3/8/PPP2PPP/RNBQKBNR b KQkq c3 0 2
Problema: Matto in 5 mosse. Nero muove. Studio su gambit triplo.
T:Matto in cinque mosse
V:N;
B:Pc4;Pd4;Pe4;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Af1;Cg1;Th1
N:Ta8;Cb8;Ac8;Dd8;Re8;Af8;Cg8;Th8;Pa7;Pb7;Pc7;Pd7;Pe7;Pf7;Pg7;Ph7
M:N;
P:1;

77. r1bqkb1r/pppp1ppp/2n2n2/4p3/2PPP3/5N2/PPP2PPP/RNBQKB1R w KQkq - 1 5
Problema: Matto in 3 mosse. Bianco muove. Tema tattico sul centro occupato.
T:Matto in tre mosse
V:B;
B:Pc4;Pd4;Pe4;Cf3;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Af1;Th1
N:Ta8;Ac8;Dd8;Re8;Af8;Th8;Pa7;Pb7;Pc7;Pd7;Pf7;Pg7;Ph7;Cc6;Cf6;Pe5
M:B;
P:4;

78. 7k/6pp/8/8/8/2R5/5PPP/6K1 w - - 0 1
Problema: Matto in 2 mosse. Bianco muove. Torre centralizzata.
T:Matto in due mosse
V:B;
B:Tc3;Pf2;Pg2;Ph2;Rg1
N:Rh8;Pg7;Ph7
M:B;
P:0;

79. rnbqkbnr/pppppppp/8/8/2PPP3/8/PPP2PPP/RNBQKBNR b KQkq - 0 3
Problema: Matto in 4 mosse. Nero muove. Studio su controspinta centrale.
T:Matto in quattro mosse
V:N;
B:Pc4;Pd4;Pe4;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Af1;Cg1;Th1
N:Ta8;Cb8;Ac8;Dd8;Re8;Af8;Cg8;Th8;Pa7;Pb7;Pc7;Pd7;Pe7;Pf7;Pg7;Ph7
M:N;
P:2;

80. r1bqkb1r/pppp1ppp/2n2n2/4p3/2PPP3/3P1N2/PPP2PPP/RNBQKB1R b KQkq - 0 6
Problema: Matto in 2 mosse. Nero muove. Tema della controffesa nel gambit.
T:Matto in due mosse
V:N;
B:Pc4;Pd4;Pe4;Pd3;Cf3;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Af1;Th1
N:Ta8;Ac8;Dd8;Re8;Af8;Th8;Pa7;Pb7;Pc7;Pd7;Pf7;Pg7;Ph7;Cc6;Cf6;Pe5
M:N;
P:5;

81. 6k1/6pp/8/8/8/1B6/5PPP/6K1 w - - 0 1
Problema: Matto in 3 mosse. Bianco muove. Vescovo e pedone.
T:Matto in tre mosse
V:B;
B:Ab3;Pf2;Pg2;Ph2;Rg1
N:Rg8;Pg7;Ph7
M:B;
P:0;

82. rnbqkbnr/pppppppp/8/8/2PPP3/2P5/PPP2PPP/RNBQKBNR b KQkq - 0 2
Problema: Matto in 4 mosse. Nero muove. Studio teorico su gambit multipli.
T:Matto in quattro mosse
V:N;
B:Pc4;Pd4;Pe4;Pc3;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Af1;Cg1;Th1
N:Ta8;Cb8;Ac8;Dd8;Re8;Af8;Cg8;Th8;Pa7;Pb7;Pc7;Pd7;Pe7;Pf7;Pg7;Ph7
M:N;
P:1;

83. r1bqkb1r/pppp1ppp/2n2n2/4p3/2PPP3/2PP1N2/PPP2PPP/RNBQKB1R w KQkq - 1 6
Problema: Matto in 3 mosse. Bianco muove. Tema del blocco e pressione.
T:Matto in tre mosse
V:B;
B:Pc4;Pd4;Pe4;Pc3;Pd3;Cf3;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Af1;Th1
N:Ta8;Ac8;Dd8;Re8;Af8;Th8;Pa7;Pb7;Pc7;Pd7;Pf7;Pg7;Ph7;Cc6;Cf6;Pe5
M:B;
P:5;

84. 7k/6pp/8/8/8/3B4/5PPP/6K1 w - - 0 1
Problema: Matto in 2 mosse. Bianco muove. Vescovo centralizzato.
T:Matto in due mosse
V:B;
B:Ad3;Pf2;Pg2;Ph2;Rg1
N:Rh8;Pg7;Ph7
M:B;
P:0;

85. rnbqkbnr/pppppppp/8/8/2PPP3/2P4/PPP2PPP/RNBQKBNR b KQkq - 0 3
Problema: Matto in 5 mosse. Nero muove. Studio su aperture di pedone triple compresse.
T:Matto in cinque mosse
V:N;
B:Pc4;Pd4;Pe4;Pc3;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Af1;Cg1;Th1
N:Ta8;Cb8;Ac8;Dd8;Re8;Af8;Cg8;Th8;Pa7;Pb7;Pc7;Pd7;Pe7;Pf7;Pg7;Ph7
M:N;
P:2;


86. r1bqkb1r/pppp1ppp/2n2n2/4p3/2PPP3/2PP1N2/PPP2PPP/RNBQKB1R b KQkq - 2 6
Problema: Matto in 2 mosse. Nero muove. Tema della fuga orizzontale.
T:Matto in due mosse
V:N;
B:Pc4;Pd4;Pe4;Pc3;Pd3;Cf3;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Af1;Th1
N:Ta8;Ac8;Dd8;Re8;Af8;Th8;Pa7;Pb7;Pc7;Pd7;Pf7;Pg7;Ph7;Cc6;Cf6;Pe5
M:N;
P:5;

87. 6k1/6pp/8/8/8/4B3/5PPP/6K1 w - - 0 1
Problema: Matto in 3 mosse. Bianco muove. Vescovo e spinta coordinata.
T:Matto in tre mosse
V:B;
B:Ae3;Pf2;Pg2;Ph2;Rg1
N:Rg8;Pg7;Ph7
M:B;
P:0;

enpassant
88. rnbqkbnr/pppppppp/8/8/1PPeP3/8/PPP2PPP/RNBQKBNR w KQkq e3 0 2
Problema: Matto in 4 mosse. Bianco muove. Studio su gambit di donna accettato anticipato.
T:Matto in quattro mosse
V:B;
B:Pb4;Pc4;Pd4;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Af1;Cg1;Th1
N:Ta8;Cb8;Ac8;Dd8;Re8;Af8;Cg8;Th8;Pa7;Pb7;Pc7;Pd7;Pe7;Pf7;Pg7;Ph7
M:B;
P:1;

89. r1bqkb1r/pppp1ppp/2n2n2/4p3/1PPEP3/2PP1N2/PPP2PPP/RNBQKB1R w KQkq - 0 7
Problema: Matto in 3 mosse. Bianco muove. Tema del sacrificio posizionale.
T:Matto in tre mosse
V:B;
B:Pb4;Pc4;Pd4;Pc3;Pd3;Cf3;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Af1;Th1
N:Ta8;Ac8;Dd8;Re8;Af8;Th8;Pa7;Pb7;Pc7;Pd7;Pf7;Pg7;Ph7;Cc6;Cf6;Pe5
M:B;
P:6;

90. 7k/6pp/8/8/8/5B2/5PPP/6K1 w - - 0 1
Problema: Matto in 2 mosse. Bianco muove. Vescovo su diagonale lunga.
T:Matto in due mosse
V:B;
B:Af3;Pf2;Pg2;Ph2;Rg1
N:Rh8;Pg7;Ph7
M:B;
P:0;

91. rnbqkbnr/pppppppp/8/8/1PPeP3/3P1N2/PPP2PPP/RNBQKB1R b KQkq - 0 3
Problema: Matto in 5 mosse. Nero muove. Studio su sistema del gambit con centro bloccato.
T:Matto in cinque mosse
V:N;
B:Pb4;Pc4;Pd4;Pd3;Cf3;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Af1;Th1
N:Ta8;Cb8;Ac8;Dd8;Re8;Af8;Cg8;Th8;Pa7;Pb7;Pc7;Pd7;Pe7;Pf7;Pg7;Ph7
M:N;
P:2;

92. r1bqkb1r/pppp1ppp/2n2n2/4p3/1PPEP3/2PP4/PPP2PPP/RNBQKBNR b KQkq - 0 8
Problema: Matto in 2 mosse. Nero muove. Tema del cavallo e controspinta.
T:Matto in due mosse
V:N;
B:Pb4;Pc4;Pd4;Pc3;Pd3;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Af1;Cg1;Th1
N:Ta8;Ac8;Dd8;Re8;Af8;Th8;Pa7;Pb7;Pc7;Pd7;Pf7;Pg7;Ph7;Cc6;Cf6;Pe5
M:N;
P:7;

93. 6k1/6pp/8/8/8/6B1/5PPP/6K1 w - - 0 1
Problema: Matto in 3 mosse. Bianco muove. Vescovo e pedone finale.
T:Matto in tre mosse
V:B;
B:Ag3;Pf2;Pg2;Ph2;Rg1
N:Rg8;Pg7;Ph7
M:B;
P:0;

enpassant
94. rnbqkbnr/pppppppp/8/8/1PPeP3/3P4/PPP2PPP/RNBQKBNR w KQkq e3 0 3
Problema: Matto in 4 mosse. Bianco muove. Studio su gambit d'avanzo centrale.
T:Matto in quattro mosse
V:B;
B:Pb4;Pc4;Pd4;Pd3;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Af1;Cg1;Th1
N:Ta8;Cb8;Ac8;Dd8;Re8;Af8;Cg8;Th8;Pa7;Pb7;Pc7;Pd7;Pe7;Pf7;Pg7;Ph7
M:B;
P:2;

95. r1bqkb1r/pppp1ppp/2n2n2/4p3/1PPEP3/2PP1N2/PPP2PPP/RNBQKB1R b KQkq - 1 7
Problema: Matto in 3 mosse. Nero muove. Tema della controspinta nel centro bloccato.
T:Matto in tre mosse
V:N;
B:Pb4;Pc4;Pd4;Pc3;Pd3;Cf3;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Af1;Th1
N:Ta8;Ac8;Dd8;Re8;Af8;Th8;Pa7;Pb7;Pc7;Pd7;Pf7;Pg7;Ph7;Cc6;Cf6;Pe5
M:N;
P:6;

96. 7k/6pp/8/8/8/1B6/5PPP/6K1 w - - 0 1
Problema: Matto in 2 mosse. Bianco muove. Vescovo su casa laterale.
T:Matto in due mosse
V:B;
B:Ab3;Pf2;Pg2;Ph2;Rg1
N:Rh8;Pg7;Ph7
M:B;
P:0;

97. rnbqkbnr/pppppppp/8/8/1CPeP3/3P1N2/PPP2PPP/RNBQKB1R b KQkq - 1 3
Problema: Matto in 4 mosse. Nero muove. Studio su gambit con sviluppo accelerato.
T:Matto in quattro mosse
V:N;
B:Pb4;Pc4;Pd3;Cf3;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Af1;Th1
N:Ta8;Cb8;Ac8;Dd8;Re8;Af8;Cg8;Th8;Pa7;Pb7;Pc7;Pd7;Pe7;Pf7;Pg7;Ph7
M:N;
P:2;

98. r1bqkb1r/pppp1ppp/2n2n2/4p3/1CPPEP3/5N2/PPP2PPP/RNBQK2R w KQkq - 0 8
Problema: Matto in 2 mosse. Bianco muove. Tema del sacrificio del vescovo.
T:Matto in due mosse
V:B;
B:Pb4;Pc4;Pd4;Cf3;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Th1
N:Ta8;Ac8;Dd8;Re8;Af8;Th8;Pa7;Pb7;Pc7;Pd7;Pf7;Pg7;Ph7;Cc6;Cf6;Pe5
M:B;
P:7;

99. 6k1/6pp/8/8/8/2B5/5PPP/6K1 w - - 0 1
Problema: Matto in 3 mosse. Bianco muove. Tema minimalista del vescovo centrale.
T:Matto in tre mosse
V:B;
B:Ac3;Pf2;Pg2;Ph2;Rg1
N:Rg8;Pg7;Ph7
M:B;
P:0;
enpassant
100. rnbqkbnr/pppppppp/8/8/1CPeP3/3P4/PPP2PPP/RNBQKBNR w KQkq e3 0 3
Problema: Matto in 5 mosse. Bianco muove. Studio conclusivo su aperture di gambit multiple complesse. XX-XXI secolo.

T:Matto in cinque mosse
V:B;
B:Pb4;Pc4;Pd3;Pa2;Pb2;Pc2;Pf2;Pg2;Ph2;Ta1;Cb1;Ac1;Dd1;Re1;Af1;Cg1;Th1
N:Ta8;Cb8;Ac8;Dd8;Re8;Af8;Cg8;Th8;Pa7;Pb7;Pc7;Pd7;Pe7;Pf7;Pg7;Ph7
M:B;
P:2;
