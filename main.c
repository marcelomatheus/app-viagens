#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "passageiros.h"
#include "motoristas.h"
#include "viagens.h"
#include "interface.h"

int main (){
    int opcao = 0;
    do {
        opcao = MenuTelaInicial();
        }while (opcao != 27);

 return 0;
}
