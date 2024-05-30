#include "../include/headerA3.h"
#include <locale.h>

void printOne (struct car * headLL, int whichOne){

    printf("\n==============================\n");
    printf("4: Print data of the nth car\n");
    printf("===========================\n\n");

    int count = 0;
    setlocale(LC_NUMERIC, "");

    // Check if the linked list exists before processing
    if (isNull(headLL) == 1){
        printf("Could not print any cars, there are currently no registered cars.\n");
        return;
    }

    // While the list is valid, print the contents of each node
    do { 
        count++;

        // Check if the count reaches car then print
        if (count == whichOne){
            printf("Car #%d:\n", count);
            printf("  Car ID: %d\n", headLL->carId);
            printf("  Model: %s\n", headLL->model);
            printf("  Type: %s\n", headLL->type);
            printf("  Price: CDN $ %'.2f\n", headLL->price);
            printf("  Year of Manufacture: %d\n", headLL->year);
            printf("\n");
            return; // since we do not need to iterate through the rest
        }

        // Change pointer to point to next car
        headLL = headLL->nextCar;
    } while(headLL != NULL); // end while loop

    // If we reach end of control let user know car DNE
    printf("Car %d was not found.\n",whichOne);

}