/*****+******-***--*--***---*-**-*-----**-**--*--***************************
*
*  Homework #: 06
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Program Description: This program requests a non-negative number from a user and then prints out the results of its sign, exponent, significand, value
*
******+******-***--*--***---*-**-*-----**-**--*--**************************/

#include <stdio.h>
#include <math.h>

#define ARRAYSIZE 32

// functions declarations
long long getInput(void);
void fillArray(int[], long long);
void findSign(int [], int *);
int findExponent(int[]);
void findSigni(int [], float *);
void findValue(int, int, float);

int main(void) 
{

  long long rawValue; // value to store input from the user
  int bitsArray[ARRAYSIZE]; // array to store the binary digits of the decimal  number entered by a user
  int sign; // variable to store the sign of the value, 0 for positive and 1 for negative
  int exponent; // variable to store the exponent of the 
  float siginificand; // this variable stores the floating  of the significand

  //functions calls
  rawValue = getInput(); 
  fillArray(bitsArray, rawValue);
  findSign(bitsArray, &sign);
  exponent = findExponent(bitsArray);
  findSigni(bitsArray, &siginificand);
  findValue(sign, exponent, siginificand);

  return 0;
}
/*****+*****--***--*--***---*-**-*-----**-**--*--***************************
*
*  Function Information
*
*  Name of Function: getInput
*
*  Function Return Type: long long
*
*  Parameters (list data type, name, and comment one per line): none
*    1.
*    2.
*    3.
*
*  Function Description: this program requests a non-negative value from the user, while also taking into account input validation. It will display an error message to the user in case the number is not non-negative.
*
******+*****--***--*--***---*-**-*-----**-**--*--**************************/

long long getInput(void)
{
  long long rawValue; //value to be returned

  do 
  {
    printf("Enter raw value -> ");
    scanf("%lld", &rawValue);

    if(rawValue < 0)
    {
      printf("\nError! Raw value must be non-negative.\n\n");
    }

  } while(rawValue < 0);

  return (rawValue);
}

/*****+***-*--***--*--***---*-**-*-----**-**--*--***************************
*
*  Function Information
*
*  Name of Function: fillArray
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line): none
*    1.int array[] - this is the array to be filled with the binary digits of the number passed
*    2. long long rawVal - this is the number passed to store its binary digits in the array
*    3.
*
*  Function Description: the array takes an array and a number, performs calculations to store the binary digits of the number in the array
*
******+***-*--***--*--***---*-**-*-----**-**--*--**************************/

void fillArray(int array[], long long rawVal)
{
  int i; // used to go over the elements of the array

  for(i = 0; i < ARRAYSIZE; i++)
  {
    if((rawVal / (int) pow(2, i)) % 2  == 0)
    {
      array[i] = 0;
    }
    else
    {
      array[i] = 1;
    }
  }
}

/*****+***-**--**--*--***---*-**-*-----**-**--*--***************************
*
*  Function Information
*
*  Name of Function: findSign
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int array[] - this function takes the already filled array with binary digits 
*    2. int *sign - this variable is passed by address and stores the sign of the value as a number, 0 for positive and 1 for negative
*    3.
*
*  Function Description: this function finds the sign of the value by checking the last element in the array, if it is equal to zero, sign is positive, otherwise negative
*
******+***-**--**--*--***---*-**-*-----**-**--*--**************************/

void findSign(int array[], int *sign)
{

  if(array[ARRAYSIZE - 1] == 0)
  {
    printf("\nSign: 0 (+)\n");
    *sign = 0;
  }

  else
  {
    printf("\nSign: 1 (-)\n"); 
    *sign = 1;
  }

}
/*****+***-*---**--*--***---*-**-*-----**-**--*--***************************
*
*  Function Information
*
*  Name of Function: findExponent
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int array[] - this function takes the whole array that is filled with binary digits
*    2.
*    3.
*
*  Function Description: this function takes the whole array that hold the binary digits, and prints out the bits of the exponent(indices 30 to 23) while also accounting for spacing and returns the decimal value of the binary exponent
*
******+***-*---**--*--***---*-**-*-----**-**--*--**************************/

int findExponent(int array[])
{
  int i; // variable to go over the elements of the array
  int exponentDec = 0; // used to store the value of the exponent in Dec
  int countSpaces = 0; // used to count the number of times exponentDec is incremented, if 4 and multiples, it will add a space

  printf("Exponent: ");

  for(i = 30; i > 22; i--) 
  {
    printf("%d", array[i]);
    exponentDec += array[i] * (int) pow(2, i - 23);
    countSpaces++;

    if(!(countSpaces % 4) && countSpaces != 0)
    {
      printf(" ");
    }
  } 
  printf("(%d)", exponentDec);

  return(exponentDec);
}
/*****+*-****-**---*--***---*-**-*-----**-**--*--***************************
*
*  Function Information
*
*  Name of Function: findsigni
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int array[] - this function takes the array filled with binary digits
*    2. float *significandDec - passed by address to and stores the number that is calculated by adding the fractional powers
*    3.
*
*  Function Description: this function displays the significand binary digits while also accounting for spacing. It then stores the calculated value in *significand
*
******+*-****-**---*--***---*-**-*-----**-**--*--**************************/

void findSigni(int array[], float *significandDec)
{
  int i; // used to go over the elements of the array
  int countSpaces = 0; // used to count the number of times exponentDec is incremented, if 4 and multiples, it will add a space
  int count = 1; // used as an exponent that increments each iteration
  *significandDec = 0; // stores the number  calculated from the operations done

  printf("\nSignificand: ");

  for(i = 22; i >= 0; i--) 
  {
    printf("%d", array[i]);
    *significandDec += array[i] * (pow((2), -1 * count++));
    countSpaces++;

    if(!(countSpaces % 4) && countSpaces != 0)
    {
      printf(" ");
    }
  } 
}
/*****+*-***--**---*--***---*-**-*-----**-**--*--***************************
*
*  Function Information
*
*  Name of Function: findValue
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int sign - the sign of value, either 0 or 1
*    2. int exp - the decimal form of the binary exponent
*    3. float signi - the value that is calculated from the previous function
*
*  Function Description: this function uses the mentioned variables and uses a given formula to calculate the value. It will also display whether it is negative or positive
*
******+*-***--**---*--***---*-**-*-----**-**--*--**************************/

void findValue(int sign, int exp, float signi)
{
  float val; // stores the final value to be displayed

  val = (int) pow(-1, sign) * pow(2, exp - 127) * (1 + signi);
  printf("\nValue: %+.9g\n", val);

}
