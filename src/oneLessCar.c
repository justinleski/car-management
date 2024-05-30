#include "../include/headerA3.h"

void oneLessCar (a3Car ** headLL, int whichOne){

    // Initialize pointer for car
    //a3Car * carPtr = malloc(sizeof(a3Car));
    a3Car * carPtr;
    carPtr = *headLL;
    a3Car * temp = NULL;
    a3Car * temp2 = NULL;
    int count = 0;

    // Check if the linked list exists before processing
    if (isNull(carPtr) == 1){
        printf("Could not remove car of ID %d, there is currently no registered car for that ID.\n", whichOne);
        return;
    }

    // While the list is valid, print the contents of each node
    do { 
        count++;
        // Check if the count reaches car then print
        if (count == whichOne){
            
            // Print what car was removed
            printf("Removed car ID: #%d \n", carPtr->carId);

            // IF end of the LL, just remove tail node   
            if (whichOne == 1){ // Check if head of LL - special case
                temp = carPtr->nextCar;
                free(carPtr);
                *headLL = temp;
                return;
            }
            else if (carPtr->nextCar == NULL){
                //printf("Did it run? %s \n", carPtr->model);
                free(carPtr);
            }

            temp = carPtr->nextCar;

            // free the current node, i.e. the one we want to delete
            free(carPtr); 

            // Re-assign temp to previous parts before removal
            temp2->nextCar = temp;

            return; // since we do not need to iterate through the rest
        }

        // Change pointer to point to next car
        temp2 = carPtr; // keep track of previous ptr
        carPtr = carPtr->nextCar;
    } while(carPtr != NULL); // end while loop

    // If we reach end of control let user know car DNE
    printf("Car ID %d was not found.\n",whichOne);

}