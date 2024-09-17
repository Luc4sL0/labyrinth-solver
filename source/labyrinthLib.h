/*
Grupo: 
    - Lucas Lopes Baroni (2024.1.08.017)
    - João Antônio Siqueira Pascuini (2024.1.08.028)
*/

#ifndef LABYRINTH_H
#define LABYRINTH_H

#include <stdbool.h>
#include "stackLib.h"

/* Quantidade máxima de posições 
presentes em um labirinto. */
#define MAX_ELEMENTS 10

#define LAB_ENTER 'E'
#define LAB_WALL 'X'
#define LAB_PATH '0'
#define LAB_PATH_INVALID '1'
#define LAB_EXIT 'S'

/* Estrutura que corresponde ao labirinto. */
typedef struct{
    bool isInvalid;
    char allEls[MAX_ELEMENTS][MAX_ELEMENTS];
} labyrinth;

/*
 * @brief Leitura de um labirinto.
 * 
 * Essa função possui a finalidade de ler o 
 * labirinto presente no arquivo "labirinto.txt".
 * 
 * @param fileName: nome do arquivo.
 * @return a estrutura do labirinto.
 */
labyrinth readLabyrinthFile(char fileName[]);

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
 * @param column: endereço de um número inteiro 
 * (onde a coluna da entrada será gravada).
 */
void findLabEnter(labyrinth lab, int* line, int* column);

/*
 * @brief Encontra o caminho necessário para 
 * sair de um determinado labirinto.
 * 
 * Essa função possui a finalidade de registrar 
 * em uma pilha, o caminho percorrido até a saída
 * de um labirinto.
 * 
 * @param lab: estrutura do tipo labirinto.
 * @return a pilha com o caminho.
 */
stack* findLabPath(labyrinth lab);

#endif
