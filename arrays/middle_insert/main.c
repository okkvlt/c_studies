#include "middle.h"
#include <stdio.h>

int main(){
    Lista * lista = create_list();

    int v[] = {1, 2, 3, 5, 10, -5};

    for(int i=0; i<6; i++)
        if(insert_begin(lista, v[i])!=true)
            printf("Não foi possível adicionar o valor v[%d] = %d.", i, v[i]);
          
    print_list(lista);

    insert_at(lista, 50, 3);

    print_list(lista);

    return 0;
}