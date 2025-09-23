#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "territory.h"
#include "battle.h"

#define ALL_TERRITORIES 5

// Limpar buffer
void cleanBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    struct Territory* WorldMap;
    int totalTerritories = 0;
    int option;

    // Alocar memória dinamicamente para o mapa
    WorldMap = (struct Territory*) malloc(sizeof(struct Territory) * ALL_TERRITORIES);
    if (!WorldMap) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Inicializar rand
    srand(time(NULL));

    // Loop do menu
    do {
        printf("==================================\n");
        printf("War_Territories\n");
        printf("==================================\n");
        printf("1 - Add new territory\n");
        printf("2 - List All territories\n");
        printf("3 - Battle Phase\n");
        printf("0 - Exit\n");
        printf("==================================\n");
        printf("Choose an option: ");

        scanf("%d", &option);
        cleanBuffer();

        switch (option) {
            case 1:
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

                    totalTerritories++;
                    printf("-- Territory Added!\n");
                } else {
                    printf("-- World Map is full!\n");
                }
                break;

            case 2:
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

            case 3:
                if (totalTerritories < 2) {
                    printf("At least 2 territories are needed to attack!\n");
                } else {
                    attack(WorldMap, totalTerritories);
                }
                break;

            case 0:
                printf("\nExiting the game...\n");
                break;

            default:
                printf("\nInvalid Option!\n");
                printf("Press enter to continue\n");
                getchar();
                break;
        }

    } while (option != 0);

    // Libera a memoria alocada
    free(WorldMap); 
    return 0;
}
