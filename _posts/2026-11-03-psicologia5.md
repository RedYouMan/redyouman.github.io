---
layout: post
title: "La bellezza di una ROTN ben scritta: estetica ed etica della Nuova Visione"
description: "Perché l'accessibilità vera è bella. Heidegger, Floridi e l'etica hacker open source spiegati con una riga di ROTN."
keywords: "estetica accessibilità, etica open source scacchi, ROTN bellezza, filosofia tecnologia, Nuova Visione, Heidegger, Floridi"
categories: blog
---

# La bellezza di una ROTN ben scritta: estetica ed etica della Nuova Visione

di Rosario Turco

### Se è accessibile ma è brutto, non è accessibile. È carità.

> Abbiamo confuso l'accessibilità con la bruttezza tollerata. I software per non vedenti sono funzionali ma inguardabili. E quando sono brutti da ascoltare con NVDA, sono inaccessibili due volte.

### 1. Estetica: una ROTN è bella

Prendete questa parte di ROTN:

`Bianchi: Re g1, Donna e2, Torri a1 f1, Cavalli c3 f3, Alfieri c1 g2, pedoni a2 b2 c2 d4 e5 f2 g3 h2 | Neri: Re g8...`

Una ROTN vi ricordo che potete scriverla mettendo prima i pezzi di maggiore importanza e, infine, i pedoni.

Sia Il file scritto in questo modo , sia se sulla scacchiera fate Ctrl+D per leggere la posizione dello schieramento avversario (ma anche il proprio),la posizione la potrete ascoltare chiaramente con NVDA.

E notate una cosa. Se la ascoltate con NVDA, sia su file, sia con Ctrl+D: ha un ritmo. Ha una metrica. Bianchi prima, Neri poi. Re, Donna, Torri, Alfieri, Cavalli, pedoni. È ordinata.

Ora facciamo un esperimento. Mettete la cuffia e attivate NVDA.
Ora ascoltate la FEN:

`r1bqkb1r/pppp1ppp/2n2n2/4p3/2P5/2N2N2/PP2PPPP/R1BQKB1R w KQkq - 0 4`

NVDA la legge come: "r uno b q k b uno r slash p p p p uno p p p slash..." È rumore. È brutta. È funzionale per Stockfish, è tortura per un umano.

Solo sperimentando si comprende. La FEN è un formato per i motori e viola i principi di interfacciamento umano (HMI).
La FEN, infatti, è unformato che è utile ma "sotto cofano", per interagire con motori come stockfish.
Gli utenti non dovrebbero avere conoscenza di tali formati che sono, invece, competenza degli sviluppatori, il che aggiunge ulteriore carico cognitivo rispetto all'obettivo di giocare a scacchi bene.

Non abbiamo bisogno di guidare un'auto mettendoci nel motore, ma vogliamo stare comodamente sul sedile.

Scacchi-it segue i principi di progettazione della Universal Design (UD) e della Universal Design for Learning (UDL).

Per questo Scacchi-it scala di un livello logico sia fen che pgn,rendendo trasparente il loro uso. L'utilizzo della FEN in incolla-FEN è solo di "transito dati" e non provoca carico della memoria cognitiva del giocatore.

Non è in discussione lo standardFEN o protocollo, è corretto. E' in discussione il livello logico architetturale dove deve essere posizionato per essere il più efficace ed efficiente possibile per l'utilizzo.

Inoltre la teoria estetica ci dice: la bellezza è quando forma e funzione coincidono. La FEN è funzione pura per macchine. La ROTN è forma umana per menti.

Bauhaus lo insegnava nel 1919: la forma segue la funzione, ma la funzione deve essere umana. Se la funzione è "una persona deve ricostruire una posizione in testa", la forma FEN è sbagliata. La forma ROTN è bella perché è giusta per l'udito e la mente.

> Non abbiamo fatto la ROTN solo per essere accessibili. L'abbiamo fatta perché l'accessibilità richiede implicitamente un criterio di bellezza di esposizione delle informazioni e il ritmo giusto per l'udito per aumentare l'intellegibilità e la chiarezza del dato, in modo da aumentare l'attenzione della mente.

Fate un altro esperimento. Mettete un video di una persona molto alterata che vi strilla le sue idee: dopo 5 secondi il vostro cervello stacca l'attenzione e pensa ad altro.

Un software che suona bene con NVDA è più accessibile di uno che rispetta le WCAG ma suona come un modem del 1995.

### 2. Etica: quando l'open source è possibile, è doveroso

Chi vive una disabilità lo sa: ci sono ausili fisici insostituibili. Una barra braille, un display dedicato, un hardware specifico. Sono oggetti complessi, prodotti in piccole serie, con costi di ricerca e materiali. Per fortuna esistono, anche se a pagamento. Senza di loro, per certe tipologie di invalidità, non ci sarebbe autonomia.

L'informatica è più fortunata. Un software, una volta scritto, può essere copiato a costo zero. Non ha bulloni. Ha idee.

