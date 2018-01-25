//
// Created by Mieszko Wawrzyniak on 17/01/2018.
//

#include "personalData.h"
#include <string.h>
#include <stdlib.h>

int readData(personalData data[], const int size) {
  for (int i = 0; i < (size - 1); ++i) {
    data[i] = PeopleStorageRead();
    
    if (!data[i].Remarks) return i;
  }
  
  return size - 1;
}

void DebuggerError(const char e[]) {
  fprintf(stderr, "%s", e);
  exit(1);
}

#define str_len 521
#define STR_SEPARATORS ";"
personalData PeopleStorageRead() {
  char str[str_len];
  char *token;
  personalData p;
  
  if ((NULL == fgets(str, str_len, stdin)) || (strncmp("~", str, 1) == 0)) {
    memset(&p, 0, sizeof(personalData));
    return p;
  }
  
  // Set the Name
  if ((token = strtok(str, STR_SEPARATORS)) == NULL) {
    DebuggerError("Name not found");
  }
  strncpy(p.Name, token, sizeof(p.Name));
  
  // Set the Age
  if ((token = strtok(NULL, STR_SEPARATORS)) == NULL) {
    DebuggerError("Age not found");
  }
  p.Age = (unsigned char) atoi(token);
  
  // Set the Weight
  if ((token = strtok(NULL, STR_SEPARATORS)) == NULL) {
    DebuggerError("Weight not found");
  }
  p.Weight = (float) atof(token);
  
  // Set the Remarks
  if ((token = strtok(NULL, STR_SEPARATORS)) == NULL) {
    DebuggerError("Remarks not found");
  }
  
  p.Remarks = malloc(strlen(token) + 1);
  if (!p.Remarks) {
    DebuggerError("allocation error");
  }
  
  strcpy(p.Remarks, token);
  
  return p;
}

int getOldestPersen(personalData data[]) {
  if (!data[0].Remarks) {
    return -1;
  }
  
  unsigned char oldestAge = 0;
  int oldestId = 0;
  
  for (int i = 0; data[i].Remarks; ++i) {
    if (data[i].Age >= oldestAge) {
      oldestAge = data[i].Age;
      oldestId = i;
    }
  }
  
  return oldestId;
}

int getSlimmestPersen(personalData data[], int len) {
  if (len <= 0) {
    return -1;
  }
  
  float slimmestWeight = data[0].Weight;
  int slimmestId = 0;
  
  for (int i = 0; i < len; ++i) {
    if (data[i].Weight < slimmestWeight) {
      slimmestWeight = data[i].Weight;
      slimmestId = i;
    }
  }
  
  return slimmestId;
}

void printInfo(personalData data[], int id, char ok[], char err[]) {
  if (id < 0) {
    puts(err);
    return;
  }
  
  personalData *p = &data[id];
  printf("%s: %s Age: %d Weight %f %s\n", ok, p->Name, p->Age, p->Weight, p->Remarks);
}