#include "utils.h"

void bubble_sort(int* array, int size){
  for(int unsorted = size-1; unsorted>0; unsorted--){
    for(int i = 0; i<unsorted; i++){
      if(array[i]>array[i+1]){
        swap(&array[i], &array[i+1]);
      }
    }
  }
}
