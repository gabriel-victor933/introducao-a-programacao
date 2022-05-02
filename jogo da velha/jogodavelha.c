#include <stdio.h>

//printa o estado atua do jogo tela
void mostra_jogo(char velha[3][3])
{
    printf("   A   B   C\n");
    printf(" ------------\n");
    printf("1| %c | %c | %c |\n",velha[0][0],velha[0][1],velha[0][2]);
    printf(" ------------\n");
    printf("2| %c | %c | %c |\n",velha[1][0],velha[1][1],velha[2][2]);
    printf(" ------------\n");
    printf("3| %c | %c | %c |\n",velha[2][0],velha[2][1],velha[2][2]);
    printf(" ------------\n");
}

//retorna 1 se o jogador X ganhou, retorna -1 se o jogador O e retorna 0 se não tiver vencedor
int alguem_ganhou(int control[3][3])
{
    int v[8];
    int i;

    //linha 1
    v[0] = control[0][0] + control[0][1] + control[0][2];
    //linha 2
    v[1] = control[1][0] + control[1][1] + control[1][2];
    //linha 3
    v[2] = control[2][0] + control[2][1] + control[2][2];
    //coluna 1
    v[3] = control[0][0] + control[1][0] + control[2][0];
    //coluna 2
    v[4] = control[0][1] + control[1][1] + control[2][1];
    //coluna 3
    v[5] = control[0][2] + control[1][2] + control[2][2];
    //diagonal 1
    v[6] = control[0][0] + control[1][1] + control[2][2];
    //diagonal 2
    v[7] = control[0][2] + control[1][1] + control[2][0];

    for(i = 0; i < 9;i++)
    {
        if(v[i] == 3 )
        {
           return 1;
        }
        else if(v[i] == -3)
        {
           return -1;
        }
    }

    return 0;


}

int main()
{
    char velha[3][3] = {{' ','-','-'},{'-','-','-'},{'-','-','-',}};
    int control[3][3] = {{0,0,0},{0,0,0},{0,0,0}};



    while(1)
    {

    }
}
