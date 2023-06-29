#include <stdio.h>
#include <stdlib.h>
#include "passageiros.h"
#include "motorista.h"
#include "viagens.h"

int main()
{
    AbrirArquivoMotorista();
    int opcao;
    Motorista moto;

    printf("Digite 1 para cadastrar novo passageiro\n");
    printf("Digite 2 para cadastrar um novo motorista\n");
    printf("Digite 3 para fazer login como passageiro\n");
    printf("Digite 4 para acessar os relatorios de viagens da bublee\n");
    scanf("%d",&opcao);

    //As seguinties funções ainda não foram criadas, são apenas para estruturar o projeto
    if(opcao==1){

    }else if(opcao==2){
    CadastroMotorista();
    }else if(opcao==3){

    }else if(opcao==4){

    }

    fseek(M,0,SEEK_SET);
    while(fread(&moto,sizeof(Motorista),1,M)){
        printf("%s\n",moto.nome);
    }
    FecharArquivoMotorista();
    return 0;
}
