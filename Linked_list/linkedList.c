#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

LinkedList createList(void){
	LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
	list->head = NULL;
	list->tail = NULL;
	list->length = 0;
	return *list;
}

int add_to_list(LinkedList *list,void *ele){
	Element *e = (Element *)malloc(sizeof(Element));
	e->value = ele;
	e->next = NULL;
	if (list->length == 0)
		list->head = list->tail = e;
	else{
		list->tail->next = e;
		list->tail = e;
	}
	list->length++;
	return list->length;
}

void *get_first_element(LinkedList list){
	return list.head->value;
}

void *get_last_element(LinkedList list){
	return list.tail->value;
}

void forEach(LinkedList list, ElementProcessor e){
	Element *el = list.head;
	while(el->next!=NULL){
		e(el->value);
		el = el->next;
	}
}
