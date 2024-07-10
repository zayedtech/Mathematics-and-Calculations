/*****+*****---*--***-**------*****---**---**-*--***************************
*
*  Homework #: 01
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Program Description: Calculating the time it takes for two cars to finish a race along with the average acceleration and time difference between them given final velocity
*
******+*****---*--***-**------*****---**---**-*--**************************/
#include<stdio.h>

#define DISTANCE 500 //race distance in ft

int main(void)
{
  float velocityCar1; //final velocity of Car 1 in ft
  float velocityCar2; //final velocity of Car 2 in ft
  float timeCar1; //time it takes Car 1 to complete the race
  float timeCar2; //time it takes Car 2 to complete the race
  float accelerationCar1; //constant acceleration of Car 1 
  float accelerationCar2; //constant acceleration of Car 2
  float averageAcceleration; //average acceleration of Car 1 and Car 2
  float timeDifference; //time difference between Car 1 and Car 2

  printf("Enter final velocity for Car 1 -> ");
  scanf("%f", &velocityCar1); //stores the value that the user enters in velocityCar1
  printf("Enter final velocity for Car 2 -> ");
  scanf("%f", &velocityCar2); //stores the value that the user enters in velocityCar2
  printf("\n");

  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"); 

  timeCar1 = DISTANCE * 2 / velocityCar1; //calculates the time needed to complete the race for Car 1
  timeCar2 = DISTANCE * 2 / velocityCar2; //calculates the time needed to complete the race for Car 2
  accelerationCar1 = velocityCar1 / timeCar1; //calculates the acceleration of Car 1
  accelerationCar2 = velocityCar2 / timeCar2; //calculates the acceleration of Car 2
  averageAcceleration = (accelerationCar1 + accelerationCar2) / 2; //calculates the average acceleration of the two cars
  timeDifference = timeCar1 - timeCar2; //calculates the time difference between Car 1 and Car 2
  
  printf("Time for Car 1 to finish the race: %8.2f", timeCar1);
  printf(" seconds\n");
  printf("Time for Car 2 to finish the race: %8.2f", timeCar2);
  printf(" seconds\n");
  printf("Average acceleration: %21.2f", averageAcceleration);
  printf(" ft/s^2\n");
  printf("Time difference (Car 1 - Car 2): %10.2f", timeDifference);
  printf(" seconds\n");
 
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"); 
  return(0); 
}
