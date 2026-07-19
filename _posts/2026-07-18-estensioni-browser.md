# ROTN: un formato nativo-accessibile per la notazione scacchistica e l'estensione FEN to ROTN Voice

Di Rosario Turco

## 1. Introduzione: il problema dell'accessibilità della FEN

Il problema di fondo è noto e condiviso: la notazione FEN, pur essendo uno standard de-facto per lo scambio dati tra motori, è strutturalmente inaccessibile.

Le criticità principali, ampiamente documentate anche dalla comunità di accessibilità digitale, sono:

1.  **Assenza di semantica e "Label Deprivation"**  
    Una stringa FEN è una sequenza opaca di lettere, numeri e separatori. Per uno screen reader rappresenta una barriera: non esistono etichette che identifichino il pezzo, la casa, il colore. L'utente deve decodificare mentalmente `rnbqkbnr/pppp...` senza alcun supporto contestuale.

2.  **Struttura non lineare e "Hierarchical Concealment"**  
    La compattazione per righe con `/` e numeri costringe l'utente con disabilità visive a una navigazione lineare ripetitiva e a calcoli mentali per risalire alla posizione di un pezzo. Le informazioni rilevanti sono "nascoste" in una gerarchia che va ricostruita ad ogni lettura.

3.  **Incompatibilità con le tecnologie assistive esistenti**  
    Le soluzioni proposte finora richiedono l'abbandono di JAWS, NVDA e altri screen reader in favore di lettori proprietari. Questo costringe l'utente a cambiare ambiente di lavoro, con perdita di configurazioni e di autonomia. Inoltre tali reader alternativi gestiscono male le interazioni dinamiche.

## 2. ROTN: i principi progettuali

ROTN nasce per risolvere proprio questi tre punti alla radice, con un approccio diverso: non "leggere la FEN", ma "trasformarla".

I principi progettuali di ROTN sono:

- **Natività semantica**: ogni riga è già un'etichetta. `B:Re1;Dd1;` è immediatamente leggibile da uno screen reader come "Bianco: Re e1; Donna d1".
- **Ordine fisso e predicibile**: i tag `B:` Bianco, `N:` Nero garantiscono che l'utente trovi sempre le informazioni nello stesso punto, senza dover scandagliare tutta la stringa.
- **Compatibilità totale**: non richiede nuovi software. Funziona con qualsiasi screen reader già in uso, perché parla il linguaggio del testo puro.

L'obiettivo non è sostituire la FEN tra motori, ma fornire un formato di interscambio e pubblicazione orientato all'uomo e all'accessibilità, là dove la FEN fallisce.

## 3. Cosa risolve l'estensione "FEN to ROTN Voice"

Per rendere ROTN immediatamente utilizzabile, è stata sviluppata l'estensione per browser **FEN to ROTN Voice**.
Con questa estensione diamo voce alla fen con sintesi vocale attraverso la ROTN.
Questa estensione risolve 3 problemi pratici:

1.  **Conversione istantanea**: Seleziona un FEN su Lichess, Chess.com o qualsiasi sito o ebook o pdf o txt e convertilo in ROTN con un tasto.
2.  **Restituzione vocale**: Legge automaticamente il riassunto della posizione in italiano con il tuo screen reader già configurato. NVDA, JAWS.
3.  **Copia negli appunti**: Con un comando suggerito dal vocale `S + Invio` copia il ROTN pronto per essere incollato in un forum, chat o documento o su file per applicativi come Scacchi-it.

Non installa nuovi lettori. Non cambia il tuo flusso di lavoro. Usa solo le API native del browser.

### Compatibilità Tecnica

- **Browser**: Mozilla Firefox 109+, Google Chrome 88+, Microsoft Edge, Brave
- **Screen Reader**: NVDA, JAWS, Narratore
- **Sistemi**: Windows 10/11, Linux, MacOS

## 4. Download e Installazione

Puoi scaricare l'estensione e il manuale di installazione ai link in fondo alla pagina.

## 5. Conclusioni

ROTN + FEN to ROTN Voice dimostrano che l'accessibilità negli scacchi non richiede di reinventare tutto.  
Basta trasformare i dati in un formato che parli la lingua dell'utente.

Gli attenti osservatori avranno notato che viene detto "Testo non disponibile" e "latoscacchiera ...". Il testo in una fen non è disponibile e il punto di vista da cui giocare non è suggerito. Due ulteriori difetti della FEN, rispetto alle immagini non utilizzabili dai non vedenti e rispetto allaROTN.
Tuttavia dopo aver fatto CtrlC su un file Notepad, si può inserire del testo nel descrittore T:, ad esempio il tema della posizione con suggerimenti tecnici, magari prelevati dal portale o dal documento visionato. Analoga cosa per il descrittore V:.
Spero che tale lavoro aiuti la comunità scacchistica, sia dei non vedenti che dei vedenti.

[estensione fen-to-rotn-firefox](https://github.com/RedYouMan/redyouman.github.io/raw/main/_posts/estensioni/fen-to-rotn-firefox.7z)

[estensione fen-to-rotn-chrome](https://github.com/RedYouMan/redyouman.github.io/raw/main/_posts/estensioni/fen-to-rotn-chrome.7z)

[manuale estensioni](https://github.com/RedYouMan/redyouman.github.io/raw/main/_posts/estensioni/manuale-estensioni.txt)

[ROTN EBNF ISO 14977 ](https://redyouman.github.io/blog/2026/07/02/Spec-ROTN.html)

[scarica Scacchi-it](https://github.com/RedYouMan/redyouman.github.io/raw/main/_posts/repo/scacchiGr.7z)

[scarica fenpos](https://github.com/RedYouMan/redyouman.github.io/raw/main/_posts/repolc/fenpos.exe)

[tutorial Scacchi-it](https://github.com/RedYouMan/redyouman
