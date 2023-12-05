//Aqui estão todas as funções utilizadas durante o projeto
#include<stdio.h>
#include<string.h>
#include<locale.h>

//              Structs auxiliares

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

//            Struct principal

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

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//                                                Funções                                                

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
        printf("Quantas partidas ganhas tem o jogador?\n");
        scanf("%d", &jogadores[i].pontos.vitorias);
        printf("Quantas partidas empatadas tem o jogador?\n");
        scanf("%d", &jogadores[i].pontos.empates);
        printf("Quantas partidas perdidas tem o jogador?\n");
        scanf("%d", &jogadores[i].pontos.derrotas);
        jogadores[i].pontos.pontuacao= (jogadores[i].pontos.vitorias*3)+jogadores[i].pontos.empates;
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
    FILE *file;
    file = fopen("jogadores.dat", "ab+");
    fwrite(&jogadores, sizeof(JOGADOR),n,file);
    return;
};


//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//                                         Alterações importantes

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void inserirPontuacao(JOGADOR jogadores[], int n){
    FILE *file;
    file= fopen("jogadores.dat","ab+");
        fseek(file, n*sizeof(JOGADOR), SEEK_SET);
        fflush(stdin);
        printf("Quantas partidas ganhas tem o jogador?\n");
        scanf("%d", &jogadores[n].pontos.vitorias);
        printf("Quantas partidas empatadas tem o jogador?\n");
        scanf("%d", &jogadores[n].pontos.empates);
        printf("Quantas partidas perdidas tem o jogador?\n");
        scanf("%d", &jogadores[n].pontos.derrotas);
        jogadores[n].pontos.pontuacao= (jogadores[n].pontos.vitorias*3)+jogadores[n].pontos.empates;
    return;


}

void exibirJogador(JOGADOR jogadores[], int i){
    printf("Informações do jogador:\n");
    printf("Nome: %s\n", jogadores[i].nome);
    printf("Data de nascimento: %d/%d/%d\n",jogadores[i].dataNascimento.dia, jogadores[i].dataNascimento.mes, jogadores[i].dataNascimento.ano);
}
void ordenarNome(){
    FILE *file;
    file= fopen("jogadores.dat","ab+");
    int tamanho, controle[tamanho], posicao;
    JOGADOR jogadores[tamanho];
    fseek(&jogadores,sizeof(JOGADOR), SEEK_END);
    tamanho= ftell(file)/sizeof(JOGADOR);
    
    
    for(int i=0; i<tamanho; i++){
        for(int j=0; j<80; j++){
            jogadores[i].nome[j]=toupper(jogadores[i].nome[j]);
        }
    }

    for(int i=0; i<tamanho; i++){
        controle[i]=i;
    }
   //percorrer todos os jogadores do arquivo 
    for(int i=0;i<tamanho;i++){
        //comparar os nomes pra encontrar o menor
        for(int j=0; j<80; j++){
            if(jogadores[i].nome[j]<jogadores[i+1].nome[j]){
                //organiza o vetor de controle na ordem que for pra escrever
                posicao =*(controle+i);
                *(controle+i)= *(controle+i+1);
                *(controle+i+1)= posicao;
                i--;
                break;
            }
        }
    }

    for(int i=0; i<tamanho; i++){
        exibirJogador(jogadores, controle[i]);
    }


}

void ordenarRanking(){
    FILE *file;
    file= fopen("jogadores.dat","ab+");
    int tamanho, controle[tamanho], posicao;
    JOGADOR jogadores[tamanho];
    fseek(&jogadores,sizeof(JOGADOR), SEEK_END);
    tamanho= ftell(file)/sizeof(JOGADOR);

    for(int i=0; i<tamanho; i++){
        controle[i]=i;
    }

    for(int i=0; i<tamanho; i++){
        for(int j=0; j<tamanho; j++){
            if(jogadores[i].posicao>jogadores[j].posicao){
                posicao =*(controle+i);
                *(controle+i)= *(controle+i+1);
                *(controle+i+1)= posicao;
            }
        }
    }

    for(int i=0; i<tamanho; i++){
        exibirJogador(jogadores, controle[i]);
    }
    
}

