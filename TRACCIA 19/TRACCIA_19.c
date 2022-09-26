/*
    TRACCIA 19
    Sviluppare una function C che, dati come parametri di input un array di char e il suo size,
    determina e restituisce come parametro di output il carattere meno frequente.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


void getLessCommonChar(char* testo, int sizeTesto);

void main() {

    char testo[100];
    scanf("%[^\n]%*c", testo);
    int sizeTesto = strlen(testo);

    getLessCommonChar(testo, sizeTesto);
}


void getLessCommonChar(char* testo, int sizeTesto){

    char alfabeto[26];
    int arrContatore[26];

    for(int i=0; i<26; i++){
        alfabeto[i] = 'a'+i;
        arrContatore[i] = 0;
    }

    for(int i=0; i<26; i++){
        for(int j=0; j<sizeTesto; j++){
            if(!isspace(testo[j]) && testo[j] == alfabeto[i]){
                arrContatore[i]++;
            }
        }
    }

    int min = 999;
    int idx = 0;
    for(int i=0; i<26; i++){
        if(arrContatore[i] < min && arrContatore[i] != 0){
            min = arrContatore[i];
            idx = i;
        }
    }

    min==999 ? printf("non e` stato inserito alcun testo") : printf("il carattere meno frequente e` \"%c\" e compare \"%d\" volte", alfabeto[idx], min);    
}