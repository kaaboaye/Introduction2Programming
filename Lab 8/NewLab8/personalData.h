//
// Created by Mieszko Wawrzyniak on 17/01/2018.
//

#ifndef NEWLAB8_PERSONALDATA_H
#define NEWLAB8_PERSONALDATA_H

#include <stdio.h>

typedef struct {
  char Name[20];
  char *Remarks;
  unsigned char Age;
  float Weight;
} personalData;

personalData PeopleStorageRead(void);
int readData(personalData [], int);
int getOldestPersen(personalData []);
int getSlimmestPersen(personalData [], int);
void printInfo(personalData [], int, char [], char []);

void DebuggerError(const char []);

#endif //NEWLAB8_PERSONALDATA_H
