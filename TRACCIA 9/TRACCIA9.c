/*
    TRACCIA 9
        Sviluppare una function C che, data come parametro di input una stringa che
        rappresenta un testo in italiano, determina e restituisce come parametro di output il
        numero di parole che terminano in are contenute nel testo. Nel testo le parole sono
        separate da un unico spazio.
*/

#include <stdio.h>
#include <string.h>

void contaParoleTreLettere(char* stringa);

void main(){
    char stringa[100];
    printf("inserisci una stringa\n");
    scanf("%[^\n]%*c", stringa);
    contaParoleTreLettere(stringa);
}

void contaParoleTreLettere(char* stringa){
    int i = 0;
    char* tmp = strtok(stringa, " ");

    while(tmp != NULL){
        if(strlen(tmp) >= 3){
            if(!strcmp(&tmp[strlen(tmp)-3], "are")){
                i++;
            }
        }
        tmp = strtok(NULL, " ");
    }

    printf("il numero di parole di tre caratteri e`: %d", i);
}
