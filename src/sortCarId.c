#include "../include/headerA3.h"

void sortCarId (struct car ** headLL){

    // NOTE: this is referenced from: https://www.geeksforgeeks.org/bubble-sort-for-linked-list-by-swapping-nodes/

    a3Car ** h;
    int i, j, swapped;

    int count = countCars(*headLL);
 
    for (i = 0; i <= count; i++) {
 
        h = headLL;
        swapped = 0;
 
        for (j = 0; j < count - i - 1; j++) {
 
            a3Car* p1 = *h;
            a3Car* p2 = p1->nextCar;
 
            if (p1->carId > p2->carId) {
 
                /* update the link after swapping */

                a3Car * tmp = p2->nextCar;
                p2->nextCar = p1;
                p1->nextCar = tmp;

                *h = p2;

                swapped = 1;
            }
 
            h = &(*h)->nextCar;
        }
 
        /* break if the loop ended without any swap */
        if (swapped == 0)
            break;
    }
}