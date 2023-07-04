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
    int opcao;
    do {
        MenuTelaInicial();
        }while (opcao != 27);

 return 0;
}



