/*****+******-***--*---*----*--****---**--**--*--***************************
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
 ******+******-***--*---*----*--****---**--**--*--**************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ARRSIZE 1000
#define DOMVALARRAYSIZE 10

// functions declaration
int getSeed(void);
int getMin(void);
int getMax(int);
void fillArray(int[], int, int);
int countNumbers(int);
void findDomValDig(int[], int[]);
void getOutput1(int[]);
int findArraySize(int[], int *);
void fillArrayIndex(int[], int[], int);
void fillNewArray(int[], int[], int[], int);
void getOutput2(int[], int);

int main(void)
{
  int seed; // stores the seed number entered by the user
  int minimum; // stores the minimum number entered by the user
  int maximum; // stores the maximum number entered by the user
  int data[ARRSIZE]; // an array to store the 1000 randomly found elements
  int domValDigit[DOMVALARRAYSIZE] = {0}; // an array to store the counts of each dominant number by index. for example, if the first element in this array is 5, this means there are five numbers with zero as a dominant number
  int arraySizeDom; // an integer that stores the size of the total number of dominant numbers
  int *dominantValues; // a pointer that will store the dominant numbers 
  int count; // counts how many digits account for the largest dominant numbers in a data set. E.g in execution #4, count will be 6 because there are six digits that account for the largest set of dominant numbers
  int *arrayIndex; // a pointer that will store the digits of the dominant numbers

  //function calls
  seed = getSeed(); 
  minimum = getMin();
  maximum = getMax(minimum);

  srand(seed);

  fillArray(data, minimum, maximum);

  findDomValDig(data, domValDigit);

  getOutput1(domValDigit);

  arraySizeDom = findArraySize(domValDigit, &count);
  dominantValues = (int*)malloc(arraySizeDom * sizeof(int));
  arrayIndex = (int*)malloc(count * sizeof(int));
  fillArrayIndex(domValDigit, arrayIndex, (arraySizeDom / count));
  fillNewArray(data, dominantValues, arrayIndex, count); 
  getOutput2(dominantValues, arraySizeDom);

  return 0;
}
/*****+******--*---*---*----*--****---**--**--*--***************************
 *
 *  Function Information
 *
 *  Name of Function: getSeed
 *
 *  Function Return Type: int
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1.none
 *    2.
 *    3.
 *
 *  Function Description: this function asks the user to enter a seed value while also validating input
 *
 ******+******--*---*---*----*--****---**--**--*--**************************/
int getSeed(void)
{
  int seed; //User input seed value

  do
  {
    printf("Enter desired seed value -> ");
    scanf("%d", &seed);
    if (seed <= 0)
    {
      printf("\nError! Seed value must be positive!\n\n");
    }
  }while (seed <= 0);
  return(seed);
}
/*****+******--*---*---*----*--****---**--**--*--***************************
 *
 *  Function Information
 *
 *  Name of Function: getMin
 i*
 *  Function Return Type:int
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1.none
 *    2.
 *    3.
 *
 *  Function Description: this function asks the user to enter the minimum value while also validating the input
 *
 ******+******--*---*---*----*--****---**--**--*--**************************/

int getMin(void)
{
  int min; //User input min value

  do
  {
    printf("Enter desired minimum range value -> ");
    scanf("%d", &min);
    if (min <= 0)
    {
      printf("\nError! Minimum range value must be positive!\n\n");
    }
  }while (min <= 0);
  return(min);
}
/*****+******--*---*---*----*--****---**--**--*--***************************
 *
 *  Function Information
 *
 *  Name of Function: getMax
 *
 *  Function Return Type: int
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int min- this is the number the user entered in the previous function
 *    2.
 *    3.
 *
 *  Function Description: this function asks the user to enter the maximum value while also validating that it is greater than the minimum.
 *
 ******+******--*---*---*----*--****---**--**--*--**************************/

int getMax(int min)
{
  int max; //User input max value

  do
  {
    printf("Enter desired maximum range value -> ");
    scanf("%d", &max);
    if (max <= min)
    {
      printf("\nError! Maximum range value must be greater than minimum range value of %d!\n\n", min);
    }
  }while (max <= min);
  return(max);
}
/*****+******--*---*---*----*--****---**--**--*--***************************
 *
 *  Function Information
 *
 *  Name of Function: fillArray
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1.int array[] - array to be filled with random number
 *    2.int min - minimum number entered by the user 
 *    3.int max - maximum number entered by the user
 *
 *  Function Description: this function fills out the array with random numbers between min and max inclusive
 *
 ******+******--*---*---*----*--****---**--**--*--**************************/

