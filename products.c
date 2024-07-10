/*****+*-**-***-***--*--**----**-*-----**-**--*--***************************
 *
 *  Lab #: 11
 *
 *  Academic Integrity Statement:
 *
 *  We have not used source code obtained from any other unauthorized source,
 *  either modified or unmodified.  Neither have we provided access to our code
 *  to another. The effort we are submitting is our own original work.
 *
 *  Program Description: Given a data set of randomized numbers, creates a data set 20 prime numbers. Then, calculates and displays the products of neighboring elements.
 *
 ******+*-**-***-***--*--**----**-*-----**-**--*--**************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MIN 1
#define MAX 1000
#define ARRAYSIZE 20

int getInput(void);
void fillArray(long long[]);
void updateArray(long long[]);
void perfectSquares(long long[]);
void ListOutput(long long[]);

int main(void) 
{
  int seed; //User input seed value
  long long array[ARRAYSIZE]; // Array of size 20

  seed = getInput();
  srand(seed);
  fillArray(array);
  updateArray(array);
  ListOutput(array);
  perfectSquares(array);

  return(0);
}

/*****+*-**-***-***-***--*----**-*-----**-**--*--***************************
*
*  Function Information
*
*  Name of Function: getInput
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. void
*
*  Function Description: Returns user input seed value
*
******+*-**-***-***-***--*----**-*-----**-**--*--**************************/
int getInput(void)
{
  int seed; //User input seed value

  do
  {
    printf("Enter desired seed value -> ");
    scanf("%d", &seed);
    if (seed <= 0)
    {
      printf("\nError! Enter a positive integer.\n\n");
    }
  }while (seed <= 0);
  return(seed);
}

/*****+*-**-***-***-***--*----**-*-----**-**--*--***************************
*
*  Function Information
*
*  Name of Function: fillArray
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. long long array[] - blank array of size 20
*
*  Function Description: Fills array with randomized prime numbers
*
******+*-**-***-***-***--*----**-*-----**-**--*--**************************/
void fillArray(long long array[])
{
  int i; //loop control variable
  int j; //loop control variable

  for (i = 0; i < ARRAYSIZE; i++)
  {
    array[i] = rand() % (MAX - MIN + 1) + MIN;
    for(j = 2; j <= sqrt(array[i]); j++)
    {
      if(array[i] % j == 0) 
      {
        array[i] = rand() % (MAX - MIN + 1) + MIN;
        j = 1;
      }
    }
  }
}

/*****+*-**-***-***-***--*----**-*-----**-**--*--***************************
*
*  Function Information
*
*  Name of Function: updateArray
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. long long array[] - array of size 20 filled with prime numbers
*
*  Function Description: Multiplies each value within the data set by the one adjacent to it
*
******+*-**-***-***-***--*----**-*-----**-**--*--**************************/
void updateArray(long long array[])
{
  int i; //loop control variable
  long long x; //Placeholder for array[0]

  x = array[0];

  for(i = 0; i < ARRAYSIZE - 1; i++)
  {
    array[i] *= array[i+1];
  }
  array[19] *= x;
}

/*****+*-**-***-***-***--*----**-*-----**-**--*--***************************
*
*  Function Information
*
*  Name of Function: perfectSquares
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. long long array[] - Array filled with products of randomized prime numbers
*
*  Function Description: Finds the perfect squares within the array and prints them
*
******+*-**-***-***-***--*----**-*-----**-**--*--**************************/
void perfectSquares(long long array[]) 
{
  int i; //loop control variable
  int count = 0; // counts number of perfect squares

  printf("\nPerfect squares:");
  for(i = 0; i < ARRAYSIZE; i++)
  {
    if(sqrt(array[i])  == (int)sqrt(array[i]))
    {
      printf(" %lld", array[i]);
      count++;
    }
  }
  if(count == 0)
  {
    printf(" None.");
  }
}

/*****+***--***-***-***--*----**-*-----**-**--*--***************************
*
*  Function Information
*
*  Name of Function: ListOutput
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. long long x[] - Array filled with products of randomized prime numbers
*
*  Function Description: Prints the array in an orderly fashion 
*
******+***--***-***-***--*----**-*-----**-**--*--**************************/
void ListOutput(long long x[])
{
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Semiprime values ( 1- 5): %7lld %7lld %7lld %7lld %7lld \n", x[0], x[1], x[2], x[3], x[4]);
  printf("Semiprime values ( 6-10): %7lld %7lld %7lld %7lld %7lld \n", x[5], x[6], x[7], x[8], x[9]);
  printf("Semiprime values (11-15): %7lld %7lld %7lld %7lld %7lld \n", x[10], x[11], x[12], x[13], x[14]);
  printf("Semiprime values (16-20): %7lld %7lld %7lld %7lld %7lld \n", x[15], x[16], x[17], x[18], x[19]);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
}

