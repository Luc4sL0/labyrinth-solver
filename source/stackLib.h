#ifndef STACKLIB_H
#define STACKLIB_H

typedef struct _pathEl{
	int line, collumn;
	struct _pathEl* next;
}pathEl;
// Estrutura de dados do tipo pilha.
typedef struct stack_{
	pathEl *items;
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
 * @brief Cria um novo elemento.
 * 
 * Essa função possui a finalidade de criar,
 * um novo elemento do tipo pathEl.
 * 
 * @param line: a linha na qual o elemento está
 * na matriz.
 * 
 * @param collumn: a coluna na qual o elemento está
 * na matriz.
 * 
 * @return o endereço do elemento criado.
 */
pathEl* createEl(int line, int collumn);

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
int addEl(stack* list, pathEl* element);

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
pathEl* removeEl(stack* list);

/*
 * @brief Busca um elemento na pilha.
 * 
 * Essa função possui a finalidade de encontrar,
 * caso seja possível, um determinado elemento 
 * presente na pilha.
 * 
 * @param list: estrutura do tipo pilha.
 * @param el: elemento buscado.
 * @return o endereço do elemento encontrado: 
 * end != NULL (êxito), end == NULL (erro).
 */
pathEl* searchEl(stack* list, pathEl* el);

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