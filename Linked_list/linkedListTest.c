#include <assert.h>
#include "linkedList.c"

void test_createList(){
	LinkedList list = createList();
	assert(list.length==0);
}

void test_add_to_list_for_int(){
	LinkedList list = createList();
	int ele1 = 5;
	int ele2 = 10;
	add_to_list(&list,&ele1);
	add_to_list(&list,&ele2);
	assert((*(int *)list.head->value)==5);
	assert(*(int *)list.tail->value==10);
	assert(list.length==2);
}

void test_add_to_list_for_char(){
	LinkedList list = createList();
	char ele1 = 'b';
	char ele2 = 'c';
	add_to_list(&list,&ele1);
	add_to_list(&list,&ele2);
	add_to_list(&list,&ele1);
	assert(*(char *)list.head->value=='b');
	assert(*(char *)list.tail->value=='b');
	assert(list.length==3);
}

void test_get_first_element(){
	LinkedList list = createList();
	double ele1 = 2.5;
	double ele2 = 3;
	add_to_list(&list,&ele1);
	add_to_list(&list,&ele2);
	double first = *(double *)get_first_element(list);
	assert(first==2.5);
	assert(list.length==2);
}

void test_get_last_element(){
	LinkedList list = createList();
	double ele1 = 2.5;
	double ele2 = 3;
	add_to_list(&list,&ele1);
	add_to_list(&list,&ele2);
	double last = *(double *)get_last_element(list);
	assert(last==3);
	assert(list.length==2);
}

void increment(void *ele){
	*(int *)ele += 1;
}

void test_forEach(){
	LinkedList list = createList();
	int ele1 = 5;
	int ele2 = 7;
	int ele3 = 9;
	int ele4 = 11;
	add_to_list(&list,&ele1);
	add_to_list(&list,&ele2);
	add_to_list(&list,&ele3);
	add_to_list(&list,&ele4);
	forEach(list,&increment);
	assert((*(int *)list.head->value)==6);
	assert((int *)list.tail->next==0x0);
}