E qui nasce la differenza etica.

In campo informatico esistono progetti proprietari, legittimi, che scelgono la via della licenza chiusa. È una scelta di mercato comprensibile. Ma quando quel software è l'unico ponte verso un diritto - come giocare, studiare, competere - la chiusura rischia di diventare rendita.

La Nuova Visione fa un'altra scelta, possibile solo perché siamo in informatica:

- _Open source:_ il codice di Scacchi-it è su GitHub, leggibile, forkabile. Se domani io non ci sono, il progetto non muore.
- _Open data:_ i tuoi esercizi e le tue partite analizzate con CoachGame (result.txt con mossa, FEN, valutazione prima e dopo, best move, giudizio "sbagliata / troppo sbagliata") sono tuoi, esportabili. Non sono chiusi nel mio cloud.
- _Open metric:_ non ti vendo un punteggio segreto. Ti insegno a calcolarlo.

Stallman, 1985: "Free as in freedom, not as in free beer". Non è una questione di gratuità. È una questione di libertà.

Non diciamo che tutto deve essere gratis. Diciamo che dove l'informatica può liberare, deve liberare. E gli scacchi sono uno di quei casi fortunati dove possiamo permettercelo.

Questa è etica, non beneficenza. Ed è l'unica etica che permette una comunità. La rendita crea clienti. L'open source crea compagni.

### 3. Filosofia della tecnologia: da Heidegger a Floridi

Heidegger, 1954, _La questione della tecnica_: la tecnologia non è neutra. O ti svela il mondo (aletheia) o te lo nasconde.

La scacchiera forata nasconde il mondo: ti dice "il mondo degli scacchi è fatto di plastica che devi toccare, e senza quella plastica non esisti".

La ROTN svela il mondo: ti dice "il mondo degli scacchi è fatto di relazioni logiche, e quelle relazioni sono già nella tua testa, da sempre".

Floridi, 2014, _The Fourth Revolution_: viviamo nell'infosfera. La realtà è informazione ben formata. La scacchiera non è legno, è informazione. Se l'informazione è ben formata (ROTN), è più reale del legno.

La NV è una rivoluzione filosofica: spostiamo gli scacchi dall'essere utensile all'essere informazione (testo, relazione).

E quando gli scacchi diventano informazione, chi non vede non è più in difficoltà. È nativo dell'infosfera scacchistica.

### Conclusione: la tombola della Nuova Visione

Ricapitoliamo fin qui un attimo gli articoli finora visti, per proseguire poi con ulteriori approfondimenti:

1.  _Neuroscienze e carico cognitivo:_ come il cervello codifica senza vedere. Legge di Hick, Span di Baddeley, Oblio, Rotazione e la curva di apprendimento. Perché la ROTN abbassa il carico cognitivo (Sweller).
2.  _Epistemologia:_ Kant seduto accanto al non vedente. Lo spazio scacchistico non è visto, è costruito.
3.  _Psicologia dell'autonomia:_ ti restituisco il locus of control (Rotter).
4.  _Psicologia agonistica:_ ti misuro il tilt e la gestione dello stress in partita.
5.  _Psicologia didattica:_ ti do lo scaffolding con CoachFEN (FEN -> mossa migliore) e ROTN, e la verifica con CoachGame (Vygotskij, Bruner, Sweller).
6.  _Sociologia della comunità:_ ti tolgo lo stigma e ti do una comunità di pratica (Goffman, Touraine, Putnam). Niente etichette politiche, solo pratica condivisa.
7.  _Estetica ed etica:_ ti do bellezza e libertà (Bauhaus, Stallman, Heidegger, Floridi) - questo articolo.

Se manca uno, guarda il mio blog https://redyouman.github.iio
Se li hai tutti , fai parte o hai appreso la Nuova Visione.

> Non stiamo facendo un software per non vedenti che gioca a scacchi.
> Stiamo facendo la dimostrazione che gli scacchi, da sempre, erano un gioco che si può pensare senza vederlo, solo che eravamo distratti dal legno.

_Ti manca l'articolo sul collante: non spaventarti, uscirà prossimamente._ È quello che lega neuroscienze, epistemologia, psicologia, didattica, sociologia ed estetica e fa vedere come cooperano tutte tra loro dentro Scacchi-it e ROTN.

### Bibliografia essenziale di chiusura

_Sull'estetica:_

- Norman, D. A. (2004). _Emotional Design: Why We Love (or Hate) Everyday Things_.
- Gropius, W. (1919). _Manifesto del Bauhaus_.

_Sull'etica hacker:_

- Stallman, R. (1985). _The GNU Manifesto_.
- Himanen, P. (2001). _The Hacker Ethic and the Spirit of the Information Age_.

_Sulla filosofia della tecnologia:_

- Heidegger, M. (1954). _Die Frage nach der Technik_.
- Floridi, L. (2014). _The Fourth Revolution: How the Infosphere is Reshaping Human Reality_.
