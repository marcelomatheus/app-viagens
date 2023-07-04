#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "produto.h"
#include "cliente.h"
#include "interface.h"


/*Controle de Viagens por Aplicativos
Cadastros:
    Motoristas
        placa do ve�culo
        marca do ve�culo
        nome do motorista
        telefone do motorista
    Passageiros
        CPF
        nome
        endereco
        telefone
Rotinas:
    Solicitar Viagem
    Cancelar Viagem
    Avaliar Motorista
Relat�rios
Viagens por Motorista (mostrar detalhes)
Viagens por Passageiro (mostrar detalhes)
Faturamento Total

Nesse exemplo, o menu principal do sistema de viagens por aplicativos tem tr�s categorias principais: Cadastros, Rotinas e Relat�rios. Cada categoria tem op��es espec�ficas relacionadas �s funcionalidades do sistema.

A op��o "Cadastros" permite o gerenciamento de informa��es relacionadas aos motoristas, passageiros e ve�culos. Isso inclui adicionar, editar e excluir registros dessas entidades.

A categoria "Rotinas" engloba funcionalidades relacionadas � execu��o das viagens, como solicitar uma viagem, verificar o hist�rico de viagens e cancelar uma viagem em andamento.

A se��o "Relat�rios" oferece a gera��o de informa��es estat�sticas sobre as viagens realizadas, como o n�mero de viagens por motorista, o n�mero de viagens por passageiro e o faturamento mensal do servi�o.

Voc� pode adaptar esse exemplo de acordo com as necessidades espec�ficas do seu sistema de viagens por aplicativos.

*/





int main (){
    Produto Produtos[100]; //J� COM TYPEDEF
    Cliente Clientes[100];
    int quant = 0, opcao, codigo, i, menu, opcao2, quant2, codigo2;
    do {
        MenuTelaInicial();
        /*printf ("\MENU\n\n");
        printf ("1 - Produto\n2 - Cliente\n\n0 - Sair\n\n\n");
        printf ("Escolha a opcao: "); scanf ("%d", &menu);*/

        //CADASTRO DE PRODUTOS
        if (menu == 0) {
        do {
        MenuProduto(&opcao);
        /*printf ("\nCADASTRO DE PRODUTOS\n\n");
        printf ("0 - Novo produto\n1 - Pesquisar produto\n2 - Alterar produto\n3 - Excluir produto\n4 - Listar produtos\n\n5 - Voltar para o menu anterior\n\n\n");
        printf ("Escolha a opcao: "); scanf ("%d", &opcao);*/
        if (opcao == 0){
            Produtos[quant]=DigitarProduto();
            quant++;
        }

        if (opcao == 1){
            /*for (i=0; i<quant;i++){
                if (codigo == Produtos[i].codigo) ImprimirProduto(Produtos[i]);
                }*/
            PesquisaProduto (Produtos, quant);
            }

        if (opcao == 2){
            printf("CODIGO DO PRODUTO: "); scanf ("%d", &codigo);
            for (i=0; i<quant;i++){
                if (codigo == Produtos[i].codigo) Produtos[quant]=DigitarProduto();
                }
            }

        if (opcao == 3){
            printf("CODIGO DO PRODUTO: "); scanf ("%d", &codigo);
            for (i=0; i<quant;i++){
                if (codigo == Produtos[i].codigo) Produtos[i].codigo = Produtos[i].codigo * (-1);

                }
            }

        if (opcao == 4){
            MostrarTelaListarProdutos();
            ListarProdutos(Produtos, quant);
            /*for (i=0; i<quant;i++){
                    if (Produtos[i].codigo >= 0) ImprimirProduto(Produtos[i]);
            }*/
                }
            }
            while (opcao != 5);
        }



        //CADASTRO DE CLIENTES
        if (menu == 2) {
            do {
                printf ("\nCADASTRO DE CLIENTE\n\n");
                printf ("1 - Novo cadastro\n2 - Pesquisar cadastro\n3 - Alterar cadastro\n4 - Excluir cadastro\n5 - Listar clientes\n\n0 - Voltar para o menu anterior\n\n\n");
                printf ("Escolha a opcao: "); scanf ("%d", &opcao2);
                if (opcao2 == 1){
                    Clientes[quant2]= DigitarCliente();
                    quant2++;
                    }

                if (opcao2 == 2){
                    printf("CODIGO DO CLIENTE: "); scanf ("%d", &codigo2);
                    PesquisaCliente (Clientes, quant2, codigo2);
                    }

                if (opcao2 == 3){
                    printf("CODIGO DO CLIENTE: "); scanf ("%d", &codigo2);
                    for (i=0; i<quant2;i++){
                        if (codigo2 == Clientes[i].codigo) Clientes[quant2]= DigitarCliente();
                        }
                    }

                if (opcao2 == 4){
                    printf("CODIGO DO CLIENTE: "); scanf ("%d", &codigo2);
                    for (i=0; i<quant2;i++){
                        if (codigo2 == Clientes[i].codigo) Clientes[i].codigo = Clientes[i].codigo * (-1);
                        }
                    }

                if (opcao2 == 5){
                    ListarClientes(Clientes, quant2);
                        }
                    }
                    while (opcao2 != 0);
                }

            }while (menu != 0 );

 return 0;
}


//VARI�VEIS COMUNS S�O REPASSADAS COMO C�PIA, MAS VETOR E MATRIZ N�O! � REPASSADO O ENDERE�O. USANDO STRUCT, O SISTEMA TBM PASSA UMA C�PIA
//O STRUCT � COMO SE FOSSE UMA VARI�VEL COMUM
//FORMAS DE ORGANIZAR PROGRAMAS GRANDES -> FAZENDO ARQUIVOS
//PARA COMPILAR V�RIOS ARQUIVOS PARA SEREM COMPILADOS JUNTOS, TEM QUE CRIAR "projeto" (igual j� estava fazendo)
//PARA CADA ARQUIVO .c QUE CRIAR, TEM QUE FAZER UM .h (COM AS FUNCIONALIDADES) PARA USAR 'INCLUDE'

/*COMO FAZER:
NOVO ARQUIVO, FILE, H (VERMELHO), DAR O NOME e PROOOOONTO!
DEPOIS: NOVO ARQUIO, FILE, CC source*/
