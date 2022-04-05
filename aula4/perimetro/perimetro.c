#include <math.h>
#include <stdio.h>

int main()
{
    float N,R,per;

    printf("Qual o numero de lados?");
    scanf("%f",&N);

    printf("\nQual o raio da circunferencia?");
    scanf("%f",&R);


    per = 2*N*R*sin(M_PI/N);


    printf("\nO perimetro e %.3f",per);

}