void ordenarVitorias(){
    FILE *file;
    file= fopen("jogadores.dat","ab+");
    int tamanho, controle[tamanho], posicao;
    JOGADOR jogadores[tamanho];
    fseek(&jogadores,sizeof(JOGADOR), SEEK_END);
    tamanho= ftell(file)/sizeof(JOGADOR);

    for(int i=0; i<tamanho; i++){
        controle[i]=i;
    }

    for(int i=0; i<tamanho; i++){
        for(int j=0; j<tamanho; j++){
            if(jogadores[i].pontos.vitorias<jogadores[j].pontos.vitorias){
                posicao =*(controle+i);
                *(controle+i)= *(controle+i+1);
                *(controle+i+1)= posicao;
            }
        }
    }

    for(int i=0; i<tamanho; i++){
        exibirJogador(jogadores, controle[i]);
    }
    
}

void ordenarPontuaca(int operacao, int valor){
    FILE *file;
    file= fopen("jogadores.dat","ab+");
    int tamanho, controle[tamanho], posicao, aux;
    JOGADOR jogadores[tamanho];
    fseek(&jogadores,sizeof(JOGADOR), SEEK_END);
    tamanho= ftell(file)/sizeof(JOGADOR);
    
    if(operacao==1){
        for(int i=0; i<tamanho; i++){
            if(jogadores[i].pontos.pontuacao<valor){
                aux++;
                break;
            }else{
                for(int j=0; j<tamanho; j++){
                    if(jogadores[i].pontos.pontuacao<jogadores[i].pontos.pontuacao){
                        posicao =*(controle+i);
                        *(controle+i)= *(controle+i+1);
                        *(controle+i+1)= posicao;
                    }
                }
            }
        }
        controle[tamanho-aux];
        for(int i=0; i<tamanho-aux; i++){
            exibirJogador(jogadores, controle[i]);
        }
    }
    if(operacao==2){
        for(int i=0; i<tamanho; i++){
            if(jogadores[i].pontos.pontuacao>valor){
                aux++;
                break;
            }else{
                for(int j=0; j<tamanho; j++){
                    if(jogadores[i].pontos.pontuacao>jogadores[i].pontos.pontuacao){
                        posicao =*(controle+i);
                        *(controle+i)= *(controle+i+1);
                        *(controle+i+1)= posicao;
                    }
                }
            }
        }
        controle[tamanho-aux];
        for(int i=tamanho-aux; i>0; i--){
            exibirJogador(jogadores, controle[i]);
        }
    }
}

void ordenarJogador(int parametro){
    int controle();
    switch (parametro)
    {
    case 1:
        ordenarNome();
        break;
    case 2:
        ordenarRanking();
        break;
    case 3:
        ordenarVitorias();
        break;
    case 4:
        printf("\nOrdenar com base em qual pontuação base?\n");
        scanf("%d", &controle);
        ordenarPontuacao(1, controle);
        break;
    case 5:
        printf("\nOrdenar com base em qual pontuação limite?\n");
        scanf("%d", &controle);
        ordenarPontuacao(2, controle);
        break;
    default:
        break;
    }

}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//                                         Alterações importantes

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

