#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "passageiros.h"
#include "interface.h"

FILE *fpPassageiro;

//ABRE O ARQUIVO DE PASSAGEIROS
FILE* AbrirArquivoPassageiros(){
    fpPassageiro = fopen("passageiros.txt", "rb+");
    if(fpPassageiro == NULL)
    {
        fpPassageiro = fopen("passageiros.txt", "wb+");
        if(fpPassageiro == NULL)
        {
            printf("Erro na abertura do arquivo passageiros.txt\n");
            exit(1);
        }
    }
return fpPassageiro;
}

//FECHA O ARQUIVO DE PASSAGEIROS
void FecharPassageiros(){
    fclose(fpPassageiro);
}

//PEDE DADOS DE PASSAGEIROS
void DigitarPassageiro(){
    Passageiro P;
    FILE * fpPassageiro = AbrirArquivoPassageiros();
    gotoxy (30,2); printf ("CADASTRO DE PASSAGEIRO");
    gotoxy (21,6); scanf ("%d", &P.ID);
    gotoxy (21,9); scanf (" %[^\n]", P.CPF);
    gotoxy (21,12); scanf (" %[^\n]", P.nome);
    gotoxy (21,15); scanf (" %[^\n]", P.telefone);
    fseek(fpPassageiro,0, SEEK_END);
    fwrite(&P, sizeof(Passageiro), 1, fpPassageiro);
    fclose(fpPassageiro);
}

//PESQUISA DE PASSAGEIRO
Passageiro PesquisarArquivoPassageiro(int codigo){
    Passageiro P;
    fseek(fpPassageiro, 0, SEEK_SET);
    while (fread (&P, sizeof(Passageiro),1,fpPassageiro)){
        if (P.ID == codigo)  return P;
    }
return P;
}

void MostrarPesquisaPassageiro(){
    int codigo;
    Passageiro P;
    FILE * fpPassageiro = AbrirArquivoPassageiros();
    fseek(fpPassageiro, 0, SEEK_SET);
    gotoxy (30,2); printf ("PESQUISA DE PASSAGEIROS");
    gotoxy (11,20); printf ("                                                                  ");
    gotoxy (37,22); printf ("                   ");
    gotoxy (21,6); scanf ("%d", &codigo);
    P = PesquisarArquivoPassageiro(codigo);
    textbackground(2);
    gotoxy (31,21); printf ("Aperte 'enter' para sair");
    textbackground(8);
    if (P.ID == codigo){
        gotoxy (21,6); printf ("%d", P.ID);
        gotoxy (21,9); printf ("%s", P.CPF);
        gotoxy (21,12); printf ("%s", P.nome);
        gotoxy (21,15); printf ("%s", P.telefone);
        textbackground(2);
        gotoxy (31,21); printf ("Aperte 'enter' para sair");
        getchar();
        getchar();
        codigo = -1;
        return;
    }
        if (codigo = -1){
            textbackground(2);
            gotoxy (26,19); printf ("O ID nao esta cadastrado no sistema");
            gotoxy (31,21); printf ("Aperte 'enter' para sair");
        }
        getchar();
        getchar();
    return;
}

//ALTERAR PASSAGEIRO
void AlterarArquivoPassageiro(){
    Passageiro P, Pnovo;
    int codigo;
    FILE * fpPassageiro = AbrirArquivoPassageiros();
    fseek(fpPassageiro, 0, SEEK_SET);
    gotoxy (30,2); printf ("ALTERAR PASSAGEIROS");
    gotoxy (11,20); printf ("                                                                  ");
    gotoxy (37,22); printf ("                   ");
    gotoxy (21,6); scanf ("%d", &codigo);
    P = PesquisarArquivoPassageiro(codigo);
    gotoxy (21,6); printf ("        ");
    textbackground(2);
    gotoxy (36,4); printf ("ID: %d", codigo);
    textbackground(8);
    if (P.ID == codigo) {
        fseek (fpPassageiro, -sizeof(Passageiro), SEEK_CUR);
        gotoxy (21,6); scanf ("%d", &Pnovo.ID);
        gotoxy (21,9); scanf (" %[^\n]", Pnovo.CPF);
        gotoxy (21,12); scanf (" %[^\n]", Pnovo.nome);
        gotoxy (21,15); scanf (" %[^\n]", Pnovo.telefone);
        textbackground(2);
        gotoxy (31,21); printf ("Aperte 'enter' para salvar");
        getchar();
        getchar();
        fwrite(&Pnovo, sizeof(Passageiro),1, fpPassageiro);
        fclose(fpPassageiro);
        codigo = -1;
        return;
    }
    if (codigo = -1){
        textbackground(2);
        gotoxy (26,19); printf ("O ID nao esta cadastrado no sistema");
        gotoxy (31,21); printf ("Aperte 'enter' para sair");
    }
    getchar();
    getchar();
    return;
}

