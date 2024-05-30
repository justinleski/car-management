#include "../include/headerA3.h"
#include <locale.h>

void printAll (struct car * headLL){

    // Initialize variables
    int count = 0;

    setlocale(LC_NUMERIC, "");

    // Print Option selected
    printf("\n==============================\n");
    printf("3: Print data of all cars\n");
    printf("===========================\n\n");

    // Check if the linked list exists before processing
    if (isNull(headLL) == 1){
        printf("Could not print any cars, there are currently no registered cars.\n");
        return;
    }

    // While the list is valid, print the contents of each node
    do { 
        count++;
        printf("Car #%d:\n", count);
        printf("  Car ID: %d\n", headLL->carId);
        printf("  Model: %s\n", headLL->model);
        printf("  Type: %s\n", headLL->type);
        printf("  Price: CDN $ %'.2f\n", headLL->price);
        printf("  Year of Manufacture: %d\n", headLL->year);
        printf("\n");

        // Change pointer to point to next car
        headLL = headLL->nextCar;
    } while(headLL != NULL);

    // Pluralize if needed
    printf("Currently, there ");
    switch(count){
        case 1:
            printf("is %d car ", count);
            break;
        default:
            printf("are %d cars ", count);
    }
    printf("in the inventory.\n");

}
