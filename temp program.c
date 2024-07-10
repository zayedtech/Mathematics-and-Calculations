/*****+***-*--**--***--*--*-*-**-**-*--*---**-*--***************************
*
*  Homework #:
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Program Description:
*
******+***-*--**--***--*--*-*-**-**-*--*---**-*--**************************/

#include<stdio.h>
#include<math.h>

#define CONSTANT 35.74
#define COEFFT 0.6215
#define COEFFV -35.75
#define EXPONENTV 0.16
#define COEFFTV 0.4275
#define CONVERSIONFACTOR 1.609344

int main(void) 
{
  int unit; // stores user's input in 'unit'. User will enter either 1 or 2
  int fConversion = 70; //ASCII table "F" in dec
  int cConversion = 67; //ASCII table "C" in dec
  int mConversion = 109; //ASCII table "m" in dec
  int kConversion = 107; //ASCII table "k" in dec
//////////  int plusConversion = 43; // ASCII table "+" in dec
  double temp; // temperature that the user enters
  double windSpeed; // wind speed that the user enters
  double tempInFarenheit; // temperature in Farenheit
  double windSpeedMPH; // wind speed in mph
  double usWindChill; // wind chill in farenheit
  double siWindChill; // wind chill in celsius

  printf("Enter 1 for US units, 2 for SI -> ");
  scanf("%d", &unit);
  unit--; // decrements unit by 1

  printf("Enter temperature (\302\260%c) -> ", fConversion * (1 - unit) + cConversion *  unit);
  scanf("%lf", &temp);

  tempInFarenheit = temp * (1 - unit) + (1.8 * temp + 32) * unit; // this will give the temperature in farenheit regardless of user choice of US or SI

  printf("Enter wind speed (%cph) -> ", mConversion * (1 - unit) + kConversion * unit );
  scanf("%lf", &windSpeed);

  windSpeedMPH = windSpeed * (1 - unit) + (windSpeed / CONVERSIONFACTOR * unit); // will give wind speed in mph regardless of user choice of US or SI

  printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=\n");
  printf("Temperature: %+8.1lf \302\260F\n", tempInFarenheit);
  printf("Wind speed: %9.1lf mph\n", windSpeedMPH );

  usWindChill = CONSTANT + COEFFT * tempInFarenheit + COEFFV * pow(windSpeedMPH, EXPONENTV) + COEFFTV * tempInFarenheit * pow(windSpeedMPH, EXPONENTV);
  //will give wind chill in farenheit regardless of user's choice of US or SI
  printf("US wind chill: %+6.1lf \302\260F\n", usWindChill);

  siWindChill = (usWindChill - 32) / 1.8; // will convert wind chill from farenheit to celsius
  printf("SI wind chill: %+6.1lf \302\260C\n", siWindChill);

  printf("=-=-=-=-=-=-=-=-=-=-=-=-=\n");

  return(0);
}
