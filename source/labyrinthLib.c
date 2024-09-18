#include <stdio.h>
#include <stdlib.h>
#include "labyrinthLib.h"
#include "systemDebug.h"

bool checkLabyrinthFile(char* fileName){ 
    FILE *file = fopen(fileName, "r");
    if(file != NULL){
        int charCounter = 1;
        char charCurrent;
        while((charCurrent = fgetc(file)) != EOF){
            if(charCurrent != LAB_ENTER && charCurrent != LAB_PATH && charCurrent != LAB_WALL 
            && charCurrent != LAB_EXIT && charCurrent != '\n'){
                fclose(file); 
                DEBUG_SYS(errorHandler[1], fileName);
                return false;
            }
            charCounter++;
        }
        if(charCounter == (MAX_ELEMENTS* MAX_ELEMENTS) + MAX_ELEMENTS){
            fclose(file); 
            return true;
        }
        DEBUG_SYS(errorHandler[2], fileName, (MAX_ELEMENTS*MAX_ELEMENTS), charCounter - MAX_ELEMENTS);
    }
    else
        DEBUG_SYS(errorHandler[0], fileName);
    fclose(file); 
    return false;
}
labyrinth readLabyrinthFile(char* fileName){
    labyrinth newLab;
    if(checkLabyrinthFile(fileName)){
        FILE *file = fopen(fileName, "r");
        for(int i = 0; i < MAX_ELEMENTS; i++)
            for(int j = 0; j < MAX_ELEMENTS; j++){
                char c = fgetc(file);
                while (c == '\n')
                    c = fgetc(file);
                newLab.allEls[i][j] = c;
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
                printf("%c", lab.allEls[i][j]);
            printf("\n");
        }
}
int findLabEnter(labyrinth lab, int* line, int* column){
    if(!lab.isInvalid)
        for(int i = 0; i < MAX_ELEMENTS; i++)
            for(int j = 0; j < MAX_ELEMENTS; j++)
                if(lab.allEls[i][j] == LAB_ENTER){
                    (*line) = i;
                    (*column) = j;
                    return 0;
                }
    return -1;
}
stack* findLabPath(labyrinth lab){
    stack* currentPath = createStack();
    if(!lab.isInvalid){
        int currentLine, currentColumn; 
        if(findLabEnter(lab, &currentLine, &currentColumn) == -1){
            DEBUG_SYS("%s", processHandler[0]);
            return currentPath;
        }
        addEl(currentPath, createEl(currentLine, currentColumn));
        while(lab.allEls[currentLine][currentColumn] != LAB_EXIT){
            bool moved = false;
            for(int i = -1; i < 2; i++){
                for(int j = -1; j < 2; j++){
                    if ((i == 0 || j == 0) && (i != j)){
                        int newLine = currentLine + i;
                        int newColumn = currentColumn + j;
                        if (newLine < MAX_ELEMENTS && newColumn < MAX_ELEMENTS && newLine >= 0 && newColumn >= 0){
                            if (lab.allEls[newLine][newColumn] == LAB_PATH || lab.allEls[newLine][newColumn] == LAB_EXIT){
                                if(searchEl(currentPath, newLine, newColumn) == NULL){
                                    addEl(currentPath, createEl(newLine, newColumn));
                                    currentLine = newLine;
                                    currentColumn = newColumn;
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
                if((*currentPath).items->next != NULL){
                    lab.allEls[currentLine][currentColumn] = LAB_PATH_INVALID;
                    free(removeEl(currentPath));
                    currentLine = (*currentPath).topEl->line;
                    currentColumn = (*currentPath).topEl->collumn;
                }
                else{
                    free(removeEl(currentPath));
                    DEBUG_SYS("%s", processHandler[1]);
                    break;
                }
            }
        }
    }
    return currentPath;
}

