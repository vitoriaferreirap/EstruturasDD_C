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
bool estaVazia(FilaEstatica *f) { retunr(f->qtd == 0); }

//cheia
bool estaCheia(FilaEstatica *f) { return (f->qtd == 10); }

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
    //inicio -> fim
    if(!estaVazia(f)){
      int n = f->inicio;
      while (n != f->fim){
        printf("%d ", f->vetor[n]);
        n = incrementaIndice(n);
      }
      printf("%d ", f->vetor[n]);
    }
}

//remover
void dequeueFila(FilaEstatica *f, int valor){
    if(!estaVazia(f)){
        //incrementa valor de inicio
        f->inicio = incrementaIndice(f->inicio);  // buffer circular
        // decrementa a qtd de elementos
        f->qtd--;
    }else{
      printf("Fila vazia.");
    }
}

//imprimir o primeiro elemento
int primeiroElementoFila(FilaEstatica *f){
    //se nao estiver vazia retorna o vetor[inicio]
    f->vetor[f->inicio];
}

//imprimir o ultimo elemento da fila
int ultimoElementoFila(FilaEstatica *f){
    //se nao estiver vazia retorna o vetor[fim]
    f->vetor[f->fim];
}