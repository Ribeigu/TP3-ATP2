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
    int controle;
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
        printf("Insira o gênero:\n(1- masculino,2- feminino, 3-outro)\n");
        scanf("%d", &controle);
        switch (controle)
        {
        case 1:
            jogadores[i].genero=masculino;
            break;
        case 2:
            jogadores[i].genero=feminino;
            break;
        case 3:
            jogadores[i].genero=outro;
            break;    
        default:
            printf("Gênero não atualizado.\n");
            break;
        }
        printf("Insira seu estado civil:\n(solteiro=1, casado, separado, divorciado, viúvo)\n");
        scanf("%d", &controle);
        switch (controle)
        {
        case 1:
            jogadores[i].estadoCivil=solteiro;
            break;
        case 2:
            jogadores[i].estadoCivil=casado;
            break;
        case 3:
            jogadores[i].estadoCivil=separado;
            break; 
        case 4:
            jogadores[i].estadoCivil=divorciado;
            break; 
        case 5:
            jogadores[i].estadoCivil=viúvo;
            break;    
        default:
            printf("Estado civil não atualizado.\n");
            break;
        }
        fflush(stdin);
        printf("Qual seu maior patrocinador?\n");
        gets(jogadores[i].patrocinador);
        fflush(stdin);
        printf("Qual é o seu nickname?\n");
        gets(jogadores[i].nickname);
        fflush(stdin);
        printf("Quantos seguidores tem nas redes sociais?\n");
        scanf("%d", &jogadores[i].seguidores);
        fflush(stdin);
        inserirPontuacao(jogadores, 0);
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
    return;
};
void inserirPontuacao(JOGADOR jogadores[], int n){
    FILE *file;
    file= fopen("jogadores.dat","ab+");
    if(n=0){
        fseek(file, 0*sizeof(JOGADOR), SEEK_END);
        fflush(stdin);
        printf("Quantas partidas ganhas tem o jogador?\n");
        scanf("%d", &jogadores.pontos.vitorias);
        printf("Quantas partidas empatadas tem o jogador?\n");
        scanf("%d", &jogadores.pontos.empates);
        printf("Quantas partidas perdidas tem o jogador?\n");
        scanf("%d", &jogadores.pontos.derrotas);
        jogadores.pontos.pontuacao= (jogadores.pontos.vitorias*3)+jogadores.pontos.empates;
    }else{
        fseek(file, n*sizeof(JOGADOR), SEEK_SET);
        fflush(stdin);
        printf("Quantas partidas ganhas tem o jogador?\n");
        scanf("%d", &jogadores.pontos.vitorias);
        printf("Quantas partidas empatadas tem o jogador?\n");
        scanf("%d", &jogadores.pontos.empates);
        printf("Quantas partidas perdidas tem o jogador?\n");
        scanf("%d", &jogadores.pontos.derrotas);
        jogadores.pontos.pontuacao= (jogadores.pontos.vitorias*3)+jogadores.pontos.empates;
    }


}
void exibirJogador(JOGADOR jogadores[], int i){
    printf("Informações do jogador:\n");
    printf("Nome: %s", jogadores[i].nome);
}
void ordenarJogador(){

}
int procurarJogadorNome(char jogador[]){
    FILE *file;
    file= fopen("jogadores.dat","ab+");
    int controle=100;
    for(int i=0; i<; i++){
        fseek(file, i*sizeof(JOGADOR), SEEK_SET);
        for (int j=0; j<80; j++){
            if(jogador[j]!=jogadores.nome[j]){
                controle=100;
                break;
            }else{
                controle=i;
            }
        }
        
    }
    return(controle);
}
void alterarInfos(){
    FILE *file;
    file= fopen("jogadores.dat","ab+");
    printf("Uhmm, ok! Vamos lá. Qual jogador você gostaria de alterar?\n");
    int n=1000;
    char jogador[80];
    fflush(stdin);
    gets(jogador);
    int joga= procurarJogadorNome(jogador);
    
    do{
        if(joga=100){
            printf("Esse jogador não existe!!\nTente novamente!!\n");
            n=14;
        }else{
            printf("Qual informação você gostaria de alterar?");
            printf("1- Nome;\n2- Data de nascimento;\n3- CPF;\n4- Gênero;\n5- Estado civil;\n6- Time;\n7- Patrocinador principal;\n8- Nickname;\n9- Seguidores;\n10- Setup;\n11- Pontuação;\n12- Títulos;\n13- Posição no ranking;\n14- Sair;\n");
            scanf("%d", &n);
        }
        switch(n){
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11: inserirPontuacao(jogadores, n);
            case 12: 
            case 13:
            case 14: if(joga=100){
                    printf("Qual jogador você gostaria de alterar?\n");
                }else{
                    printf("OK! De qual jogador você deseja alterar as informações agora?");
                }
                fflush(stdin);
                gets(jogador);
            case 15: printf("Espero ter te ajudado com o que pude!");
            default: printf("Você não escolheu uma opção válida!!\nTente novamente!!");
        }
    }while(n!=15);
}