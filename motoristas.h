#ifndef MOTORISTA_H_INCLUDED
#define MOTORISTA_H_INCLUDED

struct motorista{
    int ID;;
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
void ExcluirArquivoMotorista();
void GravarDados(Motorista motorista);
FILE* AbrirArquivoMotorista();
void SomarCorridaAoMotorista(Motorista motorista);
void ListarMotoristaHTML(FILE* fpMotorista);
int QuantidadeMotoristas(FILE *Arquivo);
void CalcularAvaliacaoMotorista(Motorista motoristaParametro, double novaAvaliacao);
Motorista PesquisarArquivoMotorista(int ID);
void MostrarPesquisaMotorista();
void MostrarTelaMotorista();
Motorista DigitarMotorista();
void AlterarArquivoMotorista();

#endif // MOTORISTA_H_INCLUDED
