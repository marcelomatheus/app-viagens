#include <stdio.h>
#include "motorista.h"
FILE *M;

void AbrirArquivoMotorista(){
    M = fopen("motorista.txt","ab+");
}

void GravarDados(Motorista motorista){
    fwrite(&motorista,sizeof(Motorista),1,M);
}
void FecharArquivoMotorista(){
    fclose(M);
}

void CadastroMotorista(){
    Motorista motorista;
    printf("Cadastro de motoristas\n");
    printf("Nome: ");
    scanf(" %[^\n]",motorista.nome);
    printf("Modelo do veiculo: ");
    scanf(" %[^\n]",motorista.carro);
    printf("Placa: ");
    scanf(" %[^\n]",motorista.placa);
    AbrirArquivoMotorista();
    GravarDados(motorista);
    FecharArquivoMotorista();
}
//a função fflush(fp) grava tudo que está no buffer
