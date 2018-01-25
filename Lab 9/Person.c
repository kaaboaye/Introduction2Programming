//
// Created by Mieszko Wawrzyniak on 28/12/2017.
//

#include <stdlib.h>
#include <memory.h>
#include <printf.h>
#include "Person.h"
#include "Debugger.h"

Person *PersonMalloc(void) {
  Person *p;
  
  p = malloc(sizeof(Person));
  if (!p) DebuggerError("Person allocation error");
  
  return p;
}

void PersonInit(Person *p) {
  p->Name = (char *) malloc(0);
  p->Remarks = (char *) malloc(0);
}

void PersonFree(Person *p) {
  free(p);
}

void PersonFreeMembers(Person *p) {
  free(p->Name);
  free(p->Remarks);
}

void PersonClean(Person *p) {
  PersonFreeMembers(p);
  PersonInit(p);
}

void PersonCopy(Person *dest, Person *src) {
  PersonInitData(dest, src->Name, src->Remarks, src->Age, src->Weight);
}

void PersonMove(Person *dest, Person *src) {
  // Copy data and pointers to destynation
  (*dest) = (*src);
  
  // Forget strings in src Person
  src->Name = NULL;
  src->Remarks = NULL;
}

void PersonInitData(Person *p, const char *name, const char *remarks, const unsigned char age, const float weight) {
  // Set the name
  p->Name = (char *) malloc(sizeof(char) * (strlen(name) + 1));
  if (!p->Name) DebuggerError("Name allocation error");
  
  strcpy(p->Name, name);
  
  // Set the remarks
  p->Remarks = (char *) malloc(sizeof(char) * (strlen(remarks) + 1));
  if (!p->Remarks) DebuggerError("Remarks allocation error");
  
  strcpy(p->Remarks, remarks);
  
  // Set the age
  p->Age = age;
  
  // Set the weight
  p->Weight = weight;
}

void PersonSetName(Person *p, const char *name) {
  p->Name = realloc(p->Name, sizeof(char) * (strlen(name) + 1) );
  if (!p->Name) DebuggerError("Name reallocation error");
  
  strcpy(p->Name, name);
}

void PersonSetRemarks(Person *p, const char *remarks) {
  p->Remarks = realloc(p->Remarks, sizeof(char) * (strlen(remarks) + 1) );
  if (!p->Remarks) DebuggerError("Remarks reallocation error");
  
  strcpy(p->Remarks, remarks);
}

// Format: "Name; Age; Weight; Remarks;"
#define STR_SEPARATORS ";"
Person *PersonRead(char *str) {
  Person *p = PersonMalloc();
  char *token;
  
  PersonInit(p);
  
  // Set the Name
  if ((token = strtok(str, STR_SEPARATORS)) == NULL) {
    DebuggerError("Name not found");
  }
  PersonSetName(p, token);
  
  // Set the Age
  if ((token = strtok(NULL, STR_SEPARATORS)) == NULL) {
    DebuggerError("Age not found");
  }
  p->Age = (unsigned char) atoi(token);
  
  // Set the Weight
  if ((token = strtok(NULL, STR_SEPARATORS)) == NULL) {
    DebuggerError("Weight not found");
  }
  p->Weight = (float) atof(token);
  
  // Set the Remarks
  if ((token = strtok(NULL, STR_SEPARATORS)) == NULL) {
    DebuggerError("Remarks not found");
  }
  PersonSetRemarks(p, token);
  
  return p;
}

void PersonPrint(const Person p) {
  printf("%s Age: %d Weight: %f Remarks: %s\n", p.Name, p.Age, p.Weight, p.Remarks);
}

void PersonPtrPrint(const Person *p) {
  printf("%s Age: %d Weight: %f Remarks: %s\n", p->Name, p->Age, p->Weight, p->Remarks);
}
