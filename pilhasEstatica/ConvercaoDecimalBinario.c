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
  int num;
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

//assinatura - prototipo
int pop(PilhaEstatica *p);

void push(PilhaEstatica *p, int num){
    if(!estaCheia(p)){
        //add a lista 
        p->vetor[p->topo].num = num;  // topo é a ultia possicao livre
        p->topo++;//atualiza ponteiro
    }
}
int pop(PilhaEstatica *p){
    if(!estaVazia(p)){
      int valor = p->vetor[p->topo - 1].num;
      p->topo--;
      return valor;
    }else{
      printf("Lista Vazia.");
    }
}

void converterBinario(PilhaEstatica *p, int decimal){
    //caso especia se a entrada for 0
    if(decimal == 0){
      printf("Binario: 0\n");
      return;
    }
    int n = decimal;
    while(n > 0 ){
        int resto = n % 2;   // 0 ou 1
        push(p, resto);        // empilha ESTE bit agora
        n = n / 2;
    }
    printf("Decimal %d e binario: ", decimal);

    while(!estaVazia(p)){
      printf("%d", pop(p));
    }
    printf("\n");
}



void imprimirPilha(PilhaEstatica *p) { 
    for (int i = 0; i < p->topo; i++){
      printf("%d ", p->vetor[i].num);
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
    int num[] = {13, 6, 3, 1};
    for (int i = 0; i < 4; i++){
        push(&pObjeto, num[i]);
        imprimirPilha(&pObjeto);
    }
    inicializaPilha(&pObjeto);
    converterBinario(&pObjeto, 13);

    return 0;
}