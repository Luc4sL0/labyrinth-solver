#include <stdio.h>
#include <stdlib.h>
#include "stackLib.h"

stack* createStack(){
	stack* list = malloc(sizeof(stack));
	(*list).items = NULL;
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
			}
			else{
				removedEl = aux;
				(*list).items = NULL;
			}
		}
	}
	return removedEl;
}
pathEl* searchEl(stack* list, pathEl* el){
	pathEl* searchedEl = NULL;
	if(list != NULL){
		pathEl* aux = (*list).items;
		if(aux != NULL){
			while(aux != NULL){
				if((*aux).line == (*el).line && (*aux).collumn == (*el).collumn)
					searchedEl = aux;
				aux = (*aux).next;
			}
		}
	}
	return searchedEl;
}
void showStack(stack list){
	while (list.items != NULL){
		printf("%d,%d\n", list.items->collumn, list.items->line);
		list.items = list.items->next;
	}
	printf("\n");
}
