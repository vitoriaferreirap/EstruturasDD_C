#include <stdio.h>
#define N 10

//funcao alg ordenacao Bubble Sort
void bubbleSort(int v[], int n){
    static int tentativa = 1;
    int aux;
    int flag = 1;
    int comparacoes = 0;
    int trocas = 0;

    printf("\n================ TENTATIVA %d ================\n", tentativa);
    // imprimir :vetor original;
    printf("Vetor original:\n", tentativa);
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");  

    //bubblesort
    while (flag) {  // continua ate que flag seja 0.
        flag = 0;
        for (int i = 0; i <= N - 2; i++) {  // n - 2 regra
        comparacoes++;
            if (v[i] > v[i + 1]) {
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                trocas++;
                flag = 1;
            }
        }
    }
    //imprime O vetor ordenado; 
    //Quantas comparações o algoritmo fez; Quantas trocas o algoritmo fez
    
    printf("Vetor ordenado:\n");
    for (int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");    

    printf("\nComparacoes: %d\n", comparacoes);
    printf("Trocas: %d\n", trocas);
    tentativa++;
}

// funcao alg ordenacao Select Sort
// imprimir :O vetor original; O vetor ordenado; Quantas comparações o algoritmo fez; Quantas trocas o algoritmo fez

// funcao alg ordenacao Insert Sort
// imprimir :O vetor original; O vetor ordenado; Quantas comparações o algoritmo fez; Quantas trocas o algoritmo fez

// funcao alg ordenacao Quick Sort
// imprimir :O vetor original; O vetor ordenado; Quantas comparações o algoritmo fez; Quantas trocas o algoritmo fez


int main() { 
    int vCrescente[N];
    int vDecrescente[N];
    int vAleatorio[N];

    // vetores NÃO ordenados pelo algoritmo, gerado com base em fórmulas
    // vetor ordenado crescente - ja ordenado
    for (int i = 0; i < N; i++){
        vCrescente[i] = i;
    }
    // vetor ordenado descescente 
    for (int i = 0; i < N; i++){
        vDecrescente[i] = N - 1 - i;
    }
    // vetor aleatorio
    for (int i = 0; i < N; i++){
        vAleatorio[i] = rand() % 10000;
    }

    // aplicar algoritmo de ordenacao em cada vator de cima
    bubbleSort(vCrescente, N);  //O(n)
    bubbleSort(vDecrescente, N); //O(N)2 muita troca    
    bubbleSort(vAleatorio, N); //O(N)2

    return 0;
}