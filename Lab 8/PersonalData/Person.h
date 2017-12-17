//
// Created by Mieszko Wawrzyniak on 13/12/2017.
//

#ifndef PERSONALDATA_PERSON_H
#define PERSONALDATA_PERSON_H

#include <stdbool.h>

typedef struct {
  char *Name;
  char *Remarks;
  unsigned char Age;
  float Weight;
} Person;

/**
 * Initializes Person object
 * @param p A pointer to the person object
 */
void PersonInit(Person *p);

/**
 * Frees Person's memory
 * @param p
 */
void PersonFree(Person *p);

/**
 * Frees Person's memory and Initializes variable again
 * @param p
 */
void PersonClean(Person *p);

/**
 *
 * @param dest
 * @param src
 */
void PersonCopy(Person *dest, Person *src);

void PersonMove(Person *dest, Person *src);

/**
 * Initializes Person object and sets appropriate data
 * @param p A pointer to the Person object
 * @param name A name of the Person
 * @param remarks Remarks about the Person
 * @param age An age of the Person
 * @param weight A weight of the Person
 */
void PersonInitData(Person *p, const char *name, const char *remarks, const unsigned char age, const float weight);

/**
 * Sets Name in the given Person
 * @remark Person have to be initialized
 * @param p A pointer to the Person object
 * @param name New Name in the Person
 */
void PersonSetName(Person *p, const char *name);

/**
 * Sets Remarks in the given Person
 * @remark Person have to be initialized
 * @param p A pointer to the Person object
 * @param name New Remark in the Person
 */
void PersonSetRemarks(Person *p, const char *remarks);

/**
 * Sets appropriate data read from input string
 * @param p A pointer to the Person object
 * @param str Input string with data "Name; Age; Weight; Remarks;"
 * @return Whether successfully read Person
 */
bool PersonSetStr(Person *p, char *str);

/**
 * Prints all information about the person
 * @param p A pointer to the Person object
 */
void PersonPrint(const Person *p);


#endif //PERSONALDATA_PERSON_H
