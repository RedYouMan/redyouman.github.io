---
title: "Accessibilità digitale e autonomia nei portali web"
description: "Linee guida tecniche per rendere i portali web autonomi per utenti non vedenti. 4 pilastri, checklist e bibliografia."
keywords:
  [
    "accessibilità web",
    "accessibilità digitale",
    "wcag 2.2",
    "wai-aria",
    "nvda",
    "non vedenti",
    "ciechi",
    "ipovedenti",
    "giochi accessibili",
    "gratuiti",
  ]
categories: Blog
---

# Accessibilità e Autonomia nei Portali Web: Linee Guida Tecniche per l'Inclusione degli Utenti Non Vedenti

_di Rosario Turco, ingegnere_

## Abstract

I portali moderni basano l’interazione su paradigmi visivi e puntamento. Questo approccio esclude di fatto gli utenti che utilizzano tecnologie assistive come gli screen reader. L’articolo analizza le barriere architetturali più comuni, propone 4 pilastri progettuali e definisce una lista di tecnologie da adottare e da evitare. L’obiettivo è fornire una base tecnica per progettare portali che garantiscano inclusione e autonomia operativa.

Con questo lavoro ci proponiamo di definire un approccio operativo all'accessibilità, spostando il focus dalla mera conformità normativa alla capacità reale dell’utente di completare un task in autonomia. L’articolo analizza e classifica le barriere architetturali più comuni, introduce 4 pilastri progettuali — Percepibile, Operabile, Comprensibile, Robusto — e fornisce due liste operative: tecnologie e pattern da evitare e tecnologie e pattern da adottare. Viene inoltre proposta una metodologia di test con utente e una checklist di rilascio.

L’obiettivo è fornire una base tecnica e pratica per progettare portali web che garantiscano inclusione, usabilità e autonomia operativa per gli utenti non vedenti, attraverso l’uso di HTML semantico, notazioni testuali e design "speech-first".

## 1. Introduzione: L'autonomia non è un optional

L’accessibilità web è spesso trattata come un add-on. Un `alt` aggiunto in ritardo. Un contrasto aggiustato a fine progetto. Questo approccio produce conformità formale, non autonomia.

Per un utente non vedente che usa NVDA o JAWS, "accessibile" significa una cosa sola: poter completare un task dall’inizio alla fine senza chiedere aiuto. Comprare, leggere, giocare, configurare.

La differenza è sostanziale. La conformità WCAG verifica la presenza di attributi. L’autonomia verifica il completamento del flusso. Un form può avere tutte le label a norma, ma se il tasto "Invia" è raggiungibile solo col mouse, l’utente è bloccato.

Questo articolo propone di spostare il focus: dalla checklist alla capacità operativa.

## 2. Analisi delle Barriere: Quando il portale dice "usa il mouse"

Le barriere si possono classificare in 5 categorie. Ogni categoria blocca un aspetto dell’autonomia.

**A. Barriere di Navigazione**  
_Problema_: Struttura piatta e focus non gestito.  
_Esempio_: Un menu a tendina fatto con `<div>`. Con Tab non ci entri. Con lo screen reader senti solo "clickable".  
_Impatto NVDA_: L’utente non trova le sezioni. È perso nella pagina.

**B. Barriere di Contenuto**  
_Problema_: Informazione trasmessa solo visivamente.  
_Esempio_: Una scacchiera è 64 tag `<img>` senza `alt`. Oppure un grafico è un unico `canvas`.  
_Impatto JAWS_: Lo screen reader legge "image, image, image". Il contenuto non esiste.

**C. Barriere di Interazione**  
_Problema_: Dipendenza da input puntatori e gesti.  
_Esempio_: Un "drag & drop" per ricaricare un file. Oppure un calendario dove si cliccano le date.  
_Impatto_: Senza mouse non c’è modo di interagire. La tastiera è ignorata.

**D. Barriere Tecnologiche**  
_Problema_: Uso scorretto di HTML e ARIA.  
_Esempio_: `<span onclick="submit()">Invia</span>`. Non è un bottone. Non è focusabile.  
_Impatto_: Le tecnologie assistive non riconoscono il controllo. Lo ignorano.

**E. Barriere di Controllo**  
_Problema_: L’utente non può gestire tempi e stati.  
_Esempio_: Un popup di sessione che scade dopo 60s senza avviso. Un errore che appare in rosso ma non viene letto.  
_Impatto_: L’utente perde dati e non capisce perché.

## 3. Pilastro 1 - Percepibile: Ogni elemento visivo deve avere un equivalente testuale

Se un’informazione esiste solo come pixel, per uno screen reader non esiste.

**Requisiti tecnici:**

1.  **Immagini**: `alt` descrittivo, non "immagine1.jpg". Se decorativa: `alt=""`.
2.  **Contenuti complessi**: Grafici, mappe, scacchiere. Servono descrizioni lunghe. Soluzione: testo alternativo strutturato o tabella dati associata.
3.  **Il caso `canvas`**: È una black box. Il browser vede solo pixel. Soluzione: mantenere un DOM parallelo con gli oggetti, e usare `aria-label` o `role="img"` con descrizione.

