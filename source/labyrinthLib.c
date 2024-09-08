#include <stdio.h>
#include <stdlib.h>
#include "labyrinthLib.h"

/*TO-DO: Essa função é terrível! Vou 
aprimorar os processos de análise de 
arquivos posteriormente.*/
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
    if(!lab.isInvalid)
        for(int i = 0; i < MAX_ELEMENTS; i++)
            for(int j = 0; j < MAX_ELEMENTS; j++)
                if(lab.allEls[i][j].value == LAB_ENTER){
                    (*line) = i;
                    (*collumn) = j;
                }
}
stack* findLabPath(labyrinth lab){
    stack* currentPath = createStack();
    if(!lab.isInvalid){
        int currentLine, currentCollumn; 
        findLabEnter(lab, &currentLine, &currentCollumn);
        addEl(currentPath, createEl(currentLine, currentCollumn));
        while(lab.allEls[currentLine][currentCollumn].value != LAB_EXIT){
            bool moved = false;
            for(int i = -1; i < 2; i++){
                for(int j = -1; j < 2; j++){
                    if ((i == 0 || j == 0) && (i != j)){
                        int newLine = currentLine + i;
                        int newCollumn = currentCollumn + j;
                        if (newLine < MAX_ELEMENTS && newCollumn < MAX_ELEMENTS && newLine >= 0 && newCollumn >= 0){
                            if ((lab.allEls[newLine][newCollumn].value == LAB_PATH || lab.allEls[newLine][newCollumn].value == LAB_EXIT) && !lab.allEls[newLine][newCollumn].pathInvalid){
                                if(searchEl(currentPath, newLine, newCollumn) == NULL){
                                    addEl(currentPath, createEl(newLine, newCollumn));
                                    currentLine = newLine;
                                    currentCollumn = newCollumn;
                                    moved = true;
                                    break;
                                }
                            }
                        }
                    }
                
                }
                if(moved) break;
            }
            if(!moved){
                lab.allEls[currentLine][currentCollumn].pathInvalid = true;
                free(removeEl(currentPath));
                currentLine = (*currentPath).topEl->line;
                currentCollumn = (*currentPath).topEl->collumn;
            }
        }
    }
    return currentPath;
}

