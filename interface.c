#include <stdio.h>
#include <windows.h>
#include <wincon.h>
#include "interface.h"
#include "passageiros.h"

//BORDA
void Borda(int x, int y, int largura, int altura, int tipo, int sombra){    // EsqSup DirSup EsqInf DirInf LHoriz LVertical
    char C[][6] = {"\xda\xbf\xc0\xd9\xc4\xb3" ,
                    "\xc9\xbb\xc8\xbc\xcd\xba"};
    int i, j;
    gotoxy(x, y); printf("%c", C[tipo][0]);
    for(i = 0; i < largura; i++) printf("%c", C[tipo][4]);
    printf("%c", C[tipo][1]);
    for(j = 0; j < altura; j++){
        gotoxy(x, y+j+1); printf("%c", C[tipo][5]);
        for(i = 0; i < largura; i++) printf(" ");
        printf("%c", C[tipo][5]);
        if(sombra) printf("\xb2");
    }
    gotoxy(x, y+altura); printf("%c", C[tipo][2]);
    for(i = 0; i < largura; i++) printf("%c", C[tipo][4]);
    printf("%c", C[tipo][3]);
    if(sombra){
        gotoxy(x+1, y+altura+1);
        for(i = 0; i < largura+2; i++) printf("\xb2");
    }
}

//TECLA
int getTecla(){
    int ch;
    ch = getch();
    if(ch == 224){
        ch = getch() + 1000;
    }
    return ch;
}

//CONTROLAR O CURSOR
void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

enum DOS_COLORS {
       BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN,
       LIGHT_GRAY, DARK_GRAY, LIGHT_BLUE, LIGHT_GREEN, LIGHT_CYAN,
       LIGHT_RED, LIGHT_MAGENTA, YELLOW, WHITE };

void textcolor (int iColor){
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
    bufferInfo.wAttributes &= 0x00F0;
    SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= iColor);
}

void textbackground (int iColor){
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
    bufferInfo.wAttributes &= 0x000F;
    SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= (iColor << 4));
}

//TAMANHO DA FONTE
void setConsoleFontSize(int size) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX font;
    font.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    GetCurrentConsoleFontEx(hConsole, FALSE, &font);
    font.dwFontSize.Y = size; // Altere o valor do tamanho da fonte desejado
    SetCurrentConsoleFontEx(hConsole, FALSE, &font);
}


void FecharTerminal (){
    //OBS: COLOCAR TODAS AS FUNCOES DE FECHAR ARQUIVOS AQUI A MEDIDA QUE FOR FAZENDO ELAS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    textcolor(WHITE); textbackground(DARK_GRAY);
    Borda (0,0,85,25,1,0);
    gotoxy (36,10); printf ("FIM DA SESSAO");
    gotoxy (19,12); printf ("Pressione qualquer tecla para fechar o terminal");
    textcolor(DARK_GRAY); textbackground(BLACK);
    gotoxy (4,25); exit(0);
}

//MENUS:
//SELECIONAR - MENU HORIZONTAL
int MenuHorizontal(char opcoes[][21], int x[], int y[], int n){
    int i; int opcao = 0; int tecla;
    textcolor(WHITE); textbackground(DARK_GRAY);
    for (i=0;i<n;i++) {
        gotoxy (x[i], y[i]);
        printf ("%s", opcoes[i]);
    }
    do{
        textcolor(WHITE); textbackground(GREEN);
        gotoxy (x[opcao], y[opcao]);
        printf ("%s", opcoes[opcao]);
        tecla = getTecla();
        textcolor(WHITE); textbackground(DARK_GRAY);
        gotoxy (x[opcao], y[opcao]);
        printf ("%s", opcoes[opcao]);
        if (tecla == TEC_DIR) opcao ++;
        if (tecla == TEC_ESQ) opcao --;
        if (opcao == n) opcao = 0;
        if (opcao <0) opcao = n -1;
        if (opcao == 13) break;
        }
        while (tecla != 13);
        return opcao;
}

//SELECIONAR - MENU VERTICAL
int MenuVertical (char opcoes[][21], int x[], int y[], int n){
    int i; int opcao = 0; int tecla;
    textcolor(WHITE); textbackground(DARK_GRAY);
    for (i=0;i<n;i++) {
        gotoxy (x[i], y[i]);
        printf ("%s", opcoes[i]);
    }
    do{
        textcolor(WHITE); textbackground(GREEN);
        gotoxy (x[opcao], y[opcao]);
        printf ("%s", opcoes[opcao]);
        tecla = getTecla();
        textcolor(WHITE); textbackground(DARK_GRAY);
        gotoxy (x[opcao], y[opcao]);
        printf ("%s", opcoes[opcao]);
        if (tecla == TEC_BAIXO) opcao ++;
        if (tecla == TEC_CIMA) opcao --;
        if (opcao == n) opcao = 0;
        if (opcao <0) opcao = n -1;
        if (opcao == 13) break;
        }
        while (tecla != 13);
        return opcao;
}


//TELA INICIAL
int MenuTelaInicial (){
    int op;
    char opcoes[][21] = {"Cadastros", "Rotinas", "Relatorios", "Sair" };
    int x[] = {12, 30, 45, 62};
    int y[] = {8, 8, 8, 8};
    do {
        textcolor(WHITE); textbackground(DARK_GRAY);
        Borda (0,0,85,25,1,0);
        textcolor(WHITE); textbackground(DARK_GRAY);
        gotoxy (34,2); printf ("MENU INICIAL");
        setConsoleFontSize(20);
        gotoxy (4,23); printf ("Desenvolvido por: Marcelo Matheus e Sarah Alkimim");
        op = MenuHorizontal (opcoes, x, y, 4);
        if (op == 0) MostrarCadastros();
        if (op == 1) MostrarRotinas();
        if (op == 2) MostrarRelatorios();
        if (op == 3) FecharTerminal();
    } while (op=! 27);
}

