#include <stdio.h>
#define N 7

int main(){
    int array[N] = {7,5,1,4,8,2,9};
    int i, j, menor, aux;

    for (i = 0; i < N-1; i++){
        menor = i; //recebe indice

        for (j = i+1; j < N; j++){
            if(array[j] < array[menor]){
                menor = j;
            }
        } 
        //atualiza as trocas
        aux = array[i];
        array[i] = array[menor]; //recebe valor indicado no indice
        array[menor] = aux; //guarda indice
    }

    for (i = 0; i < N; i++) {
      printf("%d ", array[i]);
    }
}