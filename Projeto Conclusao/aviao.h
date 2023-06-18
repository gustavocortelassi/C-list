#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aviao {
    char modelo[20];
    char destino[20];
    char origem[20];
    char horarios[3][20];
};

struct Passagem {
    char origem[20];
    char destino[20];
    char modelo[20];
    char horario[20];
};

void preencherAvioes(struct Aviao* avioes) {
    strcpy(avioes[0].modelo, "aviao 01");
    strcpy(avioes[0].destino, "Sao Paulo");
    strcpy(avioes[0].origem, "Rio de Janeiro");
    strcpy(avioes[0].horarios[0], "08:00");
    strcpy(avioes[0].horarios[1], "14:00");
    strcpy(avioes[0].horarios[2], "22:00");

    strcpy(avioes[1].modelo, "aviao 02");
    strcpy(avioes[1].destino, "Rio de Janeiro");
    strcpy(avioes[1].origem, "São Paulo");
    strcpy(avioes[1].horarios[0], "08:00");
    strcpy(avioes[1].horarios[1], "14:00");
    strcpy(avioes[1].horarios[2], "22:00");

    strcpy(avioes[2].modelo, "aviao 03");
    strcpy(avioes[2].destino, "Belo Horizonte");
    strcpy(avioes[2].origem, "São Paulo");
    strcpy(avioes[2].horarios[0], "08:00");
    strcpy(avioes[2].horarios[1], "14:00");
    strcpy(avioes[2].horarios[2], "22:00");

    strcpy(avioes[3].modelo, "aviao 04");
    strcpy(avioes[3].destino, "Recife");
    strcpy(avioes[3].origem, "São Paulo");
    strcpy(avioes[3].horarios[0], "08:00");
    strcpy(avioes[3].horarios[1], "14:00");
    strcpy(avioes[3].horarios[2], "22:00");

    strcpy(avioes[4].modelo, "aviao 05");
    strcpy(avioes[4].destino, "Foz");
    strcpy(avioes[4].origem, "São Paulo");
    strcpy(avioes[4].horarios[0], "08:00");
    strcpy(avioes[4].horarios[1], "14:00");
    strcpy(avioes[4].horarios[2], "22:00");
}

void mostrarOrigem(struct Aviao* avioes) {
    int i, escolha;

    printf("Informe o local de embarque:\n");
    printf("1: São Paulo\n");
    printf("2: Rio de Janeiro\n");

    scanf("%i", &escolha);

    if (escolha != 1) {
        printf("Opção de embarque inválida.\n");
        return;
    }

    printf("Destinos disponíveis a partir de São Paulo:\n");

    for (i = 0; i < 5; i++) {
        if (strcmp(avioes[i].origem, "São Paulo") == 0) {
            printf("Destino: %s\n", avioes[i].destino);
            printf("Modelo: %s\n", avioes[i].modelo);
            printf("Horários: %s, %s, %s\n", avioes[i].horarios[0], avioes[i].horarios[1], avioes[i].horarios[2]);
        }
    }
}


void mostrarDestino(struct Aviao* avioes) {
    int escolha, i;

    printf("Informe o número do destino desejado:\n");
    printf("1: São Paulo\n");
    printf("2: Rio de Janeiro\n");
    printf("3: Belo Horizonte\n");
    printf("4: Recife\n");
    printf("5: Foz\n");
    scanf("%d", &escolha);

    for (i = 0; i < 5; i++) {
        if (i + 1 == escolha) {
            printf("Origem: %s\n", avioes[i].origem);
            printf("Destino: %s\n", avioes[i].destino);
            printf("Modelo: %s\n", avioes[i].modelo);
            printf("Horários: %s, %s, %s\n", avioes[i].horarios[0], avioes[i].horarios[1], avioes[i].horarios[2]);
        }
    }

}

void comprarPassagem(struct Aviao* avioes) {
    int escolha2;
    struct Passagem passagem;

    printf("Compra de passagem\n");
    printf("Deseja comprar com base na origem ou destino? 1 - origem, 2 - destino: ");
    scanf("%d", &escolha2);

    if (escolha2 == 1) {
        mostrarOrigem(avioes);

        printf("Informe o número do destino desejado: ");
        int escolha;
        scanf("%d", &escolha);

        if (escolha >= 1 && escolha <= 5) {
            strcpy(passagem.origem, "São Paulo");
            strcpy(passagem.destino, avioes[escolha - 1].destino);
            strcpy(passagem.modelo, avioes[escolha - 1].modelo);
            strcpy(passagem.horario, avioes[escolha - 1].horarios[0]);

            printf("Passagem comprada com sucesso!\n");
        } else {
            printf("Opção de destino inválida.\n");
        }
    } else if (escolha2 == 2) {
        mostrarDestino(avioes);

        printf("Informe o número do destino desejado: ");
        int escolha;
        scanf("%d", &escolha);

        if (escolha >= 1 && escolha <= 5) {
            strcpy(passagem.origem, avioes[escolha - 1].origem);
            strcpy(passagem.destino, avioes[escolha - 1].destino);
            strcpy(passagem.modelo, avioes[escolha - 1].modelo);
            strcpy(passagem.horario, avioes[escolha - 1].horarios[0]);

            printf("Passagem comprada com sucesso!\n");
        } else {
            printf("Opção de destino inválida.\n");
        }
    } else {
        printf("Opção inválida.\n");
    }

    printf("Detalhes da passagem:\n");
    printf("Origem: %s\n", passagem.origem);
    printf("Destino: %s\n", passagem.destino);
    printf("Modelo: %s\n", passagem.modelo);
    printf("Horário: %s\n", passagem.horario);
}



