#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "territory.h"
#include "battle.h"
#include "mission.h"

#define ALL_TERRITORIES 5
#define TOTAL_MISSOES 5

void cleanBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    Territory* WorldMap = (Territory*) calloc(ALL_TERRITORIES, sizeof(Territory));
    int totalTerritories = 0;
    int option;

    // Missões
    char* missoes[TOTAL_MISSOES] = {
        "Conquistar território com mais de 5 tropas",
        "Eliminar todas as tropas da cor vermelha",
        "Possuir 3 territórios seguidos",
        "Ter 10 tropas no total",
        "Conquistar o território azul"
    };

    char* missaoDoJogador = NULL;
    atribuirMissao(&missaoDoJogador, missoes, TOTAL_MISSOES);
    exibirMissao(missaoDoJogador);

    do {
        printf("\n1 - Adicionar território\n2 - Listar territórios\n3 - Atacar\n0 - Sair\nEscolha: ");
        scanf("%d", &option);
        cleanBuffer();

        switch(option) {
            case 1:
                if(totalTerritories < ALL_TERRITORIES) {
                    printf("Nome do território: ");
                    fgets(WorldMap[totalTerritories].nome, CHAR_NAME_TOTAL, stdin);
                    WorldMap[totalTerritories].nome[strcspn(WorldMap[totalTerritories].nome, "\n")] = '\0';

                    printf("Cor do território: ");
                    fgets(WorldMap[totalTerritories].cor, CHAR_COLOR_TOTAL, stdin);
                    WorldMap[totalTerritories].cor[strcspn(WorldMap[totalTerritories].cor, "\n")] = '\0';

                    printf("Tropas: ");
                    scanf("%d", &WorldMap[totalTerritories].tropas);
                    cleanBuffer();

                    totalTerritories++;
                } else {
                    printf("Mapa cheio!\n");
                }
                break;

            case 2:
                for(int i=0;i<totalTerritories;i++) {
                    printf("%d - %s (%s) - Tropas: %d\n", i+1, WorldMap[i].nome, WorldMap[i].cor, WorldMap[i].tropas);
                }
                break;

            case 3:
                if(totalTerritories >= 2) {
                    int atk, def;
                    for(int i=0;i<totalTerritories;i++)
                        printf("%d - %s (%s) - Tropas: %d\n", i+1, WorldMap[i].nome, WorldMap[i].cor, WorldMap[i].tropas);

                    do {
                        printf("Escolha o atacante: "); scanf("%d", &atk);
                    } while(atk<1 || atk>totalTerritories);

                    do {
                        printf("Escolha o defensor: "); scanf("%d", &def);
                    } while(def<1 || def>totalTerritories || def==atk);

                    atacar(&WorldMap[atk-1], &WorldMap[def-1]);

                    // Verifica missão
                    if(verificarMissao(missaoDoJogador, WorldMap, totalTerritories)) {
                        printf("\nMissão cumprida! Você venceu!\n");
                    }
                    
                    // Verifica o estado atual dos territórios
                    printf("\n-- Estado Atual dos Territórios --\n");
                    for(int i=0;i<totalTerritories;i++) {
                        printf("%d - %s (%s) - Tropas: %d\n", i+1, WorldMap[i].nome, WorldMap[i].cor, WorldMap[i].tropas);
                    }

                } else {
                    printf("Necessário pelo menos 2 territórios para atacar.\n");
                }
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida!\n");
                break;
        }

    } while(option != 0);

    // Liberar memória
    free(WorldMap);
    free(missaoDoJogador);

    return 0;
}
