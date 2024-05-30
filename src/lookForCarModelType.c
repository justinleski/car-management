#include "../include/headerA3.h"

int lookForCarModelType (struct car * headLL, char key [100]){

    // Tokenize user input to check if it is
    char * model;
    char * type;
    model = strtok(key, " ");
    type = strtok(NULL, " "); // This assumes there is no model with a space
    int count = 0;

    // Check if the linked list exists before processing
    if (isNull(headLL) == 1){
        printf("Could not find %s %s, there are currently no registered cars for that model or type.\n", model, type);
        return -1;
    }

    // While 
    do { 
        count++;
        // Check if the model and type of headLL matches the key the user inputted
        if ((strcmp(headLL->model, model) == 0) && (strcmp(headLL->type, type) == 0)){
          
            return count; 
        }

        // Change pointer to point to next car
        headLL = headLL->nextCar;
    } while(headLL != NULL); // end while loop

    // If we reach end of control return -1 ; i.e. no match
    return -1;

}