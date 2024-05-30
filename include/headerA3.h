#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h> 

#define MAX_LENGTH 25

struct car
{
   int year;
   double price;
   char model[MAX_LENGTH];
   char type[MAX_LENGTH];
   int carId;
   struct car * nextCar;
                            
};


typedef struct car a3Car;

void addNewCar (struct car ** headLL);
void printAll (struct car * headLL);
void printOne (struct car * headLL, int whichOne);

int lookForCarId (struct car * headLL, int key);

int lookForCarModelType (struct car * headLL, char key [100]);

void sortCarId (struct car ** headLL);

void loadCarData (struct car ** headLL, char fileName [MAX_LENGTH]);

int countCars (a3Car * headLL);

void noMoreCars (a3Car ** headLL);
void oneLessCar (a3Car ** headLL, int whichOne);

// Helper prototpyes
int genCarId(a3Car * car);
int isNull(a3Car * car);
void addToEnd(a3Car ** headLL, a3Car * newCar);
int checkDuplicate(int token, a3Car * headLL, a3Car * carPtr);
void removeAll(a3Car ** headLL);
