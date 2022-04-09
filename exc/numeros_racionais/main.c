#include <stdio.h>
#include "rac.h"

int main()
{
    int num;
    int dem;

    Fracao *frac1;
    Fracao *frac2;

    Fracao *soma;
    Fracao *produto;

    puts("Escreva a primeira fração: ");
    printf("Numerador: ");
    scanf("%d", &num);
    printf("Denominador: ");
    scanf("%d", &dem);

    frac1 = create_frac(num, dem);

    puts("Escreva a segunda fração: ");
    printf("Numerador: ");
    scanf("%d", &num);
    printf("Denominador: ");
    scanf("%d", &dem);

    frac2 = create_frac(num, dem);

    if (equal_test(frac1, frac2) == 1)
        puts("\nAs frações são iguais!");
    else
        puts("\nAs frações são diferentes!");

    soma = soma_frac(frac1, frac2);
    produto = mult_frac(frac1, frac2);

    puts("\nSoma das frações: ");
    show_frac(soma);

    puts("\nProduto das frações: ");
    show_frac(produto);

    return 0;
}