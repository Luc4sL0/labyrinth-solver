#include <stdio.h>
#include "labyrinthLib.h"

/*
Por padrão, o primeiro labirinto a ser resolvido é o (labirintos/labirinto1.txt), 
caso queira alterar o arquivo, por favor insira o diretório dele como argumento 
para a chamada do programa. 

Exemplo: "/.labyrinthGame labirintos/labirinto2.txt"
*/
int main(int argc, char *argv[]){
    char* fileDirectory = "labirintos/labirinto1.txt";
    if(argc >= 2) fileDirectory = argv[1];
    showStack(*findLabPath(readLabyrinthFile(fileDirectory)));
    return 0;
}