_Esempio Prima vs Dopo_:  
Prima: `<canvas id="board"></canvas>` → NVDA: "grafica"  
Dopo: `<div role="grid" aria-label="Scacchiera. Re bianco in E1">` + 64 celle → NVDA: "Riga 1, Torre bianca in A1"

## 4. Pilastro 2 - Operabile: Tutto deve funzionare anche da tastiera

Il mouse è opzionale. La tastiera no.

**Requisiti tecnici:**

1.  **Focus Order Logico**: Tab deve seguire la lettura della pagina, da sx a dx, dall’alto al basso.
2.  **Focus Visibile**: Sempre un bordo. Se lo togli col CSS, lo rimetti.
3.  **Nessuna Trappola**: In un modale, Tab deve girare solo dentro al modale. Esc deve chiuderlo.
4.  **Mappatura Input**: Ogni azione mouse deve avere un equivalente da tastiera. Click → Enter/Spazio. Drag → tasti freccia + Enter.

_Esempio Prima vs Dopo_:  
Prima: Menu che si apre solo con `onmouseover`  
Dopo: Menu che si apre con `Enter`, si naviga con frecce, si chiude con `Esc`

## 5. Pilastro 3 - Comprensibile: Prevedibilità e Chiarezza del Sistema

L’utente deve sempre sapere dove è, cosa sta facendo e cosa è successo.

**Requisiti tecnici:**

1.  **Struttura**: Un solo `H1` per pagina. Gerarchia H2-H3 coerente. Serve a "scansionare" la pagina.
2.  **Form**: Ogni `input` deve avere una `label` associata con `for="id"`. Placeholder non basta.
3.  **Feedback**: Errori e stati devono essere annunciati. Usare `aria-live="polite"` per notifiche.  
    Non basta colorare di rosso. Serve testo: "Errore: la password deve avere 8 caratteri".
4.  **Titoli**: Ogni pagina deve avere un `title` univoco. Serve per orientarsi tra tab.

## 6. Pilastro 4 - Robusto: Codice Semantico per Tecnologie Assistive Future

Le tecnologie assistive leggono il DOM, non il CSS.

**Requisiti tecnici:**

1.  **HTML prima di tutto**: Usa `button` per i bottoni, `a` per i link, `nav` per la navigazione. Non reinventare.
2.  **ARIA è l'ultima spiaggia**: Usala per stati dinamici `aria-expanded`, `aria-pressed`. Non per sostituire un bottone.
3.  **DOM Valido**: Niente ID duplicati. Niente ruoli conflittuali.
4.  **Compatibilità**: Testa con NVDA + Firefox, JAWS + Chrome, VoiceOver + Safari. Se funziona lì, funziona ovunque.

_Esempio Prima vs Dopo_:  
Prima: `<div class="btn" onclick="...">Salva</div>`  
Dopo: `<button type="submit">Salva</button>`

## 7. Tecnologie e Pattern da Evitare: La Lista Nera

Queste tecnologie rompono l'autonomia. Vanno evitate o usate solo con un fallback solido.

1.  **`canvas` senza DOM parallelo**: È pixel. Lo screen reader non ci vede dentro.  
    _Alternativa_: SVG + testo, o tabella dati + descrizione.
2.  **Icon-font e Emoji senza testo**: `<i class="icon-trash"></i>`  
    _Problema_: NVDA legge "vuoto".  
    _Alternativa_: `<button aria-label="Elimina">`
3.  **CAPTCHA solo visivi**: "Seleziona tutti i semafori".  
    _Alternativa_: CAPTCHA audio, logica, o honeypot.
4.  **PDF scansionati**: Sono foto. Non selezionabili, non leggibili.  
    _Alternativa_: PDF con testo reale e tag, o HTML.
5.  **SPA che non gestiscono il focus**: Cambio pagina, ma il focus resta in alto e il titolo non cambia.  
    _Problema_: L'utente non sa che la pagina è cambiata.
6.  **Colore come unica informazione**: "I campi rossi sono obbligatori".  
    _Alternativa_: Aggiungere `* Obbligatorio` e `aria-required="true"`.
7.  **Timer senza possibilità di estensione**: Sessione che scade a 2 minuti.  
    _Alternativa_: Avviso a 60s e bottone "Estendi".

## 8. Tecnologie e Pattern da Adottare: La Lista Bianca

Queste sono la base per costruire portali autonomi.

1.  **HTML Semantico Nativo**: `header`, `nav`, `main`, `article`, `button`, `form`. Danno semantica gratis.
2.  **ARIA per Stati Dinamici**: `aria-label`, `aria-expanded`, `aria-live="polite"`, `aria-describedby`. Solo per colmare i vuoti dell'HTML.
3.  **Keyboard API**: Gestire Tab, Shift+Tab, Freccette, Enter, Esc. Testare tutto senza mouse.
4.  **Testo Alternativo Strutturato**: Per dati complessi usare tabelle. Per stati usare `aria-live`.
5.  **Contrasti WCAG AA**: Rapporto minimo 4.5:1 per testo normale. Strumento: calcolatore contrasto.
6.  **Formati Dati Aperti**: Preferire JSON, Markdown, TXT a binari chiusi.  
    _Concetto chiave_: "Notazione Accessibile". Un dato deve essere leggibile anche solo da voce. Esempio: invece di una posizione grafica, una stringa `e2-e4`.

