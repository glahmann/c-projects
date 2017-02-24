#include "listADT.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct list_type {
  ItemType* data;
  int size;
  int capacity;
};


// returns the pointer to the list; NULL if list not created
ListType create() {
  // allocate memory for a structure variable containing all
  // list components
  ListType listptr = malloc(sizeof(struct list_type));
  // if allocation was succesfull
  if (listptr != NULL) {
     listptr->size = 0;
     listptr->capacity = 10;
     // allocate memory for the actual array
     listptr->data = malloc(10*sizeof(ItemType));
     // if array not created, deallocate the list too
     if (listptr->data == NULL) {
       free(listptr);
       listptr = NULL;
     } 
  }
  // this is the statement we were missing in class demo and hence seg faults
  return listptr;
}

void destroy(ListType listptr) {
  free(listptr->data);
  free(listptr);
}

// adds a component to the array, if enough memory available
void push(ListType listptr, ItemType item) {
  // if the physical array is full
  if (listptr->size >= listptr->capacity) {
    // create a new, bigger array
    ItemType * temp = realloc(listptr->data, sizeof(ItemType) * (listptr->capacity + 100));
    if (temp != NULL) {
      listptr->capacity += 100;
      listptr->data = temp;
     }
   }
   // this needs to be if - not else or else if - as we want it to execute
   // even if the if above executed as well
   if (listptr->size < listptr->capacity){
     listptr->data[listptr->size] = item;
     listptr->size++;
   }
}

void printl(ListType listptr) {
  int i;
  for(i = 0; i < listptr->size; i++)
    printf("%d ", listptr->data[i]);
  printf("\n");
}

int size_is(ListType listptr) {
   return listptr->size;
}

int is_empty(ListType listptr) {
   return listptr->size == 0;
}


void delete(ListType listptr, ItemType item) {
  int i, flag = 0;
  
  for(i = 0; i < listptr->size; i++) {
    if(flag == 0 && listptr[i]->data == item) {
      listptr[i]->data = item;
      listptr->size--;
      flag = 1;
    }
  }
}

int is_full(ListTyp listptr) {
  int is_full = 0;
  if(listptr->size >= listptr->capacity) {
    
  }
  return is_full;
}






















