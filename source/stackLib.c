#include <stdio.h>
#include <stdlib.h>
#include "stackLib.h"

stack* createStack(){
	stack* list = malloc(sizeof(stack));
	(*list).items = NULL;
	return list;
}
int addEl(stack* list, matrixEl* element){
	if(list != NULL){
		matrixEl* aux = (*list).items;
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
matrixEl* removeEl(stack* list){
	matrixEl* removedEl = NULL;
	if(list != NULL){
		if((*list).items != NULL){
			matrixEl* aux = (*list).items;
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
void showStack(stack list){
	while (list.items != NULL){
		printf("%4d", list.items->value);
		list.items = list.items->next;
	}
	printf("\n");
}
