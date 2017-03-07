#ifndef LISTADT_H
#define LISTADT_H

struct list_type {
  void *data;
  int size;
  int capacity;
  int elementSize;
  int (*comparePtr) (const void *d1, const void *d2);
};

typedef struct list_type *ListType;

ListType createList(int elSize, int (*compare) (const void *item1, const void *item2));
void destroyList(ListType listP);
void make_empty(ListType listP);
int is_empty(ListType listP);
int is_full(ListType listP);
int size_is(ListType listP);
void push(ListType listP, void *item);

//
//pre:
//post:
void clear_list(ListType listptr, void (*destroyItem) (void *d));
//
// pre:
// post:
void sort_list(ListType listP);
//
// pre:
// post:
void * get_element(ListType listP, int index);
//
// pre:
// post:
int get_index(ListType listP, void *el);
//
// pre:
// post:
void print_list(ListType listP, void (*printItem) (void *item));

#endif
