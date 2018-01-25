//
// Created by Mieszko Wawrzyniak on 28/12/2017.
//

#include <string.h>
#include <stdlib.h>
#include "People.h"
#include "Person.h"
#include "sign.h"


void PeopleInit(People *p) {
  p->Count = 0;
  
  p->People = malloc(0);
}

void PeopleFree(People *p) {
  free(p->People);
}

void PeopleAdd(People *p) {
  p->Count++;
  
  p->People = (Person **) realloc(p->People, sizeof(Person *) * p->Count);
  p->LastPerson = &p->People[p->Count - 1];
}

#define LINE_LEN 512
void PeopleRead(People *people, FILE *input) {
  char line[LINE_LEN];
  
  while (fgets(line, LINE_LEN, input)) {
    if (!strlen(line)) continue;
    
    PeopleAdd(people);
    (*people->LastPerson) = PersonRead(line);
  }
}

static int compareWeight(const Person **a, const Person **b) {
  return (((*a)->Weight > (*b)->Weight) - ((*a)->Weight < (*b)->Weight));
}

void PeopleSortWeight(People *people) {
  qsort(people->People, people->Count, sizeof(people->People[0]), compareWeight);
}

static int compareRemarks(const void **a, const void **b) {
  Person *pA = (Person *)(*a);
  Person *pB = (Person *)(*b);
  
  return sign_i(strcmp(pA->Remarks, pB->Remarks));
}

void PeopleSortRemarks(People *people) {
  qsort(people->People, people->Count, sizeof(people->People[0]), compareRemarks);
}
