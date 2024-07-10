/*****+*-****-**--***-**------****--*-***-**--*--***************************
 *
 *  Homework #: 04
 *
 *  Academic Integrity Statement:
 *
 *  I have not used source code obtained from any other unauthorized source, 
 *  either modified or unmodified.  Neither have I provided access to my code 
 *  to another. The effort I am submitting is my own original work.
 *
 *  Program Description: This program will return the day of the week on which the first day of that year falls on and what months Friday the 13th falls on given the year that the user inputs
 *
 ******+*-****-**--***-**------****--*-***-**--*--**************************/

#include<stdio.h>

int getInput(void); // Declaration of the function that gets the input from the user
int dayPreviousYear(int); // This function calculates the day of the last day in the previous year EX: 31st dec 2023
void getOutput1(int, int); // This function prints out the first line of output 
void dominalLetters(int, int, int *, int*); // This function takes 4 inputs. 2 by value and 2 by address and assigns value depending on if the year was a leap or not
void getOutput2(int, int); // This function prints out the second line of output
void getOutput3(int, int); // This function prints out the third line of output

int main(void) 
{
  int year; // will store the value that the user inputs
  int firstDayYear; // will store the day of the week as an integer. 1 = Monday , 2 = Tuesday, ..., 7 = Sunday
  int dec1; // will store the integer of the letter  of YDL
  int dec2; // will store the integer of the letter of 2YDL in case of leap year

  year = getInput(); //function calls
  firstDayYear = dayPreviousYear(year) + 1; // adds one to the previous day number to represent today
  getOutput1(year, firstDayYear); // calls function to print out the first output
  dominalLetters(firstDayYear, year, &dec1, &dec2); 
  getOutput2(dec1, dec2); // calls the function to print out the second statement
  getOutput3(dec1, dec2); // calls the function to print out the third statement

  return 0;
}
/*****+*-****-**---**-**--*-*--***--*-***-**--*--***************************
 *
 *  Function Information
 *
 *  Name of Function: getInput
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):none
 *    1.
 *    2.
 *    3.
 *
 *  Function Description: This function returns the year that the user inputs
 *
 ******+*-****-**---**-**--*-*--***--*-***-**--*--**************************/

int getInput(void) 
{
  int year; // This variable is used to temporarily store user input

  printf("Enter year -> ");
  scanf("%d", &year);

  return year;
}
/*****+*-*-**-**---**-**--*-*--***--*-***-**--*--***************************
 *
 *  Function Information
 *
 *  Name of Function: dayPreviousYear
 *
 *  Function Return Type: int
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int year - the value of year is used to determine the day on which (01 january year) falls
 *    2.
 *    3.
 *
 *  Function Description: Returns an int that represents the day of the last day in year - 1. For example, if year is 2024, the function will return
 an int from 0 - 6 that represents the day on which dec 31 2023 falls on with 0 being Sunday, 6 Saturday
 *
 ******+*-*-**-**---**-**--*-*--***--*-***-**--*--**************************/

int dayPreviousYear(int year)
{
  return(((year - 1) * 365 + ((year - 1) / 4) - ((year - 1) / 100) + ((year - 1) / 400)) % 7); // returns the day number of previous year

}
/*****+*-*-**--*---**-**--*-*--***--*-***-**--*--***************************
 *
 *  Function Information
 *
 *  Name of Function: dominalLetters
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1.int dayNum - this is the day as an integer on which the first day of year falls on. 1 Monday ... 7 Sunday
 *    2.int year - the year is used to determine if the year is a leap year or not
 *    3.int *dec1 - this variable is passed by address to store the YDL letter as an integer
 *    4.int *dec2 - this variable is passed by address to store 2YDL as an integer in case the year is a leap year
 *
 *  Function Description: The function checks first if the year is a leap year, if so, it will store the integer letter of YDL and 2YDL in dec1 and dec2 respectively.
 *  Otherwise, if it is not a leap year, it will store YDL to dec1 and 0 to dec2.
 *
 ******+*-*-**--*---**-**--*-*--***--*-***-**--*--**************************/

void dominalLetters(int dayNum, int year, int *dec1, int *dec2) 
{
  if ((year % 4 == 0 && !(year % 100 == 0)) || (year % 400 == 0)) // Checks if it is a leap year. If so, it will have YDL and 2YDL. If not, it will store 2YDL as 0
  {    

    if (dayNum == 1)
    {
      *dec1 = 71;
      *dec2 = 70;
    }

    else if (dayNum == 2)
    {
      *dec1 = 70;
      *dec2 = 69;
    }

    else if (dayNum == 3)
    {
      *dec1 = 69;
      *dec2 = 68;
    }

    else if (dayNum == 4)
    {
      *dec1 = 68;
      *dec2 = 67;
    }

    else if (dayNum == 5)
    {
      *dec1 = 67;
      *dec2 = 66;
    }

    else if (dayNum == 6)
    {
      *dec1 = 66;
      *dec2 = 65;
    }

    else
    { 
      *dec1 = 65;
      *dec2 = 71;
    }
  }
  else 
  {
    if (dayNum == 1)
    {
      *dec1 = 71;
      *dec2 = 0;
    }

    else if (dayNum == 2)
    {
      *dec1 = 70;
      *dec2 = 0;
    }

    else if(dayNum == 3)
    {
      *dec1 = 69;
      *dec2 = 0;
    }

    else if (dayNum == 4)
    {
      *dec1 = 68;
      *dec2 = 0;
    }

    else if (dayNum == 5)
    {
      *dec1 = 67;
      *dec2 = 0;
    }

    else if (dayNum == 6)
    {
      *dec1 = 66;
      *dec2 = 0;
    }

    else
    { 
      *dec1 = 65;
      *dec2 = 0;
    }
  }
}

