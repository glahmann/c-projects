#ifndef CLIENT_H
#define CLIENT_H

typedef struct client *Client;

//
// pre:
// post:
Client createClient(int idNum, char *name, char *email, char *phone);

//
// pre:
// post:
void destroyClient(Client clientptr);

//
// pre:
// post:
int getSizeClient(Client clientptr);


#endif
