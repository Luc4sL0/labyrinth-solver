#ifndef STACKLIB_H
#define STACKLIB_H

#include "labyrinthLib.h"

// Estrutura de dados do tipo pilha.
typedef struct stack_{
	matrixEl *items;
} stack;

/*
 * @brief Cria uma estrutura de dados do tipo pilha.
 * 
 * Essa função possui a finalidade de alocar 
 * na memória e configurar uma nova pilha.
 * 
 * @return o endereço de uma nova pilha alocada 
 * na memória.
 */
stack* createStack();

/*
 * @brief Adiciona um novo elemento na pilha.
 * 
 * Essa função possui a finalidade de inserir,
 * caso seja possível, um novo elemento na pilha.
 * 
 * @param list: estrutura do tipo pilha.
 * @param element: elemento que será inserido.
 * @return o status da operação: 0 (êxito), -1 (erro). 
 */
int addEl(stack* list, matrixEl* element);

/*
 * @brief Remove um elemento da pilha.
 * 
 * Essa função possui a finalidade de remover,
 * caso seja possível, um elemento presente 
 * na pilha.
 * 
 * @param list: estrutura do tipo pilha.
 * @return o endereço do elemento removido: 
 * end != NULL (êxito), end == NULL (erro).
 */
matrixEl* removeEl(stack* list);

/*
 * @brief Exibe no console uma pilha.
 * 
 * Essa função possui a finalidade de exibir,
 * caso seja possível, todos os elemento 
 * presentes na pilha.
 * 
 * @param list: estrutura do tipo pilha.
 */
void showStack(stack list);

#endif