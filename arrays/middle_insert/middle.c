#include "middle.h"
#include <stdlib.h>
#include <stdio.h>

#define max 15

struct list
{
    int qty;
    int data[max];
};

Lista *create_list()
{
    Lista *new = malloc(sizeof(Lista));
    if (new != NULL)
        new->qty = 0;
    return new;
}

bool insert_at(Lista * lista, int x, int pos)
{
    if(lista->qty == max || pos < 0 || pos > lista->qty)
        return false;
    
    for(int i=lista->qty; i>pos; i--)
        lista->data[i] = lista->data[i-1];
    
    lista->data[pos] = x;
    lista->qty++;

    return true;
}

bool insert_begin(Lista * lista, int x)
{
    return insert_at(lista, x, 0);
}

bool insert_end(Lista * lista, int x)
{
    return insert_at(lista, x, lista->qty);
}

bool delete_at(Lista * lista, int pos)
{
    if(pos < 0 || pos > lista->qty)
        return false;
    
    int aux;
    
    for(int i = pos; i < lista->qty - 1; i++)
    {
        aux = lista->data[i];
        lista->data[i] = lista->data[i+1];
        lista->data[i+1] = lista->data[i];
    }
    
    lista->data[lista->qty - 1] = 0x0;
    lista->qty--;

    return true;
}

bool delete_begin(Lista * lista)
{
    return delete_at(lista, 0);
}

bool delete_end(Lista * lista)
{
    return delete_at(lista, lista->qty);
}

void print_list(Lista * lista)
{
    for(int i=0; i<lista->qty; i++)
        if(i != lista->qty - 1)
            printf("[%d], ", lista->data[i]);
        else
            printf("[%d].", lista->data[i]);

    putchar('\n');
}