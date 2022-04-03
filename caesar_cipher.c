#include <stdio.h>

/* #
        This Caesar Cipher program works with values from ascii tables!
   # */

int getsize(char *s)
{
    for (int i = 0; i < 100; i++)
    {
        if (s[i] != '\0')
        {
            i++;
        }
        else
        {
            return i;
        }
    }
}

void cripty(char *s, int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (s[i] != 32)
        {
            s[i] = s[i] + key;
        }
    }
}

int main()
{
    char string[100];
    int key, size;

    printf("Escreva a frase a ser criptografada (max. 100 caracteres): ");
    scanf("%[^\n]s", &string);

    printf("Escreva a chave: ");
    scanf("%d", &key);

    size = getsize(string);
    cripty(string, size, key);

    printf("String criptografada: '%s'\n", string);

    return 0;
}