#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * $ gcc base_conversion.c -o base -lm
 * $ ./base
 */

int ascii2val(char num)
{
    int value;

    if (num > 47 && num < 58)
        value = (int)num - 48;
    if (num > 96 && num < 103)
        value = (int)num - 97 + 10;

    return value;
}

char val2ascii(int num)
{
    char value;

    if (num >= 0 && num <= 9)
        value = (char)num + 48;
    if (num >= 10 && num <= 15)
        value = (char)num + 87;
}

int get_len(char *num)
{
    int i = 0;

    while (num[i] != 0x0)
    {
        i++;
    }

    return i;
}

void invert(char *num, int len)
{
    char aux;

    for (int i = 0; i < len / 2; i++)
    {
        if (i != (i + (len - i - 1)))
        {
            aux = num[i];
            num[i] = num[i + (len - i - 1)];
            num[i + (len - i - 1)] = aux;
        }
    }
}

double base2dec(char *num, int base)
{
    int val = 0;
    int expoente = 0;
    int pot;

    for (int i = get_len(num) - 1; i >= 0; i--)
    {
        pot = (int)pow(base, expoente);
        val += ascii2val(num[i]) * pot;
        expoente++;
    }
    return val;
}

void dec2base(int value, int base, char *num)
{
    int i = 0;
    while (1)
    {
        num[i] = val2ascii(value % base);
        value = value / base;

        if (value < base)
        {
            num[i + 1] = val2ascii(value);
            num[i + 2] = 0x0;
            break;
        }

        i++;
    }

    invert(num, get_len(num));
}

void soma(char *num1, int base1, char *num2, int base2, char *resultado, int base_resultado)
{
    int value1;
    int value2;
    int soma;

    if (base1 != 10)
        value1 = base2dec(num1, base1);
    else
        value1 = atoi(num1);

    if (base2 != 10)
        value2 = base2dec(num2, base2);
    else
        value2 = atoi(num2);

    soma = value1 + value2;

    dec2base(soma, base_resultado, resultado);
}

int main()
{
    char num1[20], num2[20], resultado[20];
    int base1, base2, base_resultado;

    puts("### Numero #1 ###\n");

    printf("Número: ");
    scanf("%s", &num1);
    fflush(stdin);
    printf("Base: ");
    scanf("%d", &base1);

    puts("\n### Numero #2 ###\n");

    printf("Número: ");
    scanf("%s", &num2);
    fflush(stdin);
    printf("Base: ");
    scanf("%d", &base2);

    printf("\nBase da soma: ");
    scanf("%d", &base_resultado);

    printf("Soma: ");

    soma(num1, base1, num2, base2, resultado, base_resultado);
    printf("[%s]", resultado);

    return 0;
}
