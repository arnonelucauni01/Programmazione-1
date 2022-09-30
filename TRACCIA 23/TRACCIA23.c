/*
    TRACCIA 23
        Scrivere una function C che ha come input un array di struct (struct punto, con campo
        ascissa e campo ordinata) che individuano punti nel piano, e il suo size n e che
        fornisce in output la matrice nxn delle distanze, dove sono memorizzate le distanze di
        ogni punto da tutti gli altri. La function deve fare uso di un'altra function, anch'essa
        da scrivere) che restituisce la distanza tra due qualunque punti del piano.
*/

#include <stdio.h>
#include <math.h>

#define DIM 3

typedef struct {
    double x;
    double y;
} punto;


void generdaMatriceDistanzePunti(punto arrPunti[]);
double calcolaDistanza(punto punto1, punto punto2);


void main(){
    punto arrPunti[DIM];
    for(int i=0; i<DIM; i++){
        printf("inserisci le coord del punto: \n");
        scanf("%lf%lf", &arrPunti[i].x, &arrPunti[i].y);
    }
    generdaMatriceDistanzePunti(arrPunti);
}


void generdaMatriceDistanzePunti(punto arrPunti[]){
    double matrice[DIM][DIM];
    for(int i=0; i<DIM; i++){
        for(int j=0; j<DIM; j++){
            if((arrPunti[i].x == arrPunti[j].x) && (arrPunti[i].y == arrPunti[j].y)){
                continue;
            } else {
                matrice[i][j] = calcolaDistanza(arrPunti[i], arrPunti[j]);
            }
        }
    }

    for(int i=0; i<DIM; i++){
        for(int j=0; j<DIM; j++){
            printf("%.2lf\t", matrice[i][j]);
        }
        printf("\n");
    }
}


double calcolaDistanza(punto punto1, punto punto2){
    return sqrt( pow(punto1.x-punto2.x ,2) + pow(punto1.y-punto2.y ,2) );
}