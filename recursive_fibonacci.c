#include <stdio.h>

/*
    Pesquisa valor na sequência de Fibonacci!
    Usando função recursiva (mais simples)!
*/

int getvalue(int n){
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    return getvalue(n-1) + getvalue(n-2);
}

int main(){
    int n;

    printf("Digite a posição n desejada: ");
    scanf("%d",&n);

    printf("Valor fibonacci na posição %d: %d\n",n,getvalue(n));

    return 0;
}