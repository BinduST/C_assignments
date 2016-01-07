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

void insert(int *arr,int length){
  for (int i = 0; i < length; ++i) {
    arr[i] = i+length;
  }
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

void *findFirst(ArrayUtil util, MatchFunc *match, void *hint){
  for (int i = 0; i < util.length; ++i){
    if((*match)(hint,util.base+i * util.typeSize)){
      return util.base+i * util.typeSize;
    }
  }
  return NULL;
}

void *findLast(ArrayUtil util, MatchFunc *match, void *hint){
  for (int i = util.length-1; i >=0 ; --i){
    if((*match)(hint,util.base+i * util.typeSize)){
      return util.base+i * util.typeSize;
    }
  }
  return NULL;
}

int count(ArrayUtil util, MatchFunc *match, void *hint){
  int counter = 0;
  for (int i = 0; i < util.length; ++i){
    if((*match)(hint,util.base+i * util.typeSize)){
      counter++;
    }
  }
  return counter;
}

int filter(ArrayUtil util, MatchFunc* match, void *hint, void **destination, int maxItems ){
  int counter=0;
  for (int i = 0; i < util.length; ++i){
    if((*match)(hint,util.base+i * util.typeSize)&&counter<maxItems){
        destination[counter] = util.base+i * util.typeSize;
        counter++;
      }
  }
  return counter;
}

void map(ArrayUtil source, ArrayUtil destination, ConvertFunc* convert, void* hint){
  for (int i = 0; i < source.length; ++i){
    (*convert)(&hint, (source.base+i * source.typeSize), (destination.base+i * destination.typeSize));
  }
}

void forEach(ArrayUtil util, OperationFunc* operation, void* hint){
  for (int i = 0; i < util.length; ++i){
    (*operation)(&hint,util.base+i*util.typeSize);
  }
}

void *reduce(ArrayUtil util, ReducerFunc* reducer, void* hint, void* intialValue){
  for (int i = 0; i < util.length; ++i){
    reducer(hint, intialValue, util.base+i*util.typeSize);
  }
  return intialValue;
}

