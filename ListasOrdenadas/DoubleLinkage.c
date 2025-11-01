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
  Node anterior;//criada para criar a lista duplamente encadeada
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
    Node novo = (Node) malloc(sizeof(No));  //carrega o dado, ponteiros: anterior e proximo
    novo->dado = valor;

    //ligando novo nó a lista
    novo->proximo = p->head; //novo nó aponta(com seu ponteiro proximo) para o antigo primeiro no
    novo->anterior = NULL;

    //Se novo->proximo != NULL, significa que existe um nó depois do novo, então precisamos atualizar o anterior do nó seguinte para apontar de volta para o novo.
    if(novo->proximo != NULL){
    //novo->proximo-> ponteiro PROXIMO do novo nó aponta para o nó antigo.
    //novo->proximo->anterior no antigo nó tem  ponteiro ANTERIOR que vai aponta para o novo;
    novo->proximo->anterior = novo;
       
    }
    p->head = novo;
    p->qtd++;
}

//ver tamanho da lista
int tamanho(Lista *p){
    int tam = p->qtd;
    return tam;
}

//imprimir lista
void imprimir(Lista *p){
    //nao cria nó na memoria e sim ponteiro (variavel local)
    Node atual = p->head; //atual aponta para onde head aponta

    //ver se a lista está vazia
    if(atual == NULL){
      printf("Lista vazia.\n");
      return;
    }

    printf("Elementos da lista: ");

    while (atual != NULL){
      printf("%d ", atual->dado);
      atual = atual->proximo;
    }
    printf("\n");
}

void excluir(Lista *p, int valorBuscado) { 
    Node atual = p->head; //ira percorrer a lista buscando o valor que eu quero remover
    Node anterior = NULL;

    
    // Percorre a lista até encontrar o valor ou chegar ao fim
    while (atual->dado != valorBuscado){ //buscando por um valor especifico
      anterior = atual;// anterior "fica" uma caixa atrás do atual
      atual = atual->proximo; // atual anda para a próxima caixa
    }
    // Se atual for NULL, significa que chegamos ao fim da lista sem achar o valor
    if(atual == NULL){
      printf("Valor nao encontrado");
    }
    // Se anterior for NULL, significa que o nó a remover é o primeiro da lista
     if (anterior == NULL) {    // valor está na primeira caixa
        p->head = atual->proximo;
        if (atual->proximo != NULL)
            atual->proximo->anterior = NULL; // novo primeiro nó não tem anterior
    } else { // valor a ser removido esta no meio ou final
        anterior->proximo = atual->proximo;
        if (atual->proximo != NULL)
            atual->proximo->anterior = anterior;
    }

    free(atual);               
    p->qtd--;                   
}

int main(){

    //variavel tipo Lista
    Lista minhaLista;

    //enviando end de memoria da nova variavel, onde a funcao recebe ele no seu argumento e novo ponteiro
    inicializa(&minhaLista);

    //ver tamanho da lista
    int tam = tamanho(&minhaLista);
    printf("Tamanho da lista: %d \n", tam);

    imprimir(&minhaLista);

    inserir(&minhaLista, 1);
    inserir(&minhaLista, 2);
    inserir(&minhaLista, 3);

    tam = tamanho(&minhaLista);
    printf("Tamanho da lista: %d \n", tam);

    imprimir(&minhaLista);

    excluir(&minhaLista, 2);

    tam = tamanho(&minhaLista);
    printf("Tamanho da lista: %d \n", tam);

    imprimir(&minhaLista);

    return 0;
}