#include <stdio.h>
#include <string.h>
#include "interface.h"
#include "motoristas.h"
#include "passageiros.h"
#include "viagens.h"
FILE *fpPassageiro;

/*A seguinte função solicita a escrita do cpf do passeiro e verifica se ele existe no arquivo passageiros.txt,
caso exista, retorna os dados do usuário em forma de struct; caso não exista, retorna ao MenuViagens() solicitando um novo cpf*/

Passageiro Autenticacao(){

    fpPassageiro = AbrirArquivoPassageiros();
    int CPF,op;
    Passageiro passageiro;
    system("cls");
    Borda (0,0,85,25,1,0);
    Borda(2,5,81,15,0,0);
    gotoxy(36,5);
    printf("FACO O LOGIN");
    gotoxy(34,10);
    printf("Informe o seu CPF");
    Borda (35,11,13,2,0,0);
    gotoxy(37,12);
    scanf("%d",&CPF);
    fseek(fpPassageiro,0,SEEK_SET);
    while(fread(&passageiro,sizeof(Passageiro),1,fpPassageiro)){
        if(passageiro.CPF==CPF){
            return passageiro;
        }
    }
    gotoxy(31,14);
    printf("Usuario nao encontrado!");
    gotoxy(25,15);
    printf("Pressione Enter para tentar novamente");
    gotoxy(35,16);
    printf("ou ESC para sair");
    op = getTecla();
    if(op==27){
        main();
    }else{
        MenuViagens();
    }

}

void TelaViagem(){

}

void MenuViagens(){
    Viagem viagens;
    Passageiro passageiro;
    passageiro = Autenticacao();
    TelaViagem();
}
