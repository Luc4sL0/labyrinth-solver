#include <stdio.h>
#include "labyrinthLib.h"

int main(){
    labyrinth myLab = readLabyrinthFile();
    stack* path = findLabPath(myLab);
    showStack(*path);
    return 0;
}