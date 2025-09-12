# MANUALESCNT

## INTRODUZIONE

SCNT (Simple Calculator of Number Theory) è un semplice coltellino svizzero per iniziare a studiare i numeri interi nell'ambito della Teoria dei Numeri.
Esso è realizzato in C++ con la libreria boost multiprecision per estendere i limiti dei tipi numerici unsigned long long e long double. E' , quindi, capace di trattare numeri enormi.

## CONDIZIONI D'USO DEL SOFTWARE

Il software (sorgenti, exe, txt,pkg e manuale) è tutelato da licenza MIT open source allegata, e sono distribuibili in modalità gratuita e libera,mantenendo il nome dell'autore Rosario Turco .

L'autore non può essere ritenuto responsabile di un uso maldestro di SCNT per nessun motivo.

## SORGENTI SCNT

I sorgenti c++ del progetto sono scaricabili dal repository con il file sourcescnt.7z.
Tali sorgenti sono stati prodotti con Visual Studio Code e compilatore mingw con libreriaboost_1_88_0 da installare a parte.In .vscode della directory scntmp esiste il file tasks.json in cui eventualmente modificare il pathdi boost_1_88_0 che avrete installato.

## SALVATAGGIO DATI

Nella versione eseguibile free il comando save() non è attivo.

Invece se si usano i sorgenti e compilate il progetto, nel file command.cpp si possono eliminare le prime due righe del case 3 e ottenere che il comando è attivo.

Ovviamente dovrete testare bene tale funzionalità (vedi command.cpp e sistema.cpp).
Quando save() risulta utilizabile, invece, SCNT controlla che durante i salvataggi su file rimanga al sistema operativo uno spazio di sicurezza di 30 Gigabytes.Questo avviene sia per avviare il salvataggio dei dati su file saveToFile.txt , sia durante ogni scrittura ,per garantire l'arresto della scrittura in caso di spazio disponibile inferiore a 30 Gigabytes.
L'avvertenza, ogni volta che si richiede il save, è di non utilizzare intervalli di ricerca troppo ampi ma anche con numeri troppo grandi in termini di digits da salvare su file.
Quali dati di funzioni si possono salvare su file
Sono salvabili su file i dati di tutti i comandi che comportano indagini su un intervallo . Inoltre per comodità anche il risultato delle funzioni pow e rsakey.
Per attivare il salvataggio su file occorre digitare il comando save(), vedi help().

Per leggere il file salvato digitare read. Per cancellare alla fine il file salvato digitare del.

## COME SI UTILIZZA SCNTFREE

Dopo aver unzippato il contenutodel pacchetto SCNTfree.7Z , entrare nella directory scnt e cliccare su scnt.exe, oppure da linea di comando cmd, con comando dos cd accedere alla directory scnt, percorrendo tutto il path per raggiungere la directory, e alla fine digitare sulla linea di comando: scnt.
Si consiglia di creare sul desktop un link di collegamento all'eseguibile per rendere più facile il suo lancio.  
L'eseguibile deve rimanere nella directory scnt per poter usare il package help.pkg.

## SCNT PRODOTTO DA SOLI

