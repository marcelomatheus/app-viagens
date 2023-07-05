#ifndef MOTORISTA_H_INCLUDED
#define MOTORISTA_H_INCLUDED

struct motorista{
    long int cpf;
    char nome[55];
    char carro[25];
    char cor[10];
    char placa[9];
    double avaliacao;
    int totalCorridas;
};

typedef struct motorista Motorista;
void CadastroMotorista();
void FecharArquivoMotorista();
void ExcluirMotorista();
void GravarDados(Motorista motorista);
FILE* AbrirArquivoMotorista();
void SomarCorridaAoMotorista(Motorista motorista);
Motorista PesquisarArquivoMotorista(long int cpf);
void MostrarPesquisaMotorista();
void MostrarTelaMotorista();
Motorista DigitarMotorista();

#endif // MOTORISTA_H_INCLUDED
