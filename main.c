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
    int opcao;
    do {
        MenuTelaInicial();
        }while (opcao != 27);

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
