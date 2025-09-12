#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAXTAM 10

//molde para os objetos
typedef struct{
    int vetor[MAXTAM];
    int topo;
} PilhaEstatica;

//inicializar pilha
void inicializaPilha(PilhaEstatica *p) { p->topo = 0; }

//verifica se esta vazia - o elementopode estar usando 0 espaco mas a capacidade continua MAXTAM
bool estaVazia(PilhaEstatica *p) { return (p->topo == 0); }

//verifica se esta cheia
bool estaCheia(PilhaEstatica *p) { return (p->topo == MAXTAM); }

int main() {
    PilhaEstatica pObjeto; //criando/instanciando uma variável do tipo PilhaEstatica
    inicializaPilha(&pObjeto);

    if(estaVazia){
      printf("Pilha Vazia! ");
    }

    return 0; 
}