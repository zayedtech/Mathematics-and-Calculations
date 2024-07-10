/*****+***-*------*---*------*-**-*-----***---*--***************************
 *
 *  Lab #10:
 *
 *  Academic Integrity Statement:
 *
 *  We have not used source code obtained from any other unauthorized source,
 *  either modified or unmodified.  Neither have we provided access to our code
 *  to another. The effort we are submitting is our own original work.
 *
 *  Program Description: Given a user input seed, the program randomizes a data set of 15 integers and rearranges them largest to smallest based on   user choice of odd or even, then finds difference between the terms.
 *
 ******+***-*------*---*------*-**-*-----***---*--**************************/
#include <math.h> 
#include <stdio.h> 
#include <stdlib.h>
#define MIN 0
#define MAX 999999999
#define ARRAYSIZE 15

int getRandom(int);
int getInput(int*);
void formArray(long long [], int);
void even(long long[]);
void odd(long long[]);
void getOutput1(long long [], int);

int main (void)
{ 
  int seed; //User input seed value
  int i; //User input choice for odd or even
  long long array[ARRAYSIZE]; //Created array using randomized integers

  seed = getInput(&i);
  srand(seed);
  formArray(array, seed);
  
  if(i == 1)
  {
    odd(array);
    getOutput1(array, i);
  }
  else
  {
    even(array);
    getOutput1(array, i);
  }

  return(0);
}

/*****+*-*--***-***-***-**--*-**-**----**-**--*--***************************
*
*  Function Information
*
*  Name of Function: getInput
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int *i - User input choice for odd or even
*
*  Function Description: Receives and stores user input values for seed and choice for odd or even
*
******+*-*--***-***-***-**--*-**-**----**-**--*--**************************/

int getInput(int *i)
{
  int seed; //User input seed value

  do
  {
    printf("Enter desired seed value -> ");
    scanf("%d", &seed);
    if (seed < 0)
    {
      printf("\nError! Seed value must be non-negative!\n\n");
    }
  }while (seed < 0);

  do 
  {
    printf("Enter (1) for odd (2) for even -> ");
    scanf("%d", i);

    if (*i != 1 && *i != 2)
    {
      printf("\nError! Option must be 1 or 2.\n\n");
    }
  }while(*i != 1 && *i != 2);

  return seed;
}

/*****+*-*--***-***-***-**--*-**-**----**-**--*--***************************
*
*  Function Information
*
*  Name of Function: formArray
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. long long x[] - created array of 15 values
*    2. int seed - user input seed value
*
*  Function Description: Using random integers, creates a data set of 15 values
*
******+*-*--***-***-***-**--*-**-**----**-**--*--**************************/
void formArray(long long x[], int seed)
{
  int i; //Loop variable

  for(i = 0; i < ARRAYSIZE; i++) //Finds random values for array
  {
    x[i] = rand() % (MAX  - MIN + 1);
  }
}

/*****+*-**--**-***-***-**--*-**-**----**-**--*--***************************
*
*  Function Information
*
*  Name of Function: even
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. long long x[] - created array with randomized values
*
*  Function Description: Sorts through each value within the array, sorting the individual integers to only contain even numbers and be in order of   largest to smallest
*
******+*-**--**-***-***-**--*-**-**----**-**--*--**************************/
void even(long long x[]) 
{
  int i; //Loop variable
  int temp; //Individual values within array
  int subI; //Loop variable
  int subII; //Loop variable
  int max; //Rearranged value

  for(i = 0; i < ARRAYSIZE; i++)
  {
    max = 0;
    for(subI = 0; subI <= 4; subI++)
    {
      temp = x[i];
      for(subII = 0; temp > 0; subII++)
      {
        if(temp % 10 == (8 - 2 * subI))
        {
          max = max * 10 + temp % 10;
          temp = temp / 10;
        }
        else
        {
          temp = temp / 10;
        }
      }  
    }
    x[i] = max;
  }
}

/*****+***---**-***-***-**--*-**-**----**-**--*--***************************
*
*  Function Information
*
*  Name of Function: odd
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. long long x[] - array created with randomized integers
*
*  Function Description: Sorts through each individual value within the array, sorting said value from largest to smallest and only including odd umbers
*
******+***---**-***-***-**--*-**-**----**-**--*--**************************/
void odd(long long x[])
{
  int i; //Loop variable
  int temp; //Individual values within array
  int subI; //Loop variable
  int subII; //Loop variable
  int max; //Rearranged value 

  for(i = 0; i < ARRAYSIZE; i++) 
  {
    max = 0;
    for(subI = 0; subI <= 4; subI++) 
    {
      temp = x[i];
      for(subII = 0; temp > 0; subII++)
      {
        if(temp % 10 == (9 - 2 * subI))
        {
          max = max * 10 + temp % 10;
          temp = temp / 10;
        }
        else
        {
          temp = temp / 10;
        }
      }
    }
    x[i] = max;
  }
}

/*****+****-**--***-***-**--*-**-**----**-**--*--***************************
*
*  Function Information
*
*  Name of Function: getOutput1
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. long long x[] - array created with randomized integers
*    2. int evenOrOdd - 
*
*  Function Description: Prints out rearranged array, giving the differences between the values.
*
******+****-**--***-***-**--*-**-**----**-**--*--**************************/
void getOutput1(long long x[], int evenOrOdd)
{
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Data values ( 1- 5): %9lld %9lld %9lld %9lld %9lld \n", x[0], x[1], x[2], x[3], x[4]);
  printf("Data values ( 6-10): %9lld %9lld %9lld %9lld %9lld \n", x[5], x[6], x[7], x[8], x[9]);
  printf("Data values (11-15): %9lld %9lld %9lld %9lld %9lld \n", x[10], x[11], x[12], x[13], x[14]);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Difference values ( 1- 5): %9d %9d %9d %9d %9d\n", abs(x[1] - x[0]), abs(x[2] - x[1]), abs(x[3] - x[2]), abs(x[4] - x[3]), abs(x[5] - x[4]));
  printf("Difference values ( 6-10): %9d %9d %9d %9d %9d\n", abs(x[6] - x[5]), abs(x[7] - x[6]), abs(x[8] - x[7]), abs(x[9] - x[8]), abs(x[10] - x[9]));
  printf("Difference values (11-15): %9d %9d %9d %9d %9d\n", abs(x[11] - x[10]), abs(x[12] - x[11]), abs(x[13] - x[12]), abs(x[14] - x[13]), abs(x[14] - x[0]));
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
}

