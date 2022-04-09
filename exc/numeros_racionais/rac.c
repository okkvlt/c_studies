#include <stdio.h>
#include <stdlib.h>
#include "rac.h"

struct fracao
{
    int x, y;
};

int mmc(int x, int y)
{
    int max;
    int mdc;
    int mmc;

    if (x > y)
        max = x;
    else
        max = y;

    for (int i = 1; i <= max; i++)
    {
        if (x % i == 0 && y % i == 0)
            mdc = i;
    }

    mmc = (x * y) / mdc;

    return mmc;
}

Fracao *create_frac(int x, int y)
{
    Fracao *new = malloc(sizeof(Fracao));
    if (new != NULL)
    {
        new->x = x;
        new->y = y;
    }
    return new;
}

Fracao *soma_frac(Fracao *fracao1, Fracao *fracao2)
{
    Fracao *soma = malloc(sizeof(Fracao));
    int dem_mmc = mmc(fracao1->y, fracao2->y);
    if (soma)
    {
        soma->x = (dem_mmc / fracao1->y * fracao1->x) + (dem_mmc / fracao2->y * fracao2->x);
        soma->y = dem_mmc;
    }
    return soma;
}

Fracao *mult_frac(Fracao *fracao1, Fracao *fracao2)
{
    Fracao *produto = malloc(sizeof(Fracao));
    if (produto)
    {
        produto->x = fracao1->x * fracao2->x;
        produto->y = fracao1->y * fracao2->y;
    }
    return produto;
}

void show_frac(Fracao *fracao)
{
    printf("\nNumerador: %d\n", fracao->x);
    printf("Denominador: %d\n", fracao->y);
}

int equal_test(Fracao *fracao1, Fracao *fracao2)
{
    if (fracao1->x == fracao2->x &&
        fracao1->y == fracao2->y)
        return 1;
    else
        return 0;
}