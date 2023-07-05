#ifndef PASSAGEIROS_H_INCLUDED
#define PASSAGEIROS_H_INCLUDED

//DEFINICAO
struct passageiro {
    int ID;
    char CPF [12];
    char nome[51];
    char telefone[12];
};

typedef struct passageiro Passageiro;

//ARQUIVOS
FILE* AbrirArquivoPassageiros();
void FecharPassageiros();

//INTERFACE
int MenuPassageiro();

//FUNCOES
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

#endif // PASSAGEIROS_H_INCLUDED
