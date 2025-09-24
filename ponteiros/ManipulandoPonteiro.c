#include <stdio.h>

int main(){

    //declarando variavel
    int var = 15;
    //declarando ponteiro
    int *ponteiro;
    //ponteiro recebendo endereco de variavel
    ponteiro = &var;

    printf("valor da var: %d\n", var);
    printf("endereco da var: %p\n", (void*)&var);

    printf("conteudo apontado pelo ponteiro: %d\n", *ponteiro);
    printf("endereco apontado pelo ponteiro: %p\n", (void*)ponteiro);

    printf("endereco do ponteiro: %p\n", (void*)&ponteiro);
    return 0;
}