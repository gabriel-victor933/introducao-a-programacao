#include <stdio.h>

//variaveis globais
char velha[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
int control[3][3] = {{0,0,0},{0,0,0},{0,0,0}};

//printa o estado atua do jogo tela
void mostra_jogo()
{
    printf("   A   B   C\n");
    printf(" ------------\n");
    printf("1| %c | %c | %c |\n",velha[0][0],velha[0][1],velha[0][2]);
    printf(" ------------\n");
    printf("2| %c | %c | %c |\n",velha[1][0],velha[1][1],velha[1][2]);
    printf(" ------------\n");
    printf("3| %c | %c | %c |\n",velha[2][0],velha[2][1],velha[2][2]);
    printf(" ------------\n\n");
}

//retorna 1 se o jogador X ganhou, retorna -1 se o jogador O e retorna 0 se nao tiver vencedor
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

int jogada_repetida(int lin,char col)
{
    int j;
    lin = lin-1;

    switch(col)
    {
    case 'a': j = 0; break;
    case 'b': j = 1; break;
    case 'c': j = 2; break;
    }

    if(control[lin][j] == 0)
    {
        return 1;
    }
    else
    {
        printf("Entrada Repetida!\n");
        return 0;
    }
}

//verifica se a jogada esta correta
int jogada_correta(int lin, char col)
{
    if(lin >= 1 && lin <= 3 && col >= 'a' && col <= 'c')
    {
        return (jogada_repetida(lin,col));
    }
    else
    {
        printf("Entrada invalida!\n");
        return 0;
    }


}


//modifica o tabuleiro
void modifica_tab(int lin, char col, int jogadas)
{
    int j,lc;
    char xo;

    lin = lin-1;

    switch(col)
    {
    case 'a': j = 0; break;
    case 'b': j = 1; break;
    case 'c': j = 2; break;
    }

    if((jogadas%2) != 0)
    {
       xo = 'X';
       lc = 1;
    }
    else
    {
        xo = 'O';
        lc = 0;
    }

    velha[lin][j] = xo;
    control[lin][j] = lc;

}


int main()
{
    char velha[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' ',}};
    int control[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    int jogadas = 1;
    int lin;
    char col;

    mostra_jogo();

    while(1)
    {
        //verifica de quem é a vez;
        if((jogadas%2) != 0)
        {
            printf("Jogador 1:\n\n");
        }
        else
        {
            printf("Jogador 2:\n\n");
        }


        scanf("%d%c",&lin,&col);



        if(jogada_correta(lin,col))
        {
            //modificar tabuleiro
            modifica_tab(lin,col,jogadas);
            jogadas++;
        }
        else
        {
            continue;
        }

        mostra_jogo();



        if(jogadas == 9) break;


    }
}
