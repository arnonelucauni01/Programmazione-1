/*  TRACCIA 7 Scrivere una funzione che dati in input due array
di strutture del seguente tipo struct prodotto {char *nome; int codice; double prezzo;};
restituisce in output 1 se i due array di struct sono uguali, 0 se non lo sono
Si noti che due dati struct sono uguali se sono uguali tutti i loro campi.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

const int DIM_P1 = 10;
const int DIM_P2 = 10;

typedef struct {
    char* nome;
    int codice;
    double prezzo;
} prodotto;

int confrontaListaProdotti(prodotto p1[], prodotto p2[], int sizeP1, int sizeP2);

int main()
{
    prodotto p1[DIM_P1];
    prodotto p2[DIM_P2];

    for (int i = 0; i < DIM_P1; i++) {
        p1[i].codice = i;
        p1[i].prezzo = (i * DIM_P1) / 2;
        p1[i].nome = (char*) malloc(10);
        strcpy(p1[i].nome, "Ciao");
    }
    for (int i = 0; i < DIM_P2; i++) {
        p2[i].codice = i;
        p2[i].prezzo = (i * DIM_P1) / 2;
        p2[i].nome = (char*) malloc(10);
        strcpy(p2[i].nome, "Ciao");
    }

    printf("%d", confrontaListaProdotti(p1, p2, DIM_P1, DIM_P2));
}

int confrontaListaProdotti(prodotto p1[], prodotto p2[], int sizeP1, int sizeP2) {
    if(sizeP1 != sizeP2){
        return 0;
    }

    for (int i = 0; i < sizeP1; i++) {
        if(p1[i].codice != p2[i].codice){
            printf("Codici prodotto non uguali");
            return 0;
        } else if(p1[i].prezzo != p2[i].prezzo){
            printf("Prezzi dei prodotti non uguali");
            return 0;
        } else if(strcmp(p1[i].nome, p2[i].nome) != 0){
            printf("Nomi dei prodotti non uguali");
            return 0;
        }
    }
    return 1;
}

