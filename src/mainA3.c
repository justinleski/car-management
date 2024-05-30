#include "../include/headerA3.h"

int main(){

    // Declare variables
    int option, whichOne, totalCars, temp;
    a3Car * headLL = NULL;
    char fileName[MAX_LENGTH] = "inputFile.txt"; 
    int key = 0;
    char stringKey[100];

    // Make the head null until added or read in

    printf("\n**************************\n");
    printf("Welcome to Car Base\n");
    printf("**************************\n");

    // Loop options until user exits
    while (option != 11){

        // Display menu to user
        printf("\nPlease select one of the following options:\n\n");
        printf("  (1)  - Add data on a new car\n"); 
        printf("  (2)  - Load data on cars from a given text file\n");
        printf("  (3)  - Print data of all cars\n");
        printf("  (4)  - Print data of the nth car\n");
        printf("  (5)  - Search car data based on carId\n");
        printf("  (6)  - Search car data based on model and type\n");
        printf("  (7)  - Count the total number of cars in the list\n");
        printf("  (8)  - Sort the cars in the list based on carId\n");
        printf("  (9)  - Remove data of the nth car\n");
        printf("  (10) - Remove all car data\n");
        printf("  (11) - Exit\n\n");

        printf("Please enter a number corresponding to an option: ");
        scanf("%d", &option);
        getchar(); // remove enter

        // Switch case to call function user requests
        switch(option){
            case 1:
                // call function 1
                addNewCar(&headLL);
                break;
            case 2:
                // something
                loadCarData (&headLL, fileName);
                break;
            case 3:
                // 
                printAll (headLL);
                break;
            case 4:
                // Validate the input in main using countCars()
                totalCars = countCars(headLL);

                // If there are no cars, do not let user proceed
                if(totalCars < 1){
                    printf("\nThere are currently no cars in the inventory.\nPlease add cars before attempting to display them.\n");
                    break;
                }

                // Verify that the user's input is valid
                do{
                    // Ask user to enter input
                    printf("Which car would you like to print (1-%d)?: ",totalCars);
                    scanf("%d", &whichOne);

                    // Inform user if their choice is invalid
                    if (totalCars < whichOne){
                        printf("Please enter a valid car, there are %d cars.\n", totalCars);
                    }

                } while(totalCars < whichOne);

                printOne(headLL, whichOne);
                break;
            case 5:
                // Validate to see if cars are in there
                totalCars = countCars(headLL);
                if(totalCars < 1){
                    printf("\nThere are currently no cars in the inventory.\nPlease add cars before attempting to display one.\n");
                    break;
                }

                printf("Please enter a Car ID to search for: ");
                scanf("%d", &key);
                temp = lookForCarId (headLL, key); 

                printf("REMOVE TEST; position for %d is %d\n", key, temp);

                break;
            case 6:
                // Validate to see if cars are in there
                totalCars = countCars(headLL);
                if(totalCars < 1){
                    printf("\nThere are currently no cars in the inventory.\nPlease add cars before attempting to display one.\n");
                    break;
                }

                // Ask user for model and type
                printf("Enter the car model and type: ");
                fgets(stringKey, 100, stdin);
                stringKey[strcspn(stringKey, "\n")] = 0;

                temp = lookForCarModelType (headLL, stringKey);
                //printf("REMOVE TEST; position for %s is %d\n", stringKey, temp);
                break;
            case 7:
                // Call function
                totalCars = countCars(headLL);
                printf("There are %d cars.\n",totalCars);
                break;
            case 8:
                //
                sortCarId (&headLL);
                break;

            case 9:
                // Validate user input
                totalCars = countCars(headLL);

                // Validate to see if cars are in there
                if(totalCars < 1){
                    printf("\nThere are currently no cars in the inventory.\nPlease add cars before attempting to remove one.\n");
                    break;
                }

                do{
                    printf("Please enter which car number you would like to remove (1-%d): ",totalCars);
                    scanf("%d", &key);
                } while(key < 1 || key > totalCars);
                oneLessCar(&headLL, key);
                break;

            case 10:
                // Fire all cars
                noMoreCars(&headLL);
                break;

            default:
                if (option != 11){
                    printf("Please enter a valid option.\n");
                }
        } // end switch


    } // end while loop to validate user input

    // Print message to indicate exit
    removeAll(&headLL); // free LL before exiting since C doesn't do it for us
    printf("\n****************************\n");
    printf("Thank you for using Car Base");
    printf("\n****************************\n\n");


    return 0;
}