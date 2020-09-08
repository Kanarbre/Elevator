# include <stdlib.h>
# include "person.h"


Person* createPerson(int src,int dest){
    Person* t = (Person*)malloc(sizeof(Person));
    t -> src = src;
    t -> dest = dest;
    return t;
}

PersonList* insert(Person *p, PersonList *list){
    PersonList *t = (PersonList*)malloc(sizeof(PersonList));
    t -> person = p;
    t -> next = list;
    return t;
}