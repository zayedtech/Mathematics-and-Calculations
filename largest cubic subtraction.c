/*****+****-**---*--***-**-----*-**-*-**--**--*--***************************
 *
 *  Lab #: 11
 *
 *  Academic Integrity Statement:
 *
 *  We have not used source code obtained from any other unauthorized source,
 *  either modified or unmodified.  Neither have we provided access to our code
 *  to another. The effort we are submitting is our own original work.
 *
 *  Program Description: Given a user input seed value, program creates a data set of desired size with randomized numbers, uses cube subtraction until each number equals 0, displaying the largest cube subtraction counts
 *
 ******+****-**---*--***-**-----*-**-*-**--**--*--**************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MIN 1
#define MAX 1000000

int getInput(void);
int getArraySize(void);
void getData(int*, int);
int countNums(int*, int, int *);
void fillCubes(int*,int*, int, int);
void getOutput(int [], int, int);

int main(void) 
{
  int seed; //User input seed value
  int arraySize; //User input array size
  int *data; //Array of random numbers
  int *cubeArray; //array for the cubed numbers
  int max; //Max number in array
  int countNumbers; //Number of digits within a number

// function calls
  seed = getInput();
  srand(seed);
  arraySize = getArraySize();

  data = (int*)malloc(sizeof(int) * arraySize);
  getData(data, arraySize);
  countNumbers = countNums(data, arraySize, &max);
  cubeArray = (int*)malloc(sizeof(int) * countNumbers);
  fillCubes(data, cubeArray, max, arraySize);
  getOutput(cubeArray, countNumbers, max);

  return 0;
}

/*****+*-*--***-**--***--**-*-*****---**--**--*--***************************
*
*  Function Information
*
*  Name of Function: getInput
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. None
*
*  Function Description: Scans and returns user-input seed value
*
******+*-*--***-**--***--**-*-*****---**--**--*--**************************/
int getInput(void)
{
  int seed; //User input seed value

  do
  {
    printf("Enter the desired seed value -> ");
    scanf("%d", &seed);
    if (seed <= 0)
    {
      printf("\nSeed must be a positive value!\n\n");
    }
  }while (seed <= 0);
  return(seed);
}

/*****+****--**-**--***--**-*-*****---**--**--*--***************************
*
*  Function Information
*
*  Name of Function: getArraySize
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. None
*
*  Function Description: Scans and returns user-input array size
*
******+****--**-**--***--**-*-*****---**--**--*--**************************/
int getArraySize(void)
{
  int arraySize; //User input of array size

  do
  {
    printf("Enter the desired size of the data set -> ");
    scanf("%d", &arraySize);
    if (arraySize <= 0)
    {
      printf("\nSize must be a positive value!\n\n");
    }
  }while (arraySize <= 0);

  return(arraySize);
}

/*****+***---**-**--***--**-*-*****---**--**--*--***************************
*
*  Function Information
*
*  Name of Function: getData
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int *data - Randomized data set recieved via user-input seed
*    2. int arraySize - User input size of the array
*
*  Function Description: Takes data and fills an array with the randomized values 
*
******+***---**-**--***--**-*-*****---**--**--*--**************************/
void getData(int *data, int arraySize)
{
  int i; //Loop variable

  for (i = 0; i < arraySize; i++)
  {
    data[i] = rand() % (MAX - MIN + 1) + MIN;
  }
}

/*****+****-**--**--***--**-*-*****---**--**--*--***************************
*
*  Function Information
*
*  Name of Function: countNums
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int arr[] - randomized array of data
*    2. int arraySize - user-input array size
*    3. int *max - max number of times an array can be cube subtracted
*
*  Function Description: this function counts the number of elements that have a maximum number of and returns it. for example, if the maximum number of cubic subtractions is
6, the function will return how many numbers have a cubic subtractions of 6. finally, the function stores the elements in a new array of a defined size.
*
******+****-**--**--***--**-*-*****---**--**--*--**************************/
int countNums(int arr[], int arraySize, int *max)
{
  int *array; //Array of randomized numbers 
  int i; //loop variable 
  int j; //loop variable
  int count; //Counts number of times number can be cube subtracted
  int countNumbers; //counts number of digits within a number

  *max = 0;
  array = malloc(arraySize * sizeof(int));

  count = 0;
  countNumbers = 0;
  for(i = 0; i < arraySize; i++)
  {
    array[i] = arr[i];
  }

  for(i = 0; i < arraySize; i++)
  {
    for(j = (int)cbrt(array[i]); array[i]; j--)
    {
      array[i] -= pow(j, 3);
      count++;
      j = (int)cbrt(array[i]) + 1;
    }

    if(count > *max)
    {
      *max = count;
      count = 0;
    }
    else
    {
      count = 0;
    }
  }

  for(i = 0; i < arraySize; i++)
  {
    array[i] = arr[i];
  }
  
  count = 0;

  for(i = 0; i < arraySize; i++)
  {
    for(j = (int)cbrt(array[i]); array[i]; j--)
    {
      array[i] -= pow(j, 3);
      count++;
      j = (int)cbrt(array[i]) + 1;
    }

    if(count == *max) 
    {
      countNumbers++;
      count = 0;
    }
    else
    {
      count = 0;
    }
  }
  
  return countNumbers;
}

/*****+*-**--*--**--***--**-*-*****---**--**--*--***************************
*
*  Function Information
*
*  Name of Function: fillCubes
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int arr[] - array of randomized data
*    2. int *cubeArray - array containing the values received after cube subtraction
*    3. int max - 
*    4. int arraySize - user-input array size 
*
*  Function Description: Fills empty cube array with values received via cube subtraction of the original number from the data array
*
******+*-**--*--**--***--**-*-*****---**--**--*--**************************/
void fillCubes(int arr[], int *cubeArray, int max, int arraySize)
{
  int *array; //Array of randomized numbers 
  int i; // loop variable
  int j; // loop variable
  int count = 0; //count of amount of digits in a number
  int cubeArrayCounter = 0; //counts number of values in array
  
  array = malloc(arraySize * sizeof(int)); 

  for(i = 0; i < arraySize; i++)
  {
    array[i] = arr[i];
  }

  for(i = 0; i < arraySize; i++)
  {
    for(j = (int)cbrt(array[i]); array[i]; j--)
    {
      array[i] -= pow(j, 3);
      count++;
      j = (int)cbrt(array[i]) + 1;
    }

    if(count == max)
    {
      cubeArray[cubeArrayCounter] = arr[i];
      count = 0;
      cubeArrayCounter++;
    }
    else
    {
      count = 0;
    }
  }
}

/*****+*-*---*--**--***--**-*-*****---**--**--*--***************************
*
*  Function Information
*
*  Name of Function: getOutput
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int arr[] - randomized data array 
*    2. int count - Number of variables within the cube array
*    3. int max - Max number of cube subtractions one of the variables can achieve 
*
*  Function Description: Displays all of the output data
*
******+*-*---*--**--***--**-*-*****---**--**--*--**************************/
void getOutput(int arr[], int count, int max)
{
  int i; //loop variable
  int j; //loop variable

  printf("\nThe largest cube subtraction count: %d\n", max);

  for(i = 0; i < count; i++)
  {
    printf("Value %d: ", arr[i]);
    for(j = (int)cbrt(arr[i]); arr[i] ; j = (int)cbrt(arr[i]))
    {
      arr[i] -= pow(j, 3);
      if(arr[i] != 0)
      {
        printf("%d, ", arr[i]);
      }
      else
      {
        printf("%d", arr[i]);
      }
    }
    printf("\n");
  }
}
