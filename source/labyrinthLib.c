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
        DEBUG_SYS(errorHandler[2], fileName, (MAX_ELEMENTS*MAX_ELEMENTS), charCounter - 10);
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
                newLab.allEls[i][j].value = c;
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
                    break;
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
                            if ((lab.allEls[newLine][newCollumn].value == LAB_PATH || lab.allEls[newLine][newCollumn].value == LAB_EXIT)){
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
                if((*currentPath).items->next != NULL){
                    lab.allEls[currentLine][currentCollumn].value = LAB_PATH_INVALID;
                    free(removeEl(currentPath));
                    currentLine = (*currentPath).topEl->line;
                    currentCollumn = (*currentPath).topEl->collumn;
                }
                else{
                    free(removeEl(currentPath));
                    DEBUG_SYS("%s", processHandler[0]);
                    break;
                }
            }
        }
    }
    return currentPath;
}