int procurarJogadorNome(char jogador[], JOGADOR jogadores[]){
    // n tbm precisa ser o ultimo numero de jogadores aqui. não faço ideia de como faça  isso. (Ribeigu)

    //Minha solução foi colocar um numero alto e fazer um for enquanto i for maior ou igual a 0
    FILE *file;
    file= fopen("jogadores.dat","ab+");
    int controle, n;
    for(int i=100; i>=0; i--){
        fseek(file, i*sizeof(JOGADOR), SEEK_SET);
        controle= strcmp(jogadores[i].nome, jogador);
        n=i;
        if(controle=0){
            break;
        }else{
            n=100;
        }

    }
    return(n);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//                                         Alterações importantes

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void alterarInfos(){
    FILE *file;
    file= fopen("jogadores.dat","ab+");
    fseek(file, sizeof(JOGADOR), SEEK_END);
    
    int tamanho=ftell(file)/sizeof(JOGADOR); //mesmo problema das 2 acimas
    JOGADOR jogadores[tamanho];
    printf("Uhmm, ok! Vamos lá. Qual jogador você gostaria de alterar?\n");
    int n=1000;
    char jogador[80], simOuNao;
    fflush(stdin);
    gets(jogador);
    int joga= procurarJogadorNome(jogador, jogadores);
    
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
            case 1: pritnf("O nome atual do jogador é: %s.\n", jogadores[joga].nome);//nome
                    do{
                    printf("Tem certeza que deseja mudar?\n(S- sim, N- não)\n");
                    gets(simOuNao);
                    fflsuh(stdin);
                        if(simOuNao==83 || simOuNao==115){
                            printf("Escreva o novo nome abaixo, por favor!\n");
                            gets(jogadores[joga].nome);
                            fflush(stdin);
                            printf("Prontinho!!\n");
                            simOuNao=0;
                            break;
                        }else  if(simOuNao==78||simOuNao==110){
                            printf("Operação cancelada!!\n");
                            simOuNao=0;
                            break;
                        }else{
                            printf("Escolha uma opção válida!!\n\n");
                        }
                    }while(simOuNao!=0);
            case 2:printf("A data atual de nascimento é: %d/%d/%d.\n", jogadores[joga].dataNascimento.dia, jogadores[joga].dataNascimento.mes, jogadores[joga].dataNascimento.ano);//nascimento
                    do{
                        printf("Tem certeza que deseja mudar?\n(S- sim, N- não)\n");
                        gets(simOuNao);
                        fflsuh(stdin);
                        if(simOuNao==83 || simOuNao==115){
                            printf("Digite o dia de nascimento dela no formato dd mm aaaa:\n");
                            scanf("%d%d%d", &jogadores[joga].dataNascimento.dia, &jogadores[joga].dataNascimento.mes, &jogadores[joga].dataNascimento.ano);
                            fflush(stdin);
                            printf("Prontinho!!\n");
                            simOuNao=0;
                            break;
                        }else  if(simOuNao==78||simOuNao==110){
                            printf("Operação cancelada!!\n");
                            simOuNao=0;
                            break;
                        }else{
                            printf("Escolha uma opção válida!!\n\n");
                        }
                    }while(simOuNao!=0); 
            case 3:printf("O cpf atual é: %s.\n", jogadores[joga].cpf);//cpf
                    do{
                        printf("Tem certeza que deseja mudar?\n(S- sim, N- não)\n");
                        gets(simOuNao);
                        fflsuh(stdin);
                        if(simOuNao==83 || simOuNao==115){
                            printf("Digite o cpf no formato xxx.xxx.xxx-xx:\n");
                            gets(jogadores[joga].cpf);
                            fflush(stdin);
                            printf("Prontinho!!\n");
                            simOuNao=0;
                            break;
                        }else  if(simOuNao==78||simOuNao==110){
                            printf("Operação cancelada!!\n");
                            simOuNao=0;
                            break;
                        }else{
                            printf("Escolha uma opção válida!!\n\n");
                        }
                    }while(simOuNao!=0);
            case 4:printf("O gênero atual é: %s.\n", jogadores[joga].genero);//gênero
                    do{
                        printf("Tem certeza que deseja mudar?\n(S- sim, N- não)\n");
                        gets(simOuNao);
                        fflsuh(stdin);
                        if(simOuNao==83 || simOuNao==115){
                        printf("Insira o gênero:\n(1- masculino,2- feminino, 3-outro)\n");
                        int controle;
                        scanf("%d", &controle);
                        switch (controle)
                        {
                        case 1:
                            jogadores[joga].genero=masculino;
                            break;
                        case 2:
                            jogadores[joga].genero=feminino;
                            break;
                        case 3:
                            jogadores[joga].genero=outro;
                            break;    
                        default:
                            printf("Gênero não atualizado.\n");
                            break;
                        }
                            fflush(stdin);
                            printf("Prontinho!!\n");
                            simOuNao=0;
                            break;
                        }else  if(simOuNao==78||simOuNao==110){
                            printf("Operação cancelada!!\n");
                            simOuNao=0;
                            break;
                        }else{
                            printf("Escolha uma opção válida!!\n\n");
                        }
                    }while(simOuNao!=0);
            case 5:printf("O estado civil atual é: %s.\n", jogadores[joga].estadoCivil);//estado civil
                    do{
                        printf("Tem certeza que deseja mudar?\n(S- sim, N- não)\n");
                        gets(simOuNao);
                        fflsuh(stdin);
                        if(simOuNao==83 || simOuNao==115){
                        printf("Insira seu estado civil:\n(solteiro=1, casado, separado, divorciado, viúvo)\n");
                        int controle;
                        scanf("%d", &controle);
                        switch (controle)
                        {
                        case 1:
                            jogadores[joga].estadoCivil=solteiro;
                            break;
                        case 2:
                            jogadores[joga].estadoCivil=casado;
                            break;
                        case 3:
                            jogadores[joga].estadoCivil=separado;
                            break; 
                        case 4:
                            jogadores[joga].estadoCivil=divorciado;
                            break; 
                        case 5:
                            jogadores[joga].estadoCivil=viúvo;
                            break;    
                        default:
                            printf("Estado civil não atualizado.\n");
                            break;
                        }
                            fflush(stdin);
                            printf("Prontinho!!\n");
                            simOuNao=0;
                            break;
                        }else  if(simOuNao==78||simOuNao==110){
                            printf("Operação cancelada!!\n");
                            simOuNao=0;
                            break;
                        }else{
                            printf("Escolha uma opção válida!!\n\n");
                        }
                    }while(simOuNao!=0);
            case 6:printf("O time atual é: %s.\n", jogadores[joga].team.nome);//time
                    do{
                        printf("Tem certeza que deseja mudar?\n(S- sim, N- não)\n");
                        gets(simOuNao);
                        fflsuh(stdin);
                        if(simOuNao==83 || simOuNao==115){

                            fflush(stdin);
                            printf("Prontinho!!\n");
                            simOuNao=0;
                            break;
                        }else  if(simOuNao==78||simOuNao==110){
                            printf("Operação cancelada!!\n");
                            simOuNao=0;
                            break;
                        }else{
                            printf("Escolha uma opção válida!!\n\n");
                        }
                    }while(simOuNao!=0);
            case 7:printf("O maior patrocinador atualmente é: %s.\n", jogadores[joga].patrocinador);//patrocinador
                    do{
                        printf("Tem certeza que deseja mudar?\n(S- sim, N- não)\n");
                        gets(simOuNao);
                        fflsuh(stdin);
                        if(simOuNao==83 || simOuNao==115){
                            printf("Qual o maior patrocinador atual?\n");
                            gets(jogadores[joga].patrocinador);
                            fflush(stdin);
                            printf("Prontinho!!\n");
                            simOuNao=0;
                            break;
                        }else  if(simOuNao==78||simOuNao==110){
                            printf("Operação cancelada!!\n");
                            simOuNao=0;
                            break;
                        }else{
                            printf("Escolha uma opção válida!!\n\n");
                        }
                    }while(simOuNao!=0);
            case 8:printf("O nickname atual é: %s.\n", jogadores[joga].nickname);//nickname
                    do{
                        printf("Tem certeza que deseja mudar?\n(S- sim, N- não)\n");
                        gets(simOuNao);
                        fflsuh(stdin);
                        if(simOuNao==83 || simOuNao==115){
                            printf("Qual é o seu nickname?\n");
                            gets(jogadores[joga].nickname);
                            fflush(stdin);
                            printf("Prontinho!!\n");
                            simOuNao=0;
                            break;
                        }else  if(simOuNao==78||simOuNao==110){
                            printf("Operação cancelada!!\n");
                            simOuNao=0;
                            break;
                        }else{
                            printf("Escolha uma opção válida!!\n\n");
                        }
                    }while(simOuNao!=0);
            case 9:printf("A quantidade atual de seguidores é: %d.\n", jogadores[joga].seguidores);//seguidores
                    do{
                        printf("Tem certeza que deseja mudar?\n(S- sim, N- não)\n");
                        gets(simOuNao);
                        fflsuh(stdin);
                        if(simOuNao==83 || simOuNao==115){
                            printf("Quantos seguidores tem nas redes sociais?\n");
                            scanf("%d", &jogadores[joga].seguidores);
                            fflush(stdin);
                            printf("Prontinho!!\n");
                            simOuNao=0;
                            break;
                        }else  if(simOuNao==78||simOuNao==110){
                            printf("Operação cancelada!!\n");
                            simOuNao=0;
                            break;
                        }else{
                            printf("Escolha uma opção válida!!\n\n");
                        }
                    }while(simOuNao!=0);
            case 10:printf("O setup atual é: .\n");//setup
                    do{
                        printf("Tem certeza que deseja mudar?\n(S- sim, N- não)\n");
                        gets(simOuNao);
                        fflsuh(stdin);
                        if(simOuNao==83 || simOuNao==115){

                            fflush(stdin);
                            printf("Prontinho!!\n");
                            simOuNao=0;
                            break;
                        }else  if(simOuNao==78||simOuNao==110){
                            printf("Operação cancelada!!\n");
                            simOuNao=0;
                            break;
                        }else{
                            printf("Escolha uma opção válida!!\n\n");
                        }
                    }while(simOuNao!=0);
            case 11:printf("A pontuação atual é %d.\n", jogadores[joga].pontos.pontuacao);//pontuação
                        do{
                        printf("Tem certeza que deseja mudar?\n(S- sim, N- não)\n");
                        gets(simOuNao);
                        fflsuh(stdin);
                        if(simOuNao==83 || simOuNao==115){

                            fflush(stdin);
                            printf("Prontinho!!\n");
                            simOuNao=0;
                            break;
                        }else  if(simOuNao==78||simOuNao==110){
                            printf("Operação cancelada!!\n");
                            simOuNao=0;
                            break;
                        }else{
                            printf("Escolha uma opção válida!!\n\n");
                        }
                    }while(simOuNao!=0); 
                    inserirPontuacao(jogadores, joga);
            case 12: printf("A quantidade atual de títulos é %d.\n", jogadores[joga].titulos);//titulos
                    do{
                        printf("Tem certeza que deseja mudar?\n(S- sim, N- não)\n");
                        gets(simOuNao);
                        fflsuh(stdin);
                        if(simOuNao==83 || simOuNao==115){
                            printf("O jogador possuí quantos títulos?\n");
                            scanf("%d", &jogadores[joga].titulos);
                            fflush(stdin);
                            printf("Prontinho!!\n");
                            simOuNao=0;
                            break;
                        }else  if(simOuNao==78||simOuNao==110){
                            printf("Operação cancelada!!\n");
                            simOuNao=0;
                            break;
                        }else{
                            printf("Escolha uma opção válida!!\n\n");
                        }
                    }while(simOuNao!=0);
            case 13: printf("A posição atual é:%d.\n", jogadores[joga].posicao);//posição no ranking
                    do{
                        printf("Tem certeza que deseja mudar?\n(S- sim, N- não)\n");
                        gets(simOuNao);
                        fflsuh(stdin);
                        if(simOuNao==83 || simOuNao==115){
                            printf("Qual a sua posição no ranking global?\n");
                            scanf("%d", &jogadores[joga].posicao);
                            fflush(stdin);
                            fflush(stdin);
                            printf("Prontinho!!\n");
                            simOuNao=0;
                            break;
                        }else  if(simOuNao==78||simOuNao==110){
                            printf("Operação cancelada!!\n");
                            simOuNao=0;
                            break;
                        }else{
                            printf("Escolha uma opção válida!!\n\n");
                        }
                    }while(simOuNao!=0);
            case 14: if(joga=100){//sair
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
