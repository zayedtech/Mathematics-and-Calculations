/*****+-*----*--**--*---*-**--**--*-*--*---**-*--***************************
*
*  Lab #: 03
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Program Description: given input temp calculate speed of sound at that temp in both f and c. 
*
******+-*----*--**--*---*-**--**--*-*--*---**-*--**************************/
#include<stdio.h>
#include<math.h>
#define METERTOFEET 0.3048
int main(void)
{
  int unit; //deciding variable for F or C used in selection by calculation
  int scale; //the equation for selection by calculation used to display the primary unit selected by the user
  int scaleConv; //the equation for selection by calculation for the unit not selected by the user
  int speedUnit; // the equation for selection by calculation used to display the primary speed unit selected by the user
  int speedUnitConv; //the equation for selection by calculation for the speed unit not selected by the user
  double temp;  //temp input by user
  double celsiusToFahrenheit; //conversion equation for C to F
  double fahrenheitToCelsius; //conversion equation for F to C
  double tempConv; //the temp converted from input units into opposite units
  double speedSound; //speed of sound in m/s
  double speedSoundConv; // speed of sound in f/s

  printf("Enter 1 for \302\260F, 2 for \302\260C -> ");
  scanf("%d", &unit);
  scale = 70 * (1 - (unit - 1)) + 67 * (unit - 1);  //selection by calculation equation to display the unit selected by the input
  printf("Enter the temperature in \302\260%c -> ", scale); 
  scanf("%lf", &temp);

  celsiusToFahrenheit = temp * 1.8 + 32; //convert input temp into F if given in C
  fahrenheitToCelsius = (temp - 32) / 1.8; //convert input temp into C if given in F

  tempConv = celsiusToFahrenheit * ( (unit - 1)) + fahrenheitToCelsius * (1 - (unit - 1)); //converts the given temp into the opposite  // units
  printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

  speedSound = (20.0514 * sqrt(fahrenheitToCelsius + 273.15)) * (1 - (unit - 1)) + (20.0514 * sqrt(temp + 273.15)) * (unit - 1); //calculates speed of sound in m/s after converting the given input to C
  speedSoundConv = speedSound /  METERTOFEET; //converts speed of sound in m/s to f/s
  speedSound = speedSound * (unit - 1) + speedSoundConv * (1 - (unit - 1)); // assigns the correct speed of sound depending on the given units
  speedSoundConv = speedSound * METERTOFEET * (1 - (unit - 1)) + speedSoundConv  * (unit - 1); // assigns the correct speed of sound depending on the given units

  scaleConv = 67 * (1 - (unit - 1)) + 70 * (unit - 1); //gives opposite letter depending on input unit
  speedUnit =  102 * (1 - (unit - 1)) + 109 * (unit - 1); //gives either f or m for print statement 
  speedUnitConv = 109 * (1 - (unit - 1)) + 102 * (unit - 1); //gives opposite letter f or m

  printf("Temperature: %7.2lf \302\260%c %9.2lf \302\260%c\n", temp, scale, tempConv, scaleConv ); 
  printf("Speed:  %12.2lf %c/s  %7.2lf %c/s\n", speedSound, speedUnit, speedSoundConv, speedUnitConv);
  printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

  return(0);

}
