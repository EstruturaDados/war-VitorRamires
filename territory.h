#ifndef TERRITORY_H
#define TERRITORY_H

#define CHAR_NAME_TOTAL 30
#define CHAR_COLOR_TOTAL 10

typedef struct {
    char nome[CHAR_NAME_TOTAL];
    char cor[CHAR_COLOR_TOTAL];
    int tropas;
} Territory;

#endif
