/*
    TRACCIA 17
        Sviluppare una function C che, dati come parametri di input un array di char e il suo
        size, determina e restituisce come parametro di un dato logico che indica se il testo
        nell’array è un pangramma, ovvero è un testo che contiene, almeno una volta, tutte
        le 21 lettere dell’alfabeto italiano.
*/

#include <stdio.h>
#include <string.h>


typedef enum{
    false,
    true
} bool;


int pangramma(char* testo);


void main(){
    char testo[100];
    printf("inserisci la stringa\n");
    scanf("%[^\n]%*c", testo);
    printf("%d", pangramma(testo));
}


int pangramma(char* testo){
    char* stringa = strlwr(testo);
    int contatore = 0;
    int occorrenze[21] = {0};
    int lenStringa = strlen(stringa);

    for(int i=0; i<lenStringa; i++){
        if(stringa[i]!='j' && stringa[i]!='k' && stringa[i]!='w' && stringa[i]!='x' && stringa[i]!='y'){
            if(stringa[i]>='a' && stringa[i]<='j'){
                occorrenze[stringa[i]-'a']++;
            } else if(stringa[i]>'k' && stringa[i]<='w') {
                occorrenze[stringa[i]-'a'-2]++;
            } else {
                occorrenze[stringa[i]-'a'-5]++;
            }
        }
    }

    for(int i=0; i<21; i++){
        if(occorrenze[i] == 0){
            return false;
        }
    }

    return true;
}