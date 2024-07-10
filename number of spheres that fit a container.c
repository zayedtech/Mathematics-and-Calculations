/*****+---*-***-***---*---**---**-----**---**-*--***************************
*
*  Lab #02:
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Program Description: Calculates number of spheres able to fit in shipping container using mass and volume.
*
******+---*-***-***---*---**---**-----**---**-*--**************************/
#include <stdio.h>
#include <math.h>
#define CONTAINERMASS 28280
#define CONTAINERVOL 33.1
#define KGTOG 1000
#define MTOCM 1000000

int main(void)
{
  double radius; // single sphere radius
  double density; // single sphere density
  double volume; // single sphere volume
  double mass; // single sphere mass
  int mass_max; // max number of spheres able to fit in container by mass
  int volume_max; // max number of spheres able to fit in container by volume

  printf("Enter sphere radius (cm) -> ");
  scanf("%lf", &radius); // user input single sphere radius
  printf("Enter sphere density (g/cm^3) -> ");
  scanf("%lf", &density); // user input single sphere density
  printf("\n");

  volume = (4 * M_PI * radius * radius * radius) / 3; // calculates the volume of the single sphere
  mass = volume * density; // calculates the mass of the single sphere
  volume_max = (CONTAINERVOL * M_PI * MTOCM) / (3 * sqrt(2) * volume); // calculates max number of spheres able to fit in container by volume
  mass_max = CONTAINERMASS * KGTOG / mass; // calculates max number of spheres able to fit in container by mass
  
  printf("=-= [Single sphere] =-=\n");
  printf("Volume: %11.2f cm^3\n", volume);
  printf("Mass: %13.2f g\n", mass);
  printf("=-= Maximum spheres =-=\n");
  printf("By volume limit: %6.d\n", volume_max);
  printf("By mass limit: %8.d\n", mass_max);
  return(0);
}
