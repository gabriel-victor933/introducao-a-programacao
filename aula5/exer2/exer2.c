/*

Crie um programa que lê as notas de uma
determinada prova, até que seja digitada uma nota
negativa :
a) conte e escreva quantos alunos tiveram nota
baixa (nota < 5.0)
b) conte e escreva quantos alunos tiveram nota
alta ( nota >= 5.0)
c) calcule a média geral
d) calcule a porcentagem dos alunos que
obtiveram nota maior ou igual a 5


*/

#include <stdio.h>

int main()
{
    float temp,nota[100],media,porc;
    int baixa,alta,i,con;
    i=0;
    con=0;


    /*recebendo as notas*/
    while(1)
    {
        printf("digite a nota:");
        scanf("%f",&temp);


        if(temp < 0)
        {
            break;
        }
        else
        {
          nota[i] = temp;
          i++;
          con++;
        }
    }



    /*nota baixa, alta e média*/
    for(media=0, alta=0, baixa=0, i=0; i<con; i++)
    {
        if(nota[i] < 5)
        {
            baixa++;
        }

        if(nota[i] >= 5)
        {
            alta++;
        }

        media = media + nota[i];
    }

    media = media/con;

    porc = ((float)alta/con)*100;


    /*resultados*/
    printf("\n%d tiraram notas baixas\n%d tiraram notas altas\nA media foi de %f\nA porcetagem de aprovados foi %.2f%\n",baixa,alta,media,porc);
}
