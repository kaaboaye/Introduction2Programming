//
// Created by Mieszko Wawrzyniak on 28/12/2017.
//

#ifndef LAB_9_PEOPLE_H
#define LAB_9_PEOPLE_H

#include <stdio.h>
#include "Person.h"

typedef struct {
  unsigned int Count;
  Person **People;
  Person **LastPerson;
} People;

/**
 * Initiate People array
 * @param p Not initialized array of People
 */
void PeopleInit(People *p);

/**
 * Free up memory
 * @param p
 */
void PeopleFree(People *p);

/**
 * Adds an element to the array
 * @param p
 */
void PeopleAdd(People *p);

/**
 * Reads all people from the input file
 * @param people
 * @param input
 */
void PeopleRead(People *people, FILE *input);

/**
 * Sorts People by Weight in ASC order
 * @param people
 */
void PeopleSortWeight(People *people);

/**
 * Sorts People by Remarks in ASC order
 * @param people
 */
void PeopleSortRemarks(People *people);

#endif //LAB_9_PEOPLE_H
