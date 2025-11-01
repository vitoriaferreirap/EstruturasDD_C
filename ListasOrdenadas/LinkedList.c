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

void excluir(Lista *p, int valorBuscado){
    //cria variavel local para ser o nosso ponteiro
    Node atual = p->head;
    Node anterior = NULL;

    //enquanto atual for == null, chegamos ao fim da lista
    //enquanto onde o atual esta o dados for diferente do que busco
    //while para quando o valor é encontrado ou quando chega no fim da lista.
    while(atual != NULL && atual->dado != valorBuscado){
        //atual e anterior caminham juntos, MAS preciso que o anterior esteka uma casa antes do atual
        //logo, o anterior sempre pega a posição do atual antes do atual andar.
        //anterior aponta para onde o atual aponta
        anterior = atual;
        //atual, atualizado aponta para onde o ponteiro da proxima cx aponta
        atual = atual->proximo;
    }

    //se atual == Null nao achamos o valor
    if(atual == NULL){
      printf("Valor não encontrado!");
      return;
    }

    //se atual != Null achamos o valor, devos usar o free para remover o no encontrado com o valor que busco
    if(anterior == NULL){
        //Nó que sera removido sera o head(numero que buscamos esta na primeira posicao)
        p->head = atual->proximo;
        free(atual);
        p->qtd--;
    }else{
        //valor e no qualquer no meio da lista
        anterior->proximo = atual->proximo; //atualizamos anterior->proximo para “pular” o nó removido.
        free(atual);
        p->qtd--;
    }

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