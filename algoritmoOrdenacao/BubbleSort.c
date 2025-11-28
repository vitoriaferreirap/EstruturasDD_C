#include <stdio.h>
#define N 5
int main() {
    int aux = 0;  // troca dados
    int flag = 1; // sinaliza quando a sequencia esta ordenada

    // lista de inteiros com 5 elementos
    int lista[N] = {5, 7, 4, 10, 3};
    //crescente 
    while (flag) { // continua ate que flag seja 0.
        flag = 0;
        for (int i = 0; i <= N - 2; i++) { // n - 2 regra
            if(lista[i] > lista[i + 1]) {
                aux = lista[i];
                lista[i] = lista[i + 1];
                lista[i + 1] = aux;
                flag = 1;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        printf("%d ", lista[i]);
    }
    return 0;
}   