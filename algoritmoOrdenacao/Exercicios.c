#include <stdio.h>
#define N 10

//funcao alg ordenacao Bubble Sort
void bubbleSort(int v[], int n){
    static int tentativa = 1;
    int aux;
    int flag = 1;
    int comparacoes = 0;
    int trocas = 0;
   

    printf("\n=== TENTATIVA - bubbleSort %d ===\n", tentativa);
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
void selectSort(int v[], int n){
    int comparacoes = 0;
    int trocas = 0;
    int i, j, menor, aux;
    static int tentativa = 1;

    printf("\n=== TENTATIVA - selectsort %d ===\n", tentativa);
    // imprimir :vetor original;
    printf("Vetor original:\n", tentativa);
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");  


    //selectSort
    for (i = 0; i < n-1; i++){
        menor = i; //recebe indice

        for (j = i+1; j < n; j++){
            if(v[j] < v[menor]){
                menor = j;
            }
            comparacoes++;
        } 
        //atualiza as trocas
        if (menor != i) {
            aux = v[i];
            v[i] = v[menor]; //recebe valor indicado no indice
            v[menor] = aux; //guarda indice
            trocas++;   
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

// funcao alg ordenacao Insert Sort
// imprimir :O vetor original; O vetor ordenado; Quantas comparações o algoritmo fez; Quantas trocas o algoritmo fez

// funcao alg ordenacao Quick Sort
// imprimir :O vetor original; O vetor ordenado; Quantas comparações o algoritmo fez; Quantas trocas o algoritmo fez


int main() { 
    int vCrescenteB[N];
    int vDecrescenteB[N];
    int vAleatorioB[N];

    int vCrescenteS[N];
    int vDecrescenteS[N];
    int vAleatorioS[N];

    // vetores NÃO ordenados pelo algoritmo, gerado com base em fórmulas
    // vetor ordenado crescente - ja ordenado
    for (int i = 0; i < N; i++){
        vCrescenteB[i] = i;
        vCrescenteS[i] = i;
    }
    // vetor ordenado descescente 
    for (int i = 0; i < N; i++){
        vDecrescenteB[i] = N - 1 - i;
        vDecrescenteS[i] = N - 1 - i;
    }
    // vetor aleatorio
    for (int i = 0; i < N; i++){
        vAleatorioB[i] = rand() % 10000;
        vAleatorioS[i] = rand() % 10000;
    }

    // aplicar algoritmo de ordenacao em cada vator de cima
    bubbleSort(vCrescenteB, N);  //O(n) por estar ordenado
    bubbleSort(vDecrescenteB, N); //O(N)2 muita troca    
    bubbleSort(vAleatorioB, N); //O(N)2

    selectSort(vCrescenteS, N);   //O(n) por estar ordenado
    selectSort(vDecrescenteS, N);  //O(N)2 muita troca  
    selectSort(vAleatorioS, N); //O(N)2 

    return 0;
}