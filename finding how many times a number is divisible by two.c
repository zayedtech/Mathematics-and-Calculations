/*****+**--*--*-*-*----*--****-*--*---***-**--*--***************************
*
*  Lab #: 08
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Program Description: This program accepts a seed number from the user, generates a random value from this seed, and finds how many times it can divide by two.
*
******+**--*--*-*-*----*--****-*--*---***-**--*--**************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MIN 1
#define MAX 100000

//Function Declarations
int getInput(void);
int randomize(int);
void factorsTwo(int, int*, int*);
void printOutput(int, int, int);
void noFactors(int);

int main(void)
{
//Local Declarations
  int seed; //user's desired seed value
  int value; //randomly generated value from the seed
  int counter; //number of two factors within the random number
  int lastFactor; //last factor of the random number

//Executable Statements
  seed = getInput();
  value = randomize(seed);
  factorsTwo(value, &counter, &lastFactor);
  printOutput(value, counter, lastFactor);
  noFactors(value);

  return 0;
}

/*****+**--**-*-*------*--****-*--*---***-**--*--***************************
*
*  Function Information
*
*  Name of Function: getInput
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line): N/A
*
*  Function Description: This function gets the input of the user's seed and checks to see if it is a valid number.
*
******+**--**-*-*------*--****-*--*---***-**--*--**************************/
int getInput() 
{
  int seed; //user's desired seed value

  printf("Enter desired seed value -> ");
  scanf("%d", &seed);

  while(seed < 0)
  {
    printf("\nSeed value must be non-negative!\n");
    printf("\nEnter desired seed value -> ");
    scanf("%d", &seed);
  }

  return(seed);
}

/*****+*-****-**--**---*--*-*--*-**---***-**--*--***************************
*
*  Function Information
*
*  Name of Function: randomize
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int seed - the value that the user inputs and is used to generate a random number
*
*  Function Description: This program randomizes the seed number that the user provides. 
*
******+*-****-**--**---*--*-*--*-**---***-**--*--**************************/
int randomize(int seed)
{
  int randomNum; //generates a random number within the given seed

  srand(seed);
  randomNum = rand();

  return(randomNum % (MAX - MIN + 1) + MIN);
}

/*****+***-*---**-**---*--*-*--*-**---***-**--*--***************************
*
*  Function Information
*
*  Name of Function: factorsTwo
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int value - this is the value randomly generated from the seed
*    2. int *counter - it is passed by address and is used to count the number of times value is divisible by two
*    3. int *lastFactor - it is passed by adress and used to store the value of the last factor other than 2 in value
*
*  Function Description: This program checks to see whether or not the randomized value is divisible by two. If so, it will count how many times the number can divide by two. 
*
******+***-*---**-**---*--*-*--*-**---***-**--*--**************************/
void factorsTwo(int value, int *counter, int *lastFactor)
{
  int valTemp; //temporary value for the value

  if (value % 2 == 0) 
  {
    *counter = 0;
    valTemp = value;

    while (valTemp % 2 == 0)
    {
      *counter += 1;
      valTemp = (float)valTemp / 2;    
    }

    *lastFactor = value / pow(2, *counter);
  }
}

/*****+*-*-**--**-**---*--*-*--*-**---***-**--*--***************************
*
*  Function Information
*
*  Name of Function: printOutput
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int value - It is the randomly generated number from the seed
*    2. int counter - Counter is the number of times 2 is a factor of the randomly generated value
*    3. int lastFactor - It is the last factor number other than 2
*
*  Function Description: This function prints out the factors of two for the value and the number of two factors counted.
*
******+*-*-**--**-**---*--*-*--*-**---***-**--*--**************************/
void printOutput(int value, int counter, int lastFactor)
{
  int tempCount; //temporary count for the loop

  if (value % 2 == 0)
  { 
    tempCount = counter;  
    printf("\nFactors of 2 for value %d: ", value);

    while(tempCount > 0)
    {
      printf("2 * ");
      tempCount -= 1;
    }

    printf("%d\n", lastFactor);
    printf("Number of two factors: %d\n", counter);
  }
}

/*****+*-****--**-**---*--*-*--*-**---***-**--*--***************************
*
*  Function Information
*
*  Name of Function: noFactors
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int value - It is the randomly generated number from the seed
*
*  Function Description: This function prints the statement in case the value is not divisible by two.
*
******+*-****--**-**---*--*-*--*-**---***-**--*--**************************/
void noFactors(int value)
{
  if (value % 2 != 0)
  {
    printf("\nThe following value has no two factors: %d\n", value);
  }
}

