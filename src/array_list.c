#include "array_list.h"
#include "utils.h"
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

    free(list->data);
    list->data = data;

    list->capacity = new_capacity;
    list->data[list->length] = element;
    list->length++;

    return 2;
  }
  return -1;
}

int array_list_push_at(struct ArrayList* list, int element, int position){
  if(list->capacity > list->length){
    int temp = element;
    for(int i = position; i<list->length+1; i++){
      swap(&list->data[i], &temp);
    }
    list->length++;
    return 1;
  }
  else{
    unsigned int new_capacity = list->capacity + (list->capacity/2);
    int* data = (int*)calloc(new_capacity, sizeof(int));
    if(!data){
      return -1;
    }

    unsigned int prefix_mem_size = position * sizeof(int);
    unsigned int suffix_mem_size = (list->length - position) * sizeof(int);

    memcpy(data, list->data, prefix_mem_size);
    data[position] = element;
    memcpy(&data[position+1], &list->data[position], suffix_mem_size);

    free(list->data);
    list->data = data;

    list->data = data;
    list->capacity = new_capacity;
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
int array_list_remove_at(struct ArrayList* list, int position){
  int element = list->data[position];
  for(int i = position; i<list->length-1; i++){
    list->data[i] = list->data[i+1];
  }
  list->data[list->length-1] = 0;
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
