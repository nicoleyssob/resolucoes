//TODAS AS ENTRADAS DEVEM SER EM LETRA MAIUSCULA

#include <stdio.h>
#include <string.h>
#include "forca.h"  //header files, 'biblioteca' criada por mim
#include <time.h>
#include <stdlib.h>

//variaveis globais
char palavrasecreta[TAMANHO_PALAVRA];
char chutes[26];
int chutesdados=0;

void abertura(){
    printf("*************************\n");
    printf("**    JOGO DE FORCA    **\n");
    printf("*************************\n");
}

void chuta(){ 
    char chute;
    scanf(" %c",&chute);
    chutes[(chutesdados)]=chute;//vetor pra armazenar os chutes dados
    (chutesdados)++;
}

void desenhaforca(){

    int erros = chuteserrados();

    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (erros>=1?'(':' '), 
        (erros>=1?'_':' '), (erros>=1?')':' '));
    printf(" |      %c%c%c  \n", (erros>=3?'\\':' '), 
        (erros>=2?'|':' '), (erros>=3?'/': ' '));
    printf(" |       %c     \n", (erros>=2?'|':' '));
    printf(" |      %c %c   \n", (erros>=4?'/':' '), 
        (erros>=4?'\\':' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");

    for(int i=0;i<strlen(palavrasecreta);i++){
        int achou = jachutou(palavrasecreta[i]);
        if(achou){
            printf("%c ",palavrasecreta[i]);//se achou vai imprimir o caracter na posição correta
        }else{
            printf("_");// se nao achar vai imprimir o traço
        } 
    }
    printf("\n");
}

void adicionapalavra(){
    char quer;
    printf("Voce deseja adicionar uma palavra nova? (S/N)");
    scanf(" %c",&quer);

    if(quer=='S'){
        char novapalavra [TAMANHO_PALAVRA];
        printf("Qual a nova palavra? ");
        scanf("%s",novapalavra);

        FILE* f;

        f=fopen("palavras.txt","r+");
        if(f==0){
            printf("Desculpe, banco de dados nao disponivel\n\n");
            exit(1);
        }

        int qtd;
        fscanf(f,"%d",&qtd);//pega a qtd de palavras do arquivo que ta na primeira linha
        qtd++;

        fseek(f,0,SEEK_SET); //o ponteiro aponta pro começo do arquivo por causa do 0
        fprintf(f,"%d",qtd); //imprime em cima do que tava escrito a nova qtd

        fseek(f,0,SEEK_END); //ponteiro aponta pro final do arquivo
        fprintf(f,"\n%s",novapalavra);//dá enter e imprime a nova palavra no final do arquivo

        fclose(f);
    }
}

void escolhepalavra(){
    FILE *f;

    f=fopen("palavras.txt","r");//abre o arquivo para leitura
    if(f==0){
        printf("Desculpe, banco de dados nao disponivel\n\n");
        exit(1);
    }

    int qtddepalavras;
    fscanf(f,"%d",&qtddepalavras); //chama f (abre o arq), e lê a primeira linha que tem a qtd de palavras

    srand(time(0));
    int randomico = rand() % qtddepalavras;
     /*pega um numero aleatorio e divide pela qtd de palavras,
    o resto da divisao será o aleatorio, pois o rand()
    traz um numero mt grande */

    for(int i=0;i<=randomico;i++){
        fscanf(f,"%s",palavrasecreta);
    }
    fclose(f);
}

int acertou(){
    for(int i=0;i<strlen(palavrasecreta);i++){
        if(!jachutou(palavrasecreta[i])){
            return 0;
        }
    }
    return 1;
}

int chuteserrados(){
    int erros=0;

    for(int i=0;i<chutesdados;i++){
        int existe=0;
        for(int j=0;j<strlen(palavrasecreta);j++){
            if(chutes[i]==palavrasecreta[j]){
                existe=1;
                break;
            }
        }
        if(!existe) erros++;
    }
    return erros;
}

int enforcou(){
    return chuteserrados()>=5;
}

int jachutou(char letra){
    int achou=0;

    for(int j=0;j<chutesdados;j++){ //loop pra ver se o chute é verdadeiro
        if(chutes[j]==letra){
            achou=1;
            break;
        }
    }
    return achou;
}

int main (){

    escolhepalavra();
    abertura();
    
    do{
        desenhaforca();
        chuta();
        
    }while(!acertou() && !enforcou());// ! é a negaçao, a condicao é rodar até que o usuario nao 
                                    //tenha acertado e nem tenha sido enforcado

    if(acertou()){
        printf("\nParabens, voce ganhou!\n\n");
        printf("             ___________         \n");
        printf("            '._==_==_=_.'        \n");
        printf("            .-\\:      /-.       \n");
        printf("           | (|:.     |) |       \n");
        printf("            '-|:.     |-'        \n");
        printf("              \\::.    /          \n");
        printf("               '::. .'           \n");
        printf("                 ) (             \n");
        printf("               _.' '._           \n");
        printf("          jgs `\"\"\"\"\"\"\"`          \n");

    }else{
        printf("\nPuxa, voce foi enforcado!\n");
        printf("A palavra secreta era **%s**\n\n",palavrasecreta);
        printf("  .-=-=-.           \n");
        printf(" /       \\         \n");
        printf("|         |         \n");
        printf("| )     ( |         \n");
        printf("\\/ .\\ /. \\/        \n");
        printf("(    ^    )         \n");
        printf(" |.     .|          \n");
        printf(" ||xxxxx||          \n");
        printf(" '-._._.-'          \n");

    }

    adicionapalavra();
}