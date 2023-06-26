#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "passageiros.h"


FILE *P;

void AbrirArquivoPassageiros()  //ABRE O ARQUIVO DE PASSAGEIROS
{
    P = fopen("passageiros.txt", "rb+");
    if(P == NULL)
    {
        P = fopen("passageiros.txt", "wb+");
        if(P == NULL)
        {
            printf("Erro na abertura de passageiros.txt\n");
            exit(1);
        }
    }
}

void FecharPassageiros()  //FECHA O ARQUIVO DE PASSAGEIROS
{
    fclose(P);
}


Passageiro DigitarPassageiro() //PEDE DADOS DE PASSAGEIROS
{
    Passageiro P;
    printf ("NOME: "); scanf (" %[^\n]", P.nome);
    printf ("CPF (somente numeros): "); scanf (" %[^\n]", P.CPF);
    printf ("TELEFONE: "); scanf (" %[^\n]", P.telefone);

return P;
}

//INTERFACE PRODUTO
void MenuPassageiro (){
    int op;
    char opcoes[][21] = {"Novo", "Pesquisar", "Alterar", "Excluir", "Listar", "MENU ANTERIOR"};
    int x[] = {12, 25, 40, 55, 70, 37};
    int y[] = {20, 20, 20, 20, 20, 22};
    do {
        MostrarTelaPassageiros();   //OBS: APAGAR MOSTRARTELAPRODUTO
        op = Menu (opcoes, x, y, 6);
     //TERMINAR O MENU!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
     //baseado no que est� no main, mas lembrando que todas as op��es desceram 1 n�mero. O que era 1, agora � 0.
    } while (op=! 27);
}




