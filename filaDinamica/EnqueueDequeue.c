#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NoFila* PtrNoFila;

typedef struct NoFila{
    int chave;
    PtrNoFila proximo;
} NoFila;

typedef struct{
    PtrNoFila inicio;
    PtrNoFila fim;
    int qtd;
} FilaDinamica;

//inicializar
void inicializarFila( FilaDinamica *f){
    f->inicio = NULL;
    f->fim = NULL;
    f->qtd = 0;
}

bool estaVazia(FilaDinamica *f) { return(f->inicio == NULL); }
//fila dinamica nunca ficara cheia

int tamanhoFila(FilaDinamica *f) { return (f->qtd); }

void inserir(FilaDinamica *f, int valor){
    PtrNoFila aux = malloc(sizeof(NoFila));
    aux->chave = valor;
    aux->proximo = NULL;
    if(estaVazia(f)){
        f->inicio = aux; //novo no
    }else{
        f->fim->proximo = aux;
    }
    f->fim = aux;
    f->qtd++;
}

void remover(FilaDinamica *f){
    if(!estaVazia(f)){
        PtrNoFila aux;
        aux = f->inicio;
        f->inicio = f->inicio->proximo;
        free(aux);
        f->qtd--;
    }else{
      printf("Fila vazia!");
    }
}

int inicioFila(FilaDinamica *f){
    int ret = -1;
	if(!estaVazia(f)){
		ret = f->inicio->chave;
	}
	return ret;
}

int fimFila(FilaDinamica *f) { 
        int ret = -1; 
        if(!estaVazia(f)){
        ret = f->fim->chave;
        }
    return ret;
}

void imprimirFila(FilaDinamica *f){
    printf("Fila[");
	PtrNoFila aux;
	for(aux=f->inicio;aux!=NULL;aux=aux->proximo){
		printf("%d ", aux->chave);
	}
	printf("]\n");
}

int main() { 
    FilaDinamica fila;
    inicializarFila(&fila);
    if(estaVazia(&fila)){
        printf("Fila vazia!");
        int tam = tamanhoFila(&fila);
        printf("tamanho fila: %d\n", tam);
    }

    int vetor[] = {5, 8, 9, 15, 21};
    for (int i = 0; i < 5; i++){
      inserir(&fila, vetor[i]);
      imprimirFila(&fila);
    }

    for (int i = 0; i < 5; i++) {
      remover(&fila);
      imprimirFila(&fila);
    }
    return 0;
}