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
	while(el!=NULL){
		e(el->value);
		el = el->next;
	}
}

void *getElementAt(LinkedList list, int index){
	Element *ele = (Element *)list.head;
	for (int i = 0; i < list.length; ++i){
		if(i==index)
			return ele->value;
		else
			ele = ele->next;
	}
	return NULL;
}

int indexOf(LinkedList list, void *element){
	Element *ele = (Element *)list.head;
	int el = *(int *)element;
	for (int i = 0; i < list.length; ++i){
		if(el == *(int *)ele->value)
			return i;
		else
			ele = ele->next;
	}
	return -1;
}

void *deleteElementAt(LinkedList *list, int index){
	Element *ele = (Element *)list->head;
	for (int i = 0; i < list->length; ++i){
		if(index == 0){
			list->head = ele->next;
			free(ele);
			list->length--;
			return ele->value;
		}
		if(i == index-1){
			Element *e = ele->next;
			ele->next = ele->next->next;
			list->length--;
			return e->value;
		}
		if(i == list->length-2){
			Element *e = ele->next;
			ele->next = NULL;
			return e->value;
		}
		else
			ele = ele->next;
	}
	return NULL;
}

int asArray(LinkedList list, void **arr, int maxElements){
	Element *ele = (Element *)list.head;
	int limit = list.length > maxElements ? maxElements: list.length;
	for (int i = 0; i < limit; ++i){
		arr[i] = ele->value;
		ele = ele->next;
	}
	return limit;
}

LinkedList filter(LinkedList list, MatchFunc match, void *hint){
	Element *ele = (Element *)list.head;
	LinkedList new_list = createList();
	while(ele != NULL){
		if(match(hint,ele->value)){
			add_to_list(&new_list,ele->value);
		}
		ele = ele->next;
	}
	return new_list;
}