#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
struct cliente {
    int codigo;
    char nome[51];
    char endereco[80];
    char telefone [11];
};

typedef struct cliente Cliente;

Cliente DigitarCliente();
void ImprimirCliente (Cliente C);
void ListarClientes(Cliente C[], int n);
Cliente PesquisaCliente (Cliente C[], int n, int codigo);

#endif // CLIENTE_H_INCLUDED
