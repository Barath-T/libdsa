#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

struct ArrayList {
  int* data;
  unsigned int length;
  unsigned int capacity;
};

struct ArrayList array_list_create(unsigned int capacity);

int array_list_push(struct ArrayList* list, int element);
int array_list_push_at(struct ArrayList* list, int element, int position);
int array_list_pop(struct ArrayList* list);
int array_list_remove_at(struct ArrayList* list, int position);

void array_list_free_data(struct ArrayList* list);

void array_list_print(struct ArrayList* list);

#endif // ARRAY_LIST_H
