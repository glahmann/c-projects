/**
 * Client ADT
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "clientADT.h"

struct client {
  int idNum; // TODO control num of bytes
  char *name;
  char *email;
  char phone[13]; // 12 digits + \0
  int size;
};

Client createClient(int idNum, char *name, char *email, char *phone) {
  Client clientptr = malloc(sizeof(struct client));

  // Populate struct fields
  clientptr->idNum = idNum;
  clientptr->name = malloc(strlen(name) + 1);
  clientptr->email = malloc(strlen(email) + 1);
  strcpy(clientptr->name, name);
  strcpy(clientptr->email, email);
  strcpy(clientptr->phone, phone);
  clientptr->size = 61; // TODO make this dynamic or standardized?


  return clientptr;
}

void destroyClient(Client clientptr) {
  free(clientptr->name);
  free(clientptr->email);
}

int getSizeClient(Client clientptr) {
   return clientptr->size;
}
