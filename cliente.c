#include <stdio.h>
#include "cliente.h"

//FUNÇÕES:

Cliente DigitarCliente(){
    Cliente C;
    printf ("CODIGO: "); scanf ("%d", &C.codigo);
    printf ("NOME: "); scanf (" %[^\n]", C.nome);
    printf ("ENDERECO: "); scanf (" %[^\n]", C.endereco);
    printf ("TELEFONE: "); scanf (" %[^\n]", C.telefone);

return C;
}

void ImprimirCliente (Cliente C){
    printf ("\nCODIGO: %d\nNOME:%s\nENDERECO:%s\nTELEFONE:%s\n\n", C.codigo, C.nome, C.endereco, C.telefone);
    printf ("-----------------------\n");
}

Cliente PesquisaCliente (Cliente C[], int n, int codigo){
    int i;
    for (i=0; i<n;i++){
        if (codigo == C[i].codigo) ImprimirCliente(C[i]);
        }
}

void ListarClientes(Cliente C[], int n){
    int i;
    for (i=0;i<n;i++){
        if (C[i].codigo >= 0) ImprimirCliente(C[i]);    //OBS "Clientes" é tipo e não usa para repassar para a funcção
        }
}
