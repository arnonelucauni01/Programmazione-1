/*  TRACCIA 4 Sviluppare una function C che,
* dati come parametri di input un array 2D di double,
* il numero delle righe e il numero delle colonne,
* determina e restituisce come para-metro di output il massimo tra le somme degli elementi di ogni colonna.
*/

#include <stdio.h>
#include <stdlib.h>

double sommaColonna(double arr[][5], int col, int rig);

int main()
{
    double somma;
    double arr[3][5];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            arr[i][j] = ((i+j)*2)/5;
        }
    }
    printf("%f", sommaColonna(arr, 3, 5));

    return 0;
}

double sommaColonna(double arr[][5], int col, int rig){
    double max = 0;
    double somma = 0;
    for(int i = 0; i < col; i++){
        for(int j = 0; j < rig; j++){
            somma += arr[i][j];
        }
        if(max < somma){
            max = somma;
        }
        somma = 0;
    }
    return max;
}
