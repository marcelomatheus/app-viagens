#include <stdio.h>
#include <stdlib.h>
#include "passageiros.h"
#include "motorista.h"
#include "viagens.h"

int main()
{
    int opcao;

    printf("Digite 1 para cadastrar novo passageiro\n");
    printf("Digite 2 para cadastrar um novo motorista\n");
    printf("Digite 3 para fazer login como passageiro\n");
    printf("Digite 4 para acessar os relatorios de viagens da bublee\n");
    scanf("%d",&opcao);

    //As seguinties fun��es ainda n�o foram criadas, s�o apenas para estruturar o projeto

    if(opcao==1){
        CadastroPassageiro();
    }else if(opcao==2){
        CadastroMotorista();
    }else if(opcao==3){
        MenuPassageiro();
    }else if(opcao==4){
        Relatorios();
    }
    return 0;
}
