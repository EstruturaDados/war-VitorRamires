#include <stdio.h>
#include <string.h>

#define ALL_TERRITORIES 5
#define CHAR_NAME_TOTAL 30
#define CHAR_COLOR_TOTAL 10

// Struct do território
struct Territory {
    char name[CHAR_NAME_TOTAL];
    char color[CHAR_COLOR_TOTAL];
    int troops;
};

// Limpar buffer
void cleanBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função Principal
int main() {
    //referencia a Struct do territorio com tamanho de terriorios definido
    struct Territory WorldMap[ALL_TERRITORIES];
    int totalTerritories = 0;
    int option;

    // Lógica de looping para o menu do jogo
    do {
        printf("==================================\n");
        printf("War_Territories\n");
        printf("==================================\n");
        printf("1 - Add new territory\n");
        printf("2 - List All territories\n");
        printf("0 - Exit\n");
        printf("==================================\n");
        printf("Choose an option: ");

        scanf("%d", &option);  
        cleanBuffer();

        //Tratamento das opções referentes ao menu
        switch (option) {
            case 1:
                printf("-- New territory\n\n");
                //Antes de adicionar terriorio, verifica se o mapa esta cheio e caso não, disponibiliza os campos de nome, cor e tropas
                if (totalTerritories < ALL_TERRITORIES) {
                    printf("Territory name: ");
                    fgets(WorldMap[totalTerritories].name, CHAR_NAME_TOTAL, stdin);
                    WorldMap[totalTerritories].name[strcspn(WorldMap[totalTerritories].name, "\n")] = '\0'; 

                    printf("Territory color: ");
                    fgets(WorldMap[totalTerritories].color, CHAR_COLOR_TOTAL, stdin);
                    WorldMap[totalTerritories].color[strcspn(WorldMap[totalTerritories].color, "\n")] = '\0'; 

                    printf("Territory troops: ");
                    scanf("%d", &WorldMap[totalTerritories].troops);
                    cleanBuffer();

                    //Incrementa na variavel de total de territórios
                    totalTerritories++;
                    printf("-- Territory Added!\n");
                } else {
                    printf("-- World Map is full!\n");
                }
                break; 

            case 2:
                //Caso a escolha seja listar os elementos, verifica se o mapa esta vazio. Não estando, lista os territorios criados com seus dados
                printf("-- Territory List\n\n");
                if (totalTerritories == 0) {
                    printf("-- World Map is empty!\n");
                } else {
                    for (int i = 0; i < totalTerritories; i++) {
                        printf("==================================\n");
                        printf("Territory: %d\n", i + 1); 
                        printf("Territory name: %s\n", WorldMap[i].name);
                        printf("Territory color: %s\n", WorldMap[i].color);
                        printf("Territory troops: %d\n", WorldMap[i].troops); 
                    }
                    printf("==================================\n");
                }
                break; 

            case 0:
                // Sair do jogo
                printf("\nExiting the game...\n");
                break;

            default:
                // Tratamento de erros para opções inválidas
                printf("\nInvalid Option!\n");
                printf("\nPress enter to continue\n");
                getchar();
                break;
        }
    
    // Looping continua funcionando até a opção 0 ser selecionada
    } while (option != 0);

    return 0;
}