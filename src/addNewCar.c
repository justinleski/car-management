#include "../include/headerA3.h"

void addNewCar (struct car ** headLL){ 

    // Variables
    char carModel[MAX_LENGTH];
    char carType[MAX_LENGTH];
    int carYear;
    double carPrice;

    // Print Option selected
    printf("\n==============================\n");
    printf("1: Add data on a new car\n");
    printf("===========================\n\n");

    // Create a new car for the user to populate - note it adds to the END of the LL
    a3Car * newCar = malloc(sizeof(a3Car)); 
    // a3Car * ptr = malloc(sizeof(a3Car));

    // Ask user details of car
    printf("Enter the car model: ");
    fgets(carModel, MAX_LENGTH, stdin); 
    carModel[strcspn(carModel, "\n")] = 0; // Count characters up until \n and put into carModel

    printf("Enter the car type: ");
    fgets(carType, MAX_LENGTH, stdin);
    carType[strcspn(carType, "\n")] = 0;

    printf("\n");

    printf("Enter the year of manufacture: ");
    scanf("%d", &carYear);
    getchar(); // remove enter

    do{
        printf("Enter its price: CDN $ ");
        scanf("%lf", &carPrice);
        getchar(); // remove enter

        // Prompt user to enter valid car price
        if(carPrice > 99999 || carPrice < 0){
            printf("Invalid car price, please enter a value less than $ 100,000.\n");
        }

    } while(carPrice > 99999 || carPrice < 0);

    // Set values to newCar
    strcpy(newCar->model, carModel);
    strcpy(newCar->type, carType);
    newCar->year = carYear;
    newCar->price = carPrice;
    newCar->nextCar = NULL; // since tail of list

    // Generate carId
    newCar->carId = genCarId(newCar); 
    newCar->carId = checkDuplicate(newCar->carId, *headLL, newCar); 
    printf("\nYour computer generated carId is: %d", newCar->carId);

    // Call helper to add to end of LL
    addToEnd(headLL, newCar);
}
