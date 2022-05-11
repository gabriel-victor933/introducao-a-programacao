/*
algoritmo para calcular arranjo e combinações.
*/

#include <stdio.h>

int comme(int n, int k)
{
    if(n == k || k == 0)
    {
        return 1;
    }
    else if(n < k){
        return 0;
    }
    else if(n > k){

        return comme(n-1,k) + comme(n-1,k-1);
    }

}

int main()
{

    printf("%d",comme(5,3));

}
