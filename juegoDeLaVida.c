#include<stdio.h>
#include <stdlib.h>
#include <windows.h>

#define TAM 45
#define VIVO 1
#define MUERTO 0
void inicializarMatriz(int [TAM][TAM]);
void actualizarEstado(int [TAM][TAM], int [TAM][TAM]);
void paso(int [TAM][TAM], int [TAM][TAM]);
void imprimir(int [TAM][TAM]);
int vecinasVivas(int[TAM][TAM], int, int);
void main()
{
    int estado[TAM][TAM];
    int futuro[TAM][TAM];

    inicializarMatriz(estado);

    do
    {
        paso(estado, futuro);
        imprimir(estado);
        Sleep(100);
        system("cls");
        actualizarEstado(estado, futuro);
    }while(1 == 1);

}
void imprimir(int estado[TAM][TAM])
{
    for(int i = 0; i < TAM; i++)
    {
        for(int j = 0; j < TAM; j++)
        {
            if(estado[i][j] == VIVO)
            {
                printf(" * ");
            }
            else
            {
                printf("   ");
            }
        }
        printf("\n");
    }
}
void paso(int estado[TAM][TAM], int futuro[TAM][TAM])
{
    for(int i = 0; i <TAM; i++)
    {
        for(int j = 0; j <TAM; j++)
        {
            if(estado[i][j] == MUERTO && vecinasVivas(estado,i, j) == 3)
            {
                futuro[i][j] = VIVO;
            }
            else if(estado[i][j] == VIVO && (vecinasVivas(estado,i, j) == 3 ||
                                            vecinasVivas(estado,i,j)==2))
            {
                futuro[i][j] = VIVO;
            }
            else
            {
                futuro[i][j] = MUERTO;
            }
        }
    }
}
int vecinasVivas(int estado[TAM][TAM], int x, int y)
{
    int total = 0;

            for(int i = x - 1; i <= x + 1; i++)
            {
                for(int j = y - 1; j <= y + 1; j++)
                {
                    if (i >= 0 && j >= 0 && i < TAM && j < TAM)
                    {
                        total += estado[i][j];
                    }
                }
            }

            return total - estado[x][y];
}
void actualizarEstado(int estado[TAM][TAM], int futuro[TAM][TAM])
{
    for(int i = 0; i < TAM; i++)
    {
        for(int j = 0; j < TAM; j++)
        {
            estado[i][j] = futuro[i][j];
        }
    }
}
void inicializarMatriz(int estado[TAM][TAM])
{
    for(int i = 0; i < TAM; i++)
    {
        for(int j = 0; j < TAM; j++)
        {
            int aleatorio = rand() % 101;
            if(aleatorio <= 90)
            {
                estado[i][j] = MUERTO;
            }
            else
            {
                estado[i][j] = VIVO;
            }
        }
    }
}

