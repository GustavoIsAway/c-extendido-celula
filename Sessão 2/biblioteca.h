#ifndef BIBLIOTECA_H // IF NOT DEFINED 
#define BIBLIOTECA_H

typedef struct {
    int dados[100];
    int total_dados;
} VetorInt ;


void VectorInt_init(VetorInt *self);
void VectorInt_push_back(VetorInt *self, int valor);
void VectorInt_pop_back(VetorInt *self);
void VectorInt_print(VetorInt *self);



#endif