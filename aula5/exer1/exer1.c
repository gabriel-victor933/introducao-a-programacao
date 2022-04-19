/*

programa que faz a leitura de vários
notas, até que se digite um número negativo. O
programa tem que retornar a maior e a menor nota
lida.

*/
#include <stdio.h>

int main()
{
   float maior,menor,temp;
   maior = 0;
   menor = 10;

   while(1)
   {
       printf("\ndigite a nota:\n");
       scanf("%f",&temp);

       if(temp < 0)
       {
           break;
       }

       if(temp > maior)
       {
           maior = temp;
       }

       if(temp < menor)
       {
           menor = temp;
       }
   }

   printf("maior: %.2f\nmenor:%.2f",maior,menor);
}
