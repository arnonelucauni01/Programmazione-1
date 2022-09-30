/*     TRACCIA 12
 Sviluppare una function C che, data come parametro di input una stringa
 che rappresenta un testo in italiano, determina e restituisce
 come parametri di output la parola di lunghezza massima contenuta nel testo
 e la sua lunghezza. Nel testo le parole sono separate da     un unico spazio.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parolaMax (char *testo, char *parola);

int main()
{
    char stringa[] = "Ciao Mondo, mi Chiamo Giuseppe Occhino";
    char parola[100];

    printf("Numero lettere: %d\n", parolaMax(stringa, parola));
    printf("%s", parola);
    return 0;
}

int parolaMax (char *testo, char *parola){
    char *tmp = strtok(testo, " ");

    while(tmp != NULL){
        if(strlen(tmp) > strlen(parola)){
           strcpy(parola, tmp);
        }
        tmp = strtok(NULL, " ");
    }
    return strlen(parola);
}
