/*
Leia um número positivo do usuário, então,
calcule e imprima a sequencia Fibonacci até o
primeiro número superior ao número lido.
Exemplo: se o usuário informou o número 30,
a sequencia a ser impressa será 0 1 1 2 3 5 8
13 21 34.
*/

#include <stdio.h>

int main()
{
    int x,fib1,fib2,temp;

    printf("insira um numero inteiro:\n");
    scanf("%d",&x);

    fib1 = 0;
    fib2 = 1;

    while(fib1 < x)
    {
        printf("%d ",fib1);

        temp = fib2;

        fib2 = fib1;

        fib1 = fib1 + temp;
    }

    printf("%d",fib1);

}
