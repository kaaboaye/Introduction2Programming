//
// Created by Mieszko Wawrzyniak on 13/12/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Person.h"
#include "Debugger.h"

void PersonInit(Person *p) {
  p->Name = (char *) malloc(0);
  p->Remarks = (char *) malloc(0);
}

void PersonFree(Person *p) {
  free(p->Name);
  free(p->Remarks);
}

void PersonClean(Person *p) {
  PersonFree(p);
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
  strcpy(p->Name, name);
  
  // Set the remarks
  p->Remarks = (char *) malloc(sizeof(char) * (strlen(remarks) + 1));
  strcpy(p->Remarks, remarks);
  
  // Set the age
  p->Age = age;
  
  // Set the weight
  p->Weight = weight;
}

void PersonSetName(Person *p, const char *name) {
  p->Name = realloc(p->Name, sizeof(char) * (strlen(name) + 1) );
  strcpy(p->Name, name);
}

void PersonSetRemarks(Person *p, const char *remarks) {
  p->Remarks = realloc(p->Remarks, sizeof(char) * (strlen(remarks) + 1) );
  strcpy(p->Remarks, remarks);
}

// Format: "Name; Age; Weight; Remarks;"
#define STR_SEPARATORS ";"
bool PersonSetStr(Person *p, char *str) {
  char *token;
  
  // Set the Name
  if ((token = strtok(str, STR_SEPARATORS)) == NULL) {
    DebuggerError("Name not found");
    return false;
  }
  PersonSetName(p, token);
  
  // Set the Age
  if ((token = strtok(NULL, STR_SEPARATORS)) == NULL) {
    DebuggerError("Age not found");
    return false;
  }
  p->Age = (unsigned char) atoi(token);
  
  // Set the Weight
  if ((token = strtok(NULL, STR_SEPARATORS)) == NULL) {
    DebuggerError("Weight not found");
    return false;
  }
  p->Weight = (float) atof(token);
  
  // Set the Remarks
  if ((token = strtok(NULL, STR_SEPARATORS)) == NULL) {
    DebuggerError("Remarks not found");
    return false;
  }
  PersonSetRemarks(p, token);
  
  return true;
}

void PersonPrint(const Person *p) {
  printf("%s Age: %d Weight: %f Remarks: %s\n", p->Name, p->Age, p->Weight, p->Remarks);
}