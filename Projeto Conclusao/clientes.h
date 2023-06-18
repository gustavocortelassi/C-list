#include <stdio.h>
#include <stdlib.h>

struct Pessoa {
            char nome[50];
            char sobrenome[50];
            int idade;
            char telefone[13];
            char cpf[11];
            char rg[9];
} cliente[10];

void cadastraCliente() {
    int i = 0;
    char opcao;

    do {
        printf("Cadastrar Cliente: \n");
        printf("Nome: ");
        gets(cliente[i].nome);

        printf("Sobrenome: ");
        gets(cliente[i].sobrenome);

        printf("Idade: ");
        scanf("%d", &cliente[i].idade);
        getchar(); 

        printf("Telefone: ");
        gets(cliente[i].telefone);

        printf("CPF: ");
        gets(cliente[i].cpf);

        printf("RG: ");
        gets(cliente[i].rg);

        printf("Deseja cadastrar outro cliente? (S/N): ");
        scanf(" %c", &opcao);
        getchar(); 

        i++;
    } while ((opcao == 'S' || opcao == 's') && i < 10);
}

void atualizaCliente() {
    int i;

    printf("Digite o índice do cliente que deseja atualizar (1-10): ");
    scanf("%d", &i);
    getchar();

    i--;

    if (i >= 0 && i < 10) {
        printf("Atualizando informações do cliente %d\n", i + 1);
        printf("Nome: ");
        gets(cliente[i].nome);

        printf("Sobrenome: ");
        gets(cliente[i].sobrenome);

        printf("Idade: ");
        scanf("%d", &cliente[i].idade);
        getchar();

        printf("Telefone: ");
        gets(cliente[i].telefone);

        printf("CPF: ");
        gets(cliente[i].cpf);

        printf("RG: ");
        gets(cliente[i].rg);

        printf("Informações do cliente atualizadas com sucesso.\n");
    } else {
        printf("Índice inválido.\n");
    }
}



void visualizaCliente(){
    
    int i;

    printf("Clientes cadastrados:\n");
    for (i = 0; i < 10; i++) {
        printf("Cliente %d:\n", i + 1);
        printf("Nome: %s\n", cliente[i].nome);
        printf("Sobrenome: %s\n", cliente[i].sobrenome);
        printf("Idade: %d\n", cliente[i].idade);
        printf("Telefone: %s\n", cliente[i].telefone);
        printf("CPF: %s\n", cliente[i].cpf);
        printf("RG: %s\n", cliente[i].rg);
        printf("\n");
    }
}

void excluiCliente() {
    int i;

    printf("Digite o índice do cliente que deseja excluir (1-10): ");
    scanf("%d", &i);
    getchar();

    i--;

    if (i >= 0 && i < 10) {
        printf("Excluindo cliente %d\n", i + 1);

        for (int j = i; j < 9; j++) {
            cliente[j] = cliente[j + 1];
        }

        strcpy(cliente[9].nome, "");
        strcpy(cliente[9].sobrenome, "");
        cliente[9].idade = 0;
        strcpy(cliente[9].telefone, "");
        strcpy(cliente[9].cpf, "");
        strcpy(cliente[9].rg, "");

        printf("Cliente excluído com sucesso.\n");
    } else {
        printf("Índice inválido.\n");
    }
}