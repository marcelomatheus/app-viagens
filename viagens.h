#ifndef VIAGENS_H_INCLUDED
#define VIAGENS_H_INCLUDED
#include "motoristas.h"
#include "passageiros.h"

struct viagem{
    int numeroCorrida;
    char passageiro[55];
    char motorista[55];
    int IdPassageiro;
    int IDMotorista;
    double valor;
    double distancia;
    char origem[100];
    char destino[100];
    double tempo;
};
typedef struct viagem Viagem;

//MENU DE ACESSO
Passageiro Autenticacao();

//MENU PRINCIPAL
void MenuViagens();

//MENUS DE IMPRESSÃO DE INTERFACE
void MostrarTelaViagem(Passageiro p);
void MostrarTelaEspera();
void MostrarTelaEmbarque(Viagem viagens, Motorista motorista);//COM INTERAÇÃO
void MostrarTelaEndereco(Passageiro passageiro);


//GRAVACAO, LEITURA E COPIA DE DADOS
Viagem CopiarDadosParaViagens(Motorista motorista, Passageiro passageiros, Viagem viagens);
Viagem DigitarEndereco();
void gravarDadosViagem(Viagem viagens);
Viagem DeficoesViagem();

//UTILITÁRIOS
void pausar(float delay1);

//FUNCIONALIDADE ESPECIFICAS
Motorista EncontrarMotorista();
void AvaliarMotorista(Motorista motorista);

#endif // VIAGENS_H_INCLUDED
