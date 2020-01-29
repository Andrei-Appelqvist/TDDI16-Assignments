This is a pattern recognition problem. Finds all lines that have 4 or more points on them.
Run brute test with > ./brute < data/[textfiles with points, choose as big of input you want that is in data folder] 
Example: > ./brute < data/input1600.txt
I do not recommend larger than 3200 with brute it will take a long time.
The optimized solution is : >./fast < data/input1600.txt 
Go as high as you want with this one. Run times are listed below.
./fast < data/mystery10089.txt



/**********************************************************************
 *  M�nsterigenk�nning readme.txt
 **********************************************************************/

 Ungef�rligt antal timmar spenderade p� labben (valfritt):

/**********************************************************************
 *  Empirisk    Fyll i tabellen nedan med riktiga k�rtider i sekunder
 *  analys      n�r det k�nns vettigt att v�nta p� hela ber�kningen.
 *              Ge uppskattningar av k�rtiden i �vriga fall.
 *
 **********************************************************************/

      N       brute       sortering
 ----------------------------------
     150       5(ms)       1(ms)
     200       15(ms)      7(ms)
     300       49(ms)      14(ms)
     400       115(ms)     18(ms)
     800       731(ms)     67(ms)
    1600       5727(ms)    248(ms)
    3200       46507(ms)   948(ms)
    6400       379333(ms)  4286(ms)
   12800       För länge   19131(ms)


/**********************************************************************
 *  Teoretisk   Ge ordo-uttryck f�r v�rstafallstiden f�r programmen som
 *  analys      en funktion av N. Ge en kort motivering.
 *
 **********************************************************************/
 Brute: O(n^4)
        Brute består av 4 loopar därav den sista körs endast om if-satsen är sann. Men i värsta fallet så körs den

 Sortering: O(n^(2)*log(n))
        Lösningen består av en for loop med två for-loopar inuti. Operatorn [] för map är logaritmisk därav blir värsta fallet 2n^2*log(n) som kan förkortas till O(n^(2)*log(n)).
