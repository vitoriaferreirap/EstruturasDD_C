#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


// EXERCICIO 1

// cria apelido (PtrNoLista) que equivale a struct NoLista* - so prepara o nome
// do ponteiro
typedef struct NoLista *PtrNoLista;

// tipo para o No da lista
typedef struct NoLista {
  int chave;          // dados
  PtrNoLista proximo; // ponteiro proximo
} NoLista;

// tipo para a lista
typedef struct {
  PtrNoLista inicio; // ponteiro inicio
  int qtd;           // contados
} Lista;

void inicializar(Lista *p) {
  p->inicio = NULL;
  p->qtd = 0;
}
bool estaVazia(Lista *p) { return (p->inicio == NULL); }
int tamanho(Lista *p) {
  int tam = p->qtd;
  return tam;
}

void inserir(Lista *p, int valor){
    //criando no para inserir na lista, aloca memoria dinamica
    PtrNoLista novo = (PtrNoLista) malloc(sizeof(NoLista));
    novo->chave = valor; //novo no pega o valor

    if(estaVazia(p)){
        p->inicio = novo;
        novo->proximo = NULL;
    }
    //IMMPORTATE ISSO MANTEM ORDENADO
    // Se o valor do novo nó é menor que o primeiro nó da lista, ele deve ser colocado na frente.
    else if(valor < p->inicio->chave) {
        novo->proximo = p->inicio; //O novo nó passa a apontar para o antigo primeiro.
        p->inicio = novo;//atualiza
    }
    else{ //Se o valor do novo nó é maior que o primeiro no
      PtrNoLista aux = p->inicio; //recebe o que ta no inicio
      //enquando o proximo for diferente e null e proximo for o valor, entrar na posicao proxmo
      while (aux->proximo != NULL && valor > aux->proximo->chave){
        aux = aux->proximo; //avaca prox no
      }
      novo->proximo = aux->proximo; //o novo nó aponta para o próximo nó da lista
      aux->proximo = novo; //o nó anterior agora aponta para o novo nó.
    }
    p->qtd++;
}

void imprimir(Lista *p){
    PtrNoLista aux;
    //inicia no incio, contua ate nao achar null, e a cada laco aux aponta para o proximo
    for (aux = p->inicio; aux != NULL; aux = aux->proximo) {
      printf("%d ", aux->chave);
    }
}

int main() {
  // variavel do tipoLista
  Lista minhaLista;

    // 1 inicializar
    inicializar(&minhaLista); // passa end para a funcao

    // 2 ver se ta vazia
    if (estaVazia(&minhaLista)) {
        printf("Lista vazia\n");
    }

    // 3 taanho lista
    int tam = tamanho(&minhaLista);
    printf("Tamanho da lista: %d \n", tam);

    
    inserir(&minhaLista, 5);
    inserir(&minhaLista, 2);
    inserir(&minhaLista, 1);
    inserir(&minhaLista, 4);
    inserir(&minhaLista, 6);
    inserir(&minhaLista, 7);
    inserir(&minhaLista, 3);
    imprimir(&minhaLista);
}