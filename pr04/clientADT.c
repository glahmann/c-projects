/**
 * Client ADT
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "clientADT.h"

Client createClient(int idNum, char *name, char *email, char *phone) {
  // Client *clientptr = malloc(sizeof(struct client));
  Client clientptr;
  // Populate struct fields
  clientptr.idNum = idNum;
  strcpy(clientptr.name, name);
  strcpy(clientptr.email, email);
  strcpy(clientptr.phone, phone);

  return clientptr;
}

// void destroyClient(Client clientptr) {
//   free(clientptr->name);
//   free(clientptr->email);
// }
