/*  TRACCIA 5 Sviluppare una function C che,
dati come parametri di input un array 2D di int,
il numero delle righe e il numero delle colonne,
determina e restituisce come para-metro di output
il massimo tra le somme degli elementi di ogni riga.
*/

#include <stdio.h>
#include <stdlib.h>

double sommaRiga(double arr[][5], int col, int rig);

int main()
{
    double somma;
    double arr[3][5];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            arr[i][j] = i;
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            printf ("%f %s", arr[i][j], " ");
        }
        printf ("\n");
    }
    printf("%f", sommaColonna(arr, 5, 3));

    return 0;
}

double sommaRiga(double arr[][5], int col, int rig){
    double max = 0;
    double somma = 0;
    for(int i = 0; i < rig; i++){
        for(int j = 0; j < col; j++){
            somma += arr[i][j];
        }
        if(max < somma){
            max = somma;
        }
        somma = 0;
    }
    return max;
}
