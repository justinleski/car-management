#include "../include/headerA3.h"

int genCarId(a3Car * car){

    // Initialize carId at 0
    int carId = 0;

    // Add all ASCII values to carID
    for (int i = 0; i < strlen(car->model); i++){
        carId += car->model[i];
    }

    // Return the length plus the len of type to make carId
    return carId + strlen(car->type);

} // end function to gen carId

int isNull(a3Car * car){

    // Check if the LL is empty, return 1 (T) or 0 (F)
    if (car == NULL){
        return 1;
    } // returns 1 as in it is true that it is empty
    else{
        return 0;
    }

} // end isNull

void addToEnd(a3Car ** headLL, a3Car * newCar) {

    // Allocate for ptr
    //a3Car * ptr = malloc(sizeof(a3Car));

    // Create pointer to indirectly handle LL
    a3Car * ptr = *headLL; 

    // If LL is empty, add to front: SGE FAULT IN THIS FOR LOOP
    if (ptr == NULL){
        *headLL = newCar;
    }
    else{
        // If LL is not empty, loop to tail node
        //printf("Does this run when NULL?"); // test remove
        while (ptr->nextCar != NULL){
            ptr = ptr->nextCar;
        }
        ptr->nextCar = newCar; // Make previous tail point to pos of new tail

    } // end else to add node if not NULL
}

int checkDuplicate(int token, a3Car * headLL, a3Car * carPtr){ 

    // Count cars and create array based off of size
    srand(time(NULL));
    //a3Car * temp = headLL;
    
    int carCount = countCars(headLL);
    int idArr[carCount];
    int count = 0;
   
    // Check if the linked list exists before processing
    if (isNull(headLL) == 1){
        // If LL empty, return token as ID
        return token;
    }

    do {
        idArr[count] = headLL->carId;
        count++;

        // Change pointer to point to next car
        headLL = headLL->nextCar;
       
    } while(headLL != NULL);

    // Compare the current carId with existing ones from LL
    for (int i = 0; i < carCount; i++){

        // If the user's carId matches a current carId, generate a new one using the same rule plus random
        if(idArr[i] == token){
            return genCarId(carPtr) + ((rand() % 999)+1); // add random number 1-999
        }
    }

    // If no matches, with current LL, return current carId which is stored in token
    return token;
}

void removeAll(a3Car ** headLL){

    a3Car * temp;

    // Check each node in linked list until null and remove
    while (*headLL != NULL){ 

        temp = *headLL; 
        *headLL = temp->nextCar; 

        // Make sure to free from memory the previous node
        free(temp);
    }

}