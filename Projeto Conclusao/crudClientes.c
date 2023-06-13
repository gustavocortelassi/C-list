#include <stdio.h>
#include <string.h>

    typedef struct Pessoa {
        char nome[50];
        char sobrenome[50];
        int idade;
        char telefone[13];
        char cpf[11];
        char rg[9];
    } Pessoa;

    // cria o arquivo para ser utilizado como banco de dados
    FILE *arquivo;

void cadastraCliente(Pessoa *pessoa) {
    printf("\n== Cadastro de Cliente ==\n");

    // Solicita as informações do cliente
    printf("Nome: ");
    scanf("%s", pessoa->nome);
    printf("Sobrenome: ");
    scanf("%s", pessoa->sobrenome);
    printf("Idade: ");
    scanf("%d", &(pessoa->idade));
    printf("Telefone: ");
    scanf("%s", pessoa->telefone);
    printf("CPF: ");
    scanf("%s", pessoa->cpf);
    printf("RG: ");
    scanf("%s", pessoa->rg);

    // Abre o arquivo no modo de escrita
    arquivo = fopen("bancoDados.txt", "a");

    // Escreve as informações do cliente no arquivo
    fprintf(arquivo, "Nome: %s\n", pessoa->nome);
    fprintf(arquivo, "Sobrenome: %s\n", pessoa->sobrenome);
    fprintf(arquivo, "Idade: %d\n", pessoa->idade);
    fprintf(arquivo, "Telefone: %s\n", pessoa->telefone);
    fprintf(arquivo, "CPF: %s\n", pessoa->cpf);
    fprintf(arquivo, "RG: %s\n\n", pessoa->rg);

    // Fecha o arquivo
    fclose(arquivo);

    // Exibe mensagem de sucesso
    printf("Cliente cadastrado com sucesso!\n");
}


void atualizaCliente(Pessoa *pessoa) {
    printf("\n== Atualizar Cliente ==\n");

    // Solicita o CPF do cliente a ser atualizado
    printf("Informe o CPF do cliente que deseja atualizar: ");
    char CPFAutalizar[20];
    scanf("%s", CPFAutalizar);

    // Abre o arquivo original no modo de leitura e escrita
    arquivo = fopen("bancoDados.txt", "r+");

    // Abre um novo arquivo temporário
    FILE *arquivoTemp = fopen("temp.txt", "w");

    // Variável para verificar se o cliente foi encontrado
    int encontrado = 0;

    // fazer o resto do codigo aqui

    // Fecha os arquivos
    fclose(arquivo);
    fclose(arquivoTemp);

    if (encontrado) {
        // Remove o arquivo original
        remove("bancoDados.txt");

        // Renomeia o arquivo temporário para o nome original
        rename("temp.txt", "bancoDados.txt");

        printf("Cliente atualizado com sucesso!\n");
    } else {
        printf("Cliente não encontrado!\n");
    }
}


void visualizaCliente(Pessoa *pessoa) {
    printf("\n== Visualizar Clientes ==\n");

    // Abre o arquivo no modo de leitura
    arquivo = fopen("bancoDados.txt", "r");

    char linha[100];

    // Le cada linha do arquivo e exibe na tela
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }

    // Fecha o arquivo
    fclose(arquivo);
}

void excluiCliente(Pessoa *pessoa) {
    printf("\n== Excluir Cliente ==\n");

    // Solicita o CPF do cliente a ser excluído
    printf("Informe o CPF do cliente que deseja excluir: ");
    char CPFExcluir[20];
    scanf("%s", CPFExcluir);

    // Abre o arquivo original no modo de leitura
    arquivo = fopen("bancoDados.txt", "r+");

    // Abre um novo arquivo temporário para escrita
    FILE *arquivoTemp = fopen("temp.txt", "w");

    // int encontrado = 0;

    // Escreve os dados do arquivo original para o temporario, menos os dados a serem excluidos
    while (fread(pessoa, sizeof(Pessoa), 1, arquivo) == 1) {
        if (strcmp(CPFExcluir, pessoa->cpf) != 0) {
            fwrite(pessoa, sizeof(Pessoa), 1, arquivoTemp);
        } else {
            // encontrado = 1;
        }
    }  

    // Fecha os arquivos
    fclose(arquivo);
    fclose(arquivoTemp);

    remove("bancoDados.txt");

    // Renomeia o arquivo temporário para o nome original
    rename("temp.txt", "bancoDados.txt");

    printf("Cliente excluído com sucesso!\n");
}


int main() {
    Pessoa cliente;
    int escolha, rodando = 1;

    printf("Bem-vindo ao Sistema do Aeroporto\n");

    while (rodando == 1) {
        printf("\nQual operacao deseja realizar?\n");
        printf("-----------------------------\n");
        printf("1 - Cadastrar Cliente\n");
        printf("2 - Atualizar Cliente\n");
        printf("3 - Visualizar Cliente\n");
        printf("4 - Excluir cliente\n");
        printf("5 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                cadastraCliente(&cliente);
                break;
            case 2:
                atualizaCliente(&cliente);
                break;
            case 3:
                visualizaCliente(&cliente);
                break;
            case 4:
                excluiCliente(&cliente);
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

    return 0;
}

