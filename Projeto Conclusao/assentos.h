#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Assentos {
    int valor;
    int numero;
    char classe;
    int status;
};

struct Assentos assento[50];

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
            printf("  ");
        }

        if ((i + 1) % 4 == 0) {
            printf("\n");
        }
    }
}

void escolherAssento() {
    char resposta;
    int numeroAssento;

    do {
        printf("Digite o numero do assento desejado: ");
        scanf("%d", &numeroAssento);

        // Verificar se o numero do assento e valido
        if (numeroAssento < 1 || numeroAssento > 50) {
            printf("Numero de assento invalido.\n");
            continue;
        }

        // Verificar se o assento ja esta ocupado
        if (assento[numeroAssento - 1].status == 1) {
            printf("O assento %d ja esta ocupado.\n", numeroAssento);
            continue;
        }

        // Vender o assento
        assento[numeroAssento - 1].status = 1;
        assento[numeroAssento - 1].numero = numeroAssento;

        printf("Assento %d escolhido com sucesso.\n", numeroAssento);

        printf("Deseja escolher outro assento? (S/N): ");
        scanf(" %c", &resposta);
    } while (resposta == 'S' || resposta == 's');

    // Adicionar a secao de preco do assento
    int precoAssento;

    printf("Digite o preco do assento: ");
    scanf("%d", &precoAssento);

    // Armazenar o preco do assento na estrutura
    assento[numeroAssento - 1].valor = precoAssento;

    FILE *arquivo;
    arquivo = fopen("compra.txt", "a");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(arquivo, "Assento Comprado: %d\n", numeroAssento);
    fprintf(arquivo, "Preco do Assento: %d\n", precoAssento);

    fclose(arquivo);
}
