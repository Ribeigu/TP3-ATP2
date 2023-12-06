#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <Funcoes_eSports.h>
typedef struct data{
    int dia;
    int mes;
    int ano;
}DATA;
typedef enum genero{masculino=1, feminino, outro}GENERO;
typedef enum estadoCivil{solteiro=1, casado, separado, divorciado, viúvo}ESTADO;
typedef struct pontuacao{
    int vitorias;
    int derrotas;
    int empates;
    int pontuacao;
}PONTOS;
typedef struct equipamento{
    char computador[100];
    char processador[30];
    char placa[30];
    int memoriaRAM;
}EQUIPAMENTO;
typedef struct equipe{
    char nome[20];
    char nick[25];
    int seguidores;
}EQUIPE;
typedef struct jogador{
    char nome[80];
    DATA dataNascimento;
    char cpf[15];
    GENERO genero;
    ESTADO estadoCivil;
    EQUIPE team;
    char patrocinador[30];
    char nickname[15];
    int seguidores;
    EQUIPAMENTO setup;
    PONTOS pontos;
    int titulos;
    int posicao;


}JOGADOR;

int main(){
    setlocale(LC_ALL, "portugues");
    printf("Olá!\nSeja bem vindo ao sistema de nosso campeonato!!\n");
    int controle=10000, parametro;
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
                printf("1- Ordenar por nome;\n 2-Ordenar por Ranking;\n3-Ordenar por vitórias;\n4-Ordenar com um valor base;\n 5-Ordenar com um valor limite;\n6-Exibir por nome;\n");
                scanf("%d", parametro);
                ordenarJogador(parametro);
                break;
            case 2:
                
                adicionarJogador();

                break;
            case 3:
                editarJogador();
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