#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"


int main() {
    // STRINGS - Vetor de Chars
    // Codificação UTF-8 -> Um caractere é definido por 2 chars 
    // (apenas usado para caracteres não ASCII)

    char string_estatica[100] = "Oi!";                                   // String estática
    // ['O', 'i', '\0']

    printf("%s\n", string_estatica);

    for (int i = 0; string_estatica[i] != '\0'; i++) {
        printf("%c", string_estatica[i]);
    }
    printf("\n");
    printf("Fim do FOR\n");

    char* string_dinamica = malloc(10 * sizeof(char));                   // String dinâmica

    // ESTRUTURA DE ARQUIVOS - Como a gente deve criar arquivos pra escrever a nossa própria LIB
    // Em linguagens como Python, basta criar um novo arquivo .py .
    // Depois é só usar uma diretiva de inclusão (import)

    // MAKEFILE
    // COMO CRIAR UMA LIB


    VetorInt meuVetor;
    VectorInt_init(&meuVetor);
    VectorInt_print(&meuVetor);
    VectorInt_push_back(&meuVetor, 12);
    VectorInt_push_back(&meuVetor, 13);
    VectorInt_print(&meuVetor);
    VectorInt_pop_back(&meuVetor);
    VectorInt_print(&meuVetor);


    return 0;
}