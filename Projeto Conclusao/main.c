//     CONSIDERAÇÕES DE COMO UTILIZAR ESSE SISTEMA 
//
// 1 - A parte do CRUD está funcionando 100%.   
// 2 - Primeiramente deve ser feito o cadastro. Após isso, pode seguir
//     as outras operações do CRUD.
// 3 - Para prosseguir para a "visão do cliente", é essencial que faça
//     o "login cliente", na operação 10.
// 4 - Após ser feito o login, pode prosseguir para a opção 7, para 
//     visualizar os voos disponiveis, ou opção 6, para comprar o/os assento/s.
// 5 - A escolha do assento deve ser feita antes de comprar a passagem.
// 6 - Após comprar o assento, prosseguir para o case 8, e realizar as operações
// 7 - Para escolher o destino/origem, ele vai solicitar o numero, coloque o numero do aviao
//     Ex: FOZ: aviao 05 - digitar 5
// 8 - Depois de comprar, o arquivo compra.txt estará devidamente preenchido com as 
//     informações

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "clientes.h"  
#include "aviao.h"  
#include "assentos.h"

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
    printf("6 - Sistema de venda de assentos\n");
    printf("7 - Mostrar opcoes de Embarque/Desembarque\n");
    printf("8 - Comprar passagem\n");
    printf("---------------------\n");
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

            printf("Escolha uma opcao:\n");
            printf("1. Embarque\n");
            printf("2. Desembarque\n");
            scanf("%d", &opcao);

            if (opcao == 1) {
                mostrarOrigem(avioes);
            } else if (opcao == 2) {
                mostrarDestino(avioes);
            } else {
                printf("Opcao invalida.\n");
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
