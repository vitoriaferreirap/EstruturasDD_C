#include <stdio.h>
#define N 8
//algoritmo de complexidade logaritmica O(n log n) - dois ponteiros (Hoare)

/*
    primeiro passo : Partição de Hoare (dois ponteiros):
    - pivô = v[inicio] (fixo para comparação)
    - esquerda caminha da esquerda para a direita
    - direita caminha da direita para a esquerda
    - enquanto esquerda < direita, vamos trocando elementos 
*/
int particiona(int v[], int inicio, int fim) { 
    int pivo = v[inicio]; 
    int esquerda = inicio + 1; //comeca apos pivo
    int direita = fim;
    int aux;

    while (esquerda <= direita){
        //anda ->
        while (esquerda <= fim && v[esquerda] <= pivo){
            esquerda++;
        }
        //anda <-
        while (direita >= inicio && v[direita] > pivo){
            direita--; 
        }
        //se ainda nao tiverem se cruzado
        if(esquerda < direita){
            aux = v[esquerda];
            v[esquerda] = v[direita];
            v[direita] = aux;
        }
    }
        //posicao onde o pivo deve ficar
        aux = v[direita];
        v[direita] = v[inicio];
        v[inicio] = aux;

        return direita;
}

/*
    segundo passo recursao - ordenacao
    chama quicksorte na esquerda e na direita onde:
    esquerda - avanca enquanto < pivo, para quando >= pivo
    direita - avanca enquanto > pivo, para quando <= pivo 
*/

void quickSort(int v[], int inicio, int fim){
    if(inicio < fim){
        int p = particiona(v, inicio, fim);

        //recursao só apos retorno do p
        quickSort(v, inicio, p - 1);  // esquerda: de inicio até p-1 (<= pivo)
        quickSort(v, p + 1, fim);  // direita: de p até fim (> pivo)
    }
}

int main() {
    int inicio = 0;
    int fim = N - 1;

    int v[N] = {4, 2, 8, 7, 1, 5, 3, 6};

    //chamando funcao e passando parametros
    quickSort(v, inicio, fim);

    for (int i = 0; i < N; i++){
        printf("%d ", v[i]);
    }

    return 0;
}