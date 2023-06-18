#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include "aviao.h"

int main(){
    int escolha, rodando = 1;

        printf("Bem-vindo ao Sistema do Aeroporto\n");

        while (rodando == 1) {
            printf("\nQual operacao deseja realizar?\n");
            printf("-----------------------------\n");
            printf("1 - Cadastrar Cliente\n");
            printf("2 - Atualizar Cliente\n");
            printf("3 - Visualizar Cliente\n");
            printf("4 - Excluir cliente\n");
            printf("6 - Sistema de venda de passagens\n");
            printf("5 - Sair\n");
            printf("Opcao: ");
            scanf("%d", &escolha);

            switch (escolha) {
                case 1:
                    cadastraCliente();
                    break;
                case 2:
                    atualizaCliente();
                    break;
                case 3:
                    visualizaCliente();
                    break;
                case 4:
                    excluiCliente();
                    break;
                case 5:
                    printf("Saindo do programa...\n");
                    rodando = 0; 
                    break;
                default:
                    printf("Opcao inválida. Tente novamente.\n");
                    break;
            }
        }
}