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

void increment(void *ele){
	*(int *)ele += 1;
}

void forEach(LinkedList list, ElementProcessor e){
	Element *el = list.head;
	while(el!=NULL){
		e(el->value);
		el = el->next;
	}
}

void *getElementAt(LinkedList list, int index){
	Element *ele = list.head;
	for (int i = 0; i < list.length; ++i){
		if(i==index)
			return ele->value;
		else
			ele = ele->next;
	}
	return NULL;
}

int indexOf(LinkedList list, void *element){
	Element *ele = list.head;
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
	Element *ele = list->head;
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
	Element *ele = list.head;
	int limit = list.length > maxElements ? maxElements: list.length;
	for (int i = 0; i < limit; ++i){
		arr[i] = ele->value;
		ele = ele->next;
	}
	return limit;
}

int isEven(void* hint, void* item){
  return *(int *)item%2==0;
}

LinkedList filter(LinkedList list, MatchFunc match, void *hint){
	Element *ele = list.head;
	LinkedList new_list = createList();
	while(ele != NULL){
		if(match(hint,ele->value)){
			add_to_list(&new_list,ele->value);
		}
		ele = ele->next;
	}
	return new_list;
}

LinkedList reverse(LinkedList list){
	Element *ele = list.head;
	LinkedList reversed_list = createList();
	for (int i = 0; i < list.length; ++i){
		Element *e = (Element *)malloc(sizeof(Element));
		e->value = ele->value;
		e->next = NULL;
		if(reversed_list.length == 0)
			reversed_list.head = reversed_list.tail = e;
		else{
			e->next = reversed_list.head;
			reversed_list.head = e;
		}
		reversed_list.length++;
		ele = ele->next;
	}
	return reversed_list;
}

void square(void* hint, void* sourceItem, void* destinationItem){
  *(int *)destinationItem = (*(int *)sourceItem) * (*(int *)sourceItem);
}

LinkedList map(LinkedList list, ConvertFunc convert, void *hint){
	LinkedList dest_list = createList();
	Element *src_ele = list.head;
	int initial = 0;
	for (int i = 0; i < list.length; ++i){
		void *dest_ele = malloc(sizeof(void *));
		convert(hint,src_ele->value,dest_ele);
		add_to_list(&dest_list,dest_ele);
		src_ele = src_ele->next;
	}
	return dest_list;
}
void *sum(void* hint, void* previousItem, void* item){
	(*(int *)previousItem) += (*(int *)item);
	return previousItem;
}
void *reduce(LinkedList list, Reducer reducerFunc, void *hint, void *initialValue){
	Element *ele = list.head;
	for (int i = 0; i < list.length; ++i){
		reducerFunc(hint,initialValue,ele->value);
		ele = ele->next;
	}
	return initialValue;
}