/*****+*-*-**-***-**--**--*-*--***--*-***-**--*--***************************
 *
 *  Function Information
 *
 *  Name of Function: getOutput1
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1.int year - this function uses the year variable to print it
 *    2.int dayNum - this function uses dayNum to know which day of the week it is.
 *    3.
 *
 *  Function Description: This function uses an if statement to print out the output based on the which day of the week it is.
 *
 ******+*-*-**-***-**--**--*-*--***--*-***-**--*--**************************/

void getOutput1(int year, int dayNum)
{

  switch(dayNum)
  {
    case 7: printf("\n01 January %d falls on a: Sunday\n", year);
            break;
    case 1: printf("\n01 January %d falls on a: Monday\n", year);
            break;
    case 2: printf("\n01 January %d falls on a: Tuesday\n", year);
            break;
    case 3: printf("\n01 January %d falls on a: Wednesday\n", year);
            break;
    case 4: printf("\n01 January %d falls on a: Thursday\n", year);
            break;
    case 5: printf("\n01 January %d falls on a: Friday\n", year);
            break;
    case 6: printf("\n01 January %d falls on a: Saturday\n", year);
  }
}
/*****+***-*--***-**--**--*-*--***--*-***-**--*--***************************
 *
 *  Function Information
 *
 *  Name of Function: getOutput2
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int dec1 - this function uses dec1 to print out the YDL letter
 *    2. int dec2 - this function uses dec2 to print out the YDL letter in case the year was a leap year
 *    3.
 *
 *  Function Description: the function checks if dec2 has been set to zero (which happens when the year is not a leap year) and prints out the YDL and 2YDL as a letter. If not a leap year, the function only prints out dec1
 *
 ******+***-*--***-**--**--*-*--***--*-***-**--*--**************************/

void getOutput2(int dec1, int dec2) 
{
  switch(dec2)
  {
    case 0: printf("Dominical letters: %10c\n", dec1);
            break;
    default: printf("Dominical letters: %10c%c\n", dec1, dec2);
  }

}
/*****+*-****--**-**--**--*-*--***--*-***-**--*--***************************
 *
 *  Function Information
 *
 *  Name of Function: getOutput3
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int dec1 - the function uses the YDL to know what months Friday the 13th happens
 *    2. int dec2 - the function uses the YDL to know what months Friday the 13th happens
 *    3.
 *
 *  Function Description: The function checks the value for both dec1 and dec2 and prints out the months that correspond to dec1 and dec2 from the table.
 *
 ******+*-****--**-**--**--*-*--***--*-***-**--*--**************************/

void getOutput3(int dec1, int dec2)
{
  if ((dec1 == 71 && dec2 == 70) || ( dec1 == 70 && dec2 == 0 ))  
  {
    printf("Friday the 13th falls in:   September, December\n");
  }

  else if ((dec1 == 70 && dec2 == 69) || ( dec1 == 69 && dec2 == 0)) 
  {
    printf("Friday the 13th falls in:   June\n");
  }

  else if (dec1 == 69 && dec2 == 68)
  { 
    printf("Friday the 13th falls in:   March, November\n");
  }

  else if (dec1 == 68 && dec2 == 67)
  {
    printf("Friday the 13th falls in:   February, August\n");
  }

  else if ((dec1 == 67 && dec2 == 66) || ( dec1 == 66 && dec2 == 0))
  {
    printf("Friday the 13th falls in:   May\n");
  }

  else if (dec1 == 66 && dec2 == 65)
  {
    printf("Friday the 13th falls in:   October\n");
  }

  else if (dec1 == 65 && dec2 == 71)
  {
    printf("Friday the 13th falls in:   January, April, July\n");
  }

  else if (dec1 == 71 && dec2 == 0)
  {
    printf("Friday the 13th falls in:   April, July\n");
  }

  else if (dec1 == 68 && dec2 == 0)
  {
    printf("Friday the 13th falls in:   February, March, November\n");
  }

  else if (dec1 == 67 && dec2 == 0)
  {
    printf("Friday the 13th falls in:   August\n");
  }

  else 
  {
    printf("Friday the 13th falls in:   January, October\n");
  }
}
