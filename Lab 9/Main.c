//
// Created by Mieszko Wawrzyniak on 28/12/2017.
//

#include "People.h"

int main(int argc, char *argv[]) {
  People people;
  
  PeopleInit(&people);
  PeopleRead(&people, fopen("input.txt", "r"));
  
  for (unsigned int i = 0; i < people.Count; ++i) {
    PersonPrint(*people.People[i]);
  }
  
  puts("\nSoring by  weight");
  PeopleSortWeight(&people);
  
  for (unsigned int i = 0; i < people.Count; ++i) {
    PersonPtrPrint(people.People[i]);
  }
  
  puts("\nSoring by  remarks");
  PeopleSortRemarks(&people);
  
  for (unsigned int i = 0; i < people.Count; ++i) {
    PersonPtrPrint(people.People[i]);
  }
}