/**********************************************************************
 *  Knäcka lösenord readme.txt
 **********************************************************************/

 Ungefärligt antal timmar spenderade på labben (valfritt):

/**********************************************************************
 *  Ge en högnivåbeskrivning av ditt program decrypt.c.
 **********************************************************************/
Vi börjar med att iterera ett key objekt (half_point) med hjälp av en while loop till att biten i mitten av half_point är 1 då vet man att man har itererat genom drygt hälften av alla kombinationer. Man använder sedan half_point i en annan while loop där man itererar från ett Key objekt som är noll dvs. aaaa/0000 till mittpunkten och sparar värden i en unordered_map. Dessa värden är en key som är det hashade lösenordet minus subset_sum av varje objekt och en vektor med keys som värden. Det innebär att keyn är den resterande summan som vi behöver hitta genom att iterera genom den andra halvan. Sedan brute-force:ar man kombinationerna från mittpunkten och framåt och jämför deras subset_sum med de som finns i den första tabellen. Om en summa matchar så har vi en potentiell lösning.

/**********************************************************************
 *  Beskriv symboltabellen du använt för decrypt.c.
 **********************************************************************/
Nyckeln i vår unordered_map är objekt av klassen Key och deras värden är vektorer som innehåller Keys. Keyn i mappen är den återstående summan och vektorn är alla kombinationer som krypteras till den summan.

/**********************************************************************
 *  Ge de dekrypterade versionerna av alla lösenord med 8 och 10
 *  bokstäver i uppgiften du lyckades knäca med DIN kod.
 **********************************************************************/


8 bokstäver         10 bokstäver
-----------         ------------
congrats            completely
youfound            unbreakabl
theright            cryptogram
solution            ormaybenot


/*********************************************  *******************************
 *  Hur lång tid använder brute.c för att knäcka lösenord av en viss storlek?
 *  Ge en uppskattning markerad med en asterisk om det tar längre tid än vad
 *  du orkar vänta. Ge en kort motivering för dina uppskattningar.
 ***************************************************************************/


Char     Brute
--------------
 4        ~0 sekunder
 5         3 sekunder
 6        136 sekunder
 8         * (länge, minst ett par dagar)


/******************************************************************************
 *  Hur lång tid använder decrypt.c för att knäcka lösenord av en viss storlek?
 *  Hur mycket minne använder programmet?
 *  Ge en uppskattning markerad med en asterisk om det tar längre tid än vad
 *  du orkar vänta. Ge en kort motivering för dina uppskattningar.
 ******************************************************************************/
Sekunderna nedan är körda utan valgrind som kollar minnesaanvändning.Med valgrind blev tiderna betydligt högre. Dvs. tiderna och minnesaanvändning är två olika körningar
Char    Tid (sekunder)    Minne (bytes)
----------------------------------------
6         <1                1 376 494 (bytes allocated)
8         ~1               43 668 200 (bytes allocated)
10        67              Out of memory med valgrind troligtvis på grund av
12        -               någon begränsning i mängden minne som får
                          användas.
/*************************************************************************
 * Hur många operationer använder brute.c för ett N-bitars lösenord?
 * Hur många operationer använder din decrypt.c för ett N-bitars lösenord?
 * Använd ordo-notation.
 *************************************************************************/

O(2^N) vid bruteforce och O(2^(N/2)) vid körning med decrypt.

/*************************************************************************
 * Vilka egenskaper skulle ni leta efter i en hashfunktion för att
 * försäkra er om att den är "säker"?
 *************************************************************************/

Hashning med fler characters i "alfabetet" dvs. tecken och symboler samt öka antalet bitar man kollar på från 5 som det är i den här labben till fler.
