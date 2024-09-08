#include <stdio.h>
#include <stdlib.h>
#include "stackLib.h"

stack* createStack(){
	stack* list = malloc(sizeof(stack));
	(*list).items = NULL;
	(*list).topEl = NULL;
	return list;
}
pathEl* createEl(int line, int collumn){
	pathEl *element = malloc(sizeof(pathEl));
	(*element).line = line;
	(*element).collumn = collumn;
	(*element).next = NULL;
	return element;
}
int addEl(stack* list, pathEl* element){
	if(list != NULL){
		pathEl* aux = (*list).items;
		if(aux != NULL){
			while((*aux).next != NULL)
				aux = (*aux).next;
			(*aux).next = element;
		}
		else
			(*list).items = element;
		
		(*list).topEl = element;
		return 0;
	}
	return -1;
}
pathEl* removeEl(stack* list){
	pathEl* removedEl = NULL;
	if(list != NULL){
		if((*list).items != NULL){
			pathEl* aux = (*list).items;
			if((*aux).next != NULL){
				while((*aux).next->next != NULL)
					aux = (*aux).next;
				removedEl = (*aux).next;
				(*aux).next = NULL;
				(*list).topEl = aux;
			}
			else{
				removedEl = aux;
				(*list).items = NULL;
				(*list).topEl = NULL;
			}
		}
	}
	return removedEl;
}
pathEl* searchEl(stack* list, int line, int collumn){
	pathEl* searchedEl = NULL;
	if(list != NULL){
		pathEl* aux = (*list).items;
		if(aux != NULL){
			while(aux != NULL){
				if((*aux).line == line && (*aux).collumn == collumn)
					searchedEl = aux;
				aux = (*aux).next;
			}
		}
	}
	return searchedEl;
}
void showStack(stack list){
	while (list.items != NULL){
		printf("%d,%d\n", list.items->collumn, 9 - list.items->line);
		list.items = list.items->next;
	}
}
