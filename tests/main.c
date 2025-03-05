#include <stdio.h>
#include "utils.h"
#include "algorithm.h"

int main(){
  int a = 10;
  int b = 20;
  swap(&a, &b);
  printf("(%d, %d)\n", a, b);
  
  int array[5] = {3, 5, 2, 4, 1};
  bubble_sort(array, 5);
  for( int i = 0; i<5; i++){
    printf("%d ", array[i]);
  }
  printf("\n");
  return 0;
}
