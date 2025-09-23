#include <stdio.h>
#include <stdlib.h>
#include "battle.h"

void attack(struct Territory* worldMap, int totalTerritories) {
    int attacker, defender;

    // Listar territórios
    printf("\n-- Territory List --\n");
    for (int i = 0; i < totalTerritories; i++) {
        printf("%d - %s (%s) - Troops: %d\n", i + 1,
               worldMap[i].name, worldMap[i].color, worldMap[i].troops);
    }

    // Escolher o atacante
    do {
        printf("Choose the attacker (1-%d): ", totalTerritories);
        scanf("%d", &attacker);
    } while (attacker < 1 || attacker > totalTerritories);

    // Escolher o defensor
    do {
        printf("Choose the defender (1-%d): ", totalTerritories);
        scanf("%d", &defender);
    } while (defender < 1 || defender > totalTerritories || defender == attacker);

    attacker--; defender--; // ajustar para índice do array

    // Escolher vencedor aleatoriamente, caso 0 é o atacande, caso 1 é o defensor
    int winner = rand() % 2; 

    // Escolher número de tropas perdidas aletoriamente
    int loserTroops = 0;
    if (winner == 0) {
        // atacante ou defensor vence, e assim é calculado a quantidade de tropas perdidas e dimuida com as tropas originais. 
        if (worldMap[defender].troops > 0)
            loserTroops = rand() % worldMap[defender].troops + 1;
        worldMap[defender].troops -= loserTroops;
        if (worldMap[defender].troops < 0) worldMap[defender].troops = 0;
        printf("%s wins! %s lost %d troops.\n", worldMap[attacker].name, worldMap[defender].name, loserTroops);
    } else {
        if (worldMap[attacker].troops > 0)
            loserTroops = rand() % worldMap[attacker].troops + 1;
        worldMap[attacker].troops -= loserTroops;
        if (worldMap[attacker].troops < 0) worldMap[attacker].troops = 0;
        printf("%s wins! %s lost %d troops.\n", worldMap[defender].name, worldMap[attacker].name, loserTroops);
    }

    // Mostrar estado final
    printf("\n-- Territory Status --\n");
    printf("%s: %d troops\n", worldMap[attacker].name, worldMap[attacker].troops);
    printf("%s: %d troops\n", worldMap[defender].name, worldMap[defender].troops);
}