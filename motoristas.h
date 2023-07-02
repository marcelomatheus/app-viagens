#ifndef MOTORISTA_H_INCLUDED
#define MOTORISTA_H_INCLUDED

struct motorista{
    long int cpf;
    char nome[55];
    char carro[25];
    char cor[10];
    char placa[9];
};

typedef struct motorista Motorista;
void CadastroMotorista();
void FecharArquivoMotorista();
void ExcluirMotorista();
void GravarDados(Motorista motorista);
void AbrirArquivoMotorista();
void PesquisarMotorista();
void MostrarTelaMotorista();
Motorista DigitarMotorista();

#endif // MOTORISTA_H_INCLUDED
