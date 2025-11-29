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
void insertSort(int v[], int n){
    int comparacoes = 0;
    int trocas = 0;
    int i, j, key;
    static int tentativa = 1;

    printf("\n=== TENTATIVA - insertSort %d ===\n", tentativa);
    // imprimir :vetor original;
    printf("Vetor original:\n", tentativa);
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");  

    //insertSort
    for (i = 1; i < n;i++){
        key = v[i];
        j = i - 1;

        while (j>=0 && v[j] > key){
            v[j + 1] = v[j]; //empurra
            j--;
            comparacoes++;
        }
        comparacoes++; // conta a última comparação que fez o while parar

        //atualiza a troca
        v[j + 1] = key; //fim da troca
        trocas++;
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

// funcao alg ordenacao Quick Sort
// imprimir :O vetor original; O vetor ordenado; Quantas comparações o algoritmo fez; Quantas trocas o algoritmo fez


int main() { 
    int vCrescenteB[N];
    int vDecrescenteB[N];
    int vAleatorioB[N];

    int vCrescenteS[N];
    int vDecrescenteS[N];
    int vAleatorioS[N];

    int vCrescenteI[N];
    int vDecrescenteI[N];
    int vAleatorioI[N];

    int vCrescenteQ[N];
    int vDecrescenteQ[N];
    int vAleatorioQ[N];


    // vetores chegam nas funcoes NÃO ordenados pelo algoritmo, gerado com base em fórmulas
    // vetor ordenado crescente - ja ordenado
    for (int i = 0; i < N; i++){
        vCrescenteB[i] = i;
        vCrescenteS[i] = i;
        vCrescenteI[i] = i;
        vCrescenteQ[i] = i;
    }
    // vetor ordenado descescente 
    for (int i = 0; i < N; i++){
        vDecrescenteB[i] = N - 1 - i;
        vDecrescenteS[i] = N - 1 - i;
        vDecrescenteI[i] = N - 1 - i;
        vDecrescenteQ[i] = N - 1 - i;

    }
    // vetor aleatorio
    for (int i = 0; i < N; i++){
        vAleatorioB[i] = rand() % 10000;
        vAleatorioS[i] = rand() % 10000;
        vAleatorioI[i] = rand() % 10000;
        vAleatorioQ[i] = rand() % 10000;

    }

    // aplicar algoritmo de ordenacao em cada vator de cima 
    //Bubble Sort muda com o vetor
    bubbleSort(vCrescenteB, N);  //O(n) por estar ordenado - melhor caso
    bubbleSort(vDecrescenteB, N); //O(N)2 muita troca    
    bubbleSort(vAleatorioB, N); //O(N)2

    //Selection Sort sempre é n²
    selectSort(vCrescenteS, N);   //O(N)2  por estar ordenado - melhor caso
    selectSort(vDecrescenteS, N);  //O(N)2 muita troca  
    selectSort(vAleatorioS, N); //O(N)2 

    //Insert Sort 
    insertSort(vCrescenteI, N);   //O(N)  por estar ordenado - melhor caso
    insertSort(vDecrescenteI, N);  //O(N)2 muita troca  
    insertSort(vAleatorioI, N); //O(N)2 

    //Quick Sort 
    quickSort(vCrescenteQ, N);   
    quickSort(vDecrescenteQ, N);  
    quickSort(vAleatorioQ, N); 

    return 0;
}