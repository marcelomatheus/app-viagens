#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "motoristas.h"
#include "interface.h"


FILE *M;

void AbrirArquivoMotorista()
{
    M = fopen("motorista.txt","ab+");
    if(M==NULL)
    {
        printf("Nao foi possivel abrir o arquivo\n");
        exit(1);
    }

}

void GravarDados(Motorista motorista)
{
    fwrite(&motorista,sizeof(Motorista),1,M);
}




void PesquisarMotorista()
{
    Motorista motorista;
    long int cpf;
    gotoxy (21,4);
    scanf ("%d", &cpf);
    fseek(M,0,SEEK_SET);
    while(fread(&motorista,sizeof(Motorista),1,M))
    {
        if(motorista.cpf==cpf){
        gotoxy (21,7);
        printf("%s", motorista.nome);
        gotoxy (21,10);
        printf("%s", motorista.carro);
        gotoxy (21,13);
        printf("%s", motorista.cor);
        gotoxy (21,16);
        printf("%s", motorista.placa);
        gotoxy(21,20);
        system("pause");
        scanf("%s",&motorista.cpf);
        }
    }


}

void MenuMotorista()
{
    int op;
    Motorista motorista;
    AbrirArquivoMotorista();
    char opcoes[][21] = {"Novo", "Pesquisar", "Alterar", "Excluir", "Listar", "MENU ANTERIOR"};
    int x[] = {12, 25, 40, 55, 70, 37};
    int y[] = {20, 20, 20, 20, 20, 22};
    do
    {
        MostrarTelaMotorista();
        op = MenuHorizontal (opcoes, x, y, 6);
        if (op == 0)
        {
            motorista = DigitarMotorista();
            fseek(M,0, SEEK_END);
            GravarDados(motorista);
            MenuMotorista();
        }
        else if(op==1 )
        {
            PesquisarMotorista();
            MenuMotorista();
        }else if(op==3){

        }
        if (op == 5) MenuTelaInicial();
    }
    while (op=! 27);
    fclose(M);
}

Motorista DigitarMotorista()
{

    Motorista motorista;
    gotoxy (21,4);
    scanf ("%d", &motorista.cpf);
    gotoxy (21,7);
    scanf (" %[^\n]", motorista.nome);
    gotoxy (21,10);
    scanf (" %[^\n]", motorista.carro);
    gotoxy (21,13);
    scanf (" %[^\n]", motorista.cor);
    gotoxy (21,16);
    scanf (" %[^\n]", motorista.placa);
    return motorista;
}


//a função fflush(fp) grava tudo que está no buffer
