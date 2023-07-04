#include <stdio.h>
#include <string.h>
#include "interface.h"
#include "motoristas.h"
#include "passageiros.h"
#include "viagens.h"
#include <conio.h>
#include <time.h>
#include <math.h>
FILE *fpPassageiro;
FILE *fpMotorista;
FILE *fpViagem;


/*A seguinte função solicita a escrita do cpf do passeiro e verifica se ele existe no arquivo passageiros.txt,
caso exista, retorna os dados do usuário em forma de struct; caso não exista, retorna ao MenuViagens() solicitando um novo cpf*/

void pausar(float delay1) {

   if (delay1<0.001) return; // pode ser ajustado e/ou evita-se valores negativos.

   float inst1=0, inst2=0;

   inst1 = (float)clock()/(float)CLOCKS_PER_SEC;

   while (inst2-inst1<delay1) inst2 = (float)clock()/(float)CLOCKS_PER_SEC;

   return;

}

Passageiro Autenticacao(){

    fpPassageiro = AbrirArquivoPassageiros();
    int ID;
    int op;
    Passageiro passageiro;
    system("cls");
    Borda (0,0,85,25,1,0);
    Borda(2,5,81,15,0,0);
    gotoxy(36,5);
    printf("FACO O LOGIN");
    gotoxy(34,10);
    printf("Informe o seu ID");
    Borda (35,11,13,2,0,0);
    gotoxy(37,12);
    scanf("%d",&ID);
    fseek(fpPassageiro,0,SEEK_SET);
    while(fread(&passageiro,sizeof(Passageiro),1,fpPassageiro)){
        if(passageiro.ID==ID){
            fclose(fpPassageiro);
            return passageiro;
        }
    }
    gotoxy(31,14);
    printf("Usuario nao encontrado!");
    gotoxy(25,15);
    printf("Pressione Enter para tentar novamente");
    gotoxy(35,16);
    printf("ou ESC para sair");
    op = getTecla();
    if(op==27){
        main();
    }else{
        MenuViagens();
    }
    fclose(fpPassageiro);

}

void MostrarTelaEndereco(Passageiro passageiro){
    system("cls");
    Borda (0,0,85,25,1,0);
    Borda(2,1,81,3,0,0);
    gotoxy(30,3);
    printf("Defina a rota, %s",passageiro.nome);
    Borda(4,8,77,3,0,0);
    gotoxy(10,8);
    printf(" Endereco de origem ");
    Borda(4,12,77,3,0,0);
    gotoxy(10,12);
    printf(" Endereco de destino ");
}

Viagem DigitarEndereco(){
    Viagem viagens;
    int op;
    char opcoes[][21] = {"Confirmar", "Sair"};
    int x[] = {25, 55};
    int y[] = {20, 20};
    gotoxy(11,9);
    scanf(" %[^\n]",viagens.origem);
    gotoxy(11,13);
    scanf(" %[^\n]",viagens.destino);
    op = MenuHorizontal(opcoes, x, y, 2);
    if(op==0){
        return viagens;
    }else if(op==1){
        main();
    }
}



void MostrarTelaEspera(){
    system("cls");
    Borda (0,0,85,25,1,0);

    for(int i=0; i < 3;i++){
    system("cls");

    Borda (0,0,85,25,1,0);
    Borda(2,4,81,10,0,0);
    gotoxy(31,5);

       printf("PROCURANDO MOTORISTA...\n") ;
    gotoxy(31,8);
       printf("        _______ \n");
    gotoxy(31,9);
       printf("       //  ||\\ \\ \n");
    gotoxy(31,10);
       printf(" _____//___||_\\ \\___ \n");
    gotoxy(31,11);
       printf(" )  _          _    \\ \n");
    gotoxy(31,12);
       printf(" |_/ \\________/ \\___| \n");
    gotoxy(31,13);
       printf("___\\_/________\\_/______ \n");
        pausar(1);
        system("cls");
        Borda (0,0,85,25,1,0);
        Borda(2,4,81,10,0,0);
    gotoxy(31,5);

       printf("PROCURANDO MOTORISTA...\n") ;

    gotoxy(28,8);
       printf("        _______ \n");
    gotoxy(28,9);
       printf("       //  ||\\ \\ \n");
    gotoxy(28,10);
       printf(" _____//___||_\\ \\___ \n");
    gotoxy(28,11);
       printf(" )  _          _    \\ \n");
    gotoxy(28,12);
       printf(" |_/ \\________/ \\___| \n");
    gotoxy(28,13);
       printf(" __\\_/________\\_/__  \n");
        pausar(1);
    }

}

Motorista EncontrarMotorista(){
    Motorista motorista;
    fpMotorista = AbrirArquivoMotorista();
    int qMotoristas = QuantidadeMotoristas(fpMotorista), contador=0;
    int numeroGerado;
    srand((unsigned)time(NULL));
    numeroGerado = rand()%qMotoristas; //numeroGerado guarda o número com a posição do motorista dentro do arquivo motorista.txt
    fseek(fpMotorista,0,SEEK_SET);
    while(fread(&motorista,sizeof(Motorista),1,fpMotorista)){
    if(numeroGerado==contador){
        gotoxy(31,5);
        printf("MOTORISTA ENCONTRADO") ;
        fclose(fpMotorista);
        return motorista;
    }
        contador++;
    }
    gotoxy(31,5);
    printf("MOTORISTA NAO ENCONTRADO\n");
    fclose(fpMotorista);
    system("pause");
    return;
}


