#include "biblioteca.h"
#include <stdio.h>
#include <stdlib.h>


VetorInt pool_vec_int[1024];
int pool_vec_max_obj = 0;


int soma_todos(int vetor[], int size);

typedef enum {
    OK,                 // tem tamanho de um inteiro 0
    ERRO,               // 1
    ERRO_DE_COMPILACAO, // 2
} Erros;

Erros checar_fgets();

int main() {
    // FGETS

    char buff_inteiro[10];
    char buff_float[10];
    char buff_chars[10];

    fgets(buff_inteiro, 10, stdin);   // Sempre grava dados em string/vetor de chars    
    fgets(buff_float, 10, stdin);
    fgets(buff_chars, 10, stdin);

    
    // CONVERSÃO DE DADOS
    double meu_double = atof(buff_float);
    int meu_inteiro = atoi(buff_inteiro);

    printf("Meu double eh: %lf\n", meu_double);
    printf("Meu inteiro eh: %d\n", meu_inteiro);
    printf("Minha string eh: %s\n", buff_chars);


    // sscanf
    char string_de_dados[20] = "14 14.677 99";
    int inteiro_da_string;
    double double_da_string;
    long long_da_string;
    unsigned int inteiro_sem_sinal = 0;

    sscanf(string_de_dados, "%d %lf %li", 
        &inteiro_da_string, 
        &double_da_string, 
        &long_da_string);

    inteiro_da_string = (int) inteiro_sem_sinal;    // Cast de unsigned em variável signed
    

    printf("Meu double eh: %lf\n", double_da_string);
    printf("Meu float eh: %f\n", (float) double_da_string);
    printf("Meu inteiro eh: %d\n", inteiro_da_string);
    printf("Minha string eh: %li\n", long_da_string);


    // snprintf
    snprintf(string_de_dados, 20, "%f %d %li", (float)double_da_string, inteiro_da_string, long_da_string);

    printf("Nova string de dados: %s\n", string_de_dados);


    // Vetores em Funções
    int vetor_inteiros[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    printf("Tamanho do Vetor: %d\n", (int) (sizeof(vetor_inteiros) / sizeof(vetor_inteiros[0])));
    printf("Soma de todos os valores do vetor: %d\n", soma_todos(vetor_inteiros, 10));
    
    Erros check = checar_fgets();
    if (check == OK) {
        printf("O fgets deu certo!\n");
    } else if (check == ERRO) {
        printf("O fgets deu errado!\n");
    }











    // Pool de objetos

    
    return 0;
}


int soma_todos(int* vetor, int size) {
    int soma_total = 0;
    vetor[0] = 10;

    for (int i = 0; i < size; i++) {
        soma_total += vetor[i];
    }

    return soma_total;
}

Erros checar_fgets() {
    char buffer[10];
    if (fgets(buffer, 10, stdin)) {
        return OK;
    } else {
        return ERRO;
    }
}