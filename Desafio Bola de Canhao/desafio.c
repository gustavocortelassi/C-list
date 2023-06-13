#include <stdio.h>

int main() {

    int num_bolas, i, x;
    int soma = 0;

    printf("Entre com o numero de bolas da lateral do tetraedro: ");
    scanf("%i", &num_bolas);

    for (i = num_bolas; i >= 1; i--) { // processa as fileiras
        for (x = 1; x <= i; x++) { // processa as bolas em cada fileira
            soma += x;
        }
    }

    printf("A soma de todas as bolas eh: %i", soma);
    
}
