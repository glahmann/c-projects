/**
 * Client ADT
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "clientADT.h"

Client createClient(int idNum, char *name, char *email, char *phone) {
  // Client *clientptr = malloc(sizeof(struct client));
  Client clientptr = calloc(sizeof(struct client), 1);
  // Populate struct fields
  clientptr->idNum = idNum;
  strcpy(clientptr->name, name);
  strcpy(clientptr->email, email);
  strcpy(clientptr->phone, phone);

  return clientptr;
}

void destroy_client(Client clientptr) {
  free(clientptr);
  clientptr = NULL;
}

void print_client(Client cli, FILE *fptr) {
  fprintf(fptr, "%d,%s,%s,%s\n", cli->idNum, cli->name, cli->email, cli->phone);
}
