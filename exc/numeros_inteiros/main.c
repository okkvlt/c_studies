#include <stdio.h>
#include <stdlib.h>
#include "nint.h"

int main(){
    Conjunto *new;
    Conjunto *new2;
    Conjunto *all;
    Conjunto *intersecao;
    Conjunto *diferenca;

    new = create_void();
    insert_e(new,1);
    insert_e(new,3);
    insert_e(new,2);
    insert_e(new,5);
    sort_conj(new);
    show_conj(new);

    new2 = create_void();
    insert_e(new2,1);
    insert_e(new2,3);
    insert_e(new2,5);
    insert_e(new2,2);
    sort_conj(new2);
    show_conj(new2);

    all = union_e(new, new2);
    show_conj(all);

    intersecao = intersection_e(new, new2);
    show_conj(intersecao);

    diferenca = diferent_e(new, new2);
    show_conj(diferenca);

    printf("[!] Maior elemento: %d\n[!] Menor elemento: %d\n\n", maior(new), menor(new2));

    printf("[!] São iguais [1:sim // 0:nao]? %d\n\n", equal(new, new2));
    
    printf("[!] É um conjunto vazio [1:sim // 0:nao]? %d\n\n", void_c(diferenca));

    return 0;
}