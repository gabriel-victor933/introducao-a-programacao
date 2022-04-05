/*
NOME: Gabriel Victor Alves Santana
N°USP: 10748559
*/

#include <stdio.h>

int main()
{
    /*Declaração das variaveis*/
    int A,B,T;

    /*lendo duas variaveis*/
    printf("insira o valor da variavel A:\n");
    scanf("%d",&A);

    printf("insira o valor da variavel B:\n");
    scanf("%d",&B);

    /*escrevendo variaveis na tela*/
    printf("as variaveis inseridas foram: A = %d e B = %d\n",A,B);

    /*trocando os valores das variaveis e escrevendo novamente*/
    T = B;
    B = A;
    A = T;

    printf("\ntrocando os valores: A = %d e B = %d\n",A,B);

}
