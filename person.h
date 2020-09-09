#ifndef PERSON_H
#define PERSON_H

typedef struct _Person {
    int src;
    int dest;
} Person;

typedef struct _PersonList {
    Person *person;
    struct _PersonList *next;
} PersonList;

Person* createPerson(int src, int dest);
PersonList* insert(Person *p, PersonList *list);
PersonList* sort_in_out(PersonList *in,int currentFloor);
int length(PersonList *list);


#endif
