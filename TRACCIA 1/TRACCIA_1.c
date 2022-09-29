/*     
    TRACCIA 1
        Sviluppare una function C che, dati come parametri di input un array di int e il suo size,
        determina e restituisce come parametro di output il secondo più grande elemento dell’array
        (N.B.: non bisogna seguire l’idea di ordinare prima l’array).
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[] = {1, 3, 2, 4, 6, 5, 8, 7, 10, 9};
    printf("%d", trovaSecondoNumeroPiuGrande(arr, sizeof(arr) / sizeof(arr[0])));
    return 0;
}

int trovaSecondoNumeroPiuGrande(int arr[], int size){
    int max = 0;
    int max2 = 0;

    if(arr[0] > arr[1]){
            max = arr[0];
        } else {
            max2 = arr[1];
        }

    for(int i = 2; i < size; i++){
        if(arr[i] > max){
            max2 = max;
            max = arr[i];
        } else if(arr[i] > max2){
            max2 = arr[i];
        }
    }
    return max2;
}
