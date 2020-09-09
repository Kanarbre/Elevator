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

void sort_in_out(PersonList *in,PersonList *out,int currentFloor){
    if(in!=NULL){
        if(((in -> person)-> dest) == currentFloor){
            out = insert(in -> person,out);
            in = (in->next);
            sort_in_out(in,out,currentFloor);
        }
        else{
            sort_in_out(in->next,out,currentFloor);
        }
    }

}

PersonList* exitElevator(Elevator *e){
    PersonList *t = NULL;
        sort_in_out(e->persons,t,e->currentFloor);
    return t;
}


PersonList* enterElevator(Elevator *e, PersonList *waitingList){
    if(length(e->persons)<e->capacity){
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
        enterElevator(b->elevator,(b->waitingLists)[b->elevator->currentFloor]);

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