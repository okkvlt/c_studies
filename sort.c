#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    Ordena o vetor em ordem crescente.
*/

void fill(int *v, int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        v[i] = rand() % 100;
    }
}

void print_v(int *v, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", v[i]);
    }
    puts("");
}

void swap(int *v, int i, int j)
{
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void sort_v(int *v, int size)
/*
Função ordenadora.
*/
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (v[i] > v[j])
            {
                swap(v, i, j);
            }
        }
    }
}

int main()
{
    int v[10];

    fill(v, 10);
    print_v(v, 10);
    sort_v(v, 10);
    print_v(v, 10);

    return 0;
}