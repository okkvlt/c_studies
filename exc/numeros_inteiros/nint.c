#include <stdio.h>
#include <stdlib.h>
#include "nint.h"

struct conjunto
{
    int num;
    int elem[64];
};

// essa estrutura será chamada pelo nome de "Conjunto".
// afinal, foi declarado um typedef em "nint.h".

Conjunto *create_void()
{
    Conjunto *new = malloc(sizeof(Conjunto)); // aloca espaço de tamanho Conjunto para "new".
    if (new != NULL)
    {
        new->num = 0; // numero de elementos no conjunto: 0.
    }
    return new; // retorna endereço de new.
}

int check_e(Conjunto *conj, int x)
{
    int i = 0;

    if (conj->num != 0)
    {
        while (conj->elem[i] != 0x0)
        {
            if (conj->elem[i] == x)
                return 1;
            i++;
        }
        return 0;
    }
    else
        return 1;
}

int pos_e(Conjunto *conj, int x)
{
    int i = 0;

    if (conj->num != 0)
    {
        while (conj->elem[i] != 0x0)
        {
            if (conj->elem[i] == x)
                return i;
            i++;
        }
    }
}

int conj_len(Conjunto *conj)
{
    return conj->num;
}

void insert_e(Conjunto *conj, int x)
{
    int i = 0; // counter.

    if (conj->num == 0)
    {
        /*se a quantidade de elementos no conjunto for 0, ou seja, se o
        o conjunto for vazio, o elemento a ser inserido é adicionado com sucesso.*/
        conj->elem[i] = x;
        conj->num += 1;
    }
    else
    {
        if (check_e(conj, x) == 0)
        {
            conj->elem[conj_len(conj)] = x;
            conj->num += 1;
        }
    }
}

void swap(Conjunto *conj, int i, int j)
{
    /*
        Função que substitui o elemento i do conjunto
        pelo elemento j do conjunto.
    */
    int temp = conj->elem[i];
    conj->elem[i] = conj->elem[j];
    conj->elem[j] = temp;
}

void delete_e(Conjunto *conj, int x)
{
    int i = 0; // counter.

    if (conj->num == 0)
    // se o conjunto for vazio, não é possível remover o elemento, pois ele não existe.
    {
        printf("[!] Não é possível remover elementos de um conjunto vazio.\n\n");
    }
    else
    {
        if (check_e(conj, x) == 1)
        {
            if (pos_e(conj, x) != conj_len(conj) - 1)
            {
                swap(conj, pos_e(conj, x), conj_len(conj) - 1);
            }

            conj->elem[conj_len(conj) - 1] = 0x0;
            conj->num -= 1;
        }
    }
}

void show_conj(Conjunto *conj)
{
    int i = 0; // counter.

    if (conj->num == 0) // se o conjunto for vazio.
        printf("[!] Conjunto vazio: {}");
    else // se o conjunto nao for vazio.
    {
        printf("[!] Elementos do conjunto: { ");
        while (conj->elem[i] != 0x0) // enquanto o elemento for diferente de nulo.
        {
            printf("%d ", conj->elem[i]); // printa o elemento.
            i++;
        }
        printf("}");
    }
    printf("\n[!] Numero de elementos: %d.\n\n", conj->num); // printa o numero de elementos.
}

void sort_conj(Conjunto *conj)
{
    for (int i = 0; i < conj->num; i++)
    {
        for (int j = i + 1; j < conj->num; j++)
        {
            if (conj->elem[i] > conj->elem[j])
            {
                swap(conj, i, j);
            }
        }
    }
}

Conjunto *intersection_e(Conjunto *conj1, Conjunto *conj2)
{
    Conjunto *intersectioned = malloc(sizeof(Conjunto));

    int i = 0;
    int j = 0;

    if (intersectioned)
    {
        while (conj1->elem[i] != 0x0)
        {
            if (check_e(conj2, conj1->elem[i]) == 1)
                insert_e(intersectioned, conj1->elem[i]);
            i++;
        }
    }

    return intersectioned;
}

Conjunto *diferent_e(Conjunto *conj1, Conjunto *conj2)
{
    Conjunto *dif = malloc(sizeof(Conjunto));

    int i = 0;
    int j = 0;

    if (dif)
    {
        while (conj1->elem[i] != 0x0)
        {
            if (check_e(conj2, conj1->elem[i]) == 0)
                insert_e(dif, conj1->elem[i]);
            i++;
        }

        while (conj2->elem[j] != 0x0)
        {
            if (check_e(conj1, conj2->elem[j]) == 0)
                insert_e(dif, conj2->elem[j]);
            j++;
        }
    }

    return dif;
}

Conjunto *union_e(Conjunto *conj1, Conjunto *conj2)
{
    Conjunto *united = malloc(sizeof(Conjunto));

    int i = 0;
    int j = 0;

    if (united)
    {
        while (conj1->elem[i] != 0x0)
        {
            insert_e(united, conj1->elem[i]);
            i++;
        }

        while (conj2->elem[j] != 0x0)
        {
            insert_e(united, conj2->elem[j]);
            j++;
        }
    }

    return united;
}

int maior(Conjunto *conj)
{
    int maior = 0;

    for (int i = 0; i < conj_len(conj); i++)
    {
        if (conj->elem[i] > maior)
            maior = conj->elem[i];
    }

    return maior;
}

int menor(Conjunto *conj)
{
    int menor;

    menor = conj->elem[0];

    for (int i = 1; i < conj_len(conj); i++)
    {
        if (conj->elem[i] < menor)
            menor = conj->elem[i];
    }

    return menor;
}

int equal(Conjunto *conj1, Conjunto *conj2)
{
    int i = 0;
    int j = 0;

    while (conj1->elem[i] != 0x0)
    {
        if (check_e(conj2, conj1->elem[i]) == 0)
            return 0;
        i++;
    }

    while (conj2->elem[j] != 0x0)
    {
        if (check_e(conj1, conj2->elem[j]) == 0)
            return 0;
        j++;
    }

    return 1;
}

int void_c(Conjunto *conj)
{
    if (conj->num == 0)
        return 1;
    return 0;
}