Quando ci si produce scnt.exe da soli dai sorgenti, help.pkg si ottiene tenendo il sorgente help.conf e digitando su linea di comando di scnt il comando non documentato crypt(). Dopo di che help.conf si salva o sul file precedente help.pkg (metodo usato se avete ampliato l'help)oppure help.conf si copia su un nuovo file di nomehelp.pkg.

## PUNTO DI APPRENDIMENTO

Sono consigliati come punto di apprendimento due cose contemporaneamente:

- il presente Manuale
- il comando ehlp()

## COMANDI UTILIZZABILI

Sono una sessantina i comandi utilizzabili, separabili in due categorie:

- comandi di servizio
- comandi matematici.

I comandi di servizio consentono di gestire SCNT come clear(), save(), read() etc.

I comandi matematici spaziano in almeno tre ambiti:

- teoria dei numeri
- calcolo algebrico
- calcolo simbolico

## HIGH LEVEL MICRO PROGRAMMING

SCNT consente micro programmazione di alto livello(HLMP), sia da linea di comando che da script.
Questa feature consente anche a coloro che hanno poca dimistichezza con la programmazione di linguaggi e di compilatori , di riuscire a istruire SCNT. Generalmente si prova il comando da linea di comando e poi si scrive su uno script.

## ARCHITETTURA

Ogni comando pone il risultato della propria operazione su una coda detta ricorsiva di tipo numerico intero.
Il comando successivo, se occorre, può usare in input tale valore precedente prelevandolo dalla coda ricorsiva.

Il software dispone anche di una coda detta Mem (memoria) di tipo numerico intero, dove si possono far sostare dei risultati utilizzabili dopo varie operazioni.
Alcune funzionalità hanno il compito di:

- leggere la coda ricorsiva per rendre disponibile in input ad un comando il risultato precedente
- far sostare un risultato sulla coda Mem
  -prelevare il valore in sosta sulla coda Mem e portarlo sulla coda ricorsiva

Con tale architettura è possibile avere un livello di ricorsività dei comandi pari al massimo a2, in modo che qualsiasi comando più complesso in termini di livello di profondità può essere spezzato in più comandi semplici.

## COMANDI RICORSIVI

In base all'architettura per comandi ricorsivi, si intenderà comandi che possono avere in input altri comandi.
sono utilizzabili nella ricorsività la maggior parte delle funzioni con uno o più parametri ma non funzionalità come primeR, primeG, primeM, la zeta, la funzionalità collaz, le liste.
Questo perchè zeta, collatz e le liste non comportano un risultato intero singolo e le primalità citate prima sono booleane.

Il comando lastV() permette di prelevare il risultato dell'operazione precedente dalla coda ricorsiva.
Ad esempio:
pow(2,3)
pow(lastV(),2)
e il risultato sarà 64.

Tra i comandi ricorsivi ci sono le quattrooperazioni:
add(x,y)
subt(x,y)
mul(x,y)
divide(x,y)

La funzione divide consente risultati in virgola mobile. Nel seguente caso:
divide(3,2)
da come risultato 1.5
Se tale risultato viene utilizzato con altre funzionalità il valore viene preso come numero per difetto1.
Infatti add(1,lastV()) da 2.
Lo stesso se il risultato fosse stato 0.2 sarebbe stato preso il valore per difetto 0.
con le quattro operazioni ed altre funzioni si possono creare comandi ricorsivi.
Ad esempio se vogliamo conoscere se un numero è un numero primo di Mersenne possiamo fare:
subt(pow(2,3),1)
primelast()

Qui primelast() verifica la primalità del risultato dell'ultima operazione.
Ovviamente tutto ciò ritorna molto utile se il risultato è un numero molto grande.  
Ulteriori esempi di ricorsività
pow(pow(2,7),pow(2,4))
pow(repone(3),2)
pow(2,pow(2,10))
pow(pow(3,4),2)
log10(pow(10,5))
Si ricorda che Log10, come da help(), fornisce il valore per difetto intero.
La massima profondità di ricorsività è 2, per cui possiamo chiamare:

- una funzione i cui due parametri sono ottenibili da due altre funzioni separate da virgola
- una funzione con 2 parametri numerici
- una funzione con un parametro numerico ed un altro ottenibile da una funzione
- una funzione il cui solo parametro è ottenuto da un'altra funzione
  In particolare primeR e analoghe sono utilizzabili solo nelseguente modo:
  primeR(num)

Attenzione dopo primeR e analoghe oppure dopo divisors e factors, lastV() risulta 0, per i motivi già descritti sopra precedentemente.
Per vedere la primalità dell'ultimo risultato si usa, invece, primelast().

Un altro esempio:di ricorsività
pow(repone(3),2)
add(lastV(),2)
primelast()
Con i passi di sopra scopriamo che sommando 2 al quadrato del repone 111 troviamo un numero primo.
E' possibile sapere il numero di cifre di un risultato, , con ndigits(num) o anche ndigits(lastV()).

Un altro esempio:
add(2,series(1,10,10,1))
primelast()
con cui si scopre che la serie dei primi 10 numeri a cui si somma sempre la costante 10 da il risultato 155 che sommato a 2 da un numero primo.
Altro esempioadd(ifibonacci(9),series(1,10,10,1))
primelast()

## COSTRUTTI DI HLMP IN SCNT

SCNT ha i seguenti costrutti:
lastV()
nstart:nend:for[cmd1;...;cmdn;]
assign(num)
countP()
pushM()
popM()
readM
Il costrutto lastV() lo abbiamo già incontrato. Esso preleva dallo stack l'ultimo risultato per utilizzarlo nel comando in cui è inserito lastV().
Spesso si vuole verificare se esiste una relazione o una regola tra più numeri. In tal caso torna utile il for. Da notare che ogni comando nel for va completato con un punto e virgola finale. Vediamo un esempio:
2:10:for[pow(2,x);subt(lastV(),1);primelast();]

I due numeri davanti il for determinano da che valore parte il for e dove termina.
In questo caso la variabile 'x' minuscola verrà sostituita con valori da 2 a 10.
L'esempio ci permetterà di vedere i numeri primi di Mersenne.
Attenzione nell'uso delle parentesi quadre che sono per il for da contenitore dell'elenco dei comandi e non vanno mai usate al posto delle parentesi tonde. Questo perchè il parser riconosce la lista dei comandi all'interno delle quadre, mentre le parentesi tonde vanno usate per le funzionalità. Non rispettando tale consiglio porta ad errori. E' consigliato prima di usare gli script per rendersi conto di quanto scritto.

Un altro esempio che utilizza assign potrebbe essere il seguente:
assign(1)
1:20:for[add(lastV(),2);primelast();]
In questo esempio vediamo quale numero dispari a partire da 3 è un numero primo.

Negli esempi precedenti se sostituiamo primelast() con countP() otterremo alla fine del for il conteggio totale dei numeri primi e la loro lista trovata.

Un altro esempio:
1:20:for[add(x,2);pow(2,lastV());subt(lastV(),1);countP();]
Ora vediamo un modo per studiare che il più piccolo fattore di un numero non primo è entro la sua radice quadrata. Ad esempio usando il repone possiamo fare:
2:7:for[sqrtint(repone(x));factors[repone(x));]
Da qui quando i fattori non sono 1 e se stesso,si nota che il fattore più piccolo è dentro la radice quadrata.

Se volessimo indagare sui numeri gemelli di numeri primi generati randomicamente e a cifre crescenti potremmo fare:
2:8:for[genprime(x);countP();add(lastV(),2);countP();subt(lastV(),4);countP();]
minInterv impostato a 2 e maxInterv a 8. Otterremo sia il conteggio che la lista dei numeri primi gemelli trovati. L'intervallo, per rapidità di elaborazione, nell'esempio è impostato non superiore a 10, a meno di non essere disposti ad attendere un po'.

Ora vediamo a cosa servono pushM e popM. Tutti i comandi finora visti come assign e altri leggono e scrivono il risultato sulla coda ricorsiva, che è da usare per il comando successivo. In alcuni casi serve mettere in memoria un valore da riprendere dopo rimettendolo sulla coda ricorsiva e qui risultano utili pushM e popM.
Facciamo un esempio che coinvolge tutti i costrutti. Vogliamo , ad esempio, vedere quanti numeri primi otterremo sommando 2 ai quadrati dei numeri dispari:
assign(1)
1:30:for[add(lastV(),2);pushM();pow( lastV(),2);add(lastV(),2);countP();popM();]

In questo caso pushM() si conserva il dispari calcolato, che viene ripreso con popM().

Rimane da vedere lo scopo di readM. Esso si differenzia da popM per il fatto che legge il valore da memoria e poi lo mette sulla coda ricorsiva. Nell'esempio successivo occorre readM e non popM che non fa leggere il valore.
Attenzione che se siamo in un comando dove occorre sia lastV() che readM(), (o popM) occorre fare prima lastV() per non perdere il valore precedente,che verrebbe sovrapposto nella coda ricorsiva da readM.

2:5:for[pow(2,x);pushM();add(x,1);pow(2, lastV());mul(lastV(),readM());subt(lastV(),1);countP();]Diamo ad esempio minInterv=2 e maxInterv=5.
Con questo esempio otterremo i numeri primi di Mersenne.

## SCRIPT DI HIGH LEVEL MICRO PROGRAMMING

E' sufficiente aprire col NOTEPAD un file di testo, scrivere i comandi e salvarlo con un nome con estensione txt.
Un file di esempio è example1.txt.
In esso si possono notare:

- i commenti ,utili per una descrizione di cosa fa lo script, sono posti ad inizio file. Un commento è contrassegnato dal simbolo '#' posto obbligatoriamente a inizio linea
- linea bianca di separazione
- i comandi semplici o ricorsivi
- la segnalazione di fine script obbligatoria '#end'

A questo punto da linea di comando digitare:
execute(example.txt)
oppure
execute(C:\users\<nome>\\Desktop\example.txt)
Sopra abbiamo messo come esempio il file example.txt.E' possibile mettere anche il path completo dove si trova il file.

Un utile comando è time() (vedi example2.txt), che permette dopo il save() di tracciare su file l'ora e data di inizio del job. Prima di mettere alla fine il save(), per la chiusura della scrittura su file, un altro time() permette di capire la durata del lavoro.
Per esercizio potreste fare su script tutti gli esempi del manuale. Sono forniti ulteriormente quattro script: example1.txt, example2.txt, example3.txt e example4.txt.

Vedi anche come è possibile lanciare gli script in background.

## SCRIPT LANCIATI IN BACKGROUND

E' possibile lanciare gli script da linea di comando in background, in modo che sulla linea di comando si possano fare altre cose. Tipicamente si usa dopo aver scritto nello script il comando save() per ottenere i risultati di un comando che comporta una lista di valori.
Il comando è:
backg(script\_ filename)
dove filename è il nome dello script con o senza PATH della posizione dello script.
Se si lanciano due script in background ognuno con i comandi save() di inizio e fine, si consiglia che il primo script da lanciare abbia solo il save() di inizio mentre il secondo solo il save() di fine. Questo per evitare che se stanno lavorando entrambi quello che finisce per prima non chiuda la scrittura su file. La scelta dell script da lanciare per prima dipende anche dalla quantità di operazioni da fare. Quello che ha più operazioni conviene lanciarlo per secondo.

Molto utile lanciare in background i comandi su script contenenti plprimes(min,max) su intervalli molto grandi e lasciare il pc a lavorare. Il comando plprimes(min,max) suddivide il lavoro su quattro thread in parallelo. Molto indicato per i pc di ultime generazioni che sono quad core.

## NUMERI PRIMI

La primalità più veloce dell'applicativo è primeR basata sul test di Miller-Rabbin.
I numeri primi di Mersenne sono molto rari e, verificandolo con mersennelist, nesistono circa 14 in un intervallo di esponente tra 2 e 1000.
Un numero di Mersenne primo è del tipo 2^p -1. Condizione necessaria ma non sufficiente che sia primo è che p sia a sua volta primo. Ad esempio 2^3 -1=7.

I numeri costituiti da tutti 1 sono detti numeriunoni o in inglese rep-one.I numeri primi repone sono rari; ad esempio tra 1 e 1 miliardo esiste solo il numero primo unone 11 (Vedi reponelist).
Il quadrato di un rep-one è palindromo, ad esempio 11^2=121 e 111^2=12321.
La proprietà palindroma del quadrato dei rep-one la potrete vedere col comando:
1:10:for(add(2,x);repone(lastV());pow(lastV(),2);]
A volte il quadrato dei numeri rep-one con numero di cifre dispari+2 può essere primo come 111^2+2, come il cubo dei rep-one con numero di cifre pari +6, come 111^3+6.
Anche i numeri perfetti sono pochi, come vi invitoa verificare da voi stessi.
Interessanti sono i numeri primi troncabili, ovvero numeri primi che se troncati a destra, a sinistra, a centro o a destra e sinistra contemporaneamente rimangono ancora primi.
Ad esempio 173è primo troncabile ma non troncabile perfetto perchè costituito da numeri dispari non tutti primi. Infatti si può togliere a destra il 3 e 17 è primo, 1 da sinistra e 37 è primo, 3 dal centro e 17 è primo, contemporaneamente 1 e 7 da destra e sinistra e 3 è primo. Però se rimane 17 se togliamo 1 rimane 7 che è primo ma non avviene lo stesso se leviamo dal 17 prima il 7, proprio perchè 1 non è primo anche se dispari, per cui non è troncabile perfetto. Un numero troncabile perfetto deve avere ctutte le cifre prime.
E' facile costruire numeri troncabili a 3 o 4 cifre come il 173,usando i numeri dispari 1,3,5,7 e 9.
Il numero 733 non è troncabile perfetto a causa del 33 non primo.
Per un numero a 4 cifre primo troncabile indichiamo 1373.

Per la primalità dei numeri primi si possono provare
1000003

Un metodo per cercare numeri primi con un fissato numero di cifre , ad esempio 7 cifre, è di partire dal più basso valore di 7 cifre e incrementare di 1 fino ad un massimo dell'intervallo. In questo aiuta primeslist.
SCNT dispone della funzionalità rapida genprime(digits).
Un numero primo a 10 cifre è 1000000103 . 
I numeri primi strong prime number sono quei numeri primi che non hanno un gemello adistanza 2. Ad esempio 3 e 5 sono gemelli ma non forti.
La lista dei numeri strong è di interesse per la crittografia RSA per evitare di usare due numeri primi gemelli per la costruzione della chiave asimmetrica.Solitamente per l'RSA si prelevano da tale lista randomicamente due numeri primi forti molto distanti e ognuno almeno di 100 cifre o più. Un esempio di lista di numeri strong potrebbe essere 3,7,11,17, cioè va saltato il gemello a distanza 2.
Con stronglist si può ottenere tale lista.

Di grande interesse per la crittografia dell'algoritmo ElGamal, basato sul logaritmo discreto,sono le sequenze dei numeri primi di Cunningham . Queste sequenze sono di interesse anche nella Teoria dei Numeri per dimostrare che la complessità dei numeri primi è caratterizzabile in modo finito. Cisono due tipidi numeri di Cunningham:

- numeri primi di Cunningham di prima forma, ottenuti moltiplicando un numero primo per 2 e sommando 1
- numeri primi di Cunningham di seconda forma, ottenuti moltiplicando un numero primo per 2 e sottraendo 1
  La sequenza è detta di lunghezza n, se il numero di essi a partire dal primo pi e l'ultimo pj è proprio n.
  Per prendere confidenza si può usare, per comprendere meglio:
  seqcunn(1,6,1) per la prima formaseqcumm(2,6,2) per la seconda forma
  Una volta confidenti, dopo la comprensione su piccoli numeri si può procedere con numeri con maggior numero di digit.

E' possibile valutare quanto sia strong una rsakey facendone la fattorizzazione.
La fattorizzazione cerca di scomporre in fattori, tramite factors, il prodotto(rsa=p1\*p2) che costituiranno la chiave privata di codifica/decodifica.
Non occorre riferirsi per forza a rsakey, la cosa si potrà osservare anche con numeri composti grandi, ottenibili anche con repone(valore).
Più sono le cifre del valore maggiore sono i tempi di fattorizzazione, che tendono a diventare esponenziali.
Un esempio dei tempi osservabili all'aumentare delle cifre di un numero composto è dato da example4.txt . Qui trattiamo appena da 50 a 70 cifre. Si potrà notare che in alcuni casi la fattorizzazione termina in breve (a 60 cifre), mentre a 70 e 50 cifre la fattorizzazione inizia con vari fattori, poi si rimane in attesa che venga scorso tutto l'intervallo dei numeri dispari. Spesso questo dipende dal fatto che il numero rimasto è molto grande e non piiù divisibile e, quindi, primo.In tal caso tale ultimo numero verrà detto solo alla fine tra i fattori.
L'RSA basa tutto sul fatto che il prodotto di due numeri di moltissime cifre è rapido, ma non è rapida la fattorizzazione del risultato.
La crittografia a curve ellittiche è più veloce e soprattutto può utilizzare chiavi più piccole senza inficiare sulla sicurezza. Avere chiavi di minor lunghezza è importante per i telefonini che posseggono minore capacità di memorizzazionr su disco. I numeri primi importanti per le curve ellittiche sono i numeri primi supersingolari nell'ambito dell'insieme Q razionale.

Interessante è anche il problema di Collatz: dato un n positivo maggiore di1, si calcola una sequenza di numeri,valutando se il numero di partenza o successivo ottenuto è pario dispari. quest'ultimo se pari va diviso per 2 ma se dispari va ottenuto da 3n+1.Si deve dimostrare che tale sequenza termina sempre con 1. Successiva curiosità sarebbe riuscire a calcolare prima del lancio il numero di passi per raggiungere 1 o cooscere il massimo valore raggiungibile. In natura ci sono fenomeni descrivibili come sequenza di Collatz come l'impennata degli aquiloni e la loro successiva picchiata etc. Nonostante la semplicità del problema, esso non è stato mai risolto.n La

Per l'uttilizzo della funzionalità zeta, si possono individuare sia gli zeri banali che quelli non banali, in dipendenza dell'area su cui si indaga.
Esempio per gli zeri banali:
Area 0,1,0,20 con 100 iterazioni(gli zeri da cercare)
Esempio per gli zeri non banali:
Area 1,2,1,30 con 100 iterazioni (gli zeri da cercare)

## AMBITI MATEMATICI

Come si potrà notare dal help online, sono presenti molte funzionalità di Teoria dei Numeri, di Algebra e di calcolo simbolico.

## CONCLUSIONE

Con l'utility SCNT potrete studiare le proprietà dei numeri interi e usare varie funzionalità matematiche su essi.

Buona ricerca di numeri primi e di test di primalità più veloci!

Manuale a cura di Rosario Turco
