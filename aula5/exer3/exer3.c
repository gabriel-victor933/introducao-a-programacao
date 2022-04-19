/*
Ler x e y e depois exibir a soma dos números
de x a y. Incluir os valores de x e y na soma.
*/

#include <stdio.h>

int main()
{
    int x,y,soma;

    printf("insira os inteiros na forma x-y:\n");
    scanf("%d-%d",&x,&y);

    for(soma=0;x<=y;x++)
    {
        soma = soma + x;
    }

    printf("O valor da soma e %d",soma);
}
