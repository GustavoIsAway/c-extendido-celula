#ifndef BIBLIOTECA_H // IF NOT DEFINED 
#define BIBLIOTECA_H

// Classe Pública
typedef struct {
    int dados[100];
    int total_dados;
} VetorInt ;


// Classe Privada
typedef struct VetorFloat VetorFloat;   // Struct Opaca - impossível de ver através dela


void VectorInt_init(VetorInt *self);
void VectorInt_push_back(VetorInt *self, int valor);
void VectorInt_pop_back(VetorInt *self);
void VectorInt_print(VetorInt *self);

VetorFloat* VectorFloat_init();
void VectorFloat_push_back(VetorFloat *self, float valor);
void VectorFloat_pop_back(VetorFloat *self);
void VectorFloat_print(VetorFloat *self);


#endif