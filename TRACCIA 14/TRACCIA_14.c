/*    TRACCIA 14   Sviluppare una function C che, data come
    parametro di input una stringa che rappresenta un testo in italiano,
    determina e restituisce come parametri di output la parola di lunghezza
    minima contenuta nel testo e la posizione di inizio della parola nella
    stringa. Nel testo le parole sono separate da un unico spazio.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int trovaParolaPiuPiccola(char *testo, char *parola);

int main()
{
    char *parolapiuPiccola;
    char testo[] = "Ciao mi chiamo Luca";
    printf("\nPosizione parola = %d", trovaParolaPiuPiccola(testo, parolapiuPiccola));
    return 0;
}

int trovaParolaPiuPiccola(char *testo, char *parolapiuPiccola){
    char *tmpTesto = strtok(testo, " ");
    parolapiuPiccola = tmpTesto;
    int posizioneParola = 0;
    int contatore = 0;
    while(tmpTesto != NULL){
        if(strlen(parolapiuPiccola) > strlen(tmpTesto)){
            posizioneParola = contatore;
            strcpy(parolapiuPiccola, tmpTesto);
        }
        tmpTesto = strtok(NULL, " ");
        contatore++;
    }
    printf("Parola piu' piccola: %s", parolapiuPiccola);
    return posizioneParola+1;
}
