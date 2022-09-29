/*
    TRACCIA 3
        Sviluppare una function C che, dato come parametro di input un array di tipo struct
        punto {double x; double y;} e il suo size, determina e restituisce come parametro di
        output la massima distanza tra i punti. I campi x e y contengono l’ascissa e
        l’ordinata, rispettivamente, di un punto.
*/

#include <stdio.h>
#include <math.h>

#define DIM 3

typedef struct punto{
    double x;
    double y;
} punto;

void distMaxTraPunti(punto arrPunti[]);

void main(){
    punto arrPunti[DIM];
    for(int i=0; i<DIM; i++){
        printf("inserisci i valori per le coord x e y\n");
        scanf("%lf%lf", &arrPunti[i].x, &arrPunti[i].y);
    }

    distMaxTraPunti(arrPunti);
}

void distMaxTraPunti(punto arrPunti[]){
    double distMax = 0;

    for(int i=0; i<DIM; i++){
        for(int j=0; j<DIM; j++){
            if((arrPunti[i].x == arrPunti[j].x) && (arrPunti[i].y == arrPunti[j].y)) continue;

            double distanza = sqrt(pow(arrPunti[i].x-arrPunti[j].x ,2) +  pow(arrPunti[i].y-arrPunti[j].y ,2));

            if(distanza > distMax){
                distMax = distanza;
            }

       }
    }
    printf("distanza massima -> %lf", distMax);
}

