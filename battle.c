#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "battle.h"

void atacar(Territory* atacante, Territory* defensor) {
    srand(time(NULL));
    int dadoAtacante = rand() % 6 + 1;
    int dadoDefensor = rand() % 6 + 1;

    printf("%s rolou %d, %s rolou %d\n", atacante->nome, dadoAtacante, defensor->nome, dadoDefensor);

    if (dadoAtacante > dadoDefensor) {
        // Atacante vence → transfere tropas do defensor para o atacante
        int tropasTransferidas = defensor->tropas / 2;
        atacante->tropas += tropasTransferidas;
        defensor->tropas -= tropasTransferidas;
        if(defensor->tropas < 0) defensor->tropas = 0;
        printf("%s venceu! Recebeu %d tropas do defensor.\n", atacante->nome, tropasTransferidas);
    } else {
        // Defensor vence → transfere tropas do atacante para o defensor
        int tropasTransferidas = atacante->tropas / 2;
        defensor->tropas += tropasTransferidas;
        atacante->tropas -= tropasTransferidas;
        if(atacante->tropas < 0) atacante->tropas = 0;
        printf("%s defendeu! Recebeu %d tropas do atacante.\n", defensor->nome, tropasTransferidas);
    }
}
