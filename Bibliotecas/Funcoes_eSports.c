//Aqui estão todas as funções utilizadas durante o projeto
#include<stdio.h>
#include<locale.h>
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
void adicionarJogador(){
    setlocale(LC_ALL, "portugues");
    int n;
    printf("Quantos jogadores você quer adicionar?\n");
    scanf("%d", &n);            
    JOGADOR jogadores[n];
    for(int i=0; i<n; i++){
        fflush(stdin);
        printf("Digite o nome do jogador:\n");
        gets(jogadores[i].nome);
        fflush(stdin);
        printf("Digite o dia de nascimento dela no formato dd mm aaaa:\n");
        scanf("%d%d%d", &jogadores[i].dataNascimento.dia, &jogadores[i].dataNascimento.mes, &jogadores[i].dataNascimento.ano);
        fflush(stdin);
        printf("Digite o cpf no formato xxx.xxx.xxx-xx:\n");
        gets(jogadores[i].cpf);
        fflush(stdin);
        // printf("Insira o gênero:\n(masculino,feminino, outro)\n");
        // scanf("%d", &jogadores[i].genero);
        // printf("Insira seu estado civil:\n(solteiro=1, casado, separado, divorciado, viúvo)\n");
        // scanf("%d", &jogadores[i].estadoCivil);
        // fflush(stdin);
        printf("Qual seu maior patrocinador?\n");
        gets(jogadores[i].patrocinador);
        fflush(stdin);
        printf("Qual é o seu nickname?\n");
        gets(jogadores[i].nickname);
        fflush(stdin);
        printf("Quantos seguidores tem nas redes sociais?\n");
        scanf("%d", &jogadores[i].seguidores);
        fflush(stdin);
        printf("Quantas partidas ganhas tem o jogador?\n");
        scanf("%d", &jogadores[i].pontos.vitorias);
        printf("Quantas partidas empatadas tem o jogador?\n");
        scanf("%d", &jogadores[i].pontos.empates);
        printf("Quantas partidas perdidas tem o jogador?\n");
        scanf("%d", &jogadores[i].pontos.derrotas);
        jogadores[i].pontos.pontuacao= (jogadores[i].pontos.vitorias*3)+jogadores[i].pontos.empates;
        printf("O jogador possuí quantos títulos?\n");
        scanf("%d", &jogadores[i].titulos);
        printf("Qual a sua posição no ranking global?\n");
        scanf("%d", &jogadores[i].posicao);
        fflush(stdin);
        printf("\nVamos falar do setup do jogador\n");
        printf("Qual o modelo do computador?\n");
        gets(jogadores[i].setup.computador);
        fflush(stdin);
        printf("Qual o processador?\n");
        gets(jogadores[i].setup.processador);
        fflush(stdin);
        printf("Qual o modelo da placa de vídeo?\n");
        gets(jogadores[i].setup.placa);
        fflush(stdin);
        printf("Quantas Gigas de ram possui?\n");
        scanf("%d",&jogadores[i].setup.memoriaRAM);
        fflush(stdin);
        printf("\n");
        printf("\nAgora vamos para as informações da equipe!!\n");
        printf("Qual o nome da equipe?\n");
        gets(jogadores[i].team.nome);
        fflush(stdin);
        printf("Qual o nick da equipe?\n");
        gets(jogadores[i].team.nick);
        fflush(stdin);
        printf("Quantos seguidores tem a equipe?\n");
        scanf("%d", &jogadores[i].team.seguidores);       
    }
};
