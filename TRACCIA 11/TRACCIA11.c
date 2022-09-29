/*
    TRACCIA 11
        Sviluppare una function C che, data come parametro di input una stringa che
        rappresenta un testo in italiano, determina e restituisce come parametro di output il
        numero delle parole contenute nel testo che hanno almeno 5 vocali. Nel testo le
        parole sono separate da un unico spazio.
*/

#include <stdio.h>
#include <string.h>

void checkVocali(char* stringa);

void main(){
    char* stringa[100];
    printf("inserisci una stringa\n");
    scanf("%[^\n]%*c" ,stringa);

    checkVocali(stringa);
}

void checkVocali(char* stringa){
    int contatore = 0;
    char* tmp = strtok(stringa," ");
    while(tmp!=NULL){
        if(strchr(tmp,'a') && strchr(tmp,'e') && strchr(tmp,'i') && strchr(tmp,'o') && strchr(tmp,'u')){
            contatore++;
        }
        tmp = strtok(NULL," ");
    }
    printf("le parole che contengono aeiou sono %d", contatore);
}