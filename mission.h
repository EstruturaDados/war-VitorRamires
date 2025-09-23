#ifndef MISSION_H
#define MISSION_H

#include "territory.h"

void atribuirMissao(char** missaoDoJogador, char* missoes[], int totalMissoes);
int verificarMissao(char* missao, Territory* mapa, int tamanho);
void exibirMissao(const char* missao);

#endif