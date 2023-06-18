#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"  
#include "aviao.h"  
#include "assentos.h"


void gerarTicket(){
    FILE *arquivo;
    arquivo = fopen("compra.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fclose(arquivo);
}