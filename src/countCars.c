#include "../include/headerA3.h"

int countCars (a3Car * headLL){

    // Initialize variables
    int count = 0;

    // We need to check if the linked list is empty, return 0 if it is
    if (isNull(headLL) == 1){
        return count; 
    }

   // While the list is valid, print the contents of each node
    while(headLL->nextCar != NULL){ 
        count++;

        // Change pointer to point to next car
        headLL = headLL->nextCar;
    } // end while loop

    // Add 1 more at end since tail node not accounted for
    count++;
    return count;

}