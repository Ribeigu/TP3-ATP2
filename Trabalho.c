#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
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

typedef struct jogador{
    char nome[80];
    DATA dataNascimento;
    float cpf;
    GENERO genero;
    ESTADO estadoCivil;
    char nickname[15];
    float seguidores;
    EQUIPAMENTO setup;
    PONTOS pontos;
    int titulos;
    int posição;


}JOGADOR;

int main(){
    setlocale(LC_ALL, "portugues");
}