Viagem DeficoesViagem(){
    Viagem viagem;
    srand((unsigned)time(NULL));
    viagem.distancia = rand()%7+1;

    if(viagem.distancia<=3){
        viagem.valor = (viagem.distancia*2)+4;
        viagem.tempo = viagem.distancia*5;
    }else{
        viagem.valor = (viagem.distancia*2)+2.5;
        viagem.tempo = viagem.distancia*3;
    }

    return viagem;
}

void MostrarTelaEmbarque(Viagem viagens, Motorista motorista){
    int op;
    system("cls");
    Borda (0,0,85,25,1,0);
    Borda(2,1,38,12,0,0);
    Borda(46,1,38,12,0,0);
    gotoxy(4,3);
    printf("MOTORISTA:");
    gotoxy(4,5);
    printf("%.25s",motorista.nome);
    gotoxy(4,7);
    printf("%.15s",motorista.carro);
    gotoxy(20,7);
    printf("%s",motorista.cor);
    gotoxy(4,9);
    printf("%s",motorista.placa);
    gotoxy(4,11);
    printf("%d corridas",motorista.totalCorridas);
    gotoxy(18,11);
    printf("%.2lf estrelas",motorista.avaliacao);
    gotoxy(49,3);
    printf("CORRIDA:");
    gotoxy(49,5);
    printf("|Saida: %.25s",viagens.origem);
    gotoxy(49,7);
    printf("|Destino: %.25s",viagens.destino);
    gotoxy(49,9);
    printf("R$%.2lf",viagens.valor);
    gotoxy(49,11);
    printf("%.2lf min",viagens.tempo);
    gotoxy(29,19);
    printf("O motorista esta a caminho");
    pausar(10);
    gotoxy(24,19);
    printf("O motorista esta no ponto de embarque");
    pause(2);
    gotoxy(29,20);
    printf("Pressione ENTER para embarcar");
    op = getTecla();
    while(op!=13){
       op = getTecla();
    }
    if(op==13){
        gotoxy(17,19);
        printf("Aguarde o fim da viagem para chegar ao seu destino");
        gotoxy(24,20);
        printf("    Previsao de chegada em %.0lf minutos    ",viagens.tempo);
        pausar(5);
        gotoxy(17,19);
        printf("Voce chegou ao seu destino, o valor a pagar e R$%.2lf",viagens.valor);
        gotoxy(20,20);
        printf("      Obrigado(a) por viajar com a Bublee     ");
        pause(3);
    }
}

void gravarDadosViagem(Viagem viagens){
    fpViagem = fopen("viagens.txt","ab+");
    if(fpViagem==NULL){
        printf("Erro ao gravar os dados");
    }
    fwrite(&viagens,sizeof(Viagem),1,fpViagem);
    fclose(fpViagem);
}

Viagem CopiarDadosPsgParaViagens(Passageiro passageiros){
    Viagem viagem;
    strcpy(viagem.passageiro, passageiros.nome);
    viagem.IdPassageiro = passageiros.ID;
    return viagem;

}

Viagem CopiarDadosMotoristaParaViagens(Motorista motorista){
    Viagem viagem;
    strcpy(viagem.motorista,motorista.nome);
    viagem.cpfMotorista = motorista.cpf;
    return viagem;
}

void AvaliarMotorista(Motorista motorista){
    double avaliacao;
    gotoxy(12,19);
    printf("Atribua uma nota de 0 a 5 ao motorista (use tambem casas decimais): ");
    scanf("%lf",&avaliacao);
    CalcularAvaliacaoMotorista(motorista, avaliacao);
    gotoxy(20,20);
    printf("      Obrigado(a) por viajar com a Bublee     ");
}

void MenuViagens(){
    Viagem viagens;
    int opMenu;
    int x[] = {25, 55};
    int y[] = {23, 23};
    char opcoes[][21] = {"Finalizar", "Avaliar"};
    Passageiro passageiros;
    Motorista motorista;
    passageiros = Autenticacao();
    MostrarTelaEndereco(passageiros); //Essa função mostra a tela para digitar endereco
    viagens = DigitarEndereco(); //Essa função recebe os endereços digitados pelo usuário
    MostrarTelaEspera();//Tela apenas para ilustrar
    motorista = EncontrarMotorista(); //busca um motorista aleatório no arquivo motoristas.txt
    SomarCorridaAoMotorista(motorista);//Essa função acrescenta mais uma corrida ao motorista
    viagens = DeficoesViagem(); //passa valor, diatancia e tempo para o struct viagem
    MostrarTelaEmbarque(viagens,motorista); //realiza toda operação de viagem
    viagens = CopiarDadosPsgParaViagens(passageiros); //Essa função passa dados do passageiro para o struct viagens
    viagens = CopiarDadosMotoristaParaViagens(motorista); //Essa função passa dados do motorista para o struct viagens
    gravarDadosViagem(viagens);//Grava os dados da viagem em viagens.txt
    //Essa funcao acrescenta mais uma corrida ao total de corridas do motorista
    opMenu = MenuHorizontal(opcoes, x, y, 2);
        if(opMenu==0){
            main();
        }else if(opMenu==1){
            AvaliarMotorista(motorista);
        }
}
