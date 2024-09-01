#ifndef LABYRINTH_H
#define LABYRINTH_H

/* Quantidade máxima de posições 
presentes em um labirinto. */
#define MAX_ELEMENTS 10

/* Estrutura que corresponde a cada 
posição presente no labirinto. */
typedef struct _matrixEl{
    char value;
    bool pathInvalid;
    struct _matrixEl *next;
} matrixEl;

// Estrutura que corresponde ao labirinto
typedef struct{
    matrixEl allEls[MAX_ELEMENTS][MAX_ELEMENTS];
} labyrinth;

#endif