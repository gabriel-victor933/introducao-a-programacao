#include <stdio.h>
#include <stdlib.h>

//variaveis globais que representa a matriz do jogo
char velha[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
int control[3][3] = {{0,0,0},{0,0,0},{0,0,0}};

//printa o estado atual do jogo tela
void mostra_jogo()
{
    printf("\t   A   B   C\n");
    printf("\t ------------\n");
    printf("\t1| %c | %c | %c |\n",velha[0][0],velha[0][1],velha[0][2]);
    printf("\t ------------\n");
    printf("\t2| %c | %c | %c |\n",velha[1][0],velha[1][1],velha[1][2]);
    printf("\t ------------\n");
    printf("\t3| %c | %c | %c |\n",velha[2][0],velha[2][1],velha[2][2]);
    printf("\t ------------\n\n");
}

//retorna 1 se o jogador 1 ganhou, retorna -1 se o jogador 2 ganhou e retorna 0 se nao tiver vencedor
int alguem_ganhou()
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


    //para existir um vencedor alguma das linhas ou colunas ou diagonais
    // devem somar 3 ou -3
    for(i = 0; i < 9;i++)
    {
        if(v[i] == 3 )
        {
           return 1;
        }
        else if(v[i] == -3)
        {
           return (-1);
        }
    }

    return 0;


}

//função que retorna 1 se a jogada for nova e 0 se a jogada for repetida
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

    //para a jogada não ser repetida a matriz de controle deve conter 0, caso contrario a jogada já foi realizada
    if(control[lin][j] == 0)
    {
        return 1;
    }
    else
    {
        printf("Entrada Repetida!\n\n");
        return 0;
    }
}

//função que retorna 1 se a jogada for permitida e 0 se a jogada não for permitida
int jogada_correta(int lin, char col)
{
    //para a jogada ser correta o numero da linha e a letra da coluna devem estar no intervalo do tabuleiro do jogo
    //alem da jogada não poder ser repetida
    if(lin >= 1 && lin <= 3 && col >= 'a' && col <= 'c')
    {
        return (jogada_repetida(lin,col));
    }
    else
    {
        printf("Entrada invalida!\n\n");
        return 0;
    }


}


//função que modifica o tabuleiro
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

    //verifica qual jogador esta jogando atraves do numero da jogada ja que o jogador 1 sempre joga antes
    // descobrindo o jogador se atribui 1 e X ou -1 e O.
    if((jogadas%2) != 0)
    {
       xo = 'X';
       lc = 1;
    }
    else
    {
        xo = 'O';
        lc = -1;
    }

    velha[lin][j] = xo;
    control[lin][j] = lc;

}


//função que mostra o menu principal
void menu_principal()
{
    printf("\t---JOGA DA VELHA#---\n\n");
    printf("digite: j - jogar  i - instrucoes  s - sair\n\n");

}

//função que mostra as inntruções do jogo
void instrucoes()
{
    mostra_jogo();
    printf("Como jogar: na vez indica para cada jogador insira o \nnumero da linha seguido pela letra da coluna para \nfazer uma jogada. O jogador 1 joga com X e o \njogador 2 joga com O\n\n");
}

//reinicia os valores da matriz principal do jogo
void limpa_tabuleiro()
{
    int i,j;

    for(i = 0;i <= 2;i++)
    {
        for(j = 0; j <= 2;j++)
        {
            control[i][j] = 0;
            velha[i][j] = ' ';
        }
    }
}

int main()
{
    int jogadas;
    int lin;
    char col;
    int ag;
    char *menu;
    int j;

    mostra_jogo();

    while(1)
    {
    //carregando as variaveis com seus valores iniciais
    j = 0;
    jogadas = 1;
    limpa_tabuleiro();

    menu_principal();

    menu = (char *)malloc(1);
    scanf(" %c",menu);

    switch(*menu)
    {
    case 'j': j = 1; break;
    case 'i': instrucoes(); break;
    case 's': exit(0);
    default: printf("entrada invalida\n\n");
    }


    //loop principal do jogo
    while(j == 1)
    {
        mostra_jogo();
        //verifica de quem é a vez;
        if((jogadas%2) != 0)
        {
            printf("\nJOGADOR 1:\n\n");
        }
        else
        {
            printf("\nJOGADOR 2:\n\n");
        }

        //le a entrada do jogador
        scanf(" %d%c",&lin,&col);
        putchar('\n');


        //verificando se a jogada é correta e se for mudar o tabuleiro
        if(jogada_correta(lin,col))
        {
            //modifica o tabuleiro
            modifica_tab(lin,col,jogadas);
            jogadas++;
        }
        else
        {
            continue;
        }



        //verificando se há algum vencedor
        ag = alguem_ganhou();
        if(ag == 1)
        {   mostra_jogo();
            printf("JOGADOR 1 GANHOU!!!\n\n\n"); break;
        }
        else if(ag == -1)
        {   mostra_jogo();
            printf("JOGADOR 2 GANHOU!!!\n\n\n"); break;
        }

        //verificando se o numero maximo de jogadas foi atingido
        if(jogadas > 9)
        {
            printf("EMPATE!!!\n\n\n");
            break;
        }


    }

    }

    free(menu);

}
