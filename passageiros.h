#ifndef PASSAGEIROS_H_INCLUDED
#define PASSAGEIROS_H_INCLUDED

struct passageiro {
    char CPF [11];
    char nome[51]; //somente números
    char telefone[11];
};

typedef struct passageiro Passageiro;

void AbrirArquivoPassageiros();
void FecharPassageiros();
void MenuPassageiro ();



#endif // PASSAGEIROS_H_INCLUDED
