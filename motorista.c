#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "motoristas.h"
#include "interface.h"


FILE *M;

FILE* AbrirArquivoMotorista()
{
    FILE *MAberto;
    MAberto = fopen("motorista.txt","rb+");
    if(MAberto==NULL)
    {
        MAberto = fopen("motorista.txt","wb+");

        if(MAberto==NULL){
            printf("Nao foi possivel abrir o arquivo");
            exit(0);
        }
        return MAberto;
    }
    return MAberto;

}

void GravarDados(Motorista motorista)
{

    fwrite(&motorista,sizeof(Motorista),1,M);
    fclose(M);
}

void ListarMotoristaHTML(FILE* fpMotorista) {
    FILE* fpHTML = fopen("motoristas.html", "w");

    if (fpHTML == NULL) {
        printf("Erro ao abrir o arquivo HTML.\n");
        return;
    }
    // Escreve o cabeçalho do arquivo HTML
    fprintf(fpHTML, "<html>\n");
    fprintf(fpHTML, "<head>\n");
    fprintf(fpHTML, "<title>Motoristas Cadastrados</title>\n");
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
    fprintf(fpHTML, "td.carro {\n");
    fprintf(fpHTML, "  width: 30%%;\n");
    fprintf(fpHTML, "}\n");
    fprintf(fpHTML, "td.placa {\n");
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
    fprintf(fpHTML, "<h1>MOTORISTAS CADASTRADOS</h1>\n"); // Texto centralizado e com fundo verde
    fprintf(fpHTML, "<table>\n");
    fprintf(fpHTML, "<tr>\n");
    fprintf(fpHTML, "<th>ID</th>\n");
    fprintf(fpHTML, "<th>Nome</th>\n");
    fprintf(fpHTML, "<th>Carro</th>\n");
    fprintf(fpHTML, "<th>Placa</th>\n");
    fprintf(fpHTML, "</tr>\n"); //ID, Nome, Carro, Placa

    // Lê os dados do arquivo binário e escreve no arquivo HTML
    Motorista M;
    while (fread(&M, sizeof(Motorista), 1, fpMotorista) == 1) {
            if (M.ID != -1) {
                    fprintf(fpHTML, "<tr>\n");
                    fprintf(fpHTML, "<td class=\"id\">%10d</td>\n", M.ID);
                    fprintf(fpHTML, "<td class=\"nome\">%s</td>\n", M.nome);
                    fprintf(fpHTML, "<td class=\"carro\">%s</td>\n", M.carro);
                    fprintf(fpHTML, "<td class=\"claca\">%7s</td>\n", M.placa);
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
    system("start motoristas.html");

}


void MenuMotorista()
{
    int op;
    Motorista motorista;
    M=AbrirArquivoMotorista();
    char opcoes[][21] = {"Novo", "Pesquisar", "Alterar", "Excluir", "Listar", "MENU ANTERIOR"};
    int x[] = {12, 25, 40, 55, 70, 37};
    int y[] = {20, 20, 20, 20, 20, 22};
    do
    {
        MostrarTelaMotorista();
        op = MenuHorizontal (opcoes, x, y, 6);
        if (op == 0)
        {
            motorista = DigitarMotorista();
            fseek(M,0, SEEK_END);
            GravarDados(motorista);

        }
        else if(op==1 )
        {
            MostrarPesquisaMotorista();

        }else if(op==2){
            AlterarArquivoMotorista();
        }else if(op==3){
            ExcluirArquivoMotorista();
        }else if(op==4){
            ListarMotoristaHTML(M);
        }
        fclose(M);
        if (op == 5) MenuTelaInicial();
    }
    while (op=! 27);
    fclose(M);
}

int QuantidadeMotoristas(FILE *Arquivo){
    Motorista motorista;
    int quantidadeMotorista = 0;
    fseek(Arquivo,0,SEEK_SET);
    while(fread(&motorista,sizeof(Motorista),1,Arquivo)){
        quantidadeMotorista++;
    }
    return quantidadeMotorista;
}

void CalcularAvaliacaoMotorista(Motorista motoristaParametro, double novaAvaliacao){
    Motorista motoristaComparacao;
    FILE *MAvaliacao = fopen("motorista.txt","rb+");
    if(MAvaliacao==NULL){
        printf("Erro");
    }
    ;
    fseek(MAvaliacao,0,SEEK_SET);
    while(fread(&motoristaComparacao,sizeof(Motorista),1,MAvaliacao)){
        if(motoristaComparacao.ID==motoristaParametro.ID){
            motoristaParametro.avaliacao = (motoristaParametro.avaliacao+novaAvaliacao)/(double)motoristaParametro.totalCorridas;
           fseek(MAvaliacao,-sizeof(Motorista),SEEK_CUR);
           fwrite(&motoristaParametro,sizeof(Motorista),1,MAvaliacao);
           fflush(MAvaliacao);
           return;
        }
    }
    fclose(MAvaliacao);
}

void SomarCorridaAoMotorista(Motorista motoristaParametro){
    Motorista motoristaComparacao;
    FILE *MSoma = fopen("motorista.txt","rb+");
    if(MSoma==NULL){
        printf("Erro");
    }
    motoristaParametro.totalCorridas = motoristaParametro.totalCorridas+1;
    fseek(MSoma,0,SEEK_SET);
    while(fread(&motoristaComparacao,sizeof(Motorista),1,MSoma)){
        if(motoristaComparacao.ID==motoristaParametro.ID){
           fseek(MSoma,-sizeof(Motorista),SEEK_CUR);
           fwrite(&motoristaParametro,sizeof(Motorista),1,MSoma);
           fflush(MSoma);
           return;
        }
    }
    fclose(MSoma);
}

//PESQUISAR MOTORISTA
Motorista PesquisarArquivoMotorista(int ID){
    Motorista motorista;
    fseek(M, 0, SEEK_SET);
    while (fread (&motorista, sizeof(Motorista),1,M)){
        if (motorista.ID == ID)  return motorista;
    }
    return motorista;
}

void MostrarPesquisaMotorista(){
    int ID;
    Motorista motorista;
    FILE *MPesquisa = AbrirArquivoMotorista();
    fseek(MPesquisa, 0, SEEK_SET);
    gotoxy (30,1); printf ("PESQUISA DE MOTORISTAS");
    gotoxy (11,20); printf ("                                                                  ");
    gotoxy (37,22); printf ("                   ");
    gotoxy (21,4); scanf ("%d", &ID);
    motorista = PesquisarArquivoMotorista(ID);
    textbackground(2);
    gotoxy (31,21); printf ("Aperte 'enter' para sair");
    textbackground(8);
    if (motorista.ID == ID){

    gotoxy (21,7);
        printf("%s", motorista.nome);
    gotoxy (21,10);
        printf("%s", motorista.carro);
    gotoxy (21,13);
        printf("%s", motorista.cor);
    gotoxy (21,16);
    printf("%s", motorista.placa);
        textbackground(2);
        gotoxy (31,21); printf ("Aperte 'enter' para sair");
        getchar();
        getchar();
        ID = -1;
        return;
    }
        if (ID = -1){
            textbackground(2);
            gotoxy (26,19); printf ("O ID nao esta cadastrado no sistema");
            gotoxy (31,21); printf ("Aperte 'enter' para sair");
        }
        getchar();
        getchar();
    return;
}

void AlterarArquivoMotorista(){
    Motorista motorista, MNovo;
    int codigo;
    FILE * M = AbrirArquivoMotorista();
    fseek(M, 0, SEEK_SET);
    gotoxy (30,2); printf ("ALTERAR MOTORISTA");
    gotoxy (11,20); printf ("                                                                  ");
    gotoxy (37,22); printf ("                   ");
    gotoxy (21,4); scanf ("%d", &codigo);
    motorista = PesquisarArquivoMotorista(codigo);
    gotoxy (21,6); printf ("        ");
    textbackground(2);
    gotoxy (36,4); printf ("ID: %d", codigo);
    textbackground(8);
    if (motorista.ID == codigo) {

        gotoxy (21,4);
        scanf ("%d", &MNovo.ID);
        gotoxy (21,7);
        scanf (" %[^\n]", MNovo.nome);
        gotoxy (21,10);
        scanf (" %[^\n]", MNovo.carro);
        gotoxy (21,13);
        scanf (" %[^\n]", MNovo.cor);
        gotoxy (21,16);
        scanf (" %[^\n]", MNovo.placa);
        textbackground(2);
        gotoxy (31,21); printf ("Aperte 'enter' para salvar");
        getchar();
        getchar();
        fseek (M, -sizeof(Motorista), SEEK_CUR);
        fwrite(&MNovo, sizeof(Motorista),1, M);
        fclose(M);
        codigo = -1;
        MenuMotorista();
    }
    if (codigo == -1){
        textbackground(2);
        gotoxy (26,19); printf ("O ID nao esta cadastrado no sistema");
        gotoxy (31,21); printf ("Aperte 'enter' para sair");
    }
    getchar();
    getchar();
    MenuMotorista();
}

void ExcluirArquivoMotorista(){
    Motorista motorista;
    int codigo;
    FILE * fpMotorista = AbrirArquivoMotorista();
    gotoxy (30,2); printf ("EXCLUIR MOTORISTA");
    gotoxy (11,20); printf ("                                                                  ");
    gotoxy (37,22); printf ("                   ");
    gotoxy (21,6); scanf ("%d", &codigo);
    motorista = PesquisarArquivoMotorista(codigo);
    if (motorista.ID != -1) {
        gotoxy (21,7);
        printf("%s", motorista.nome);
        gotoxy (21,10);
        printf("%s", motorista.carro);
        gotoxy (21,13);
        printf("%s", motorista.cor);
        gotoxy (21,16);
        printf("%s", motorista.placa);
        textbackground(2);
        gotoxy (29,21); printf ("Aperte 'enter' para excluir");
        getchar();
        getchar();
        motorista.ID = -1;
        fseek (fpMotorista, -sizeof(Motorista), SEEK_CUR);
        fwrite(&motorista, sizeof(Motorista),1, fpMotorista);
        fclose(fpMotorista);
        gotoxy (25,21); printf ("Motorista excluido com sucesso");
        gotoxy (29,23); printf ("Aperte 'enter' para sair");
        getchar();
        }
        fclose(fpMotorista);
        return;
}

Motorista DigitarMotorista()
{

    Motorista motorista;
    gotoxy (21,4);
    scanf ("%d", &motorista.ID);
    gotoxy (21,7);
    scanf (" %[^\n]", motorista.nome);
    gotoxy (21,10);
    scanf (" %[^\n]", motorista.carro);
    gotoxy (21,13);
    scanf (" %[^\n]", motorista.cor);
    gotoxy (21,16);
    scanf (" %[^\n]", motorista.placa);
    motorista.avaliacao = 0;
    motorista.totalCorridas = 0;
    return motorista;
}


//a função fflush(fp) grava tudo que está no buffer
