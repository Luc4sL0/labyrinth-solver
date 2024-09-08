#include <stdio.h>
#include <stdlib.h>
#include "labyrinthLib.h"
#include "stackLib.h"

//TO-DO: Essa função está horrível, nojenta! Melhorar.
bool checkLabyrinthFile(){ 
    FILE *file = fopen("labirinto.txt", "r");
    if(file == NULL){
        fclose(file);
        return false;
    }
    fclose(file);
    return true;
}
labyrinth readLabyrinthFile(){
    labyrinth newLab;
    if(checkLabyrinthFile()){
        FILE *file = fopen("labirinto.txt", "r");
        for(int i = 0; i < MAX_ELEMENTS; i++)
            for(int j = 0; j < MAX_ELEMENTS; j++){
                char c = fgetc(file);
                while (c == '\n')
                    c = fgetc(file);
                newLab.allEls[i][j].value = c;
                newLab.allEls[i][j].pathInvalid = false;
            }
        newLab.isInvalid = false;
        fclose(file);
    }
    else
        newLab.isInvalid = true;
    return newLab;
}
void showLabyrinth(labyrinth lab){
    if(!lab.isInvalid)
        for(int i = 0; i < MAX_ELEMENTS; i++){
            for(int j = 0; j < MAX_ELEMENTS; j++)
                printf("%c", lab.allEls[i][j].value);
            printf("\n");
        }
}
void findLabEnter(labyrinth lab, int* line, int* collumn){
    for(int i = 0; i < MAX_ELEMENTS; i++)
        for(int j = 0; j < MAX_ELEMENTS; j++)
            if(lab.allEls[i][j].value == LAB_ENTER){
                (*line) = i;
                (*collumn) = j;
            }
}
stack findLabPath(labyrinth lab){
    stack* currentPath = createStack();
    int currentLine, currentCollumn; 
    findLabEnter(lab, &currentLine, &currentCollumn);
    addEl(currentPath, createEl(currentLine, currentCollumn));

    if(!lab.isInvalid){
        while(lab.allEls[currentLine][currentCollumn].value != LAB_EXIT){
            for(int i = -1; i < 2; i++){
                if (currentLine + i < MAX_ELEMENTS){
                    if (lab.allEls[currentLine + i][currentCollumn].value == LAB_PATH && !lab.allEls[currentLine + i][currentCollumn].pathInvalid){
                        if(searchEl(currentPath, &lab.allEls[currentLine + i][currentCollumn]) == NULL)
                            addEl(currentPath, createEl(currentLine, currentCollumn));
                        else{
                            lab.allEls[currentLine][currentCollumn].pathInvalid = true;
                            removeEl(currentPath);
                        }
                        currentLine = currentLine + i;
                        break;
                    }
                }
                for(int j = -1; j < 2 && i == 0; j++){
                    if (currentLine + i < MAX_ELEMENTS && currentCollumn + j < MAX_ELEMENTS){
                        if (lab.allEls[currentLine + i][currentCollumn +j].value == LAB_PATH && !lab.allEls[currentLine + i][currentCollumn + j].pathInvalid){
                            if(searchEl(currentPath, &lab.allEls[currentLine + i][currentCollumn + j]) == NULL)
                                addEl(currentPath, createEl(currentLine, currentCollumn));
                            else{
                                lab.allEls[currentLine][currentCollumn].pathInvalid = true;
                                removeEl(currentPath);
                            }
                            currentLine = currentLine + i;
                            currentCollumn = currentCollumn + j;
                            break;
                        }
                    }
                }
            }  
        }
    }
    return *currentPath;
}

