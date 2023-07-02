#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "produto.h"
#include "cliente.h"
#include "interface.h"


/*Controle de Viagens por Aplicativos
Cadastros:
    Motoristas
        placa do veículo
        marca do veículo
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
Relatórios
Viagens por Motorista (mostrar detalhes)
Viagens por Passageiro (mostrar detalhes)
Faturamento Total

Nesse exemplo, o menu principal do sistema de viagens por aplicativos tem três categorias principais: Cadastros, Rotinas e Relatórios. Cada categoria tem opções específicas relacionadas às funcionalidades do sistema.

A opção "Cadastros" permite o gerenciamento de informações relacionadas aos motoristas, passageiros e veículos. Isso inclui adicionar, editar e excluir registros dessas entidades.

A categoria "Rotinas" engloba funcionalidades relacionadas à execução das viagens, como solicitar uma viagem, verificar o histórico de viagens e cancelar uma viagem em andamento.

A seção "Relatórios" oferece a geração de informações estatísticas sobre as viagens realizadas, como o número de viagens por motorista, o número de viagens por passageiro e o faturamento mensal do serviço.

Você pode adaptar esse exemplo de acordo com as necessidades específicas do seu sistema de viagens por aplicativos.

*/





int main (){
    Produto Produtos[100]; //JÁ COM TYPEDEF
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


//VARIÁVEIS COMUNS SÃO REPASSADAS COMO CÓPIA, MAS VETOR E MATRIZ NÃO! É REPASSADO O ENDEREÇO. USANDO STRUCT, O SISTEMA TBM PASSA UMA CÓPIA
//O STRUCT É COMO SE FOSSE UMA VARIÁVEL COMUM
//FORMAS DE ORGANIZAR PROGRAMAS GRANDES -> FAZENDO ARQUIVOS
//PARA COMPILAR VÁRIOS ARQUIVOS PARA SEREM COMPILADOS JUNTOS, TEM QUE CRIAR "projeto" (igual já estava fazendo)
//PARA CADA ARQUIVO .c QUE CRIAR, TEM QUE FAZER UM .h (COM AS FUNCIONALIDADES) PARA USAR 'INCLUDE'

/*COMO FAZER:
NOVO ARQUIVO, FILE, H (VERMELHO), DAR O NOME e PROOOOONTO!
DEPOIS: NOVO ARQUIO, FILE, CC source*/
