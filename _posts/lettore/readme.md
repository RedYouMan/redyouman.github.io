---
title: "Progetto di un lettore di file Text To Speech - Autore: Rosario Turco (C) 2025"
categories: project 
---

# **PROGETTO LETTORE  TEXT-TO-SPEECH**

Nel seguito sono forniti i sorgenti di un
sempliceprogetto C++ per la lettura di file con la tecnica Text To Speech.
Il progetto è stato realizzato con IDE Visual Studio Community 2022.

# ** Sorgenti **

lettore.ini: file di configurazione dei valori ritardo della voce (in ms default 0) , max records da leggere dopo di cui si fa ESC oppure SPACE per proseguire
lettore.cpp: il main
proto.h: prototipi di servizio 
tasti.h: header generale per utilizzo dei tasti di una tastiera
tasti.cpp: gestione dei tasti
readme.md: il file che state leggendo scritto con markdown

# ** Installazione **

Dopo aver compilato (COMPILE SOURCE) con Visual Studio Community 2022,
si crea una cartella su Desktop e si pongono in essa  i seguenti items:
- lettore.ini
- - lettore.exe
	- - readme.md
		- - poker.txt (file fornito per prova)

# ** Configurazione **

Normalmente i valori forniti dovrebbero andare bene. Tuttavia aprendo il file lettore.ini si possono modificare:
il primo intero è il valore di ritardo desiderato della voce , espresso in millisecondi (ad esempio 1000 rappresenta 1 secondo)
-il secondo intero rappresenta il massimo numero di records da leggere, prima di decidere di uscire (ESC) o continuare ad ascoltare (SPACE).

# ** Comandi di utilizzo **
Si digita su console (prompt linea di comando): lettore nomefile.txt

Un esempio: lettore poker.txt per la lettura delle regole del software pokerNV.exe

Se si uscissecon ESC ci viene ricordato il valore da cui riprendere la lettura del file, eventualmente.
In tal caso il comando sarà lettore poker.txt 31 ad esempio

# ** Future implementazioni **
	
Il lettore si presta ad ulteriori stensioni, sia in termini grafici che di funzionalità
