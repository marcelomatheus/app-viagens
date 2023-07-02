#ifndef PRODUTO_H_INCLUDED
#define PRODUTO_H_INCLUDED
//AQUI EU COLOCO AS DEFINIÇÕES

struct produto {
    int codigo;
    char descricao[51];
    double preco;
    int saldo;
};

typedef struct produto Produto;


Produto DigitarProduto();
void ImprimirProduto (Produto P);
void ListarProdutos(Produto P[], int n);
Produto PesquisaProduto (Produto P[], int n);
void ImprimirProduto2 (Produto P);

//INTERFACE
void MenuProduto (int*opcao);

//PROGRAMA FICA ENTRE O CABEÇALHO E ESSA LINHA DE BAIXO
#endif // PRODUTO_H_INCLUDED
