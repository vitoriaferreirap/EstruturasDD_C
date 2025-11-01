#include <stdio.h>
#include <stdlib.h>

#define MAX 5 //necessario para listas NAO dinamicas

typedef struct {
    int dados[MAX]; //num posicoes
    int qtd;
} ArrayLista;

void inicializa(ArrayLista *l) {
    l->qtd = 0;
}

int tamanho(const ArrayLista *l) {
    return l->qtd;
}

int inserirFim(ArrayLista *l, int valor) {
    if (l->qtd >= MAX){
        return 0;// temque verificar se existe espaco para add elementos
    }else{
        l->dados[l->qtd++] = valor;
        return 1;
    }

}
//Remove primeira ocorrência do valor; retorna 1 se removido, 0 se não encontrado.
int removerValor(ArrayLista *l, int valor) {
    for (int i = 0; i < l->qtd; ++i) {
        if (l->dados[i] == valor) {
            return removerPosicao(l, i);
        }
    }
    return 0;
}
// Remove elemento na posição especifica  Retorna 1 se removido, 0 se idx inválido. 
int removerPosicao(ArrayLista *l, int posicao) {
    if (posicao < 0 || posicao >= l->qtd){
        return 0;
    }
    // desloca todos os elementos à direita de posicao uma casa para a esquerda
    for (int i = posicao; i + 1 < l->qtd; ++i) {
        l->dados[i] = l->dados[i + 1];
    }
    l->qtd--;
    return 1;
}

void imprimir(ArrayLista *l) {
    printf("Lista: [ ");
    for (int i = 0; i < l->qtd; ++i) {
        printf("%d ", l->dados[i]);
    }
    printf("]\n");
}



int main(void) {
    ArrayLista l;
    inicializa(&l);

    // preencher com valores (opcionalmente vindo de um array estático)
    int inicial[] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; ++i){
        inserirFim(&l, inicial[i]);
    } 

    imprimir(&l);
    printf("Acesso direto ao indice 2: %d\n", l.dados[2]); // 30

    removerValor(&l, 30); // remove primeira ocorrência de 30
    imprimir(&l); 

    // remover por posição (remover índice)
    removerPosicao(&l, 1);
    imprimir(&l); // 20

    return 0;
}
