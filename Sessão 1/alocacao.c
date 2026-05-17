#include <stdio.h>
#include <stdlib.h>     // Windows, Linux, Android, IOs, MacOS, BSD
#include <unistd.h>


int main() {
    // HEAP do Sistema Operacional
    // Espaço público e GRANDE, gerenciado pelo Sistema Operacional


    int *vetor = malloc(2 * sizeof(int));   // Vetor alocado na HEAP dos sistema

    vetor[0] = 2;
    vetor[1] = 3;
    
    int *temp = vetor;      // temp recebe o ENDEREÇO de vetor
    vetor = malloc(4 * sizeof(int));

    for (int i = 0; i < 2; i++) {
        vetor[i] = temp[i];
    }


    sleep(5);

    free(temp);
    temp = NULL;

    vetor[2] = 4;



    printf("Hello World!\n");
    printf("Valor 1: %d\n", vetor[0]);
    printf("Valor 2: %d\n", vetor[1]);
    printf("Valor 3: %d\n", vetor[2]);
    return 0;
}