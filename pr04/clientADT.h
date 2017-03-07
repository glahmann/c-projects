#ifndef CLIENT_H
#define CLIENT_H

struct client {
  int idNum;
  char name[40];
  char email[40];
  char phone[15]; // 12 digits + \0
};

typedef struct client *Client;

//
// pre:
// post:
Client createClient(int idNum, char *name, char *email, char *phone);

//
// pre:
// post:
void destroy_client(Client clientptr);

//
//
// pre:
// post:
void print_client(Client cli);


#endif
