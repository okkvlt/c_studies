#ifndef RAC_H
#define RAC_H

typedef struct fracao Fracao;

Fracao *create_frac(int, int);
// cria uma fracao.
// params: numerador e denominador.

Fracao *soma_frac(Fracao *, Fracao *);
// retorna a soma.

Fracao *mult_frac(Fracao *, Fracao *);
// retorna o produto.

void show_frac(Fracao *);
// printa a fracao.

int equal_test(Fracao *, Fracao *);
// retorna 1 se forem iguais, retorna 0 se forem diferentes.

#endif