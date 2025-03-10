#include "array_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ArrayList array_list_create(unsigned int capacity){
  int* data = (int*)calloc(capacity, sizeof(int));
  if(!data){
    return (struct ArrayList) {NULL, 0, 0};
  }

  struct ArrayList list = {data, 0, capacity};

  return list;
}

int array_list_push(struct ArrayList* list, int element){
  if(list->capacity > list->length){
    list->data[list->length] = element;
    list->length++;
    return 1;
  }
  else{
    unsigned int new_capacity = list->capacity + (list->capacity/2);

    int* data = (int*)calloc(new_capacity, sizeof(int));
    if(!data){
      return -1;
    }

    unsigned int data_mem_size = list->length * sizeof(int);
    memcpy(data, list->data, data_mem_size);

    list->data = data;
    list->capacity = new_capacity;

    list->data[list->length] = element;
    list->length++;

    return 2;
  }
  return -1;
}

int array_list_pop(struct ArrayList* list){
  int element = list->data[list->length-1];
  list->length--;

  return element;
}

void array_list_free_data(struct ArrayList* list){
  free(list->data);

  list->data = NULL;
  list->length = 0;
  list->capacity = 0;
}

void array_list_print(struct ArrayList* list){
  printf("[");
  for(int i = 0; i < list->length; i++){
    printf("%d ", list->data[i]);
  }
  printf("]\n");
}