void fillArray(int array[], int min, int max) 
{
  int i; // counter for loop

  for(i = 0; i < ARRSIZE; i++)
  {
    array[i] = rand() % (max - min + 1) + min;
  }
}
/*****+*-***---*---*---*----*--****---**--**--*--***************************
 *
 *  Function Information
 *
 *  Name of Function: findDomValDig
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1.int array[] - this is the array that is filled with random numbers
 *    2. int domValDig[] - this array is the array that will store the dominant values by digits
 *    3.
 *
 *  Function Description: this function stores the dominant values by digits by testing each element in the array[] array. 
 *
 ******+*-***---*---*---*----*--****---**--**--*--**************************/

void findDomValDig(int array[], int domValDig[])
{
  int i; // counter for loop
  int temp; // temporarily stores the value of an array
  int numberOfDigits; // number of digits in a number

  int countzero; // counts how many zeros are in a number
  int countone; // counts how many ones in a number
  int counttwo; // counts how many twos in a number
  int countthree; // counts how many threes in a number
  int countfour; // counts how many fours in a number
  int countfive; // counts how many fives in a number
  int countsix; // counts how many sixes in a number
  int countseven; // counts how many sevens in a number
  int counteight; // counts how many eights in a number
  int countnine; // counts how many nines in a number

  for(i = 0; i < ARRSIZE; i++)
  {
    countzero = 0;
    countone = 0;
    counttwo = 0;
    countthree = 0;
    countfour = 0;
    countfive = 0;
    countsix = 0;
    countseven = 0;
    counteight = 0;
    countnine = 0;
    numberOfDigits = countNumbers(array[i]); 
    temp = array[i];
    while(temp > 0)
    {
      if(temp % 10 == 0)
      {
        countzero++;
        temp /= 10;
      }

      else if(temp % 10 == 1)
      {
        countone++;
        temp /= 10;
      }

      else if(temp % 10 == 2)
      {
        counttwo++;
        temp /= 10;
      }

      else if(temp % 10 == 3)
      {
        countthree++;
        temp /= 10;
      }

      else if(temp % 10 == 4)
      {
        countfour++;
        temp /= 10;
      }

      else if(temp % 10 == 5)
      {
        countfive++;
        temp /= 10;
      }

      else if(temp % 10 == 6)
      {
        countsix++;
        temp /= 10;
      }

      else if(temp % 10 == 7)
      {
        countseven++;
        temp /= 10;
      }

      else if(temp % 10 == 8)
      {
        counteight++;
        temp /= 10;
      }

      else
      {
        countnine++;
        temp /= 10;
      }
    }

    if(countzero > (numberOfDigits / 2))
    {
      domValDig[0]++;
    }
    if(countone > (numberOfDigits / 2))
    {
      domValDig[1]++;
    }
    if(counttwo > (numberOfDigits / 2))
    {
      domValDig[2]++;
    }
    if(countthree > (numberOfDigits / 2))
    {
      domValDig[3]++;
    }
    if(countfour > (numberOfDigits / 2))
    {
      domValDig[4]++;
    }
    if(countfive > (numberOfDigits / 2))
    {
      domValDig[5]++;
    }
    if(countsix > (numberOfDigits / 2))
    {
      domValDig[6]++;
    }
    if(countseven > (numberOfDigits / 2))
    {
      domValDig[7]++;
    }
    if(counteight > (numberOfDigits / 2))
    {
      domValDig[8]++;
    }
    if(countnine > (numberOfDigits / 2))
    {
      domValDig[9]++;
    }
  }
}
/*****+******--*---*---*----*--****---**--**--*--***************************
 *
 *  Function Information
 *
 *  Name of Function: countNumbers
 *
 *  Function Return Type: int
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int num- this is the number whose number of digits is to be found
 *    2.
 *    3.
 *
 *  Function Description: this function calculates the number of digits in the number passed
 *
 ******+******--*---*---*----*--****---**--**--*--**************************/

int countNumbers(int num)
{
  int count; // counts number of digits in a number

  count = 0;

  if(num == 0) 
  {
    count = 1;
  }

  while(num > 0) 
  {
    num /= 10;
    count++;
  }
  return count;
}
/*****+******--*---*---*----*--****---**--**--*--***************************
 *
 *  Function Information
 *
 *  Name of Function: getOutput1
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int arr[] - this is the array with the dominant values by digits
 *    2.
 *    3.
 *
 *  Function Description: this function prints out the first line of output which is the dominant values by digits
 *
 ******+******--*---*---*----*--****---**--**--*--**************************/

