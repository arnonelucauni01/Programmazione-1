/*
    TRACCIA 2
        Sviluppare una function C che, dato come parametro di input un array di tipo struct
        punto double x; double y;  e il suo size, determina e restituisce come parametri di
        output gli indici dei due punti che hanno distanza minima tra loro. I campi x e y
        contengono l’ascissa e l’ordinata, rispettivamente, di un punto.
*/

#include <stdio.h>
#include <math.h>

#define DIM 3


typedef struct punto{
    double x;
    double y;
} punto;


void idxPuntiConDistMin(punto arrPunti[]);


void main(){
    punto arrPunti[DIM];

    for(int i=0; i<DIM; i++){
        printf("inserisci il valore di x e y:\n");
        scanf("%lf%lf", &arrPunti[i].x, &arrPunti[i].y);
    }

    idxPuntiConDistMin(arrPunti);

}



void idxPuntiConDistMin(punto arrPunti[]){

    int idxPunto1;
    int idxPunto2;

    double distMin = 999;

    for(int i=0; i<DIM; i++){
        for(int j=0; j<DIM; j++){
            if((arrPunti[i].x == arrPunti[j].x) && (arrPunti[i].y==arrPunti[j].y)){
                continue;
            }

            double distanza = sqrt( pow(arrPunti[i].x-arrPunti[j].x, 2) +  pow(arrPunti[i].y-arrPunti[j].y, 2));

            if(distanza < distMin){
                idxPunto1 = i;
                idxPunto2 = j;
                distMin = distanza;
            }
        }
    }

    printf("idx 1 -> %d, idx 2 -> %d, distMin -> %lf", idxPunto1, idxPunto2, distMin);
}