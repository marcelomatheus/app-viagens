#ifndef MOTORISTA_H_INCLUDED
#define MOTORISTA_H_INCLUDED

struct motorista{
    char nome[25];
    char carro[25];
    char placa[9];
};

typedef struct motorista Motorista;
void CadastroMotorista();
void FecharArquivoMotorista();
void GravarDados(Motorista motorista);
void AbrirArquivoMotorista();

#endif // MOTORISTA_H_INCLUDED
