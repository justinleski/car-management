#include "../include/headerA3.h"

void noMoreCars (a3Car ** headLL){

    a3Car * temp; 
    char userInput[100];

    do {

        printf("Remove all cars y or n?: ");
        scanf("%s", userInput);

        if(strcmp(userInput, "n") == 0){
            break;
        }

    } while(strcmp(userInput, "y") != 0);

    // Check each node in linked list until null and remove
    while (*headLL != NULL){ 

        temp = *headLL; 
        *headLL = temp->nextCar; 

        // Make sure to free from memory the previous node
        free(temp);
    }

    printf("All cars successfully removed. \n");

}