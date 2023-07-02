#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "passageiros.h"
#include "interface.h"

FILE *fpPassageiro;

//ABRE O ARQUIVO DE PASSAGEIROS
FILE* AbrirArquivoPassageiros(){
    fpPassageiro = fopen("passageiros.txt", "rb+");
    if(fpPassageiro == NULL)
    {
        fpPassageiro = fopen("passageiros.txt", "wb+");
        if(fpPassageiro == NULL)
        {
            printf("Erro na abertura do arquivo passageiros.txt\n");
            exit(1);
        }
    }
    return fpPassageiro;
}

//FECHA O ARQUIVO DE PASSAGEIROS
void FecharPassageiros(){
    fclose(fpPassageiro);
}


//PEDE DADOS DE PASSAGEIROS
void DigitarPassageiro(){
    Passageiro P;
    FILE * fpPassageiro = AbrirArquivoPassageiros();
    gotoxy (21,6); scanf ("%d", &P.ID);
    gotoxy (21,9); scanf (" %[^\n]", P.nome);
    gotoxy (21,12); scanf (" %[^\n]", P.CPF);
    gotoxy (21,15); scanf (" %[^\n]", P.telefone);
    fseek(fpPassageiro,0, SEEK_END);
    fwrite(&P, sizeof(Passageiro), 1, fpPassageiro);
    fclose(fpPassageiro);
    MenuPassageiro();
}

//PESQUISA DE PASSAGEIRO
Passageiro PesquisarArquivoPassageiro(int codigo){
    Passageiro P;
    fseek(fpPassageiro, 0, SEEK_SET);
    while (fread (&P, sizeof(Passageiro),1,fpPassageiro)){
        if (P.ID == codigo)  return P;
    }
    return P;
}



//INTERFACE DE PASSAGEIRO
void MenuPassageiro (){
    int op;
    char opcoes[][21] = {"Novo", "Pesquisar", "Alterar", "Excluir", "Listar", "MENU ANTERIOR"};
    int x[] = {12, 25, 40, 55, 70, 37};
    int y[] = {20, 20, 20, 20, 20, 22};
    do {
        MostrarTelaPassageiros();   //OBS: APAGAR MOSTRARTELAPRODUTO
        op = MenuHorizontal (opcoes, x, y, 6);
        if (op == 0) DigitarPassageiro();
        if (op == 5) MenuTelaInicial();
     //TERMINAR O MENU!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    } while (op=! 27);
}




