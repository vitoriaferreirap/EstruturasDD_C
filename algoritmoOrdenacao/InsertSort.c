#include <stdio.h>
#define N 5
int main(){
    int i,j,key;
    int array[N] = {15, 7, 11, 5, 8};

    //inicia posicao 1
    for (i = 1; i < N;i++){
        key = array[i];
        j = i - 1;

        while (j>=0 && array[j] > key){
            array[j + 1] = array[j]; //empurra
            j--;
        }
        //atualiza a troca
        array[j + 1] = key; //fim da troca
    }

    for (i = 0; i < N; i++) {
        printf("%d ", array[i]);
    }
}