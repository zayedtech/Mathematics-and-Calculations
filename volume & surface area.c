/*****+*-*-**--**--*---*--*---*****---**---**-*--***************************
*
*  Lab #: 01
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Program Description: Calculate volume and surface area given the radius of the sphere.
*
******+*-*-**--**--*---*--*---*****---**---**-*--**************************/
#include<stdio.h>
#define PI 3.1416

int main (void)
{
  float radius;  //radius of the sphere
  float volumeSphere; //define volume of the sphere
  float surfaceAreaSphere; //define the surface area of the sphere
  float volHemisphere; //volume of the hemisphere
  float surfaceAreaHemis; // surface area of the hemisphere

  printf("Enter the radius of the sphere -> "); //Get radius of the sphere
  scanf("%f",&radius); // make the radius input a variable

  printf(" \n"); //print empty line
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"); 

  volumeSphere = 4 * PI * radius * radius * radius / 3; //calculate volume of a sphere
  surfaceAreaSphere = 4 * PI * radius * radius; // calculate surface area of sphere
  volHemisphere = 2 * PI * radius * radius * radius / 3; //calculate volume of hemisphere
  surfaceAreaHemis = 3 * PI * radius * radius; //calculate surface area of hemisphere

  printf("Radius: %.2f\n", radius);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Volume of the sphere: %.2f\n", volumeSphere);
  printf("Surface area of the sphere: %.2f\n", surfaceAreaSphere);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Volume of the hemisphere: %.2f\n", volHemisphere);
  printf("Surface area of the hemisphere: %.2f\n", surfaceAreaHemis);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  return(0);  
}
