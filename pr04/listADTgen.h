#ifndef LISTADT_H
#define LISTADT_H

typedef struct list_type *ListType;

ListType createList(int elSize, int (*compare) (void *item1, void *item2));
void destroyList(ListType listP);
void make_empty(ListType listP);
int is_empty(ListType listP);
int is_full(ListType listP);
int size_is(ListType listP);
void push(ListType listP, void *item);

//
// pre:
// post:
//void clear_list(ListType listptr);
//
// pre:
// post:
void delete(ListType listP, void* item);
//
// pre:
// post:
void * get_element(ListType listP, int index);
void printl(ListType listP, void (*printItem) (void *item));

#endif
