#ifndef NINT_H
#define NINT_H

typedef struct conjunto Conjunto;
//"struct conjunto" se chamará Conjunto.

Conjunto *create_void();
/* cria um conjunto vazio e retorna
o endereço do conjunto criado. */

int check_e(Conjunto *, int);
/* Verifica se já existe algum elemento int
no conjunto informado.
    Retorno 1: existe;
    Retorno 0: não existe.*/

int pos_e(Conjunto *, int);
/* Retorna a posição de um elemento em um conjunto. */

int conj_len(Conjunto *);
/* Retorna a quantidade de elementos em um conjunto. */

void insert_e(Conjunto *, int);
/* Insere um elemento em um conjunto. */

void delete_e(Conjunto *, int);
/* Deleta um elemento em um conjunto. */

void show_conj(Conjunto *);
/* Printa o conjunto. */

void sort_conj(Conjunto *);
/* Ordena o conjunto. */

Conjunto *intersection_e(Conjunto *, Conjunto *);
/* Cria um conjunto resultante da interseção
de dois conjuntos. Retorna o endereço do
conjunto resultante. */

Conjunto *diferent_e(Conjunto *, Conjunto *);
/* Cria um conjunto com os elementos diferentes
entre dois conjuntos. Retorna o endereço do
conjunto resultante. */

Conjunto *union_e(Conjunto *, Conjunto *);
/* Cria um conjunto com a união de dois conjuntos.
Retorna o endereço do conjunto resultante. */

int maior(Conjunto *);
/* Retorna o maior elemento de um conjunto. */

int menor(Conjunto *);
/* Retorna o menor elemento de um conjunto. */

int equal(Conjunto *, Conjunto *);
/* Retorna 1: se ambos os conjuntos são iguais.
           0: se ambos os conjuntos são diferentes. */

int void_c(Conjunto *);
/* Retorna 1: se o conjunto for vazio.
           0: se o conjunto não for vazio. */

#endif