/**
 * animals.c
 *
 * Contains functions that operate on an animals binary file.
 */
#include <stdio.h>
#include "animals.h"

void print_file(FILE *fptr) {
  char curr;
  int line = 1; // Length of the current print line

  printf("\n"); // TODO relocate
  while(!feof(fptr)) {
    curr = fgetc(fptr);
    if (line > 80) {
      printf("\n");
      line = 1;
    }
    if(((int) curr) >= 32 && ((int) curr) <= 127) {
      printf("%c", curr);
      line++;
    }
  }

  printf("\n\n");
  rewind(fptr); // Return pointer to beginning of file
}

void replace(FILE *fptr, int skip, char newChar) {
  char curr;

  fseek(fptr, skip - 1, SEEK_CUR);
  while(fscanf(fptr, "%c", &curr) == 1) { // Loop until unsuccessful seek
    fseek(fptr, -1, SEEK_CUR);
    fwrite(&newChar, sizeof(newChar), 1, fptr);
    fseek(fptr, skip - 1, SEEK_CUR);
  }

  rewind(fptr); // Return pointer to beginning of file
}

void display_by_num(FILE *fptr, int recordNum) {
  Animal *record;
  fseek(fptr, (recordNum - 1) * sizeof(Animal), 0);
  if (fread(record, sizeof(Animal), 1, fptr) == 1) {
    printf("%d,%s,%s,%c,%d\n", record->id, record->name, record->species, record->size, record->age);
  } else {
    printf("ERROR: invalid selection");
  }

  rewind(fptr);
}

void display_by_id(FILE *fptr, int idNum) {

}

void swap(FILE *fptr, int recOne, int recTwo) {

}
