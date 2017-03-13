/**
 * driver.c
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "animals.h" //TODO change filename


int main(void) {
  char newChar;
  int choice = -1, recOne = -1, recTwo = -1, skip;
  FILE *binFile, *outFile;

  binFile = fopen("animals.dat", "rb+");
  printf("Welcome to Binary Animals!\n"); // Working title

  while (choice != 0) {
    // TODO handle invalid input: >5, <0
    printf("Select one of the choices below: \n");
    printf("1 : print contents of the binary file \n");
    printf("2 : replace chars in the binary file \n");
    printf("3 : display an animal record by number \n");
    printf("4 : display an animal record by ID \n");
    printf("5 : swap two animal records \n");
    printf("0 : quit \n");
    scanf(" %d", &choice);

    if (choice == 1) {
      print_file(binFile);
    } else if (choice == 2) {
      printf("Enter an interval and a character replacement: ");
      scanf(" %d %c", &skip, &newChar);
      replace(binFile, skip, newChar);
    } else if (choice == 3) {
      printf("Enter animal record number: ");
      scanf(" %d", &recOne);
      display_by_num(binFile, recOne);
    } else if (choice == 4) {
      printf("Enter animal ID number: ");
      scanf(" %d", &recTwo);
      display_by_id(binFile, recTwo);
    } else if (choice == 5) {
      printf("Enter two record numbers: ");
      scanf(" %d %d", &recOne, &recTwo);
      swap(binFile, recOne, recTwo);
    }
  }

  // Open .csv file to print output
  outFile = fopen("animalsTest.csv", "w");
  // Write to .csv file
  write_to_file(binFile, outFile);

  fclose(binFile);
  fclose(outFile);

}
