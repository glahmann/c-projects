/**
 * animals.c
 *
 * Contains functions that operate on an animals binary file.
 */
#include <stdio.h>
#include <stdlib.h>
#include "animals.h"

void print_file(FILE *fptr) {
  char curr;
  int line = 1; // Length of the current print line

  printf("\n"); // TODO relocate
  while (!feof(fptr)) { // TODO don't use feof!
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
  while (fscanf(fptr, "%c", &curr) == 1) { // Loop until unsuccessful seek
    fseek(fptr, -1, SEEK_CUR);
    fwrite(&newChar, sizeof(newChar), 1, fptr);
    fseek(fptr, skip - 1, SEEK_CUR);
  }

  rewind(fptr); // Return pointer to beginning of file
}

void display_by_num(FILE *fptr, int recordNum) {
  Animal *record = malloc(sizeof(Animal));

  fseek(fptr, (recordNum - 1) * sizeof(Animal), 0);
  if (recordNum > 0 && fread(record, sizeof(Animal), 1, fptr) == 1) {
    printf("\n%d,%s,%s,%c,%d\n", record->id, record->name,
            record->species, record->size, record->age);
  } else {
    printf("\nRecord not found!\n");
  }

  printf("\n");
  free(record);
  rewind(fptr);
}

void display_by_id(FILE *fptr, int idNum) {
  Animal *record = malloc(sizeof(Animal));
  int left, mid, right, flag = 0;

  fseek(fptr, 0, SEEK_END);  // SEEK_END not portable
  left = 0;
  right = (ftell(fptr) / sizeof(Animal)) - 1; // Get index of last record
  while (!flag) {
    if (left > right) {
      printf("\nRecord not found!\n");
      flag = 1;
    } else {
      mid = (left + right) / 2;
      fseek(fptr, mid * sizeof(Animal), 0);
      fread(record, sizeof(Animal), 1, fptr);
      if (record->id == idNum) {
        printf("\n%d,%s,%s,%c,%d\n", record->id, record->name,
                record->species, record->size, record->age);
        flag = 1;
      } else if (record->id < idNum) {
        left = mid + 1;
      } else { // record ID greater than given ID
        right = mid - 1;
      }
    }
  }

  printf("\n");
  free(record);
  rewind(fptr);
}

void swap(FILE *fptr, int recA, int recB) {
  int max, temp;
  Animal *recordA = malloc(sizeof(Animal));
  Animal *recordB = malloc(sizeof(Animal));

  fseek(fptr, 0, SEEK_END);
  max = (ftell(fptr) / sizeof(Animal));
  if (recA < 1 || recB < 1 || recA > max || recB > max) {
    printf("\nInvalid record selection!\n");
  } else {
    // Get struct for first animal
    fseek(fptr, (recA - 1) * sizeof(Animal), 0);
    fread(recordA, sizeof(Animal), 1, fptr);

    // Get struct for second animal
    fseek(fptr, (recB - 1) * sizeof(Animal), 0);
    fread(recordB, sizeof(Animal), 1, fptr);

    // Swap ID's
    temp = recordA->id;
    recordA->id = recordB->id;
    recordB->id = temp;

    // Write structs to new locations
    fseek(fptr, (recA - 1) * sizeof(Animal), 0);
    fwrite(recordB, sizeof(Animal), 1, fptr);
    fseek(fptr, (recB - 1) * sizeof(Animal), 0);
    fwrite(recordA, sizeof(Animal), 1, fptr);
  }

  printf("\n");
  free(recordA);
  free(recordB);
  rewind(fptr);
}

void write_to_file(FILE *inptr, FILE *outptr) {
  int i, max;
  Animal *record = malloc(sizeof(Animal));

  fseek(inptr, 0, SEEK_END);
  max = ftell(inptr) / sizeof(Animal);

  for (i = 0; i < max; i++) {
    fseek(inptr, i * sizeof(Animal), 0);
    fread(record, sizeof(Animal), 1, inptr);
    fprintf(outptr, "%d,%s,%s,%c,%d\n", record->id, record->name,
            record->species, record->size, record->age);
  }

  free(record);
}
