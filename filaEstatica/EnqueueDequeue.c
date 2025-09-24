#include <stdio.h>
#include <stdbool.h>
/* 
implemente um TDA para Fila com alocação estática, e
as funções de manipulação.
Quais TDAs serão necessários?
*/
#define TAMANHO 10

typedef struct {
  int vetor[TAMANHO];
  int inicio;
  int fim;
  int qtd;
} FilaEstatica;

//inicializar
void iniciaFila(FilaEstatica *f){
    f->inicio = 0;
    f->fim = -1;
    f->qtd = 0;
}

//vazia
bool estaVazia(FilaEstatica *f) { return (f->qtd == 0); }

//cheia
bool estaCheia(FilaEstatica *f) { return (f->qtd == TAMANHO); }

//retorna tamanho da fila
int tamanhoFila(FilaEstatica *f) { return (f->qtd); }


/*
Pilha circular 
final do vetor (TAMANHO-1), o próximo índice válido volta a ser 0.
Isso garante que o espaço do vetor seja aproveitado mesmo depois de retirar elementos do início.
Se eu remover 3 elementos (inicio=3), ainda restam posições livres em [0,1,2].
Para aproveitar, o próximo fim tem que "voltar para o início" (índice 0).
*/
int incrementaIndice(int indice){
  int retorno;
  if (indice == (TAMANHO - 1)) {
    retorno = 0;
    }else{
      retorno = indice + 1;
    }
    return (retorno);
}



//inserir
void enqueueFila(FilaEstatica *f, int valor){
    if(!estaCheia(f)){
        //incrementa valor do fim
        f->fim = incrementaIndice(f->fim);
        //joga novo valor na posicao fim
        f->vetor[f->fim] = valor;
        //incrementa a qtd de elementos na fila
        f->qtd = f->qtd + 1;
    }else{
      printf("Fila cheia");
    }
}

//imprimir Fila
void imprimirFila(FilaEstatica *f){
    // [Inicio -> Fim]
    printf("Fila = [");
    if(!estaVazia(f)){
      int n = f->inicio;
      while (n != f->fim){
        printf("%d ", f->vetor[n]);
        n = incrementaIndice(n);
      }
      printf("%d ", f->vetor[n]); // último (fim)
    }
    printf("]\n");
}

//remover
void dequeueFila(FilaEstatica *f) {
  if (!estaVazia(f)) {
    // incrementa valor de inicio
    f->inicio = incrementaIndice(f->inicio);  // buffer circular
    // decrementa a qtd de elementos
    f->qtd--;
  } else {
    printf("Fila vazia.");
  }
}

//imprimir o primeiro elemento
int primeiroElementoFila(FilaEstatica *f){
    //se nao estiver vazia retorna o vetor[inicio]
   if (!estaVazia(f)) {
    return f->vetor[f->inicio];
  }
  printf("Warning: fila vazia!\n");
  return -1;
}

//imprimir o ultimo elemento da fila
int ultimoElementoFila(FilaEstatica *f){
    //se nao estiver vazia retorna o vetor[fim]
   if (!estaVazia(f)) {
    return f->vetor[f->fim];
  }
  printf("Warning: fila vazia!\n");
  return -1;
}

int main(){
    FilaEstatica fila;
    iniciaFila(&fila); // passa endereco do ponteiro p funcao
    
    if(estaVazia(&fila)){
      printf("Fila Vazia");
    }else{
      printf("H elementos da fila");
    }

    if(estaCheia(&fila)){
      printf("Fila cheia");
    }else{
      printf("Nao esta cheia");
    }

    int tam = tamanhoFila(&fila);
    printf("Tamanho = %d]n", tam);

    int inserir[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int i;

    //inserindo e imprimindo numero um por um 
    for (i = 0; i < 11; i ++){
      enqueueFila(&fila, inserir[i]);
      imprimirFila(&fila);
    } 

    //remover e imprimindo numero um por um 
    for (i = 0; i < 11; i ++){
      dequeueFila(&fila);
      imprimirFila(&fila);
    }
    return 0;
}