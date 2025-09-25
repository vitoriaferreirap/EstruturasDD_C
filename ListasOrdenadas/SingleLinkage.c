#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


// EXERCICIO 1

// cria apelido (PtrNoLista) que equivale a struct NoLista* - so prepara o nome
// do ponteiro
typedef struct NoLista *PtrNoLista;

// tipo para o No da lista
typedef struct NoLista {
  int valor;          // dados
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
    }