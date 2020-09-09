# include <stdlib.h>
# include "elevator.h"
# include "person.h"

Elevator *create_elevator(int capacity, int currentFloor, PersonList *persons){
    Elevator *t = (Elevator*)malloc(sizeof(Elevator));
    t -> capacity = capacity;
    t -> currentFloor = currentFloor;
    t -> persons = persons;
    return t;
}

Building *create_building(int nbFloor, Elevator *elevator, PersonList **waitingLists){
    Building *t = (Building*)malloc(sizeof(Building));
    t -> nbFloor = nbFloor;
    t -> elevator = elevator;
    t -> waitingLists = waitingLists;
    return t;
}

PersonList* sort_in_out(PersonList *in,int currentFloor){
    if(in!=NULL){
        if(((in -> person)-> dest) == currentFloor){
            return sort_in_out(in->next,currentFloor);
        }
        else{
            return insert(in->person,sort_in_out(in->next,currentFloor));
        }
    }
    else{
            return in;
    }


}

PersonList* exitElevator(Elevator *e){
    e->persons = sort_in_out(e->persons,e->currentFloor);
    return e->persons;
}


PersonList* enterElevator(Elevator *e, PersonList *waitingList){
    if((length(e->persons)<(e->capacity))&&waitingList!=NULL){
        e->persons = insert((waitingList->person),e->persons);
        waitingList = (waitingList->next);
        return enterElevator(e,waitingList);
    }
    else{
        return waitingList;
        }
    }


void stepElevator(Building *b){
    if(b->elevator->currentFloor==b->elevator->targetFloor){
        exitElevator(b->elevator);
        b->waitingLists[b->elevator->currentFloor] = enterElevator(b->elevator,(b->waitingLists)[b->elevator->currentFloor]);

    }
    else{
        if(b->elevator->currentFloor>b->elevator->targetFloor){
            b->elevator->currentFloor--;
        }
        else{
            b->elevator->currentFloor++;
        }

    }
}