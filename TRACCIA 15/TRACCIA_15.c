/*
    TRACCIA 15
        Sviluppare una function C che, dati come parametri di input un array di char
        e il suo size, determina e restituisce come parametro di output l'array
        (di size 21) del numero delle occorrenze delle 21 lettere dell'alfabeto
        italiano.
*/

#include <stdio.h>
#include <string.h>

typedef enum{
    false,
    true
} bool;

void contaOccorrenze();

void main(){
    contaOccorrenze();
}

void contaOccorrenze(){
    char testo[100];
    scanf("%[^\n]%*c", testo);
    int lenTesto = strlen(testo);
    char occorrenze[lenTesto];
    int charContati = 0;

    for(int i=0; i<lenTesto; i++){
        bool charGiaPresente = false;
        for(int j=0; j<charContati; j++){
            if(testo[i] == occorrenze[j]){
                charGiaPresente = true;
            }
        }

        if(charGiaPresente) continue;

        int contaOccorrenze = 0;
        for(int j=0; j<lenTesto; j++){
            if(testo[i] == testo[j]) contaOccorrenze++;
        }

        if(testo[i] != ' '){
            printf("%c : %d\n", testo[i], contaOccorrenze);
        }

        occorrenze[charContati] = testo[i];
        charContati++;
    }
}