---
layout: post
title: "Kant gioca accanto al non vedente: l'epistemologia di Scacchi-it"
description: "Perché l'accessibilità non limita la complessità scacchistica, la chiarifica. Dal visivo al logico-formale."
keywords: "epistemologia scacchi, Scacchi-it, ROTN, Kant, spazio scacchistico, accessibilità, FSI, UICI, ASCID, open source"
categories: blog
---

# Kant gioca accanto al non vedente: l'epistemologia di Scacchi-it

di Rosario Turco

### il rapporto tra L'accessibilità e la complessità

> "L'accessibilità non è una limitazione della complessità, ma una sua chiarificazione."

Questa frase abbastanza potente, è capace di riassumere i miei articoli. È la frase più epistemologica mai detta sugli scacchi tiflologici italiani.

Per 50 anni abbiamo pensato: togliere la vista = togliere informazione. Quindi c'è sembrato naturale di dover compensare con plastica, con tatto, con volontari che descrivono.

Falso. Togliere la vista = togliere il rumore. Ora chiarisco.

### Kant sulla scacchiera accanto al non vedente

Kant diceva che spazio e tempo non sono fuori di noi, sono forme a priori con cui la mente organizza il mondo. Il non vedente dalla nascita lo dimostra ogni giorno: non ha mai visto un Alfiere che corre in diagonale, eppure sa che c3-f6 è diagonale. Il non vedente non ha mai visto un cavallo saltare, eppure sa farlo. Come?

Perché la scacchiera non è visiva. È semantico-sintattica. Non sono gli occhi a costruirla, ma la nostra mente come una matrice 8x8 e in tal modo dobbiamo sostenerla e rafforzarla.

Noi l'abbiamo resa tale con la ROTN. Abbiamo preso una immagine grafica e trasformata in immagine testuale, ordinata e leggibile dagli screen reader, con organizzazione semantica dei pezzi in ordine di importanza, corredata di didascalia (il tema) e dando la rotazione alla immagine per vederla con il colore dei pezzi dal lato da cui si gioca.

Kant chiamava questo "forma a priori". Noi in ingegneria lo chiamiamo invariante. La scacchiera visiva cambia, la ROTN resta. Quello che resta è la vera scacchiera. La ROTN è l'invariante.

#### La tabella della rivoluzione

Dimensione | Prima di Scacchi-it | Dopo Scacchi-it
**Natura dello spazio** | Grafico-visiva: la scacchiera è un'immagine 2D dove l'occhio segue linee | Semantico-sintattica: la posizione è testo strutturato, albero logico-formale, slegato dalla vista
**Codice** | Proprietario e chiuso: l'inclusione è una pezza ex-post, costosa | Open Source nativo: l'inclusione è proprietà del codice stesso, non adattamento
**Rapporto allievo-istruttore** | Asimmetrico: il non vedente dipende dal vedente che trascrive | Simmetrico e autoconsistente: log + CoachFEN + SVG, il software è mediatore logico oggettivo
Questa tabella vale più di mille discorsi.

### Tre prove di forza didattica tra le tante

_1. Ctrl+D come ancoraggio cognitivo._ Non insegni più "il Cavallo va in f3". Insegni la relazione: "il Cavallo in f3 controlla e5 e g5 e scopre la diagonale dell'Alfiere". La funzione di Scacchi-it ti costringe a pensare per pattern relazionali, non per coordinate. È didattica purificata.

_2. Web scraping tiflologico._ Con le estensioni browser, l'istruttore prende un FEN da Lichess o Chess.com e in un secondo lo ha in ROTN offline. Prima servivano 3 giorni di volontariato per trascrivere una dispensa. Ora è real-time. La lezione del torneo di ieri è accessibile oggi. Questa è democrazia del dato.

_3. Didattica simmetrica._ Il vedente e il non vedente siedono allo stesso tavolo, uno con gli occhi, uno con NVDA. Leggono la stessa ROTN. Nessuno dei due ha un vantaggio percettivo, solo calcolo. È la prima volta nella storia FSI che succede.

### Il ponte con le metriche

Ieri abbiamo misurato Span, Rotazione, Oblio, Hick-Hyman. Oggi spieghiamo perché funzionano: perché non misurano la vista, misurano le forme a priori. Misurano Kant. Ecco perché quei 4 numeri sono più veri di una vittoria.

### Conclusione: perché Kant gioca accanto al non vedente

Se un non vedente congenito può fare rotazione mentale di una posizione di 90 gradi senza aver mai visto una scacchiera, allora lo spazio scacchistico è davvero una forma a priori, non un'immagine.

Scacchi-it non ha "adattato" gli scacchi ai non vedenti. Ha dimostrato che gli scacchi sono sempre stati un linguaggio, e che noi li abbiamo confusi per un disegno.

La bellezza di un matto in 3 non è vedere il Re accerchiato. È capire che non ha vie di fuga. E questo è logico, non visivo.

L'accessibilità quindi non toglie. Chiarifica. Togli il disegno, resta la geometria. Togli la plastica tattile, resta la memoria di lavoro. Togli la pietà, resta la scienza.

> Scacchi-it è open source e open data proprio per questo: se l'accessibilità fosse una pezza, la venderesti. Se è una chiarificazione, la regali.

### Bibliografia essenziale

_Sullo spazio come forma a priori:_

- Kant, I. (1781). _Critica della ragion pura_. Estetica trascendentale.

_Sullo spazio scacchistico non-visivo e memoria di lavoro:_

- Chase, W. G., & Simon, H. A. (1973). Perception in chess. _Cognitive Psychology_, 4(1), 55-81. [Il paper che dimostra che la scacchiera è un albero di chunk, non un'immagine]
- Saariluoma, P. (1995). _Chess Players' Thinking_. Dimostra che i Grandi Maestri ciechi e vedenti usano la stessa rappresentazione semantica.

\*Sulle metriche

- Shepard, R. N., & Metzler, J. (1971). Mental Rotation. _Science_. [La tua Rotazione]
- Baddeley, A. (1992). Working Memory. _Science_. [Il tuo Span e Oblio]
- Hick, W. E. (1952) e Hyman, R. (1953). [La tua Hick-Hyman per la decisione]
