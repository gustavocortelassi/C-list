#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    while (1) {
        char palavra[5][10] = {
            "computador",
            "celular",
            "mouse",
            "teclado",
            "notebook"
        };

        char matriz[5][33] = {
            "|  |  |  |  |  |  |  |  |  |  |\n",
            "|  |  |  |  |  |  |  | *| *| *|\n",
            "|  |  |  |  |  | *| *| *| *| *|\n",
            "|  |  |  |  |  |  |  | *| *| *|\n",
            "|  |  |  |  |  |  |  |  | *| *|\n",
        };

        char letra[10];

        int i, escolha, jogarNovamente = 0;

        printf("-----Bem vindo ao Word Play-----\n");
        printf("Dicas:\n");
        printf("1 - Palavra: Conjunto de componentes eletrônicos capaz de executar variados tipos de algoritmos e tratamento de informações. Máquina que realiza calculos\n");
        printf("2 - Palavra: Aparelho portátil com autonomia energética, que funciona em radiofrequência e permite efectuar ligações telefónicas\n");
        printf("3 - Palavra: Periférico do computador. É a parte que no permite interagir com os objetos que aparecem na tela através de um cursor\n");
        printf("4 - Palavra: Periférico/dispositivo que apresenta o conjunto das teclas de diversos aparelhos, máquinas e instrumentos.\n");
        printf("5 - Palavra: Computador pessoal que pode ser transportado com facilidade\n");
        printf("----------------------------------\n");
        printf("Informe qual palavra deseja tentar adivinhar: \n");
        printf("----------------------------------\n");
        scanf("%i", &escolha);
        getchar(); 

        
        for (i = 0; i < 5; i++) {
            printf("%s", matriz[i]);
        }

        int tamanhoPalavra = strlen(palavra[escolha - 1]); // verifica o tamanho

        for (i = 0; i < tamanhoPalavra; i++) {
            printf("Informe a letra: ");
            fgets(letra, sizeof(letra), stdin); // armazena e le o tamanho para que nao leia mais
            letra[strcspn(letra, "\n")] = '\0'; // remove o caractere lido pelo fgets

            int acertou = 0;
            for (int j = 0; j < tamanhoPalavra; j++) {
                if (letra[0] == palavra[escolha - 1][j]) {
                    acertou = 1;
                    matriz[escolha - 1][3 + (j * 3)] = letra[0]; // atualiza a posição na matriz com a letra
                }
            }

            if (acertou) {
                printf("Voce acertou!\n");
            } else {
                printf("Voce errou!\n");
                break; 
            }
        }

        // mostra a matriz nova 
        printf("\nMatriz Atualizada:\n");
        for (i = 0; i < 5; i++) {
            printf("%s", matriz[i]);
        }

        // ver se o jogador quer jogar novamente
        printf("Deseja jogar novamente? (1 - Sim, 0 - Nao): ");
        scanf("%d", &jogarNovamente);
        getchar(); 

        if (!jogarNovamente) {
            break; 
        }

        printf("\n\n");
    }
    return 0;
}
