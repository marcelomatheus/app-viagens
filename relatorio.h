#ifndef RELATORIO_H_INCLUDED
#define RELATORIO_H_INCLUDED
#include "motoristas.h"
#include "passageiros.h"
#include "viagens.h"
#include "interface.h"

//PARA ABRIR ARQUIVOS
FILE* AbrirArquivoViagens();

//IMPRESSAO DOS ARQUIVS HTML
void ImprimirRelatorioHTMLMoto(FILE* fpMotorista, int codigo);
void ImprimirRelatorioHTMLPass(FILE* fpViagem, int codigo);

//MENUS DE RELATÓRIO
void MenuRelatoriosMotorista();
void MenuRelatoriosPassageiro();


#endif // RELATORIO_H_INCLUDED
