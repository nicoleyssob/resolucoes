#include <stdio.h>
#include <stdlib.h>>
#include <time.h>

int main(){
    //imprime o cabecalho
    printf("                   |>>>                          \n");
    printf("                   |                             \n");
    printf("          |>>>    _|_    |>>>                  \n");
    printf("          |      /   \\      |                   \n");
    printf("     _  _|_  _  /     \\  _  _|_  _             \n");
    printf("    | |_| |_| |/_______\\| |_| |_| |            \n");
    printf("    \\  .      /         \\     .   /           \n");
    printf("     \\    .  /           \\  .    /             \n");
    printf("      | .    |    JOGO    |    . |             \n");
    printf("      |      |     DE     |      |             \n");
    printf("      |   .  | ADVINHACAO |   .  |             \n");
    printf("     / \\     |___________ |     / \\           \n");
    printf("    /   \\  .    |     |    .   /   \\          \n");
    printf("   /_____\\      |     |       /_____\\        \n");
    printf("    |   |       |     |        |   |          \n");
    printf("    |___|_______|_____|________|___|          \n");


    //pega os segundos passados desde 1970 ate hj
    int segundos=time(0);
    srand(segundos);//coloca ele como semente da funcao rand
    int numerogrande=rand();//faz um numero aleatorio a partir da semente

    int numerosecreto=numerogrande % 100;
    int chute=0;
    int ganhou=0;
    int tentativas=1;
    double pontos=1000;
    double pontosperdidos=0;
    int acertou=0;
    int nivel;

    printf("\nQual o nivel de dificuldade?\n1-Facil 2-Medio 3-Dificil\n");
    printf("Escolha: ");
    scanf("%d",&nivel);

    int numerodetentativas;

    switch(nivel){
        case 1:
            numerodetentativas=15;
            break;
        case 2:
            numerodetentativas=10;
            break;
        default:
            numerodetentativas=6;
            break;
    }

    for(int i=1;i<=numerodetentativas;i++){
        printf("\nTentativa %d",tentativas);
        printf("\nChute um numero de 0 a 99:\n");
        scanf("%d",&chute);
        printf("Seu chute foi %d.\n",chute);

        if(chute<0){
            printf("Voce nao pode chutar numeros negativos!\n");
            continue; //quebra o resto do codigo mas volta pra proxima
                      //iteracao do laco de repeticao
        }

        acertou =(chute==numerosecreto);
        int maior = chute>numerosecreto;

        if(acertou){
            break;
        }
        else if(maior){
            printf("Seu chute foi maior que o numero secreto\n");
        }
        else{
            printf("Seu numero foi menor que o numero secreto\n");
        }
        tentativas++;
        pontosperdidos=abs(chute-numerosecreto)/2.0;
        
        pontos=pontos-pontosperdidos;
    }
    printf("Fim de jogo.\n");
    if(acertou){
printf("                    *****************\n");
printf("               ******               ******\n");
printf("           ****                           ****\n");
printf("        ****                                 ***\n");
printf("      ***                                       ***\n");
printf("     **           ***               ***           **\n");
printf("   **           *******           *******          ***\n");
printf("  **            *******           *******            **\n");
printf(" **             *******           *******             **\n");
printf(" **               ***               ***               **\n");
printf("**                                                     **\n");
printf("**       *                                     *       **\n");
printf("**      **                                     **      **\n");
printf(" **   ****                                     ****   **\n");
printf(" **      **                                   **      **\n");
printf("  **       ***                             ***       **\n");
printf("   ***       ****                       ****       ***\n");
printf("     **         ******             ******         **\n");
printf("      ***            ***************            ***\n");
printf("        ****                                 ****\n");
printf("           ****                           ****\n");
printf("               ******               ******\n");
printf("                    *****************\n");
        printf("\nVoce ganhou! Voce acertou em %d tentativas!\n",tentativas);
        printf("Voce fez %.1f pontos",pontos);
    }else{
        printf("                          oooo$$$$$$$$$$$$oooo\n");
        printf("                      oo$$$$$$$$$$$$$$$$$$$$$$$$o\n");
        printf("                   oo$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$o         o$   $$ o$\n");
        printf("   o $ oo        o$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$o       $$ $$ $$o$\n");
        printf("oo $ $ ""$      o$$$$$$$$$    $$$$$$$$$$$$$    $$$$$$$$$o       $$$o$$o$\n");
        printf("""$$$$$$o$     o$$$$$$$$$      $$$$$$$$$$$      $$$$$$$$$$o    $$$$$$$$\n");
        printf("  $$$$$$$    $$$$$$$$$$$      $$$$$$$$$$$      $$$$$$$$$$$$$$$$$$$$$$$\n");
        printf("  $$$$$$$$$$$$$$$$$$$$$$$    $$$$$$$$$$$$$    $$$$$$$$$$$$$$  $$$$$$$\n");
        printf("   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$     $$$$$\n");
        printf("    $$$   o$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$     $$$$$o\n");
        printf("   o$$$$   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$       $$$o\n");
        printf("   $$$    $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ $$$$$$$ooooo$$$$o\n");
        printf("  o$$$oooo$$$$$  $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$   o$$$$$$$$$$$$$$$$$\n");
        printf("  $$$$$$$$""$$$$   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$     $$$$""""""""\n");
        printf(" $$$$       $$$$    $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$      o$$$\n");
        printf("            $$$$o     $$$$$$$$$$$$$$$$$$$$$$$$$        $$$\n");
        printf("              $$$$o          $$$$$$$$$$$$$$           o$$$\n");
        printf("               $$$$o                 oo             o$$$$\n");
        printf("                $$$$$o      o$$$$$$o$$$$$o        o$$$$\n");
        printf("                  $$$$$$oo     $$$$$$o$$$$$o   o$$$$$$  \n");
        printf("                     $$$$$$$oooo  $$$$o$$$$$$$$$$$$\n");
        printf("                        $$$$$$$$$oo $$$$$$$$$$       \n");
        printf("                                $$$$$$$$$$$$$$        \n");
        printf("                                    $$$$$$$$$$$$       \n");
        printf("                                     $$$$$$$$$$$      \n");
        printf("                                      $$$$$$$$\n\n");
        printf("O numero secreto era %d.\nVoce perdeu, tente de novo.\n",numerosecreto);
    }

    return 0;
}