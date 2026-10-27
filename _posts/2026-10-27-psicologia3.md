---
title: "Scacchi-it come protesi psicologica: non insegna scacchi, insegna a pensare"
description: "Vygotskij, Bruner e Sweller spiegati con CoachFEN e ROTN. Perché Scacchi-it è una zona di sviluppo prossimale, non un software."
keywords: "psicologia didattica scacchi, Vygotskij zona sviluppo prossimale, Bruner scaffolding, Sweller cognitive load, Scacchi-it, ROTN, didattica inclusiva"
categories: blog
---

# Scacchi-it come protesi psicologica: non insegna scacchi, insegna a pensare

di Rosario Turco

### Abbiamo confuso il software con lo scopo.

> Scacchi-it non è solo un software per imparare gli scacchi. È innanzitutto una protesi psicologica per imparare a pensare con gli scacchi.

### 1. Vygotskij: la Zona di Sviluppo Prossimale è CoachFEN + ROTN

Vygotskij, 1934: c'è quello che sai fare da solo, e quello che sai fare con un aiuto. In mezzo c'è la Zona di Sviluppo Prossimale (ZSP). Lì avviene l'apprendimento.

Prima di Scacchi-it, la ZSP per un non vedente era chiedere a un vedente: "cosa giocheresti qui?". Una ZSP fragile, perché dipende da una persona.

Con Scacchi-it, la ZSP è diventata autonoma e replicabile:

- _CoachFEN_ è l'aiuto puntuale: gli fornisci una FEN e ti restituisce la mossa migliore. Una tantum. Non ti spiega il piano, ti sblocca. Ti permette di continuare a stare in partita senza dipendere da nessuno.
- _ROTN_ è il linguaggio comune tra allievo e istruttore. Una volta avuta la mossa da CoachFEN, la leggi in ROTN con NVDA e ci ragioni sopra: "Perché Re g1 e non Re h1?".
- _Scacchi-it_ ti permette di rigiocarla e interiorizzarla.

Scacchi-it permette molte soluzioni per questo argomento. Si può anche giocare la posizione per più mosse con stockfish forzandolo con Ctrl+A.

Oppure se la partita è registrata,l'allievo se la può analizzare con coachGame ottenendo il report.txt. E tale file, che rappresenta i suggerimenti di stockfish sulle mosse sotto tono, può essere copiato e incollato ad una AI esterna come Chat GPT o Gemini o Meta-AI.
All'AI l'allievo potrà chiedere: "perchè ho perso?"e la AI, facendo una analisi strategico-tattica, gli insegnerà in italiano il tutto.

L'allievo non dipende più dal Maestro come persona. Ha un mediatore che gli dà la risposta corretta quando è bloccato o l'analisi di una partita e gli restituisce la possibilità di pensare da solo.

Questa è la definizione esatta di scaffolding di Bruner. Solo che Bruner nel 1966 non aveva un open source per sperimentare e ottenere dati.

### 2. Bruner: apprendimento a spirale con SVG -> ROTN -> Bendato

Bruner diceva: lo stesso concetto va rivisto più volte, a livelli di rappresentazione diversi. Enattivo (faccio), Iconico (vedo), Simbolico (penso).

Scacchi-it è l'unico software scacchistico italiano che fa esattamente la spirale bruneriana, completa per i vedenti e mentale per i non vedenti:

_Giro 1 - Iconico:_ vedi la posizione in SVG ottenuta da una FEN. Capisci visivamente.
Oppure per i non vedenti l'Iconico si può avere con la ROTN ottenuta facendo una sospensione e leggendo il file nella cartella sospensioni.

_Giro 2 - Simbolico:_ la stessa posizione la leggi in ROTN con NVDA dalla scacchiera. Non la vedi più, la decodifichi (pensi). "Senti dalla cuffia:Re casa g1, Donna d4...". Devi solo ricostruirla mentalmente.

_Giro 3 - Simbolico puro:_ chiudi gli occhi (o spegni lo screen) e giochi dalla ROTN in memoria. Ctrl+D per verificare una relazione, ma senza SVG.

Stessa posizione, tre cervelli diversi. È così che si impara per davvero. Non ripetendo la mossa, ma cambiando rappresentazione. Questo rafforza il concetto e la memoria di esso.

Il vedente e il non vedente fanno la stessa spirale. Nessuno è escluso, perché la spirale è già inclusiva per costruzione.

Provate a fare i tre esercizi su almeno 5 posizioni molte volte, sia che siate vedenti che non vedenti.

### 3. Sweller: l'accessibilità come riduzione del carico estraneo

Sweller, 1988, Cognitive Load Theory.

Dice: il cervello ha memoria di lavoro limitata. Se la riempi di rumore inutile (carico estraneo), non resta spazio per imparare (carico intrinseco).

La scacchiera visiva 2D per un non vedente è TUTTA carico estraneo: devi toccare, contare, ricordare dove sei, chiedere conferma. Alla fine non hai più RAM per calcolare se Cf3 è buona.

La ROTN fa una cosa geniale in termini swelleriani: _toglie il carico estraneo visivo e aptico, e lascia solo il carico intrinseco logico-formale._

Non semplifica gli scacchi. Li purifica. Ti lascia solo la geometria, le relazioni, i pattern.

Ecco perché gli allievi non vedenti, dopo 2 mesi di ROTN, calcolano meglio di molti vedenti di pari ELO: perché non sprecano RAM a gestire la vista.

Tenere una scheda dell'allievo sulle sue capacità di calcolare e ricordare permette di vedere questi progressi nel tempo.

> L'accessibilità non è aggiungere qualcosa per chi non vede. È togliere il rumore per chi deve pensare.

La navigazione e il Ctrl+D, il posizionamento nel proprio schieramento quando hai il tratto, la posizione dei soli re per fornire l'orientamento iniziale durante il caricamento della posizione aiutano molto in questo. La FEN no.

### Conclusione: perché è una protesi psicologica

Una protesi non ti fa diventare più forte di un umano. Ti restituisce la funzione che l'ambiente ti aveva tolto.

Le gambe del non vedente funzionano. Gli scacchi no, perché l'ambiente li aveva costruiti solo per gli occhi.

Scacchi-it è la protesi che restituisce la funzione di pensare scacchisticamente senza dipendere dagli occhi, dalla plastica, da un vedente.

E come tutte le protesi ben fatte, dopo un po' non la senti più. Senti solo che pensi meglio e ti concentri sull'essenza del gioco, la strategia e la tattica. E diventa inenarrabile e sublime assaporare, poi, la bellezza di una combinazione travolgente.

### Bibliografia essenziale

_Sulla ZSP e scaffolding:_

- Vygotskij, L. S. (1934). _Pensiero e linguaggio_.
- Wood, D., Bruner, J. S., & Ross, G. (1976). The role of tutoring in problem solving. _Journal of Child Psychology and Psychiatry_, 17, 89-100.
- Bruner, J. S. (1966). _Toward a Theory of Instruction_.

_Sul carico cognitivo:_

- Sweller, J. (1988). Cognitive load during problem solving. _Cognitive Science_, 12, 257-285.
- Mayer, R. E., & Moreno, R. (2003). Nine ways to reduce cognitive load in multimedia learning. _Educational Psychologist_.
