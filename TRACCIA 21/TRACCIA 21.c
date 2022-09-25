/*
    TRACCIA 21
        Scrivere un programma per simulare l'inserimento di un PIN per il telefonino.
        Nella prima fase viene costruito il PIN di riferimento,che deve essere di lunghezza 5 e che deve essere costruito in modo casuale.
        Nella seconda fase l'utente inserisce il codice di tentativ e ha al massimo 3 tentativi per indovinarlo.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum {
    true,
    false
} bool;

void creaPin(int* array);
bool confrontaPin(int* arr);

void main(){
    srand(time(NULL));
    int arr[5];
    creaPin(arr);
    for(int i = 0; (i < 3 && confrontaPin(arr)); i++);
}

void creaPin(int* array){
    for(int i = 0; i < 5; i++){
        array[i] = rand()%10;
    }
}

bool confrontaPin(int* arr){
    int pinInserito[5];
    bool pinCorretto = true;

    for(int i=0; i<5; i++){
        printf("%s %d %s", "Inserisci la cifra " , i+1, " del pin: ");
        scanf("%d", &pinInserito[i]);
    }

    for(int i=0; i<5; i++){
        pinInserito[i] != arr[i] ? pinCorretto = false : 0;
    }
    if(pinCorretto == true) {
        printf("%s", "Il pin e' corretto\n");
        return true;
    } else {
        printf("%s", "Il pin non e' corretto\n");
        return false;
    }
}