## 9. Il Ruolo degli Standard Aperti e delle Notazioni: Da Dato Visivo a Dato Vocale

Il problema non è il contenuto. È il formato.

Molti dati sono pensati per gli occhi. Per essere autonomi, devono essere pensati per le orecchie.

**Studio di Caso Anonimo "Prima vs Dopo"**

**Caso A: La Posizione su una Griglia**  
_Prima_: Una griglia grafica. L'utente deve chiedere "dov'è il pezzo?".  
_Dopo_: Una stringa strutturata: `POS: D4=Torre Bianca`. Lo screen reader la legge in 2 secondi.  
_Principio_: Il dato deve essere "speech-first". È il concetto dietro a notazioni come ROTN 1.8.

**Caso B: Il Grafico**  
_Prima_: `canvas` con barre colorate. Alt="Grafico vendite".  
_Dopo_: Sotto al grafico, una tabella HTML nascosta visivamente:  
`Anno 2024: 120k. Anno 2025: 150k.`  
_Principio_: Ogni visualizzazione deve avere un equivalente tabellare.

_Tesi_: Standardizzare notazioni testuali per dati complessi è più importante che rendere "bello" il `canvas`.

## 10. Metodologia di Test: Validare con l’Utente Finale e con NVDA

Gli strumenti automatici tipo axe o lighthouse trovano il 30% dei problemi. Il resto lo trova solo un utente reale.

**Procedura di Test Minima:**

1.  **Disattiva il mouse**. Riesci a fare tutto con Tab, Shift+Tab, Enter, Esc, Frecce?
2.  **Accendi NVDA**. Chiudi gli occhi. Riesci a capire la struttura della pagina solo con H e Tab?
3.  **Esegui 5 Task Critici**: Login, Ricerca, Compilazione Form, Checkout, Logout. Cronometra.
4.  **Metriche da Raccogliere**:
    - Tempo per completare il task
    - Numero di pressioni Tab
    - Numero di errori / punti di blocco
5.  **Regola d'oro**: Se un utente NVDA non riesce a finire in autonomia, il portale non è finito.

## 11. Checklist di Progettazione: 10 Domande Prima del Rilascio

Da stampare e attaccare alla scrivania del dev.

1.  Posso navigare l'intero sito con solo la tastiera?
2.  Il focus è sempre visibile e logico?
3.  Tutte le immagini non decorative hanno un `alt` utile?
4.  Ogni `input` ha una `label` associata?
5.  Gli errori vengono annunciati e spiegati a voce?
6.  I titoli `H1-H2-H3` descrivono la struttura della pagina?
7.  I modali intrappolano il focus e si chiudono con `Esc`?
8.  Se disattivo il CSS, il contenuto ha ancora senso?
9.  Il titolo della pagina cambia ad ogni "schermata" della SPA?
10. Un utente con NVDA può completare il task principale senza aiuto?

Se la risposta a una sola è "No", non rilasciare.

## 12. Conclusioni: Inclusione come Riduzione della Complessità

Progettare per l'autonomia non complica. Semplifica.

Un portale accessibile usa meno JavaScript custom, meno `div`, meno librerie UI pesanti. Usa più HTML nativo. Usa più testo.

L'inclusione non è un costo. È una scelta architetturale: passare da interfacce "visive e basta" a interfacce "dati + semantica".

La proposta finale è questa: smettiamo di inseguire la conformità. Iniziamo a scrivere Specifiche Tecniche Operative. Documenti che dicono non "usa l'alt" ma "l'utente deve poter completare X in Y secondi usando solo la tastiera".

Solo così il web smette di dire "usa il mouse" e inizia a dire "benvenuto".

## Bibliografia

- **W3C Web Accessibility Initiative**. _Web Content Accessibility Guidelines (WCAG) 2.2_. W3C Recommendation, 5 Ottobre 2023. https://www.w3.org/TR/WCAG22/
- **W3C**. _Accessible Rich Internet Applications (WAI-ARIA) 1.2_. W3C Recommendation, 6 Giugno 2023. https://www.w3.org/TR/wai-aria-1.2/
- **W3C / WHATWG**. _HTML Living Standard_. Ultimo aggiornamento continuo. https://html.spec.whatwg.org/
- **Henry, S.L., Abou-Zahra, S., Brewer, J.** _The Role of Accessibility in a Universal Web_. In: _Proceedings of the 11th Web for All Conference_, 2014. https://dl.acm.org/doi/10.1145/2596695.2596719
- **Power, C., Petrie, H., Swallow, D., Sharp, H.** _Understanding the Use of Web-Based Interactive Applications by People with Visual Impairments_. In: _Universal Access in the Information Society_, 2012.
- **The Paciello Group**. _WCAG 2.2 Understanding Documents_. https://www.w3.org/WAI/WCAG22/Understanding/
