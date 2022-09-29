/*
    TRACCIA 22
        Due giocatori si sfidano lanciando un “dado truccato”. Il dado ha dei valori interi 
        nell’intervallo [5 , 15]. A ogni turno vince il giocatore che ottiene un punteggio 
        maggiore. In caso di parità il punto viene assegnato a entrambi. Simulare 10 sfide e 
        visualizzare il giocatore che vince più volte. 
*/


#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void gioca();
int lancioDadi();

typedef struct partita{
    int punti_giocatore_1;
    int punti_giocatore_2;
} partita;


int main() {
    srand(time(NULL));
    gioca();
    return 0;
}

void gioca() {
    int num_1, num_2 = 0;
    partita p;
    for(int i = 0; i < 10; i++){
        num_1 = lancioDadi();
        num_2 = lancioDadi();
        if(num_1 > num_2) {
            p.punti_giocatore_1++;
        } else if(num_1 < num_2) {
            p.punti_giocatore_2++;
        } else {
            p.punti_giocatore_1++;
            p.punti_giocatore_2++;
        }
    }

    if(p.punti_giocatore_1 > p.punti_giocatore_2) {
        printf("%s", "Giocatore 1 ha vinto");
    } else if(p.punti_giocatore_2 > p.punti_giocatore_1) {
        printf("%s", "Giocatore 2 ha vinto");
    } else {
        printf("%s", "Pareggio, nessun vincitore");
    }
}

int lancioDadi() {
    return 5 + rand() % 11;
}