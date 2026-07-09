---
title: "Come inserire ROTN nei tuoi articoli, blog e ebook"
description: "Guida per editori: inserire posizioni scacchistiche accessibili in Markdown, HTML ed ePub usando file separati e template da compilare."
author: "Rosario Turco"
categories: Blog
---

# Come inserire ROTN nei tuoi contenuti

di Rosario Turco

ROTN è la Rot Notation, un formato testuale ASCII per descrivere posizioni scacchistiche accessibili agli screen reader come NVDA.

Per non interrompere la lettura, la posizione ROTN non va messa nel testo. Va messa in un file separato e linkata.

## 1. Flusso di lavoro per Blog, Siti e Markdown

Usiamo un template HTML da compilare una sola volta per ogni posizione.

_Passo 1: Scarica il template_  
[Scarica template-html](https://github.com/RedYouMan/redyouman.github.io/raw/main/_posts/templates/template-html.7z)  
È un file base. Fai unzip e ottieni il file html.

_Passo 2: Compila e Rinomina_  
Apri il file con Blocco Note. Incolla la tua posizione nella textarea.  
Salvalo subito con un nome descrittivo. Esempi:
`carlsen-nakamura-2025-34.html` oppure `italia-2026-stallo.html`  
Importante: non lasciare mai il nome `template.html`

Modifica i dati del file.

_Passo 3: Carica il file nella cartella del sito e Linka nel Markdown_  
Carica il file nella cartella del tuo sito.  
Nel tuo articolo scrivi così:
Il Bianco muove e vince in 2.
[Vedi e Copia posizione ROTN: Carlsen vs Nakamura m.34](/rotn/carlsen-nakamura-2025-34.html)
Cliccando si apre una pagina semplice con 1 textarea e 1 bottone "Copia". L'utente copia e torna all'articolo. NVDA legge tutto correttamente.

## 2. Flusso di lavoro per eBook ePub e PDF accessibile

Negli eBook il javascript può non funzionare. Usiamo gli allegati .txt

_Passo 1: Scarica e Compila il template_  
[Scarica template-ebook](https://github.com/RedYouMan/redyouman.github.io/raw/main/_posts/templates/template-ebook.7z)  
Fai unzip, compila i dati e salvalo con un nome diverso dal template e che sia descrittivo.  
Nome esempio: `cap3-pos2.rotn.txt`

_Passo 2: Inseriscilo nell'eBook_  
Allega il file tra le risorse dell'ePub.

_Passo 3: Linkalo nel testo_
Analizziamo la posizione.
<a href="cap3-pos2.rotn.txt" download>Scarica file ROTN </a>
Il lettore scarica e apre il .txt con NVDA.

## 3. Nota importante su IT e EN

L'ordine dei tag è fisso: `T;V;B;N;M;P;` per l'italiano  
L'ordine dei tag è fisso: `T;V;W;B;M;P;` per l'inglese

Il tag `V` decide la lingua:  
`V:B;` o `V:N;` = Italiano. Quindi usa `B:` e `N:`  
`V:W;` o `V:B;` = Inglese. Quindi usa `W:` e `B:`

## 4. Contenuto del template HTML da scaricare

Il codice completo è nel file che hai scaricato al punto 1.
Aprilo con Blocco Note e compila solo la textarea.
