#include <stdio.h>
#include "biblioteca.h"


int main() {
    VetorInt meuVetor;  // De fato tem conteúdo (stack)
    VetorFloat* meuVetorFloat = VectorFloat_init();  // Todo ponteiro tem tamanho igual à palavra da arquitetura (32 bits)

    printf("===OPERAÇÕES COM VECTORINT===\n");
    VectorInt_print(&meuVetor);
    VectorInt_push_back(&meuVetor, 12);
    VectorInt_push_back(&meuVetor, 13);
    VectorInt_print(&meuVetor);
    VectorInt_pop_back(&meuVetor);
    VectorInt_print(&meuVetor);

    printf("===OPERAÇÕES COM VECTORFLOAT===\n");
    VectorFloat_print(meuVetorFloat);
    VectorFloat_push_back(meuVetorFloat, 34.69f);
    VectorFloat_print(meuVetorFloat);



    return 0;
}