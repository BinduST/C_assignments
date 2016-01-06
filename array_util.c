#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "array_util.h"

ArrayUtil create(int typeSize, int length){
  ArrayUtil *array = (ArrayUtil *)calloc(typeSize,length);
  array->base = array;
  array->typeSize = typeSize;
  array->length = length;
  return *array;
}

int areEqual(ArrayUtil a, ArrayUtil b){
  int length;
  if(a.length>b.length)
    length = a.length;
  length = b.length;
  int check_value = memcmp(a.base,b.base,length);
  if(a.typeSize == b.typeSize && a.length == b.length &&check_value==0){
    return 1;
  }
  return 0;
}

ArrayUtil resize(ArrayUtil util, int length) {
  util.base = realloc(util.base,length);
  util.length = length;
  return util;
}

int findIndex(ArrayUtil util, void *element){
  int *arr = (int *)util.base;
  int *value = (int *)element;
  for (int i = 0; i < util.length; ++i){
    if(arr[i] == *value){
      return i;
    }
  }
  return -1;
}

void dispose(ArrayUtil util){
  free(util.base);
}

int isEven(void *hint, void *item){
  int *num = (int *)item;
  printf("item is:%d\n", *(int *)num);
  return(*num%2==0);
}

void *findFirst(ArrayUtil util, MatchFunc *match, void *hint){
  MatchFunc func = *match;
  for (int i = 0; i < util.length; ++i){
    unsigned char *ele = (unsigned char *)util.base+i * util.typeSize;
    if(func(&hint,ele)){
      printf("%d\n", *ele);
      return ele;
    }
  }
  printf("%d\n",0);
  return 0;
}

void *findLast(ArrayUtil util, MatchFunc *match, void *hint){
  MatchFunc func = *match;
  for (int i = util.length-1; i >=0 ; --i){
    unsigned char *ele = (unsigned char *)util.base+i * util.typeSize;
    if(func(&hint,ele)){
      return ele;
    }
  }
  return 0;
}

int count(ArrayUtil util, MatchFunc* match, void* hint){
  MatchFunc func = *match;int count=0;
  for (int i = 0; i < util.length; ++i){
    unsigned char *ele = (unsigned char *)util.base+i * util.typeSize;
    if(func(&hint,ele)){
      count ++;
    }
  }
  return count;
}