#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Suponha que uma pilha possua 4 valores na
seguinte ordem: 1, 2, 3 e 4. Topo aponta para 1.
Qual seria a sequência correta de operações de
inserção (I) e eliminação (E) para se obter os
registros na ordem 2 4 3 1 com topo apontando
para o 2? considere que vc tem uma pilha auxiliar.
*/

// Definição da estrutura da pilha dinâmica
// ponteiro para o próximo nó (struct NoPilha*)
typedef struct NoPilha* ProxPonteiroNoPilha;

// tipo de dado que representa cada no na pilha
struct NoPilha{
    int elemento;
    ProxPonteiroNoPilha proximo; // ponteiro para o proximo no
} NoPilha;

typedef struct{
    ProxPonteiroNoPilha topo; // aponta para null
    int qtd; //inicia com 0
} PilhaDinamica;

//inicia pilha
void iniciaPilha(PilhaDinamica* p) { 
    p->qtd = 0;
    p->topo = NULL;
}
//vazia
bool estaVazia(PilhaDinamica *p) { 
    return (p->topo == NULL); 
}

//NAO EXISTE PILHA DINAMICA CHEIA

// tamanho pilha
int tamanhoPilhaDinamica(PilhaDinamica *p){
	return(p->qtd);
}

void imprimirPilhaDinamica(PilhaDinamica *p){
	printf("Pilha = [");
	ProxPonteiroNoPilha aux;
	for(aux =p->topo; aux != NULL; aux =  aux->proximo){
		printf("%d ", aux->elemento);
	}
	printf(" ]\n");
}

//inserir na pilha
void inserirPilha(PilhaDinamica *p, int num){
  ProxPonteiroNoPilha aux = malloc(sizeof(NoPilha));
  aux->elemento = num;
  aux->proximo = p->topo;
  p->topo = aux;
  p->qtd++;
}

//remmover
void removerPilha(PilhaDinamica *p){
    if(!estaVazio(p)){
        ProxPonteiroNoPilha aux;
        aux = p->topo;
        p->topo = p->topo->proximo;
        free(aux); //lipando memoria
        p->qtd--;
    }else{
      printf("Pilha esta vazia");
    }
}


int main(){
	
	PilhaDinamica pilha;
	iniciaPilha(&pilha);
	
	if(estaVazia(&pilha)){
		printf("Pilha Vazia!\n");
	}
	else{
		printf("Ha elementos na pilha!\n");
	}
	
	int tam = imprimirTamanho(&pilha);
	printf("Tamanho: %d \n", tam);
	
	inserirPilha(&pilha, 6);
	imprimirPilhaDinamica(&pilha);		
	
	inserirPilha(&pilha, 10);
	imprimirPilhaDinamica(&pilha);
	
	inserirPilha(&pilha, 2);
	imprimirPilhaDinamica(&pilha);
	
	inserirPilha(&pilha, 7);
	imprimirPilhaDinamica(&pilha);
	tam = imprimirTamanho(&pilha);
	printf("Tamanho: %d \n", tam);
	
	
	removerPilha(&pilha);
	imprimirPilhaDinamica(&pilha);
	tam = imprimirTamanho(&pilha);
	printf("Tamanho: %d \n", tam);
	
	
	return 0;
}