#include <stdio.h>
#include "biblioteca.h"


int main() {
    VetorFloat* meuVetorFloat = VectorFloat_init();  // Todo ponteiro tem tamanho igual à palavra da arquitetura (32 bits)

    printf("===OPERAÇÕES COM VECTORINT===\n");
    VetorInt* minha_superclasse = VectorFloat_get_super(meuVetorFloat);

    VectorInt_print(minha_superclasse);
    VectorInt_push_back(minha_superclasse, 12);
    VectorInt_push_back(minha_superclasse, 13);
    VectorInt_print(minha_superclasse);
    VectorInt_pop_back(minha_superclasse);
    VectorInt_print(minha_superclasse);

    printf("===OPERAÇÕES COM VECTORFLOAT===\n");
    VectorFloat_print(meuVetorFloat);
    VectorFloat_push_back(meuVetorFloat, 34.65f);
    VectorFloat_print(meuVetorFloat);



    return 0;
}