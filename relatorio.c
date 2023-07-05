#include <stdio.h>
#include <string.h>
#include "motoristas.h"
#include "passageiros.h"
#include "viagens.h"
#include "interface.h"
#include "relatorio.h"
FILE *fpViagem;
FILE *fpPassageiro;
FILE *fpMotorista;
FILE *fpRelatorioMotorista;

FILE* AbrirArquivoViagens(){
    fpViagem = fopen("viagens.txt","rb+");
    if(fpViagem==NULL){
        printf("Erro ao abrir o arquivo");
    }
    return fpViagem;
}


void ImprimirRelatorioHTMLMoto(FILE* fpMotorista, int codigo) {
    FILE* fpHTML = fopen("remotorista.html", "w");

    if (fpHTML == NULL) {
        printf("Erro ao abrir o arquivo HTML.\n");
        return;
    }
    // Escreve o cabeçalho do arquivo HTML
    fprintf(fpHTML, "<html>\n");
    fprintf(fpHTML, "<head>\n");
    fprintf(fpHTML, "<title>Relatorio de Viagens</title>\n");
    fprintf(fpHTML, "<style>\n");
    fprintf(fpHTML, "body {\n");
    fprintf(fpHTML, "  background-color: #222;\n"); // Cor de fundo cinza escuro
    fprintf(fpHTML, "  color: white;\n"); // Cor do texto branco
    fprintf(fpHTML, "}\n");
    fprintf(fpHTML, "table {\n");
    fprintf(fpHTML, "  border-collapse: collapse;\n");
    fprintf(fpHTML, "  width: 100%%;\n");
    fprintf(fpHTML, "}\n");
    fprintf(fpHTML, "th, td {\n");
    fprintf(fpHTML, "  border: 1px solid white;\n"); // Linhas da tabela em branco
    fprintf(fpHTML, "  padding: 8px;\n");
    fprintf(fpHTML, "  color: white;\n"); // Cor do texto da tabela branco
    fprintf(fpHTML, "}\n");
    fprintf(fpHTML, "td.id {\n");
    fprintf(fpHTML, "  width: 10%%;\n");
    fprintf(fpHTML, "}\n");
    fprintf(fpHTML, "td.nome {\n");
    fprintf(fpHTML, "  width: 14%%;\n");
    fprintf(fpHTML, "}\n");
    fprintf(fpHTML, "td.origem {\n");
    fprintf(fpHTML, "  width: 30%%;\n");
    fprintf(fpHTML, "}\n");
    fprintf(fpHTML, "td.descricao {\n");
    fprintf(fpHTML, "  width: 10%%;\n");
    fprintf(fpHTML, "}\n");
    fprintf(fpHTML, "h1 {\n");
    fprintf(fpHTML, "  text-align: center;\n");
    fprintf(fpHTML, "  background-color: green;\n"); // Fundo verde do cabeçalho
    fprintf(fpHTML, "  color: white;\n"); // Cor do texto do cabeçalho branco
    fprintf(fpHTML, "  padding: 10px;\n");
    fprintf(fpHTML, "}\n");
    fprintf(fpHTML, "</style>\n");
    fprintf(fpHTML, "</head>\n");
    fprintf(fpHTML, "<body>\n");
    fprintf(fpHTML, "<h1>HISTORICO DO MOTORISTA</h1>\n"); // Texto centralizado e com fundo verde
    fprintf(fpHTML, "<table>\n");
    fprintf(fpHTML, "<tr>\n");
    fprintf(fpHTML, "<th>ID Passageiro</th>\n");
    fprintf(fpHTML, "<th>Nome</th>\n");
    fprintf(fpHTML, "<th>Origem e destino</th>\n");
    fprintf(fpHTML, "<th>Descricao</th>\n");
    fprintf(fpHTML, "</tr>\n");

    // Lê os dados do arquivo binário e escreve no arquivo HTML
    Viagem V;
    while (fread(&V, sizeof(Viagem), 1, fpViagem) == 1) {
            if (V.IDMotorista==codigo) {
                    fprintf(fpHTML, "<tr>\n");
                    fprintf(fpHTML, "<td class=\"id\">%10d</td>\n", V.IdPassageiro);
                    fprintf(fpHTML, "<td class=\"nome\">%14s</td>\n", V.passageiro);
                    fprintf(fpHTML, "<td class=\"origem\">De %.20s a %.20s</td>\n", V.origem, V.destino);
                    fprintf(fpHTML, "<td class=\"descricao\">R$%.2lf - %.0lf minutos</td>\n", V.valor,V.tempo);
                    fprintf(fpHTML, "</tr>\n");
            }
    }

    // Fecha as tags do arquivo HTML
    fprintf(fpHTML, "</table>\n");
    fprintf(fpHTML, "</body>\n");
    fprintf(fpHTML, "</html>\n");

    fclose(fpHTML);
    textbackground(2);
    gotoxy (29,18); printf("Arquivo HTML gerado com sucesso.");
    system("start remotorista.html");
    return;
}

