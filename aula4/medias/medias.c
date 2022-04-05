#include <stdio.h>

int main()
{
    float p1,p2,p3,t1,t2;
    float MP,MT,MF;

    printf("insira as notas das provas no seguinte formato p1-p2-p3\n");
    scanf("%f-%f-%f",&p1,&p2,&p3);

    printf("insira as notas dos trabalhos no seguinte formato t1-t2\n");
    scanf("%f-%f",&t1,&t2);

    MP = (2*p1 + 3*p2 + 3*p3)/8;
    MT = (t1 + t2)/2;
    MF = (7*MP + 3*MT)/10;

    printf("\nMedia das provas: %.2f \nMedia dos trabalhos: %.2f \nMedia final: %.2f\n",MP,MT,MF);


}
