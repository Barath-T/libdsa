#include <stdio.h>
#include <assert.h>
#include "utils.h"
#include "algorithm.h"
#include "array_list.h"

int main(){
  printf("\nTest 1: Swaping\n");
  int a = 10;
  int b = 20;
  swap(&a, &b);
  assert((a==20) && (b==10));
  printf("Success\n");

  printf("\nTest 2: Bubble Sort\n");
  int array[5] = {3, 5, 2, 4, 1};
  for( int i = 0; i<5; i++){
    printf("%d ", array[i]);
  }
  printf("\n");

  bubble_sort(array, 5);

  for( int i = 0; i<5; i++){
    printf("%d ", array[i]);
  }
  printf("\n");

  printf("\nTest3: ArrayList create\n");
  struct ArrayList list = array_list_create(5);
  printf("{ %p, %d, %d }\n", list.data, list.length, list.capacity); 

  printf("\nTest4a: ArrayList push\n");
  for(int i = 0; i<15; i++){
    int ret = array_list_push(&list, i);
    if(ret == -1){
      printf("\nTest 4a: failed");
    }
    else if(ret == 2){
      printf("After reallocation: %d { %p, %d, %d }\n", i, list.data, list.length, list.capacity); 
    }
  }
  printf("After pushing: { %p, %d, %d }\n", list.data, list.length, list.capacity); 
  array_list_print(&list);

  printf("\nTest4b: ArrayList push\n");
  int ret = array_list_push_at(&list, 100, 4);
  if(ret == -1){
    printf("\nTest 4b: failed");
  }
  else if(ret == 2){
    printf("After reallocation: { %p, %d, %d }\n", list.data, list.length, list.capacity); 
  }
  printf("After pushing at 4: { %p, %d, %d }\n", list.data, list.length, list.capacity); 
  array_list_print(&list);

  printf("\nTest5a: ArrayList pop\n");
  printf("popped element: %d\n", array_list_pop(&list));
  printf("After popping: { %p, %d, %d }\n", list.data, list.length, list.capacity); 
  array_list_print(&list);

  printf("\nTest5b: ArrayList pop\n");
  printf("popped element: %d\n", array_list_remove_at(&list, 4));
  printf("After popping: { %p, %d, %d }\n", list.data, list.length, list.capacity); 
  array_list_print(&list);

  printf("\nTest6: ArrayList print\n");
  array_list_print(&list);

  printf("\nTest7: ArrayList free data\n");
  array_list_free_data(&list);
  printf("After freeing: { %p, %d, %d }\n", list.data, list.length, list.capacity); 


  return 0;
}
