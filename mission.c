#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "mission.h"

void atribuirMissao(char** missaoDoJogador, char* missoes[], int totalMissoes) {
    srand(time(NULL));
    int sorteio = rand() % totalMissoes;
    *missaoDoJogador = (char*) malloc(strlen(missoes[sorteio]) + 1);
    strcpy(*missaoDoJogador, missoes[sorteio]);
}

int verificarMissao(char* missao, Territory* mapa, int tamanho) {
    // Lógica simples inicial: se algum território tiver mais de 5 tropas, missão cumprida
    for(int i=0; i<tamanho; i++) {
        if(strcmp(missao, "Conquistar território com mais de 5 tropas") == 0 && mapa[i].tropas > 5) {
            return 1;
        }
    }
    return 0;
}

void exibirMissao(const char* missao) {
    printf("Sua missão: %s\n", missao);
}