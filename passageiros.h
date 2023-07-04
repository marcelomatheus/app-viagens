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
void MenuPassageiro();

//FUNCOES
void DigitarPassageiro();
Passageiro PesquisarArquivoPassageiro(int codigo);
Passageiro MostrarPesquisaPassageiro();
void AlterarArquivoPassageiro();
void ExcluirArquivoPassageiro();
void ListarPassageiroHTML(FILE* fpPassageiro);

#endif // PASSAGEIROS_H_INCLUDED
