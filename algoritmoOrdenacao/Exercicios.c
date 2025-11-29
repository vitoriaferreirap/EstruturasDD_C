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
void quickSortImprime(int v[], int n){
    int inicio = 0;
    int fim = N - 1;
    int comparacoes = 0;
    int trocas = 0;
    static int tentativa = 1;

    printf("\n=== TENTATIVA - quickSort %d ===\n", tentativa);
    printf("Vetor original:\n");
    for (int i = 0; i < n; i++){
        printf("%d ", v[i]);
    } 
    printf("\n");

    // chama a função recursiva de ordenação
    quickSort(v, inicio, fim, &comparacoes, &trocas);

    // imprime vetor ordenado
    printf("Vetor ordenado:\n");
    for (int i = 0; i < n; i++) printf("%d ", v[i]);
    printf("\n");

    printf("Comparacoes: %d\nTrocas: %d\n", comparacoes, trocas);
    tentativa++;
}

void quickSort(int v[], int inicio, int fim, int *comparacoes, int *trocas){
    if (inicio < fim) {
    int p = particiona(v, inicio, fim, comparacoes, trocas);

    // recursao só apos retorno do p
    quickSort(v, inicio, p - 1, comparacoes, trocas);  // esquerda: de inicio até p-1 (<= pivo)
    quickSort(v, p + 1, fim, comparacoes, trocas);     // direita: de p até fim (> pivo)
    }
}


int particiona(int v[], int inicio, int fim, int *comparacoes, int *trocas) { 
    int pivo = v[inicio]; 
    int esquerda = inicio + 1; //comeca apos pivo
    int direita = fim;
    int aux;

    while (esquerda <= direita){
        //anda ->
        while (esquerda <= fim && v[esquerda] <= pivo){
            esquerda++;
            (*comparacoes)++; //necessario para incrementar valores que os ponteiros apontam
        }
        //anda <-
        while (direita >= inicio && v[direita] > pivo){
            direita--;
            (*comparacoes)++;
        }
        //se ainda nao tiverem se cruzado
        if(esquerda < direita){
            aux = v[esquerda];
            v[esquerda] = v[direita];
            v[direita] = aux;
        (*trocas)++;
        }
    }
        //troca final do pivo
        aux = v[direita];
        v[direita] = v[inicio];
        v[inicio] = aux;
        (*trocas)++;

        return direita;
}



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
    //melhor caso O(n log n), pior caso - ja ordenado é O(n)2 o pivo sendo a posicao 0 
    quickSortImprime(vCrescenteQ, N);  //O(n)2
    quickSortImprime(vDecrescenteQ, N);  //O(n)2
    quickSortImprime(vAleatorioQ, N); //O(n log n)

    return 0;
}