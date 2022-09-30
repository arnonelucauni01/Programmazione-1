/*
    TRACCIA 14
        Sviluppare una function C che, data come
        parametro di input una stringa che rappresenta un testo in italiano,
        determina e restituisce come parametri di output la parola di lunghezza
        minima contenuta nel testo e la posizione di inizio della parola nella
        stringa. Nel testo le parole sono separate da un unico spazio.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void trovaParolaPiuPiccola(char* stringa);

void main()
{
    char stringa[100];
    printf("inserisci una frase\n");
    scanf("%[^\n]%*c", stringa);

    trovaParolaPiuPiccola(stringa);
}


void trovaParolaPiuPiccola(char* stringa){
    char* tmp = strtok(stringa," ");
    char* parola = tmp;
    char* pos;
    int min = strlen(stringa);

    while(tmp!=NULL){
        if(strlen(tmp)<min){
            min = strlen(tmp);
            strcpy(parola, tmp);
            pos = tmp;
        }
        tmp = strtok(NULL, " ");
    }
    printf("La parola e` -> \"%s\" e inizia all'indice \"%d\"", parola, (int)pos-(int)stringa);
}