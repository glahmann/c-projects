/**
 * animals.h
 * Author: Garrett Lahmann
 *
 * Contains structure definitions and function prototypes.
 */
#ifndef ANIMALS_H
#define ANIMALS_H

#pragma pack(1)

struct animal {
  short int id;
  char name[20];
  char species[35];
  char size;
  short int age;
};

typedef struct animal Animal;

// Prints ASCII values from binary file to console.
// pre: fptr assigned
// post: none
void print_file(FILE *fptr);

// Replaces characters at the given skip interval with newChar.
// pre: file pointer assigned, skip assigned, newChar assigned
// post: Every skip # character is replaced by newChar
void replace(/*inout*/ FILE *fptr, /*in*/ int skip, /*in*/ char newChar);

// Displays the selected animal record.
// pre: fptr assigned, recordNum assigned
// post: none
void display_by_num(/*inout*/ FILE *fptr, /*in*/ int recordNum);

// Displays the selected animal record.
// pre: fptr assigned, idNum assigned, len == number of structs in file
// post: none
void display_by_id(/*inout*/ FILE *fptr, /*in*/ int idNum, /*in*/ int len);

// Displays the selected animal record.
// pre: fptr assigned, recA assigned, recB assigned,
// post: Record at recA location swapped with record at recB,
//       len == number of structs in file
void swap(/*inout*/ FILE *fptr, /*in*/ int recA, /*in*/ int recB,
          /*in*/ int len);

// Writes struct contents of binary file to a .csv file
// pre: fptr assigned, outptr assigned, len == number of structs in file
// post: Records from input file written to .csv file
void write_to_file(/*inout*/ FILE *inptr, FILE *outptr, /*in*/ int len);

// Adds an animal record to the binary file.
// pre: fptr assigned, len == number of structs in file
// post: An animal record added to the binary file at user specified ID location
void add_record(/*inout*/ FILE *fptr, /*in*/ int len);

// Gets an unused animal ID from the user.
// pre: fptr assigned, len == number of structs in file
// post: A unique animal ID number
short int get_id(/*inout*/ FILE *fptr, /*in*/ int len);

// Uses binary search to find the index corresponding to the given ID.
// pre: fptr assigned, idNum assigned, len == number of structs in file
// post: An index location in the binary file where the given ID can be found
int find_idx(/*inout*/ FILE *fptr, /*in*/ int idNum, /*in*/ int len);

#endif
