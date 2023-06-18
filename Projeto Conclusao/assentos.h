#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Assentos {
    int valor;
    int numero;
    char classe;
    int status;
} assento[50];

void assentosLivres() {
    printf("Assentos Livres:\n");
    printf("Frente do aviao:\n");

    for (int i = 0; i < 50; i++) {
        if (assento[i].status == 0) {
            printf("[ ]");  
        } else {
            printf("[X]");  
        }

        if ((i + 1) % 2 == 0) {
            printf("  ");  // Espaço para separar as fileiras
        }

        // Quebra de linha após a impressão de uma fileira completa
        if ((i + 1) % 4 == 0) {
            printf("\n");
        }
    }
}

void escolherAssento() {
    char resposta;
    int numeroAssento;

    do {
        printf("Digite o número do assento desejado: ");
        scanf("%d", &numeroAssento);

        // Verificar se o número do assento é válido
        if (numeroAssento < 1 || numeroAssento > 50) {
            printf("Número de assento inválido.\n");
            continue;
        }

        // Verificar se o assento já está ocupado
        if (assento[numeroAssento - 1].status == 1) {
            printf("O assento %d já está ocupado.\n", numeroAssento);
            continue;
        }

        // Vender o assento
        assento[numeroAssento - 1].status = 1;
        assento[numeroAssento - 1].numero = numeroAssento;

        printf("Assento %d escolhido com sucesso.\n", numeroAssento);

        printf("Deseja escolher outro assento? (S/N): ");
        scanf(" %c", &resposta);
    } while (resposta == 'S' || resposta == 's');
}


