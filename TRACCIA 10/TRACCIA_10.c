/*     TRACCIA 10
Sviluppare una function C che,
data come parametro di input una stringa che rappresenta un testo in italiano,
determina e restituisce     come parametro di output il numero di parole che iniziano
con a e terminano con e contenute nel testo. Nel testo le parole sono separate
da un unico spazio.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contaParole (char *frase);

int main()
{
    char testo[] = "ae fgfgfd ae geg ae ae aa ee";
    printf("%d", contaParole(testo));
    return 0;
}

int contaParole (char *frase){
    char *tmp = strtok(frase, " ");
    int counter = 0;
    while(tmp != NULL){
        if((tmp[0] == 'a') && (tmp[strlen(tmp)-1] == 'e')){
            counter ++;
        }
        tmp = strtok(NULL, " ");
    }
    return counter;
}
