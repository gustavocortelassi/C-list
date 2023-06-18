#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aviao {
    char modelo[20];
    char destino[20];
    char origem[20];
    char horarios[3][20];
};

int main() {
    struct Aviao avioes[5];

    // Definindo valores para o vetor de avioes
    strcpy(avioes[0].modelo, "aviao 01");
    strcpy(avioes[0].destino, "São Paulo");
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

    return 0;
}
