#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define QTD 10

typedef struct aluno{

    int id;
    float nota;

}  aluno;


int  main()
{
    aluno classe[QTD];
    int i;
    float media;

    for(i=0; i < QTD;i++)
    {
        classe[i].id = i+1;
        classe[i].nota = (rand()%100)/10;
    }

        for(i=0; i < QTD;i++)
    {
        printf("id: %d nota: %f\n",classe[i].id,classe[i].nota);
        media = media + classe[i].nota;
    }

    printf("\nA media foi de %f\n",(media/QTD));
}
