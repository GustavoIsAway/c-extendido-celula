#include <stdio.h>


struct Nome {
    int valorA;
    float valorB;
};


typedef struct {
    int valorA;
    float valorB;
    char valorC;
} NomeDois;


typedef struct {
    int vetor[100];
    int tamanho;
} Vector;


int main() {
    // VARIÁVEIS
    int inteiro = 0;                        // 4 bytes (32 bits)
    char caractere = 65;                    // 1 byte (8 bits)
    float ponto_flutuante = 0.2f;           // 4 bytes (32 bits)
    double ponto_flutuante_extendido = 0.4; // 8 bytes (64 bits)


    // VARIÁVEIS A NÍVEL DE MÁQUINA (64 bits) 
    // Palavra = Formato padrão do processador (32 bits)
    // Byte = "Geralmente" equivale a 8 bits
    

    // STRUCTS
    struct Nome minha_struct = {
        .valorA = 14,
        .valorB = 69.69f
    };

    NomeDois minha_nova_struct = {
        .valorA = 22,
        .valorB = 67.67f,
        .valorC = 'C'
    };

    // PONTEIROS E VETORES
    int vetor[50] = { 0 };           // Vetor estático
    // Aloque no espaço do programa (pilha de execução) 50 espaços para inteiros (4 bytes * 50)
    // Aponte para o começo desse espaço e chame esse ponteiro de "vetor"
    // Inicialize tudo em 0


    for (int i = 0; i < 50; i++) {
        printf("%d, ", vetor[i]);    // Leitura inbounds (dentro de alcance)
    }
    

    int* meuPonteiro = &inteiro;     // Variável que contém endereços
                                     // Endereço da memória de "inteiro"
    *meuPonteiro = 2;                // Modifica dado no endereço apontado
    meuPonteiro = NULL;              // Troca o valor de meuPonteiro = 0

    printf("\n");

    // ALOCAÇÃO DE MEMÓRIA

    printf("Hello World!\n");
    printf("Valor do inteiro: %d\n", inteiro);
    printf("Valor do char: %c\n", caractere);
    printf("Valor do float: %f\n", ponto_flutuante);
    printf("Valor do double: %lf\n", ponto_flutuante_extendido);
    printf("------------------------\n");
    printf("Valor A: %d\n", minha_struct.valorA);
    printf("Valor B: %f\n", minha_struct.valorB);
    printf("Novo Valor A: %d\n", minha_nova_struct.valorA);
    printf("Novo Valor B: %f\n", minha_nova_struct.valorB);
    printf("Novo Valor C: %c\n", minha_nova_struct.valorC);
    printf("------------------------\n");
    printf("Primeiro Elemento do Vetor: %d\n", *vetor);
    printf("Endereço do Vetor: %p\n", vetor);



    return 0;
}