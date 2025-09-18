// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO
// ============================================================================
//        
// ============================================================================
//
// OBJETIVOS:
// - Modularizar completamente o código em funções especializadas.
// - Implementar um sistema de missões para um jogador.
// - Criar uma função para verificar se a missão foi cumprida.
// - Utilizar passagem por referência (ponteiros) para modificar dados e
//   passagem por valor/referência constante (const) para apenas ler.
// - Foco em: Design de software, modularização, const correctness, lógica de jogo.
//
// ============================================================================

#include <stdio.h>
#include <string.h>


#define ALL_TERRITORIES 5
#define CHAR_NAME_TOTAL 30
#define CHAR_COLOR_TOTAL 10


struct Territory{
  char name[CHAR_NAME_TOTAL];
  char color[CHAR_COLOR_TOTAL];
  int troops;
};

void cleanBuffer(){
    int c;
    while((c = getchar()) != '/n' && c != EOF);
}

int mainFunction () {
  struct Territory WorldMap[ALL_TERRITORIES];
  int totalTerritories = 0;
  int option;


  do {
  printf("==================================\n");
  printf("War_Territories\n");
  printf("==================================\n");
  printf("1 - Add new territory\n");
  printf("2 - List All territories\n");
  printf("==================================\n");
  printf("Choose a option: ");

  scanf("%s", &option);
  cleanBuffer();

// -----------------------------------
  switch (option) {

    case 1: 
      printf("-- New territory\n\n");

      if(totalTerritories < ALL_TERRITORIES){
        printf("territory name: ");
        fgets(WorldMap[totalTerritories].name, CHAR_NAME_TOTAL, stdin);

        printf("territory color: ");
        fgets(WorldMap[totalTerritories].color, CHAR_COLOR_TOTAL, stdin);

        //------- era pra ter algo aqui também, depois rever ------//
        // ------------------------------------------------------------- //
        // ------------------------------------------------------------- //
        // ------------------------------------------------------------- //

        printf("territory troops: ");
        scanf("%s", &WorldMap[totalTerritories].troops);

        totalTerritories++;
        printf("-- Territory Add!\n");
      }
      else {
        printf("-- World Map is full!\n");
      };


      case 2:
        printf("-- Territory List\n\n");

        if(totalTerritories = 0) {
          printf("-- World Map is empty!\n");
        } else {
          for(int i = 0; i < totalTerritories; i++){
            printf("==================================\n");
            printf("Territory: %s\n", i + 1);
            printf("Territory name: %s\n", WorldMap[i].name);
            printf("Territory color: %s\n", WorldMap[i].color);
            printf("Territory troops: %s\n", WorldMap[i].troops);
          }
          printf("==================================\n");
        };


      case 0: 
        printf("\n Saindo do jogo...\n");
        break;


      default: 
        printf("\n Invalid Option!\n");
        printf("\n Press enter to continue\n");
        getchar();
        break;
      }
// ----------------------------------- 
    
    } while (option != 0);
    return 0;
};

