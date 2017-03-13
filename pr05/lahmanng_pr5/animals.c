/**
 * animals.c
 * Author: Garrett Lahmann
 *
 * Contains functions that operate on an binary file containing animal records.
 */
#include <stdio.h>
#include <stdlib.h>
#include "animals.h"

void print_file(FILE *fptr) {
  char curr;
  int line = 1; // Length of the current print line

  printf("\n");
  while (fscanf(fptr, "%c", &curr) == 1) { // Loop until end of file
    if (line > 80) {
      printf("\n");
      line = 1;
    }

    // Print standard ASCII characters
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

  // Print record at given location
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

void display_by_id(FILE *fptr, int idNum, int len) {
  int idx;
  Animal *record = malloc(sizeof(Animal));

  idx = find_idx(fptr, idNum, len);
  if (idx == -1) {
    printf("\nRecord not found!\n");
  } else {
    // Print record corresponding to the ID given
    fseek(fptr, idx * sizeof(Animal), 0);
    fread(record, sizeof(Animal), 1, fptr);
    printf("\n%d,%s,%s,%c,%d\n", record->id, record->name,
              record->species, record->size, record->age);
  }

  printf("\n");
  free(record);
  rewind(fptr);
}

void swap(FILE *fptr, int recA, int recB, int len) {
  int temp;
  Animal *recordA = malloc(sizeof(Animal));
  Animal *recordB = malloc(sizeof(Animal));

  if (recA < 1 || recB < 1 || recA > len || recB > len) {
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

void write_to_file(FILE *inptr, FILE *outptr, int len) {
  int i;
  Animal *record = malloc(sizeof(Animal));

  // Loop over and print every record to a file
  for (i = 0; i < len; i++) {
    fseek(inptr, i * sizeof(Animal), 0);
    fread(record, sizeof(Animal), 1, inptr);
    fprintf(outptr, "%d,%s,%s,%c,%d\n", record->id, record->name,
            record->species, record->size, record->age);
  }

  free(record);
}

void add_record(FILE *fptr, int len) {
  int flag = 0, i, idNum, idx = 0;
  Animal *record = malloc(sizeof(Animal));
  Animal *current= malloc(sizeof(Animal));

  // Populate an animal record struct
  record->id = get_id(fptr, len);
  printf("Enter name: ");
  scanf(" %s", record->name);
  printf("Enter species: ");
  scanf(" %[^\n]s", record->species);
  printf("Enter size: ");
  scanf(" %c", &record->size);
  printf("Enter age: ");
  scanf(" %hd", &record->age);

  // Find insertion index
  fseek(fptr, idx * sizeof(Animal), 0);
  while (!flag && fread(current, sizeof(Animal), 1, fptr) == 1) {
    if (record->id < current->id) {
      flag = 1;
    } else {
      idx++;
      fseek(fptr, idx * sizeof(Animal), 0);
    }
  }

  // Shift old entries to the right
  for (i = len; i >= idx; i--) {
    fseek(fptr, (i - 1) * sizeof(Animal), 0);
    fread(current, sizeof(Animal), 1, fptr);
    fseek(fptr, i * sizeof(Animal), 0);
    fwrite(current, sizeof(Animal), 1, fptr);
  }

  // Insert new struct
  fseek(fptr, idx * sizeof(Animal), 0);
  fwrite(record, sizeof(Animal), 1, fptr);

  printf("\n");
  free(current);
  free(record);
  rewind(fptr);
}

short int get_id(FILE *fptr, int len) {
  int flag = 0;
  short int idNum;

  printf("Enter animal ID: ");
  scanf(" %hd", &idNum);
  flag = find_idx(fptr, idNum, len);

  // Search list until selected idNum not found
  while (flag != -1) {
    printf("ID taken, try again: ");
    scanf(" %hd", &idNum);
    flag = find_idx(fptr, idNum, len);
  }
  return idNum;
}

int find_idx(FILE *fptr, int idNum, int len) {
  Animal *record = malloc(sizeof(Animal));
  int idx, left, mid, right, flag = -2;

  left = 0;
  right = len - 1; // Get index of last record
  while (flag < -1) {
    if (left > right) {
      flag = -1;
    } else {
      mid = (left + right) / 2;
      fseek(fptr, mid * sizeof(Animal), 0); // Set to mid index
      fread(record, sizeof(Animal), 1, fptr);
      if (record->id == idNum) {
        flag = mid;
      } else if (record->id < idNum) {
        left = mid + 1;
      } else { // record ID greater than given ID
        right = mid - 1;
      }
    }
  }
  free(record);
  return flag;
}
