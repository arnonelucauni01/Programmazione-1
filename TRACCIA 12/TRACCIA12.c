/*
    TRACCIA 12
        Sviluppare una function C che, data come parametro di input una stringa che
        rappresenta un testo in italiano, determina e restituisce come parametri di output la
        parola di lunghezza massima contenuta nel testo e la sua lunghezza. Nel testo le
        parole sono separate da un unico spazio.
*/

#include <stdio.h>
#include <string.h>

void checkLongestWord(char* stringa);

void main() {
    char stringa[100];
    printf("inserisci una frase\n");
    scanf("%[^\n]%*c", stringa);

    checkLongestWord(stringa);
}


void checkLongestWord(char* stringa){
    char* parola;
    int lenWord = 0;
    char* tmp = strtok(stringa," ");

    while(tmp!=NULL){

        if(strlen(tmp)>lenWord){
            lenWord = strlen(tmp);
            parola = tmp;
        }
        tmp = strtok(NULL," ");
    }

    printf("la parola piu` grande e` %s ed e` composta da %d caratteri", parola, lenWord);
}