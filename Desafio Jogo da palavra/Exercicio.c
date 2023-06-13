#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    while (1){
        char palavra[5][10] = {
            "computador",
            "celular",
            "mouse",
            "teclado",
            "desktop"
            };

        char matriz[5][33] = {
            "|  |  |  |  |  |  |  |  |  |  |\n",
            "|  |  |  |  |  |  |  | *| *| *|\n",
            "|  |  |  |  |  | *| *| *| *| *|\n",
            "|  |  |  |  |  |  |  | *| *| *|\n",
            "|  |  |  |  |  |  |  | *| *| *|\n",
        };

        char letra[10];

        int i, tentativasComp = 0, tentativasCel = 0, tentativasMouse = 0, tentativasTeclado = 0, tentativasDesktop = 0, escolha, jogarNovamente = 0;

        printf("-----Bem vindo ao Word Play-----\n");
        printf("Dicas:\n");
        printf("1 - Palavra: computador\n");
        printf("2 - Palavra: celular\n");
        printf("3 - Palavra: mouse\n");
        printf("4 - Palavra: teclado\n");
        printf("5 - Palavra: desktop\n");
        printf("----------------------------------\n");
        printf("Informe qual palavra deseja tentar adivinhar: \n");
        printf("----------------------------------\n");
        scanf("%i", &escolha);
        getchar(); // Limpar o caractere de nova linha deixado pelo scanf

        // Imprime a matriz
        for (i = 0; i < 5; i++){
            printf("%s", matriz[i]);
        }

        switch (escolha){
        case 1:
            if (tentativasComp != 2){ // verifica se ainda tem tentativas
                for (i = 0; i < 10; i++){
                    printf("Informe a letra: ");
                    fgets(letra, sizeof(letra), stdin);
                    if (letra[0] == palavra[0][i]){ // confere se a letra digitada é igual a da palavra na posição i
                        printf("Voce acertou!\n");
                        matriz[0][3 + (i * 3)] = letra[0]; // atualiza a posição na matriz com a letra
                    } else {
                        printf("Voce errou!\n");
                        tentativasComp = 2;
                        break;
                    }
                }
            }
            break;

        case 2:
            if (tentativasCel != 2){
                for (i = 0; i < 7; i++){
                    printf("Informe a letra: ");
                    fgets(letra, sizeof(letra), stdin);
                    if (letra[0] == palavra[1][i]){
                        printf("Voce acertou!\n");
                        matriz[1][3 + (i * 3)] = letra[0];
                    } else {
                        printf("Voce errou!\n");
                        tentativasCel = 2;
                        break;
                    }
                }
            }
            break;

        case 3:
            if (tentativasMouse != 2){
                for (i = 0; i < 5; i++){
                    printf("Informe a letra: ");
                    fgets(letra, sizeof(letra), stdin);
                    if (letra[0] == palavra[2][i]){
                        printf("Voce acertou!\n");
                        matriz[2][3 + (i * 3)] = letra[0];
                    } else {
                        printf("Voce errou!\n");
                        tentativasMouse = 2;
                        break;
                    }
                }
            }
            break;

        case 4:
            if (tentativasTeclado != 2){
                for (i = 0; i < 7; i++){
                    printf("Informe a letra: ");
                    fgets(letra, sizeof(letra), stdin);
                    if (letra[0] == palavra[3][i]){
                        printf("Voce acertou!\n");
                        matriz[3][3 + (i * 3)] = letra[0];
                    } else {
                        printf("Voce errou!\n");
                        tentativasTeclado = 2;
                        break;
                    }
                }
            }
            break;

        case 5:
            if (tentativasDesktop != 2){
                for (i = 0; i < 7; i++){
                    printf("Informe a letra: ");
                    fgets(letra, sizeof(letra), stdin);
                    if (letra[0] == palavra[4][i]){
                        printf("Voce acertou!\n");
                        matriz[4][3 + (i * 3)] = letra[0];
                    }
                    else {
                        printf("Voce errou!\n");
                        tentativasDesktop = 2;
                        break;
                    }
                }
            }
            break;

        default:
            break;
        }

        // mostra a matriz nova com as respostas
        printf("\nMatriz Atualizada:\n");
        for (i = 0; i < 5; i++){
            printf("%s", matriz[i]);
        }

        // ver se o jogador quer jogar novamente
        printf("Deseja jogar novamente? (1 - Sim, 0 - Nao): ");
        scanf("%d", &jogarNovamente);
        getchar(); // limpa o caractere de nova linha deixado pelo scanf

        if (!jogarNovamente){
            break; // sai do loop e encerra o programa
        }

        printf("\n\n");
    }
    return 0;
}
