#include "../include/headerA3.h"
#include <locale.h>

int lookForCarId (struct car * headLL, int key){

    int count = 0;
    setlocale(LC_NUMERIC, "");

    // Check if the linked list exists before processing
    if (isNull(headLL) == 1){
        printf("Could not find any cars of ID %d, there are currently no registered cars.\n", key);
        return -1;
    }

    // While 
    do { 
        count++;
        // Check if the count reaches car then print
        if (headLL->carId == key){
            // printf("Car #%d:\n", count);
            // printf("  Car ID: %d\n", headLL->carId);
            // printf("  Model: %s\n", headLL->model);
            // printf("  Type: %s\n", headLL->type);
            // printf("  Price: CDN $ %'.2f\n", headLL->price);
            // printf("  Year of Manufacture: %d\n", headLL->year);
            // printf("\n");
            return count; // FIXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX: how do we return position of LL? does it mean just car count?
        }

        // Change pointer to point to next car
        headLL = headLL->nextCar;
    } while(headLL != NULL); // end while loop

    // If we reach end of control return -1 ; i.e. no match
    return -1;

}