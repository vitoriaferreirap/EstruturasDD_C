#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//tipo para o No da lista
typedef struct{
  Lista obj; //dados
  PonteiroNoLista proximo; //ponteiro proximo
} PonteiroNoLista;

//tipo para a lista
typedef struct{
    PonteiroNoLista inicio; //ponteiro inicio
    int qtd;//contados
} Lista;