//EXCLUIR PASSAGEIRO
void ExcluirArquivoPassageiro(){
    Passageiro P;
    int codigo;
    FILE * fpPassageiro = AbrirArquivoPassageiros();
    gotoxy (30,2); printf ("EXCLUIR PASSAGEIROS");
    gotoxy (11,20); printf ("                                                                  ");
    gotoxy (37,22); printf ("                   ");
    gotoxy (21,6); scanf ("%d", &codigo);
    P = PesquisarArquivoPassageiro(codigo);
    if (P.ID != -1) {
        gotoxy (21,6); printf ("%d", P.ID);
        gotoxy (21,9); printf ("%s", P.CPF);
        gotoxy (21,12); printf ("%s", P.nome);
        gotoxy (21,15); printf ("%s", P.telefone);
        fseek (fpPassageiro, -sizeof(Passageiro), SEEK_CUR);
        textbackground(2);
        gotoxy (29,21); printf ("Aperte 'enter' para excluir");
        getchar();
        getchar();
        P.ID = -1;
        fwrite(&P, sizeof(Passageiro),1, fpPassageiro);
        fclose(fpPassageiro);
        gotoxy (25,21); printf ("Passageiro excluido com sucesso");
        gotoxy (29,23); printf ("Aperte 'enter' para sair");
        getchar();
        }
        fclose(fpPassageiro);
        return;
}

//LISTAR PASSAGEIROS (abre arquivo HTML)
void ListarPassageiroHTML(FILE* fpPassageiro) {
    FILE* fpHTML = fopen("passageiros.html", "w");

    if (fpHTML == NULL) {
        printf("Erro ao abrir o arquivo HTML.\n");
        return;
    }
    // Escreve o cabeçalho do arquivo HTML
    fprintf(fpHTML, "<html>\n");
    fprintf(fpHTML, "<head>\n");
    fprintf(fpHTML, "<title>Passageiros Cadastrados</title>\n");
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
    fprintf(fpHTML, "td.cpf {\n");
    fprintf(fpHTML, "  width: 14%%;\n");
    fprintf(fpHTML, "}\n");
    fprintf(fpHTML, "td.nome {\n");
    fprintf(fpHTML, "  width: 30%%;\n");
    fprintf(fpHTML, "}\n");
    fprintf(fpHTML, "td.telefone {\n");
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
    fprintf(fpHTML, "<h1>PASSAGEIROS CADASTRADOS</h1>\n"); // Texto centralizado e com fundo verde
    fprintf(fpHTML, "<table>\n");
    fprintf(fpHTML, "<tr>\n");
    fprintf(fpHTML, "<th>ID</th>\n");
    fprintf(fpHTML, "<th>CPF</th>\n");
    fprintf(fpHTML, "<th>Nome</th>\n");
    fprintf(fpHTML, "<th>Telefone</th>\n");
    fprintf(fpHTML, "</tr>\n");

    // Lê os dados do arquivo binário e escreve no arquivo HTML
    Passageiro P;
    while (fread(&P, sizeof(Passageiro), 1, fpPassageiro) == 1) {
            if (P.ID != -1) {
                    fprintf(fpHTML, "<tr>\n");
                    fprintf(fpHTML, "<td class=\"id\">%10d</td>\n", P.ID);
                    fprintf(fpHTML, "<td class=\"cpf\">%14s</td>\n", P.CPF);
                    char nome[29];
                    strncpy(nome, P.nome, 28);
                    nome[28] = '\0';
                    fprintf(fpHTML, "<td class=\"nome\">%s</td>\n", nome);
                    fprintf(fpHTML, "<td class=\"telefone\">%10s</td>\n", P.telefone);
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
    system("start passageiros.html");
    return;
}

//INTERFACE DE PASSAGEIRO
int MenuPassageiro (){
    FILE * fpPassageiro = AbrirArquivoPassageiros();
    int op;
    char opcoes[][21] = {"Novo", "Pesquisar", "Alterar", "Excluir", "Listar", "MENU ANTERIOR"};
    int x[] = {12, 25, 40, 55, 70, 37};
    int y[] = {20, 20, 20, 20, 20, 22};
    do{
        MostrarTelaPassageiros();
        op = MenuHorizontal (opcoes, x, y, 6);
        if (op == 0) DigitarPassageiro();
        if (op == 1) MostrarPesquisaPassageiro();
        if (op == 2) AlterarArquivoPassageiro();
        if (op == 3) ExcluirArquivoPassageiro();
        if (op == 4) ListarPassageiroHTML(fpPassageiro);
        if (op == 5) MenuTelaInicial ();
    } while (op != 27);
    return op;
}




