#include <stdio.h>

int main(){

    int G, C, X, Z, E, N, D;
    int Y;

    printf("Entre com o ano que se deseja calcular a data da pascoa: ");
    scanf("%i", &Y);

    G = (Y % 19) + 1;
    C = (Y / 100) + 1;
    X = ((3 * C) / 4) - 12;
    Z = ((8 * C + 5) / 25) - 5;
    E = ((11 * G + 20 + Z - X) % 30);

    if((E == 25 && G > 11) || (E == 24)){
        E += 1;
    }

    N = 44 - E;

    if(N < 21){
        N = N + 30;
    }

    D = ((5 * Y) / 4) - (X + 10);
    N = (N + 7) - ((D + N) % 7);

    if(N > 31){
        printf("Pascoa: %i de abril de %i.", (N - 31), Y);
    } else {
        printf("Pascoa: %i de marco de %i.", N, Y);  
    }
}