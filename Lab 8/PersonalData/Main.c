//
// Created by Mieszko Wawrzyniak on 13/12/2017.
//

#include "Person.h"
#include "PeopleStorage.h"

int main(int argc, char *argv[]) {
  FILE *input;
  PeopleStorage storage;
  PeopleStorageInit(&storage);
  
  if (NULL == (input = fopen("input.txt", "r"))) {
    puts("Cannot open file");
  }
  
  PeopleStorageRead(&storage, input);
  
  // Print all
  for (unsigned int i = 0; i < storage.Count; ++i) {
    PersonPrint(&storage.People[i]);
  }
  
  puts("\n");
  printf("Oldest person: ");
  PersonPrint(PeopleStorageGetOldestPerson(&storage));
  
  printf("Slimmest person: ");
  PersonPrint(PeopleStorageGetSlimmestPerson(&storage));
  
  return 0;
}