#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Lista encadeada: 
//cria um apelido (alias) chamado Node para o tipo struct No*.
typedef struct No *Node; // * DIZ : Node é um ponteiro para struct No

//estrutura de um no da lista
//primeiro nó da lista, cada nó tem o dado e um ponteiro proximo
//estrutuda do nó
typedef struct No{
  int dado;
  Node proximo; //variável do tipo Node, um ponteiro para struct No.
}No;//estrutura do no , node ponteiro da estrutura No

//criando lista
typedef struct{
  Node head; //ponteiro inicial (head->Node)
  int qtd;
} Lista;

//inicializa lista
void inicializa(Lista *p){
    p->head = NULL; //nao existe nó aqui, head é o ponteiro que indica o incio da lista
    printf("Lista inicializada \n");
}

//inserir
void inserir(Lista *p, int valor){
    //1-criar novo no
    Node novo = (Node) malloc(sizeof(No));
    novo->dado = valor;

    //ligando novo nó a lista
    novo->proximo = p->head; //novo nó aponta para onde o antigo apontava
    p->head = novo;
    p->qtd++;
}

//ver tamanho da lista
int tamanho(Lista *p){
    int tam = p->qtd;
    return tam;
}

int main(){

    //variavel tipo Lista
    Lista minhaLista;

    //enviando end de memoria da nova variavel, onde a funcao recebe ele no seu argumento e novo ponteiro
    inicializa(&minhaLista);

    //ver tamanho da lista
    int tam = tamanho(&minhaLista);
    printf("Tamanho da lista: %d \n", tam);
}