void getOutput1(int arr[])
{
  int i; // counter

  printf("\nDominant values by digit: ");
  for(i = 0; i < DOMVALARRAYSIZE; i++)
  {
    printf("%d ", arr[i]);
  }
}
/*****+*-****--*---*---*----*--****---**--**--*--***************************
 *
 *  Function Information
 *
 *  Name of Function: findArraySize
 *
 *  Function Return Type: int
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int arr[] - this is the array with dominant values by digits
 *    2. int *count - this will count how many dominant values by digits are there
 *    3.
 *
 *  Function Description: this function will return the array size by multiplying the number of times the maximum occured by the maximum.
 *
 ******+*-****--*---*---*----*--****---**--**--*--**************************/

int findArraySize(int arr[], int *count)
{
  int i; // inner loop couter
  int max = 0; //to find maximum number
  *count = 0; // to find how many times the maximum occurs

  for(i = 0; i < DOMVALARRAYSIZE; i++)
  {
    if(arr[i] > max)
    {
      max = arr[i];
    }
  }

  for(i = 0; i < DOMVALARRAYSIZE; i++)
  {
    if(arr[i] == max)
    {
      *count = *count + 1;
    }
  }

  return (max * *count);
}
/*****+*-****--*---*---*----*--****---**--**--*--***************************
 *
 *  Function Information
 *
 *  Name of Function: fillNewArray
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int arr[] - this is the array with the random numbers
 *    2. int arrNew[] - this is the array that will store the dominant numbers
 *    3. int arrayIndex[]- this is the array that has the dominant values themselves in a number
 4. int count - this is the number of times a dominant value has occured
 *
 *  Function Description: this function will store the dominant values in the array arrNew[] by checking if the numbers in arrIndex[] occured more than half the number of  digits in arr[]
 *
 ******+*-****--*---*---*----*--****---**--**--*--**************************/

void fillNewArray(int arr[], int arrNew[], int arrIndex[], int count)
{
  int i; // counter for inner loop
  int j; // counter for outer loop
  int temp; // stores the element of the array temporarily
  int numberOfNumber = 0; // counts how many times the given number is found in an arr element
  int numberOfDigits; // number of digits in a number
  int subI = 0; // counter for an array

  for(j = 0; j < count; j++) 
  {
    for(i = 0; i < ARRSIZE; i++)
    {
      numberOfDigits = countNumbers(arr[i]);
      temp = arr[i];
      while(temp > 0)
      {
        if(temp % 10 == arrIndex[j])
        {
          numberOfNumber++;
          temp /= 10;
        }
        else
        {
          temp /= 10;
        }
      }

      if(numberOfNumber > (numberOfDigits / 2))
      {
        arrNew[subI++] = arr[i];
      }
      numberOfNumber = 0;
    }
  }
}
/*****+*-****--*---*---*----*--****---**--**--*--***************************
 *
 *  Function Information
 *
 *  Name of Function: fillArrayIndex
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int arr[] - this is the array with dominant values by digits
 *    2. int arrIndex - this is the array that will store the dominant digits themselves 
 *    3. int max - this is the maximum number of in the dominant value by digit array
 *
 *  Function Description: this function will store the arrIndex[] with the actual dominant values
 *
 ******+*-****--*---*---*----*--****---**--**--*--**************************/

void fillArrayIndex(int arr[], int arrIndex[], int max)
{
  int i; // count for loop
  int j; // counts for array
  j = 0;

  for(i = 0; i < DOMVALARRAYSIZE; i++)
  {
    if(arr[i] == max)
    {
      arrIndex[j++] = i;
    }
  }
}
/*****+*-****--*---*---*----*--****---**--**--*--***************************
 *
 *  Function Information
 *
 *  Name of Function: getOutput2
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1.int arr[] - this is the array with dominant values
 *    2. int arraySize - this is the size of the array that stores the dominant values
 *    3.
 *
 *  Function Description: this function displays the results of the dominant values
 *
 ******+*-****--*---*---*----*--****---**--**--*--**************************/

void getOutput2(int arr[], int arraySize)
{
  int i; // counter
  int j; // counter
  int count = 0; // counts the number of times before it stops 

  printf("\n");
  for(i = 0; i < ceil(((double)arraySize / 5)); i++)
  {
    printf("Dominant values #%d:", i + 1);
    for(j = 0; j < 5; j++)
    {
      if(count != arraySize)
      {
        printf(" %d", arr[i * 5 + j]); 
        count++;
      }

    }
    printf("\n");
  }
}
