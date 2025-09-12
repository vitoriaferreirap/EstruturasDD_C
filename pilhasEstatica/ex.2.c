#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAXTAM 10

/**
 * Exercício 2: A conversão de um número decimal para sua representação
 * binária é feita através de divisões sucessivas por 2. 
 */

//molde para os objetos - dados abstratos
typedef struct{
  int decimal;
} Objeto;

typedef struct{
    Objeto vetor[MAXTAM];
    int topo;
} PilhaEstatica;


//inicializar pilha
void inicializaPilha(PilhaEstatica *p) { p->topo = 0; }

//verifica se esta vazia - o elementopode estar usando 0 espaco mas a capacidade continua MAXTAM
bool estaVazia(PilhaEstatica *p) { return (p->topo == 0); }

//verifica se esta cheia
bool estaCheia(PilhaEstatica *p) { return (p->topo == MAXTAM); }

void push(PilhaEstatica *p, int decimal){
    if(!estaCheia(p)){
      p->vetor[p->topo].decimal = decimal;  // topo é a ultia possicao livre
      p->topo++;//atualiza ponteiro
    }
}

void imprimirPilha(PilhaEstatica *p) { 
    for (int i = 0; i < p->topo; i++){
      printf("%d ", p->vetor[i].decimal);
    }
    printf("\n");
}

int main() {
    PilhaEstatica pObjeto; //criando/instanciando uma variável do tipo PilhaEstatica
    inicializaPilha(&pObjeto); // passando endereco de meoria da variavel

    if(estaVazia(&pObjeto)){
      printf("Pilha Vazia!\n");
    }

    //empilhar eleentos na pilha
    int decimal[] = {13, 6, 3, 1};
    for (int i = 0; i < 4; i++){
      push(&pObjeto, decimal[i]);
      imprimirPilha(&pObjeto);
    } 

    return 0;
}