#ifndef PASSAGEIROS_H_INCLUDED
#define PASSAGEIROS_H_INCLUDED

//DEFINICAO
struct passageiro {
    int ID;
    long int CPF;
    char nome[51]; //somente números
    char telefone[11];
};

typedef struct passageiro Passageiro;

//ARQUIVOS
FILE* AbrirArquivoPassageiros();
void FecharPassageiros();

//INTERFACE
void MenuPassageiro();

//FUNCOES
void DigitarPassageiro();


#endif // PASSAGEIROS_H_INCLUDED
