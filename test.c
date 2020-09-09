
#include <stdlib.h>
#include <stdio.h>

#include "elevator.h"
#include "person.h"

int main(){

    // generate list of waiting persons
  int nbFloor = 5;
  PersonList **waitingLists = malloc(nbFloor*sizeof(PersonList*));
  for(int currentFloor=0; currentFloor < nbFloor; currentFloor++) {
  waitingLists[currentFloor] = NULL;
  int nbPerson = 5; // 5 persons in the waiting list
  for(int j=0 ; j<nbPerson ; j++) {
    int dest = rand() % (nbFloor);
    Person *p = createPerson(currentFloor, dest);
    waitingLists[currentFloor] = insert(p,waitingLists[currentFloor]);
    }
  }

  // Initialize building and elevator
  int capacity = 3;
  int currentFloor = 0;
  Elevator *elevator = create_elevator(capacity, currentFloor , NULL);
  Building *building = create_building(nbFloor, elevator, waitingLists);
  // printf(building->elevator->persons->person);
  // exitElevator(building->elevator);
  int p = length(building->waitingLists[0]);
  enterElevator(building->elevator,building->waitingLists[0]);
  int q = length(building->waitingLists[0]);
  // int r = building->elevator->persons->person->dest;
  printf("source %d %p \n",p,q);
  building->elevator->currentFloor = 3;


  return 0;
}