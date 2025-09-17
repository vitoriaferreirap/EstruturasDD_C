#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//objeto carro
typedef struct{
  int placa;
} ObjetoCarro;

//estacionamento principal e uma pilha
//estrutura lista
typedef struct{
  ObjetoCarro vetor[10];
  int topo;
} PilhaEstatica;

//rua de manobra, e outra pilha
typedef struct{
  ObjetoCarro vetor[10];
  int topo;
} PilhaRuaManobra;

//inicializar piiha
int push(PilhaEstatica *p) { p->topo = 0; }

bool estaVazia(PilhaEstatica *p) { return p->topo == 0; }
bool estaCheia(PilhaEstatica *p) { return p->topo == 10; }


//impilhar carros com entrada,placa 
void push(PilhaEstatica *p, int placa){
  //ver se tem espaco
  if(!estaCheia){
    p->vetor[p->topo].placa = placa;
    p->topo++;
  }else{
    print("Estacionamento cheio!");
  }

}

//desempilhar carro com saida,placa
void pop(PilhaEstatica *p, int placa){

    //ve se nao esta vazia
    if(!estaVazia(p)){
        //se a placa é igual a ultimo que entrou
        if(p->topo > 0 && p->vetor[p->topo - 1].placa == placa){
            //retirar o carro com a placa desejada
            p->topo--;
        }else{
            PilhaRuaManobra rua;//pilha auxiliar
            rua.topo = 0;
            /*se nao for, colocar os carros da frente na pilha manobra,
            ate que o desejado esteja no topo*/
            while (p->topo > 0 && p->vetor[p->topo - 1].placa != placa) {
                if (rua.topo >= 10) { /* tratar overflow da rua se necessário */
                    break;
                }
                // mover carro para a rua de manobra
                ObjetoCarro c = p->vetor[p->topo - 1];// guarda o carro que vai sair
                p->topo--;                        // pop do estacionamento
                rua.vetor[rua.topo++] = c;        // push na rua
            }

            // devolve os carros da rua
            while (rua.topo > 0) {
                if (p->topo >= 10) { /* tratar overflow do estacionamento */ break; }
                ObjetoCarro c = rua.vetor[rua.topo - 1];
                rua.topo--;                      // pop da rua
                p->vetor[p->topo++] = c;         // push de volta
            }
        
        }
    }
}

int main(){
    PilhaEstatica p;
    ObjetoCarro removido;

    inicializaPilha(&p);

    push(&p, 10);
    

    imprimirPilha(&p);

    pop(&p, &removido);
    printf("Removido: %d\n", removido.placa);

    imprimirPilha(&p);

    return 0;
}