void ImprimirRelatorioHTMLPass(FILE* fpViagem, int codigo) {
    FILE* fpHTML = fopen("repassageiro.html", "w");

    if (fpHTML == NULL) {
        printf("Erro ao abrir o arquivo HTML.\n");
        return;
    }
    // Escreve o cabeçalho do arquivo HTML
    fprintf(fpHTML, "<html>\n");
    fprintf(fpHTML, "<head>\n");
    fprintf(fpHTML, "<title>Relatorio de Viagens</title>\n");
    fprintf(fpHTML, "<style>\n");
    fprintf(fpHTML, "body {\n");
    fprintf(fpHTML, "  background-color: #222;\n"); // Cor de fundo cinza escuro
    fprintf(fpHTML, "  color: white;\n"); // Cor do texto branco
    fprintf(fpHTML, "}\n");
    fprintf(fpHTML, "table {\n");
    fprintf(fpHTML, "  border-collapse: collapse;\n");
    fprintf(fpHTML, "  width: 100%%;\n");
    fprintf(fpHTML, "}\n");
    fprintf(fpHTML, "th, td {\n");
    fprintf(fpHTML, "  border: 1px solid white;\n"); // Linhas da tabela em branco
    fprintf(fpHTML, "  padding: 8px;\n");
    fprintf(fpHTML, "  color: white;\n"); // Cor do texto da tabela branco
    fprintf(fpHTML, "}\n");
    fprintf(fpHTML, "td.id {\n");
    fprintf(fpHTML, "  width: 10%%;\n");
    fprintf(fpHTML, "}\n");
    fprintf(fpHTML, "td.nome {\n");
    fprintf(fpHTML, "  width: 14%%;\n");
    fprintf(fpHTML, "}\n");
    fprintf(fpHTML, "td.origem {\n");
    fprintf(fpHTML, "  width: 30%%;\n");
    fprintf(fpHTML, "}\n");
    fprintf(fpHTML, "td.descricao {\n");
    fprintf(fpHTML, "  width: 10%%;\n");
    fprintf(fpHTML, "}\n");
    fprintf(fpHTML, "h1 {\n");
    fprintf(fpHTML, "  text-align: center;\n");
    fprintf(fpHTML, "  background-color: green;\n"); // Fundo verde do cabeçalho
    fprintf(fpHTML, "  color: white;\n"); // Cor do texto do cabeçalho branco
    fprintf(fpHTML, "  padding: 10px;\n");
    fprintf(fpHTML, "}\n");
    fprintf(fpHTML, "</style>\n");
    fprintf(fpHTML, "</head>\n");
    fprintf(fpHTML, "<body>\n");
    fprintf(fpHTML, "<h1>HISTORICO DO PASSAGEIRO</h1>\n"); // Texto centralizado e com fundo verde
    fprintf(fpHTML, "<table>\n");
    fprintf(fpHTML, "<tr>\n");
    fprintf(fpHTML, "<th>ID Motorista</th>\n");
    fprintf(fpHTML, "<th>Motorista</th>\n");
    fprintf(fpHTML, "<th>Origem e destino</th>\n");
    fprintf(fpHTML, "<th>Descricao</th>\n");
    fprintf(fpHTML, "</tr>\n");

    // Lê os dados do arquivo binário e escreve no arquivo HTML
    Viagem V;
    while (fread(&V, sizeof(Viagem), 1, fpViagem) == 1) {
            if (V.IdPassageiro==codigo) {
                    fprintf(fpHTML, "<tr>\n");
                    fprintf(fpHTML, "<td class=\"id\">%10d</td>\n", V.IDMotorista);
                    fprintf(fpHTML, "<td class=\"nome\">%14s</td>\n", V.motorista);
                    fprintf(fpHTML, "<td class=\"origem\">De %.20s a %.20s</td>\n", V.origem, V.destino);
                    fprintf(fpHTML, "<td class=\"descricao\">R$%.2lf - %.0lf minutos</td>\n", V.valor,V.tempo);
                    fprintf(fpHTML, "</tr>\n");
            }
    }

    // Fecha as tags do arquivo HTML
    fprintf(fpHTML, "</table>\n");
    fprintf(fpHTML, "</body>\n");
    fprintf(fpHTML, "</html>\n");

    fclose(fpHTML);
    textbackground(2);
    gotoxy (29,18); printf("Arquivo HTML gerado com sucesso.");
    system("start repassageiro.html");
    return;
}


void MenuRelatoriosMotorista(){
    Viagem viagens;
    fpViagem=AbrirArquivoViagens();
    int codigo;
    Borda (0,0,85,25,1,0);
    Borda (32,12,18,3,0,0);
    gotoxy(15,10);
    printf("Digite o ID do motorista para gerar o historico de viagens");
    gotoxy(33,13);
    scanf("%d",&codigo);
    ImprimirRelatorioHTMLMoto(fpViagem,codigo);
    fclose(fpViagem);
}



void MenuRelatoriosPassageiro(){
    Viagem viagens;
    fpViagem=AbrirArquivoViagens();
    int codigo;
    Borda (0,0,85,25,1,0);
    Borda (32,12,18,3,0,0);
    gotoxy(15,10);
    printf("Digite o ID do passageiro para gerar o historico de viagens");
    gotoxy(33,13);
    scanf("%d",&codigo);
    ImprimirRelatorioHTMLPass(fpViagem,codigo);
    fclose(fpViagem);
}
