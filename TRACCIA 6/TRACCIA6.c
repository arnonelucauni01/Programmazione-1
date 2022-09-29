/*
    TRACCIA 6
        Scrivere una funzione che dati in input due array ordinati (rispetto al campo
        matricola) di elementi della seguente struttura
        struct studente {char *nome; char *cognome; int matricola;};
        restituisca in output l’array fusione dei due array. La fusione deve avvenire in base
        al campo matricola.
*/

#include <stdio.h>

#define DIM 1

typedef struct studente{
    char* nome;
    char* cognome;
    int matricola;
} studente;

void fusioneArrayStudenti(studente arrStudenti1[], studente arrStudenti2[]);

void main(){
    studente arrStudenti1[DIM];
    studente arrStudenti2[DIM];

    for(int i=0; i<DIM; i++){
        printf("inserisci il nome, il cognome e la matricola per il primo studente\n");
        scanf("%s%s%d", &arrStudenti1[i].nome, &arrStudenti1[i].cognome, &arrStudenti1[i].matricola);

        printf("inserisci il nome, il cognome e la matricola per il secondo studente\n");
        scanf("%s%s%d", &arrStudenti2[i].nome, &arrStudenti2[i].cognome, &arrStudenti2[i].matricola);
    }
    fusioneArrayStudenti(arrStudenti1, arrStudenti2);
}


void fusioneArrayStudenti(studente arrStudenti1[], studente arrStudenti2[]){

    studente studentiComplessivi[DIM+DIM];

    int i = 0;
    int j = 0;
    int k = 0;

    while(i<DIM || j<DIM){
        if(arrStudenti1[i].matricola < arrStudenti2[j].matricola){
            studentiComplessivi[k] = arrStudenti1[i];
            k++;
            i++;
        } else {
            studentiComplessivi[k] = arrStudenti2[j];
            k++;
            j++;
        }
    }

    for(int i=0; i<k; i++){
        printf("%s %s %d\n", &studentiComplessivi[i].nome, &studentiComplessivi[i].cognome, studentiComplessivi[i].matricola);
    }
}