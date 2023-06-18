#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"  
#include "aviao.h"  
#include "assentos.h"
#include "geraTicket.h"  

int main() {

    struct Aviao avioes[5];
    preencherAvioes(avioes);

    int escolha, rodando = 1; 

    printf("Bem-vindo ao Sistema do Aeroporto\n");

    while (rodando == 1) {
        printf("\nQual operacao deseja realizar?\n");
        printf("-----------------------------\n");
        printf("1 - Cadastrar Cliente\n");
        printf("2 - Atualizar Cliente\n");
        printf("3 - Visualizar Cliente\n");
        printf("4 - Excluir cliente\n");
        printf("10 - Login cliente\n");
        printf("---------------------\n");
        printf("6 - Sistema de venda de passagens\n");
        printf("7 - Mostrar opcoes de Embarque/Desembarque\n");
        printf("8 - Comprar passagem\n");
        printf("9 - Gerar Ticket\n");
        printf("---------------------\n");
        printf("5 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                cadastraCliente();
                // gerarTicket();
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
            case 6:
                printf("Venda de assentos\n");
                assentosLivres();
                printf("Deseja comprar um lugar?\n");
                escolherAssento();
                assentosLivres();
                break;    
            case 7:
                printf("Embarque/Desembarque\n");
                
                int opcao;

                printf("Escolha uma opção:\n");
                printf("1. Embarque\n");
                printf("2. Desembarque\n");
                scanf("%d", &opcao);

                if (opcao == 1) {
                    mostrarOrigem(avioes);
                } else if (opcao == 2) {
                    mostrarDestino(avioes);
                } else {
                    printf("Opção inválida.\n");
                }
                break;
            case 8: {
                comprarPassagem(avioes);              
                }
                break;
            case 10: {
                loginCliente();              
                }
                break;
        }
    }

    return 0;
}
