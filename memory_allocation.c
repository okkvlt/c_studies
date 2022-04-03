#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    Este programa cria um vetor de tamanho x
    utilizando alocação dinâmica de memória.
    Em seguida, preenche este vetor com valores
    aleatórios em uma escala de 0-100. Depois
    ordena estes valores em ordem crescente e
    printa a ordem original conjuntamente à
    ordem crescente.
*/

int *create(int *v, int size)
/*função que cria um vetor alocando
dinamicamente um espaço na memoria e,
em seguida, retorna o endereço deste
vetor.*/
{
    v = (int *)malloc(size * sizeof(int));
    return v;
}

void fill(int *v, int size)
/*função que preenche com valores
aleatórios cada elemento do vetor
alocado dinamicamente.*/
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        v[i] = rand() % 100;
    }
}

void show(int *v, int size)
/*função que printa na tela cada elemento
do vetor alocado dinamicamente.*/
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", v[i]);
    }
    putchar('\n');
}

void swap(int *v, int i, int j)
/*função que inverte dois valores
de um vetor alocado.*/
{
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void crescent_sort(int *v, int size)
/*função que ordena em ordem crescente
cada elemento existente no vetor alocado.*/
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (v[i] > v[j])
                swap(v, i, j);
        }
    }
}

void clear(int *v)
/*função que, finalmente, limpa o
espaço na memoria alocado pelo vetor.*/
{
    free(v);
}

int main()
{
    int *v, size = 10;

    create(v, size);
    fill(v, size);

    puts("Original:");
    show(v, size);

    puts("Ordem crescente:");
    crescent_sort(v, size);
    show(v, size);

    clear(create(v, size));

    return 0;
}