//SUB-MENU: CADASTROS
int MostrarCadastros (){
    int op;
    char opcoes[][21] = {"Passageiros", "Motoristas", "Voltar"};
    int x[] = {13, 13, 13};
    int y[] = {11, 13, 15};
    do {
        textcolor(WHITE); textbackground(DARK_GRAY);
        Borda (11,10,14,6,1,0);
        textcolor(WHITE); textbackground(GREEN);
        op = MenuVertical (opcoes, x, y, 3);
        if (op == 0) MenuPassageiro();
       //if (op == 1) MenuMotorista();
        if (op == 2) MenuTelaInicial ();
    } while (op=! 27);
return op;
}

//SUB-MENU: ROTINAS
int MostrarRotinas (){
    int op;
    char opcoes[][21] = {"Solicitar viagem", "Cancelar viagem", "Avaliar motorista", "Voltar"};
    int x[] = {25, 25, 25, 25};
    int y[] = {11, 13, 15, 17};
    do {
        textcolor(WHITE); textbackground(DARK_GRAY);
        Borda (23,10,19,8,1,0);
        textcolor(WHITE); textbackground(GREEN);
        op = MenuVertical (opcoes, x, y, 4);
        //if (op == 0) MenuProduto();
        //if (op == 1) MenuMotorista();
        //if (op == 2) MenuTelaInicial ();
        if (op == 3) MenuTelaInicial();
    } while (op=! 27);
return op;
}

//SUB-MENU: RELATORIOS
int MostrarRelatorios (){
    int op;
    char opcoes[][21] = {"Viagens - motorista", "Viagens - passageiro", "Faturamento", "Voltar"};
    int x[] = {40, 40, 40, 40};
    int y[] = {11, 13, 15, 17};
    do {
        textcolor(WHITE); textbackground(DARK_GRAY);
        Borda (38,10,22,8,1,0);
        textcolor(WHITE); textbackground(GREEN);
        op = MenuVertical (opcoes, x, y, 4);
        //if (op == 0) MenuProduto();
        //if (op == 1) MenuMotorista();
        //if (op == 2) MenuTelaInicial ();
        if (op == 3) MenuTelaInicial();
    } while (op=! 27);
return op;
}








//PASSAGEIROS
//INTERFACE DE PASSAGEIROS
void MostrarTelaPassageiros(){
    textcolor(WHITE); textbackground(DARK_GRAY);
    Borda (0,0,85,25,1,0);
    textcolor(WHITE); textbackground(DARK_GRAY);
    gotoxy (36,2); printf ("PASSAGEIROS");
    gotoxy (10,6); printf ("ID: ");
    Borda (20,5,14,2,0,0);
    gotoxy (10,9); printf ("CPF*: ");
    Borda (20,8,14,2,0,0);
    gotoxy (10,12); printf ("Nome: ");
    Borda (20,11,60,2,0,0);
    gotoxy (10,15); printf ("Telefone*: ");
    Borda (20,14,14,2,0,0);
    gotoxy (10,17); printf ("* somente numeros");
}



//INTERFACE DE LISTAR PRODUTOS
void MostrarTelaListarProdutos(){ //apenas desenha a tela
    textcolor(MAGENTA); textbackground(WHITE);
    Borda (0,0,85,200,0,0);
    gotoxy (32,2); printf ("PRODUTOS");
    gotoxy (5,6);
    textcolor(MAGENTA); textbackground(WHITE);

}

//PRODUTOS
//TELA INICIAL
/*void MostrarProdutosInicial(int*opcao){
    int escolha;
    textcolor(MAGENTA); textbackground(WHITE);
    Borda (0,0,60,20,1,0);
    textcolor(MAGENTA); textbackground(WHITE);
    gotoxy (20,2); printf ("PRODUTOS");
    gotoxy (10,6); printf ("1 - Novo produto");
    gotoxy (10,9); printf ("2 - Pesquisar produto");
    gotoxy (10,12); printf ("3 - Alterar produto");
    gotoxy (10,15); printf ("4 - Excluir produto");
    gotoxy (10,15); printf ("5 - Listar produtos");
    gotoxy (10,15); printf ("0 - Voltar para o menu anterior");
    gotoxy (10,19); printf ("Escolha a opcao: ");
    scanf ("%d", &opcao);
    *opcao=escolha;
}*/





/*int main(){
    int Codigo;
    char Nome[50], Endereco[80], Telefone[20], Confirmacao;
    textcolor(MAGENTA); textbackground(WHITE);
    Borda (0,0,85,20,1,0);
    textcolor(MAGENTA); textbackground(WHITE);
    gotoxy (20,2); printf ("Cadastro de Clientes");
    gotoxy (10,6); printf ("Codigo: ");
    Borda (20,5,15,2,0,0); //posição, largura, tamanho da borda
    gotoxy (10,9); printf ("Nome: ");
    Borda (20,8,60,2,0,0);
    gotoxy (10,12); printf ("Endereco: ");
    Borda (20,11,60,2,0,0);
    gotoxy (10,15); printf ("Telefone: ");
    Borda (20,14,20,2,0,0);
    gotoxy (21,6); scanf ("%d", &Codigo);
    gotoxy (21,9); scanf (" %[^\n]", Nome);
    gotoxy (21,12); scanf (" %[^\n]", Endereco);
    gotoxy (21,15); scanf (" %[^\n]", Telefone);
    gotoxy (10,19); printf ("Confirma (S/N): ");
    scanf ("%s", Confirmacao);
}*/
