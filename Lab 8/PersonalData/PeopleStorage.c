//
// Created by Mieszko Wawrzyniak on 13/12/2017.
//

#include <stdlib.h>
#include "PeopleStorage.h"
#include "Person.h"

void PeopleStorageInit(PeopleStorage *ps) {
  ps->Count = 0;
  ps->People = (Person *) malloc(0);
}

void PeopleStorageAdd(PeopleStorage *ps) {
  ps->Count++; // Increase the counter
  ps->People = (Person *) realloc(ps->People, ps->Count * sizeof(Person)); // Allocate memory
  ps->LastPerson = &ps->People[ps->Count - 1]; // Set pointer to the LastPerson
}

void PeopleStorageRead(PeopleStorage *ps, FILE *input) {
  char line[LINE_LEN];
  Person p;
  
  while (fgets(line, LINE_LEN, input)) {
    PersonInit(&p);
  
    if (PersonSetStr(&p, line)) {
      PeopleStorageAdd(ps);
      PersonMove(ps->LastPerson, &p);
    }
    else {
      return;
    }
  }
}

Person *PeopleStorageGetOldestPerson(PeopleStorage *ps) {
  if (ps->Count < 1) {
    return NULL;
  }
  
  Person *p;
  unsigned char oldestAge = 0;
  unsigned int oldestId = 0;
  
  for (unsigned int i = 0; i < ps->Count; ++i) {
    p = &ps->People[i];
    
    if (p->Age >= oldestAge) {
      oldestAge = p->Age;
      oldestId = i;
    }
  }
  
  return &ps->People[oldestId];
}

Person *PeopleStorageGetSlimmestPerson(PeopleStorage *ps) {
  if (ps->Count < 1) {
    return NULL;
  }
  
  Person *p;
  float slimmestWeight = ps->People[0].Weight;
  unsigned int slimmestId = 0;
  
  for (unsigned int i = 0; i < ps->Count; ++i) {
    p = &ps->People[i];
    
    if (p->Weight < slimmestWeight) {
      slimmestWeight = p->Weight;
      slimmestId = i;
    }
  }
  
  return &ps->People[slimmestId];
}

void PeopleStoragePrintById(PeopleStorage *ps, unsigned int id) {
  if (ps->Count < id) {
    puts("undefined");
  }
  
  PersonPrint(&ps->People[id]);
}