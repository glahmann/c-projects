/**
 * animals.h
 *
 * Contains structure definitions and function prototypes.
 */
 #include <stdio.h>
 #pragma pack(1)

struct animal {
  short int id;
  char name[20];
  char species[35];
  char size;
  short int age;
};

typedef struct animal Animal;

// Prints ascii values from binary file to console.
// pre:
// post:
void print_file(FILE *fptr);

// Replaces characters at the given skip interval with newChar.
// pre:
// post:
void replace(FILE *fptr, int skip, char newChar);

// Displays the selected animal record.
// pre:
// post:
void display_by_num(FILE *fptr, int recordNum);

// Displays the selected animal record.
// pre:
// post:
void display_by_id(FILE *fptr, int idNum);

// Displays the selected animal record.
// pre:
// post:
void swap(FILE *fptr, int recOne, int recTwo);
