/*
TRACCIA 18
    Sviluppare una function C che, dati come parametri di input un array di char e il suo size,
    determina e restituisce come parametro di output il carattere più frequente.
*/


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


void mostCommonChar(char* testo, int sizeTesto);

void main() {
    char testo[100];
    scanf("%[^\n]%*c", testo);
    int sizeTesto = strlen(testo);

    mostCommonChar(testo, sizeTesto);
}

void mostCommonChar(char* testo, int sizeTesto){

    char alfabeto[26];
    char contatoreArr[26];

    for(int i=0; i<26; i++){
        alfabeto[i] = 'a'+i;
        contatoreArr[i] = 0;
    }

    for(int i=0; i<26; i++){
        for(int j=0; j<sizeTesto; j++){
            if(!isspace(testo[j]) && testo[j] == alfabeto[i]){
                contatoreArr[i]++;
            }
        }
    }

    int max = 0;
    int idx = 0;

    for(int i=0; i<26; i++){
        if(contatoreArr[i] > max){
            max = contatoreArr[i];
            idx = i;
        }
    }

    max == 0 ? printf("non e`stata inserita alcuna parola") : printf("il carattere piu` comune e` \"%c\" e compare \"%d\" volte ", alfabeto[idx], max);
}
