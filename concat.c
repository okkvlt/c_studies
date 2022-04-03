#include <stdio.h>
#include <stdlib.h>

/*
    Este programa concatena duas strings e,
    em seguida, armazena o valor em uma
    unica string.

    Uso: [./concat "string 01" "string 02"]
*/

int getsize(char *s)
{
    for (int i = 0; i < 128; i++)
    {
        if (s[i] != '\0')
        {
            continue;
        }
        else
        {
            return i;
        }
    }
}

char *concat(char *main, char *second)
{
    int len_main = getsize(main);
    int len_second = getsize(second);

    char *concatened = malloc(sizeof(char) * 128);

    for (int i = 0; i < len_main; i++)
    {
        concatened[i] = main[i];
    }

    for (int i = len_main; i < (len_main + len_second); i++)
    {
        concatened[i] = second[i - len_main];
    }

    concatened[len_main + len_second] = '\0';

    concatened = realloc(concatened, (len_main + len_second) * sizeof(char));

    return concatened;
}

int main(int argc, char **argv)
{
    char *main;
    char *second;

    main = argv[1];
    second = argv[2];

    char *string;

    string = concat(main, second);
    puts(string);

    free(concat(main, second));

    return 0;
}