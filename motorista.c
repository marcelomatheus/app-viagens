#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "motoristas.h"
#include "interface.h"


FILE *M;

FILE* AbrirArquivoMotorista()
{
    FILE *MAberto;
    MAberto = fopen("motorista.txt","ab+");
    if(MAberto==NULL)
    {
        printf("Nao foi possivel abrir o arquivo\n");
        exit(1);
    }
    return MAberto;

}

void GravarDados(Motorista motorista)
{
    fwrite(&motorista,sizeof(Motorista),1,M);
}



void MenuMotorista()
{
    int op;
    Motorista motorista;
    M=AbrirArquivoMotorista();
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

        }
        else if(op==1 )
        {
            MostrarPesquisaMotorista();

        }else if(op==2){

        }
        fclose(M);
        if (op == 5) MenuTelaInicial();
    }
    while (op=! 27);
    MenuMotorista();
    fclose(M);
}

int QuantidadeMotoristas(FILE *Arquivo){
    Motorista motorista;
    int quantidadeMotorista = 0;
    fseek(Arquivo,0,SEEK_SET);
    while(fread(&motorista,sizeof(Motorista),1,Arquivo)){
        quantidadeMotorista++;
    }
    return quantidadeMotorista;
}

void CalcularAvaliacaoMotorista(Motorista motoristaParametro, double novaAvaliacao){
    Motorista motoristaComparacao;
    FILE *MAvaliacao = fopen("motorista.txt","rb+");
    if(MAvaliacao==NULL){
        printf("Erro");
    }
    ;
    fseek(MAvaliacao,0,SEEK_SET);
    while(fread(&motoristaComparacao,sizeof(Motorista),1,MAvaliacao)){
        if(motoristaComparacao.cpf==motoristaParametro.cpf){
            motoristaParametro.avaliacao = (motoristaParametro.avaliacao+novaAvaliacao)/(double)motoristaParametro.totalCorridas;
           fseek(MAvaliacao,-sizeof(Motorista),SEEK_CUR);
           fwrite(&motoristaParametro,sizeof(Motorista),1,MAvaliacao);
           fflush(MAvaliacao);
           return;
        }
    }
    fclose(MAvaliacao);
}

void SomarCorridaAoMotorista(Motorista motoristaParametro){
    Motorista motoristaComparacao;
    FILE *MSoma = fopen("motorista.txt","rb+");
    if(MSoma==NULL){
        printf("Erro");
    }
    motoristaParametro.totalCorridas = motoristaParametro.totalCorridas+1;
    fseek(MSoma,0,SEEK_SET);
    while(fread(&motoristaComparacao,sizeof(Motorista),1,MSoma)){
        if(motoristaComparacao.cpf==motoristaParametro.cpf){
           fseek(MSoma,-sizeof(Motorista),SEEK_CUR);
           fwrite(&motoristaParametro,sizeof(Motorista),1,MSoma);
           fflush(MSoma);
           return;
        }
    }
    fclose(MSoma);
}

//PESQUISAR MOTORISTA
Motorista PesquisarArquivoMotorista(long int cpf){
    Motorista motorista;
    fseek(M, 0, SEEK_SET);
    while (fread (&motorista, sizeof(Motorista),1,M)){
        if (motorista.cpf == cpf)  return motorista;
    }
    return motorista;
}

void MostrarPesquisaMotorista(){
    long int cpf;
    Motorista motorista;
    FILE *MPesquisa = AbrirArquivoMotorista();
    fseek(MPesquisa, 0, SEEK_SET);
    gotoxy (30,1); printf ("PESQUISA DE MOTORISTAS");
    gotoxy (11,20); printf ("                                                                  ");
    gotoxy (37,22); printf ("                   ");
    gotoxy (21,4); scanf ("%d", &cpf);
    motorista = PesquisarArquivoMotorista(cpf);
    textbackground(2);
    gotoxy (31,21); printf ("Aperte 'enter' para sair");
    textbackground(8);
    if (motorista.cpf == cpf){
        gotoxy (21,4);
    printf("%d", motorista.cpf);
    gotoxy (21,7);
        printf("%s", motorista.nome);
    gotoxy (21,10);
        printf("%", motorista.carro);
    gotoxy (21,13);
        printf("%s", motorista.cor);
    gotoxy (21,16);
    printf("%s", motorista.placa);
        textbackground(2);
        gotoxy (31,21); printf ("Aperte 'enter' para sair");
        getchar();
        getchar();
        cpf = -1;
        MenuMotorista();
    }
        if (cpf = -1){
            textbackground(2);
            gotoxy (26,19); printf ("O CPF nao esta cadastrado no sistema");
            gotoxy (31,21); printf ("Aperte 'enter' para sair");
        }
        getchar();
        getchar();
    MenuMotorista();
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
    motorista.avaliacao = 0;
    motorista.totalCorridas = 0;
    return motorista;
}


//a função fflush(fp) grava tudo que está no buffer
