/*
Algoritmo para solucionar a torre de hanoi para n discos.
*/

#include <stdio.h>

void hanoi(int n, char inic, char fin, char aces)
{
    if(n == 1)
    {
        printf("Mover N = %d de %c para %c\n",n,inic,fin);
    }
    else
    {
        hanoi(n-1,inic,aces,fin);

        printf("Mover N = %d de %c para %c\n",n,inic,fin);

        hanoi(n-1,aces,fin,inic);
    }


}

int main()
{
    int n;

    printf("insira o numero de discos: ");
    scanf("%d",&n);
    putchar('\n');

    hanoi(n,'A','C','B');
}
