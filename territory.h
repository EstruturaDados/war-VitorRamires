#ifndef TERRITORY_H
#define TERRITORY_H

#define CHAR_NAME_TOTAL 30
#define CHAR_COLOR_TOTAL 10

struct Territory {
    char name[CHAR_NAME_TOTAL];
    char color[CHAR_COLOR_TOTAL];
    int troops;
};

#endif
