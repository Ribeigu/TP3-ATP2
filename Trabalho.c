#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Bibliotecas/Funcoes_eSports.h"

int main(){
    setlocale(LC_ALL, "portugues");
    printf("Olá!\nSeja bem vindo ao sistema de nosso campeonato!!\n");
    int controle=10000;
    FILE *file;
    file = fopen("jogadores.dat", "ab+");

    do{
        printf("O que você deseja fazer?\n");
        printf("Selecione 1 para checar os dados de algum jogador; \nSelecione 2 para adicionar algum jogador; \nSelecione 3 para alterar o dado de algum jogador;\n\n");
        scanf("%d", &controle);
        printf("\n");
        switch (controle){
            case 0: break;
            case 1:
                // exibirDados();
                break;
            case 2:
                adicionarJogador();

                break;
            case 3:
                // editarJogador();
                break;
            default:
                printf("Parece que você não selecionou uma das opções predefinidas =/\nTente novamente!\n\n");
        }
    }while(controle!=0);
    printf("----------------------------------------------\n");
    printf("OBRIGADO por utilizar nosso programa ;p"); 
    printf("      |\n                                             |\n");
    printf("DESENVOLVIDO POR:"); 
    printf("                            |\n");
    printf("-> Paulo Celso dos Santos Júnior"); 
    printf("            |\n");
    printf("-> Gustavo Ribeiro da Mota"); 
    printf("                   |\n                                             |");
    printf("\n2° Semestre Ciência da Computação"); 
    printf("         |\n                                             |");
    printf("\nFCT/UNESP - Presidente Prudente"); 
    printf("              |");
    printf("\n----------------------------------------------");


}