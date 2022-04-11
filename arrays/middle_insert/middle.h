#ifndef MIDDLE_H
#define MIDDLE_H

#include <stdbool.h>

typedef struct list Lista;

Lista * create_list();

bool insert_at(Lista *, int, int);

bool insert_begin(Lista *, int);

bool insert_begin(Lista *, int);

void print_list(Lista *);

#endif