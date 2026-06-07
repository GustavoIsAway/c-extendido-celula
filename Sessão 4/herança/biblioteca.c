#include "biblioteca.h"
#include <stdio.h>
#include <stdlib.h>


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




struct VetorFloat {
    VetorInt super;     // É a Superclasse
    float dados[100];
    int total_dados;
};


VetorFloat* VectorFloat_init() {
    VetorFloat* newVec = malloc(sizeof(VetorFloat));
    newVec->total_dados = 0;
    return newVec;
}

void VectorFloat_push_back(VetorFloat *self, float valor) {
    if (self->total_dados < 100) {
        self->dados[self->total_dados] = valor;
        self->total_dados++;
    }
}


void VectorFloat_pop_back(VetorFloat *self) {
    if (self->total_dados == 0)
        return;

    self->total_dados--;
}

void VectorFloat_print(VetorFloat *self) {
    printf("[");
    for (int i = 0; i < self->total_dados; i++) {
        if (i < self->total_dados - 1)
            printf("%f, ", self->dados[i]);
        else 
            printf("%f", self->dados[i]);
    }
    printf("]\n");
}

VetorInt* VectorFloat_get_super(VetorFloat *self) { // Getter da superclasse
    return &self->super;
}