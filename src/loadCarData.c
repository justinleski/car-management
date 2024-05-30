#include "../include/headerA3.h"

void loadCarData (struct car ** headLL, char fileName [MAX_LENGTH]){

    // Initialize vars
    FILE * fptr;
    fptr = fopen(fileName, "r");
    char tempString[900];
    char *token;
    int tempId;

    // Remember, INITIALIZE then MALLOC - this took to long to figure out seg fault dingus
    a3Car * carPtr = NULL;

    // Print Option selected
    printf("\n==============================\n");
    printf("2: Load data on cars from a given text file \n");
    printf("===========================\n\n");

    // Check if file is valid
    if (fptr == NULL){
        printf("Could not read file!");
        return;
    }

    // Read all lines until empty file
    while (fgets(tempString, 500, fptr) != NULL){

        carPtr = NULL;
        carPtr = malloc(sizeof(a3Car)); // !!!!! SAVING GRACE !!!!! TY EASON AND RITHIK

        token = strtok(tempString, ","); // tokenize each line based on comma
        
        // Keep going until EOF
        while(token != NULL){  

            //printf("token is %d \n", atoi(token));

            // Set the carId as the token temporarily - we need the pointer to not be empty before checking duplicate
            tempId = atoi(token);
            carPtr->carId = -1; // temp value so no accidental overwrites
            // Put tokenized item in carPtr but check if duplicate
            
            token = strtok(NULL, ",");

            strcpy(carPtr->model, token);
            token = strtok(NULL, ","); // moves to next token

            strcpy(carPtr->type, token);
            token = strtok(NULL, ",");

            carPtr->year = atoi(token);
            token = strtok(NULL, ",");

            carPtr->price = (double)(atof(token)); 
            token = strtok(NULL, ",");

            carPtr->nextCar = NULL; // Null since this gets added to end of list

            // Check against existing carId's
            carPtr->carId = checkDuplicate(tempId, *headLL, carPtr); 

            // Put carPtr into LL
            addToEnd(headLL, carPtr); 

        }  // end while
        
    } // end while loop to read and tokenize

    // Close file
    fclose(fptr);

}
