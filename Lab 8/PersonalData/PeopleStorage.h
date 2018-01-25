//
// Created by Mieszko Wawrzyniak on 13/12/2017.
//

#ifndef PERSONALDATA_PERSONSSTORAGE_H
#define PERSONALDATA_PERSONSSTORAGE_H

#include <stdio.h>
#include "Person.h"

#define LINE_LEN 512

/**
 * List of the People objects
 */
typedef struct {
  unsigned int Count;
  Person *People;
  Person *LastPerson;
} PeopleStorage;

/**
 * Initializes the PeopleStorage object from given pointer
 * @param ps A pointer to the PeopleStorage array
 */
void PeopleStorageInit(PeopleStorage *ps);

/**
 * Frees all memory used by PeopleStorage and each person in this storage
 * @param ps
 */
void PeopleStorageFree(PeopleStorage *ps);

/**
 * Allocate memory for one more element and set LastItem
 * @param ps
 */
void PeopleStorageAdd(PeopleStorage *ps);

/**
 * Reads every person from input file using PersonSetStr() function
 * @param ps A pointer to the PeopleStorege
 * @param input Input file
 */
void PeopleStorageRead(PeopleStorage *ps, FILE *input);

/**
 * Finds the oldest person in the storage
 * @param ps A pointer to the PeopleStorege
 * @return The pointer to the oldest person in the storage. If there is none returns NULL
 */
Person *PeopleStorageGetOldestPerson(PeopleStorage *ps);

/**
 * Finds the slimmest person in the storage
 * @param ps A pointer to the PeopleStorege
 * @return The pointer to the slimmest person in the storage. If there is none returns NULL
 */
Person *PeopleStorageGetSlimmestPerson(PeopleStorage *ps);

/**
 * Calls PersonPrint() function for given person in storage
 * @param ps A pointer to the PeopleStorege
 * @param id An person id
 */
void PeopleStoragePrintById(PeopleStorage *ps, unsigned int id);

#endif //PERSONALDATA_PERSONSSTORAGE_H
