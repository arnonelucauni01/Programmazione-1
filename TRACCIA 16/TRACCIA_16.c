/*
    TRACCIA 16
        Sviluppare una function C che, dati come parametri di input un array di char e il suo
        size, determina e restituisce come parametro di output l’array occorrenze (di size 21)
        del numero delle occorrenze dell’evento a precede ognuna delle 21 lettere
        dell’alfabeto italiano (cioè occorrenze[0] è il numero di volte in cui accade che “a
        precede a”, cioè che nel testo compare aa, occorrenze[1] è il numero di volte in cui
        accade che “a precede b”, cioè che nel testo compare ab, occorrenze[2] è il numero
        di volte in cui accade che a precede c, cioè che nel testo compare ac, ...).
*/

#include <stdio.h>
#include <stdlib.h>

int* restituisciOccorrenze(char testo[], int size);

void main()
{
    char testo[] = "una madonna grande cagna succhia pesce lecca palla1";
    int *occorrenze = restituisciOccorrenze(testo, sizeof(testo)/sizeof(testo[0]));
    for(int i = 0; i < 21; i++){
        printf("\n a%c: %d", 'a'+i, occorrenze[i]);
    }
}

int* restituisciOccorrenze(char testo[], int size){
    static int occorrenze[21] = {0};
    for(int i = 1; i <= size; i++){
        if(testo[i-1] == 'a' && (testo[i] >= 'a' && testo[i] <= 'z')){
            printf("\nTEST %d", i);
            int pos= testo[i] - 'a';
            occorrenze[pos]++;
        }
    }
    return occorrenze;
}
