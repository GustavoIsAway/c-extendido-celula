#include "biblioteca.h"
#include <stdio.h>


void VectorInt_init(VetorInt *self) {
    self->total_dados = 0;
    
    for (int i = 0; i < 100; i++){
        self->dados[i] = 0;
    }
}

// Coloca dado no final do vetor
void VectorInt_push_back(VetorInt *self, int valor) {
    if (self->total_dados < 100) {
        self->dados[self->total_dados] = valor;
        self->total_dados++;
    }
}


void VectorInt_pop_back(VetorInt *self) {
    if (self->total_dados == 0)
        return;

    self->total_dados--;
}


void VectorInt_print(VetorInt *self) {
    printf("[");
    for (int i = 0; i < self->total_dados; i++) {
        if (i < self->total_dados - 1)
            printf("%d, ", self->dados[i]);
        else 
            printf("%d", self->dados[i]);
    }
    printf("]\n");
}