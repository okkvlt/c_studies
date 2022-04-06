#include <stdio.h>

/*
    Pesquisa valor na sequência de Fibonacci!
*/

void fill(long long int *fib)
/*
    Non-recursive function.
*/
{
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < 30; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

void getvalue(long long int *fib, int n)
{
    printf("\nO valor da posição %d na sequência é: %d\n", n, fib[n - 1]);
}

void show_fib(long long int *fib)
{
    puts("\nSequência de 1-30: ");
    for (int i = 0; i < 30; i++)
    {
        printf("Posição %d: %d\n", i + 1, fib[i]);
    }
    puts("");
}

int main()
{
    long long int fib[30], value;
    int n;

    printf("Escreva o numero da posição 'n' (max. 30) na sequência de Fibonacci: ");
    scanf("%d", &n);

    fill(fib);
    getvalue(fib, n);
    show_fib(fib);

    return 0;
}