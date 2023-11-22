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
}PONTOS;

typedef struct equipamento{
    char computador[100];
    char processador[30];
    char placa[30];
    int memoriaRAM;
}EQUIPAMENTO;

typedef struct equipe{
    char nomeEquipe[50];
    char redesocialEquipe[50];
    int seguidoresEquipe;
} EQUIPE;

typedef struct jogador{
    char nome[80];
    DATA dataNascimento;
    char cpf[15];
    GENERO genero;
    ESTADO estadoCivil;
    EQUIPE equipeProfissional;
    char patrocionadoraPrincipal[80];
    char nickname[30];
    float seguidores;
    EQUIPAMENTO setup;
    PONTOS pontos;
    int titulos;
    int posição;


}JOGADOR;

int main(){
    setlocale(LC_ALL, "portugues");
}