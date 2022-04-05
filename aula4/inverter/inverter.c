#include <stdio.h>

int main()
{
    int n,n1,n2,n3;

    printf("insira um numero de tres digitos:\n");
    scanf("%d",&n);

    n1 = (n%10)*100;
    n = n - (n%10);
    n2 = (n%100);
    n = n - n2;
    n3 = n/100;

    n = n1 + n2 + n3;

    printf("%d",n);

}
