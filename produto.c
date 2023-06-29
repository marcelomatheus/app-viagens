#include <stdio.h>
#include "produto.h" //ASPAS PQ ESTÁ NA MINHA PASTA DE PROJETOS E NÃO NA PADRÃO DO CODEBLOCKS
#include <windows.h>
#include "interface.h"
//FUNÇÕES:


Produto DigitarProduto(){
    Produto P;
    gotoxy (21,6); scanf ("%d", &P.codigo);
    gotoxy (21,9); scanf (" %[^\n]", &P.descricao);
    gotoxy (21,12); scanf ("%lf", &P.preco);
    gotoxy (21,15); scanf ("%d", &P.saldo);
return P;
}

void ImprimirProduto (Produto P){
    gotoxy (21,6); printf ("%d", P.codigo);
    gotoxy (21,9); printf ("%s", P.descricao);
    gotoxy (21,12); printf ("%.2lf", P.preco);
    gotoxy (21,15); printf ("%d", P.saldo);
}

Produto PesquisaProduto (Produto P[], int n){
    int i, codigo;
    gotoxy (21,6); scanf ("%d", &codigo);
    for (i=0; i<n;i++){
        if (codigo == P[i].codigo) {ImprimirProduto(P[i]);
        gotoxy (5,23);
        system("pause");
        }
        }
}

/*Produto AlterarProduto (Produto P[], int n){
    int i, codigo;
    gotoxy (21,6); scanf ("%d", &codigo);
    for (i=0; i<n;i++){
        if (codigo == P[i].codigo) {ImprimirProduto(P[i]);
        gotoxy (5,23);
        system("pause");
        }
        }
}*/


void ImprimirProduto2 (Produto P){
    printf ("\nCODIGO: %d\n", P.codigo);
    printf ("DESCRICAO: %s\n", P.descricao);
    printf ("PRECO: %.2lf\n", P.preco);
    printf ("SALDO: %d\n", P.saldo);
    printf ("------------------\n");
}

void ListarProdutos(Produto P[], int n){
    int i, x=5, y=6;
    for (i=0;i<n;i++){
        if (P[i].codigo >= 0) {
                gotoxy (x,y);
                ImprimirProduto2 (P[i]);} //OBS "Produto" é tipo e não usa para repassar para a funcção
                y=y+5;
        }
        gotoxy (5,5);
        system("pause");
}

//INTERFACE PRODUTO
void MenuProduto (int*opcao){
    int op;
    char opcoes[][21] = {"Novo", "Pesquisar", "Alterar", "Excluir", "Listar", "MENU ANTERIOR"};
    int x[] = {12, 25, 40, 55, 70, 37};
    int y[] = {20, 20, 20, 20, 20, 22};
    do {
        //MostrarTelaProdutos();
        //op = Menu (opcoes, x, y, 6);
        *opcao = op;
     //TERMINAR O MENU!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
     //baseado no que está no main, mas lembrando que todas as opções desceram 1 número. O que era 1, agora é 0.
    } while (opcao=! 27);
}


