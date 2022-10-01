/*
   TRACCIA 20
        Dato un elenco (array) di persone partecipanti a un concorso, ordinare l’elenco in
        ordine alfabetico in base al campo cognome. La struttura che identifica il partecipante è
        struct persona {char *nome; char *cognome;};
        typedef struct persona id;
        struct partecipante {id *utente; unsigned short codice; };
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define DIM 3

typedef struct persona{
    char nome[100];
    char cognome[100];
} persona;

typedef struct persona id;

typedef struct partecipante{
    id* utente;
    unsigned short codice;
} partecipante;

void ordinaPartecipanti(partecipante* arrPartecipanti);

void main(){
    srand(time(NULL));

    partecipante arrPartecipanti[DIM];
    id nominativi[DIM];

    for(int i=0; i<DIM; i++){
        printf("inserisci nome ed il cognome del partecipante\n");
        scanf("%s%s", &nominativi[i].nome, &nominativi[i].cognome);

        arrPartecipanti[i].codice = rand()%100;

        arrPartecipanti[i].utente = &nominativi[i];
    }

    ordinaPartecipanti(arrPartecipanti);

    for(int i=0; i<DIM; i++){
        printf("\nnome: %s\ncognome: %s\ncodice: %d\n###########", &arrPartecipanti[i].utente->nome, &arrPartecipanti[i].utente->cognome, arrPartecipanti[i].codice);
    }
}


void ordinaPartecipanti(partecipante* arrPartecipanti){

    for(int i=1; i<DIM; i++){
        partecipante key = arrPartecipanti[i];
        int j = i-1;

        while(j >= 0 && (strcmp(key.utente->cognome, arrPartecipanti[j].utente->cognome) < 0)){
            arrPartecipanti[j+1] = arrPartecipanti[j];
            j--;
        }
        arrPartecipanti[j+1] = key;
    }
}