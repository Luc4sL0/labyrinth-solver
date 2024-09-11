#ifndef SYSTEMDEBUG_H
#define SYSTEMDEBUG_H

#include <stdio.h>

/* Remova o comentário do termo (printf) para obter 
mensagens de erro no terminal. */
#define DEBUG_SYS printf

/* Estrutura que armazena todos as mensagens de erro.*/
char* errorHandler[] = {
    "O arquivo do labirinto (%s) não foi encontrado.\n",
    "O arquivo do labirinto (%s) possui caracteres não permitidos.\n",
    "O arquivo do labirinto (%s) possui um número de caracteres menor que %d (%d). Observação: Deve haver quebra de linhas no arquivo! \n",
};

char* processHandler[] = {
    "O labirinto processado não possui solução.\n",
};

#endif
