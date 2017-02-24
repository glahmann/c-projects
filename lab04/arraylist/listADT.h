#ifndef LISTADT_H
#define LISTADT_H

typedef struct list_type *ListType;
typedef int ItemType;

ListType create(void);
void destroy(ListType listP);
void make_empty(ListType listP);
int is_empty(ListType listP);
int is_full(ListType listP);
void push(ListType listP, ItemType item);
void delete(ListType listP, ItemType item);
void printl(ListType listP);

#endif



