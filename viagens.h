#ifndef VIAGENS_H_INCLUDED
#define VIAGENS_H_INCLUDED

struct viagem{
    int numeroCorrida;
    char passageiro[55];
    char motorista [55];
    long int cpfPassageiro;
    long int cpfMotorista;
    double valor;
    double distancia;
    char origem[100];
    char destino[100];
    double tempo;
};

Passageiro Autenticacao();
void MenuViagens();

typedef struct viagem Viagem;
#endif // VIAGENS_H_INCLUDED
