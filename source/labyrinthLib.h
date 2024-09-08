#ifndef LABYRINTH_H
#define LABYRINTH_H

#include <stdbool.h>

/* Quantidade máxima de posições 
presentes em um labirinto. */
#define MAX_ELEMENTS 10

#define LAB_ENTER 'E'
#define LAB_WALL 'X'
#define LAB_PATH '0'
#define LAB_EXIT 'S'

/* Estrutura que corresponde a cada 
posição presente no labirinto. */
typedef struct{
    char value;
    bool pathInvalid;
} matrixEl;

// Estrutura que corresponde ao labirinto.
typedef struct{
    bool isInvalid;
    matrixEl allEls[MAX_ELEMENTS][MAX_ELEMENTS];
} labyrinth;

/*
 * @brief Leitura de um labirinto.
 * 
 * Essa função possui a finalidade de ler o 
 * labirinto presente no arquivo "labirinto.txt".
 * 
 * @return a estrutura do labirinto.
 */
labyrinth readLabyrinthFile();

/*
 * @brief Escreve o labirinto no console.
 * 
 * Essa função possui a finalidade de escrever
 * um labirinto lido ateriormente no console.
 */
void showLabyrinth(labyrinth lab);

/*
 * @brief Encontra a entrada do labirinto.
 * 
 * Essa função possui a finalidade de encontrar 
 * a posição da entrada na matriz.
 * 
 * @param lab: estrutura do tipo labirinto.
 * 
 * @param line: endereço de um número inteiro 
 * (onde a linha da entrada será gravada).
 * 
 * @param line: endereço de um número inteiro 
 * (onde a coluna da entrada será gravada).
 */
void findLabEnter(labyrinth lab, int* line, int* collumn);

#endif