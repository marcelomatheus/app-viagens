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
    int opcao;
    do {
        MenuTelaInicial();
        }while (opcao != 27);

 return 0;
}



