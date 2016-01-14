#include <assert.h>
#include <stdlib.h>
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
	assert((*(int *)list.tail->value)==12);
	assert((int *)list.tail->next==0x0);
}

void test_getElementAt(){
	LinkedList list = createList();
	int ele1 = 5;
	int ele2 = 7;
	int ele3 = 9;
	int ele4 = 11;
	add_to_list(&list,&ele1);
	add_to_list(&list,&ele2);
	add_to_list(&list,&ele3);
	add_to_list(&list,&ele4);
	int *el1 = (int *)getElementAt(list,2);
	assert(*el1 == 9);
	int *el2 = (int *)getElementAt(list,5);
	assert(el2 == 0);
}

void test_indexOf(){
	LinkedList list = createList();
	int ele1 = 4;
	int ele2 = 2;
	int ele3 = 1;
	int ele4 = 2;
	add_to_list(&list,&ele1);
	add_to_list(&list,&ele2);
	add_to_list(&list,&ele3);
	add_to_list(&list,&ele4);
	int num1 = 2, num2 = 5;
	int index1 = indexOf(list,&num1);
	assert(index1 == 1);	
	int index2 = indexOf(list,&num2);
	assert(index2 == -1);
}

void test_deleteElementAt(){
	LinkedList list = createList();
	int ele1 = 5;
	int ele2 = 4;
	int ele3 = 3;
	int ele4 = 2;
	int ele5 = 1;
	int ele6 = 5;
	int ele7 = 4;
	int ele8 = 3;
	int ele9 = 2;
	int ele10 = 1;
	add_to_list(&list,&ele1);
	add_to_list(&list,&ele2);
	add_to_list(&list,&ele3);
	add_to_list(&list,&ele4);
	add_to_list(&list,&ele5);
	add_to_list(&list,&ele6);
	add_to_list(&list,&ele7);
	add_to_list(&list,&ele8);
	add_to_list(&list,&ele9);
	add_to_list(&list,&ele10);
	int *el1 = (int *)deleteElementAt(&list,0);
	assert(*el1 == 5);
	int *el2 = (int *)deleteElementAt(&list,3);
	assert(*el2 == 1);
	int *el3 = (int *)deleteElementAt(&list,7);
	assert(*el3 == 1);
	assert(list.length==7);
}

void test_asArray(){
	LinkedList list = createList();
	int ele1 = 1;
	int ele2 = 2;
	int ele3 = 3;
	int ele4 = 4;
	add_to_list(&list,&ele1);
	add_to_list(&list,&ele2);
	add_to_list(&list,&ele3);
	add_to_list(&list,&ele4);
	void *arr[5];
	int len_arr = asArray(list,arr,5);
	assert(len_arr == 4);	
	assert(*(int *)arr[0] == ele1);
}

void test_filter(){
	LinkedList list = createList();
	int ele1 = 1;
	int ele2 = 2;
	int ele3 = 3;
	int ele4 = 4;
	int hint = 9;
	add_to_list(&list,&ele1);
	add_to_list(&list,&ele2);
	add_to_list(&list,&ele3);
	add_to_list(&list,&ele4);
	LinkedList new_list = filter(list,isEven,&hint);
	assert(new_list.length == 2);
}

void test_reverse(){
	LinkedList list = createList();
	int ele1 = 1;
	int ele2 = 2;
	int ele3 = 3;
	int ele4 = 4;
	add_to_list(&list,&ele1);
	add_to_list(&list,&ele2);
	add_to_list(&list,&ele3);
	add_to_list(&list,&ele4);
	LinkedList new_list = reverse(list);
	assert(*(int *)new_list.head->value == 4);
	assert(*(int *)new_list.tail->value == 1);
	assert(new_list.length == 4);
}

void test_map(){
	LinkedList source_list = createList();
	int ele1 = 1;
	int ele2 = 2;
	int ele3 = 3;
	int ele4 = 4;
	int hint = 10;
	add_to_list(&source_list,&ele1);
	add_to_list(&source_list,&ele2);
	add_to_list(&source_list,&ele3);
	add_to_list(&source_list,&ele4);
	LinkedList destination_list = map(source_list,square,&hint);
	Element *ele = destination_list.head;
	assert(*(int *)destination_list.head->value == 1);
	assert(*(int *)destination_list.head->next->value == 4);
	assert(*(int *)destination_list.head->next->next->value == 9);
	assert(*(int *)destination_list.tail->value == 16);
	assert(destination_list.length == 4);
}

void test_reduce(){
	LinkedList source_list = createList();
	int ele1 = 1;
	int ele2 = 2;
	int ele3 = 3;
	int ele4 = 4;
	void *hint = malloc(sizeof(int));
	void *intial = malloc(sizeof(int));
	add_to_list(&source_list,&ele1);
	add_to_list(&source_list,&ele2);
	add_to_list(&source_list,&ele3);
	add_to_list(&source_list,&ele4);
	void *result = reduce(source_list,sum,hint,intial);
	assert(*(int *)result == 10);
}