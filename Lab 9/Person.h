//
// Created by Mieszko Wawrzyniak on 28/12/2017.
//

#ifndef LAB_9_PERSON_H
#define LAB_9_PERSON_H

#include <stdbool.h>

typedef struct {
  char *Name;
  char *Remarks;
  unsigned char Age;
  float Weight;
} Person;

/**
 * Allocates memory of Person object and returns pointer to that memory
 * @return
 */
Person *PersonMalloc(void);

/**
 * Initializes Person object
 * @param p A pointer to the person object
 */
void PersonInit(Person *p);

/**
 * Free up memory used by the object
 * @param p
 */
void PersonFree(Person *p);

/**
 * Free up memory used by the object members
 * @param p
 */
void PersonFreeMembers(Person *p);

/**
 * Frees Person's memory and Initializes variable again
 * @param p
 */
void PersonClean(Person *p);

/**
 * Copy all data from src to the dest
 * @param dest
 * @param src
 */
void PersonCopy(Person *dest, Person *src);

/**
 * Copy data and pointers from src to the dest
 * and set pointers in src Person to NULL
 * @param dest
 * @param src
 */
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
 * Reads Person from string and returns pointer to the Person object
 * @param str
 * @return
 */
Person *PersonRead(char *str);

/**
 * Prints all information about the person
 * @param p A Person object
 */
void PersonPrint(const Person p);

/**
 * Prints all information about the person
 * @param p A pointer to the Person object
 */
void PersonPtrPrint(const Person *p);

#endif //LAB_9_PERSON_H
