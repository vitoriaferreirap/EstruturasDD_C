#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//define tamanho de N
#define N 100

//struct = registro
typedef struct {
  int x; //valor int que quero inserir na pilha dado de cada posicao
} Objeto; // impleenta nosso objeto

//Tipos de dados abstratos = armazena objeto
typedef struct {
  Objeto vetor[N];
  int topo; //indica quantos elementos existem na pilha
} PilhaEstatica;

void inciaPilha(PilhaEstatica *pilha){ //recebendo ponteiro como parametro
  pilha->topo = 0; //operador -> acessa o campo de uma estrutura através de um ponteiro.
}
bool estaVazia(PilhaEstatica *pilha){
    return (pilha -> topo == 0);
}
bool estaCheia(PilhaEstatica *pilha){
    return (pilha -> topo == N);
}
void push(PilhaEstatica *pilha, int x){ //empilha
    if(!estaCheia(pilha)){
        //o valor de topo recebe x?
        pilha->vetor[pilha->topo].x = x; //se nao esta cheia ponteiro aponta para proxima posicao
        pilha->topo++;
    }else{
      printf("Pilha cheia\n");
    }
}
void pop(PilhaEstatica *pilha, Objeto *obj){ //desempilha
    if(!estaVazia(pilha)){
      *obj = pilha->vetor[pilha->topo - 1];
      pilha->topo--;  // ultima posicao
    }else{
      printf("Pilha cheia!\n");
    }
}
int size(PilhaEstatica *pilha){
    return (pilha->topo); //estava na ultima posicao
}


void imprimirPilha(PilhaEstatica *pilha){
    int i;
    printf("Pilha = [ ");
    for (i = 0; i < pilha->topo;i++) {
      printf("%d ", pilha->vetor[i].x);
    }
    printf(" ]\n");
};
int tipoPilha(PilhaEstatica *pilha){
    int remocao = pilha->vetor[pilha->topo-1].x; // recebe topo - 1 , retirando de traz antes
    return remocao;
}

int main(){
  PilhaEstatica p; //variavel do tipo estrutura
  inciaPilha(&p);  // passando o endereco da variavel

  if(estaVazia(&p)){
    printf("Pilha Vazia\n");
  }

  int tamanho = size(&p);
  printf("Tamanho da pilha: %d\n", tamanho);

  int insercao[]={22, 13, 15, 45, 50, 17};
  for (int i = 0; i < 6; i++){
    push(&p, insercao[i]);
    imprimirPilha(&p);
  }

  int topo = tipoPilha(&p);
  printf("Topo da pilha: %d \n", topo);

  Objeto removido;
  pop(&p, &removido);
  printf("Valor removido: %d\n", removido);
  imprimirPilha(&p);

  //necessita atualizar o topo
  int novoTop = tipoPilha(&p);
  printf("Topo da pilha: %d \n", novoTop);

  return 0;
}
/*
 * int x; declara variavel inteira
 * int *ptr;  declara um ponteiro para um inteiro
 * ptr = &x;  faz o ponteiro apontar para o endereco de memoria de x - recupera
 * valor = *ptr; valor recebe conteudo armazenado no end para onde ptr aponta - valor de x
 */