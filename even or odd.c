/*****+*--*-**--*-*---------*--**-**----***---*--***************************
*
*  Lab #:09
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Program Description:This program, the user decides odd or even function for sorting and then inputs a long number. Then through our program, the long number is sorted by either even or odd ranging from largest to least. 
*
******+*--*-**--*-*---------*--**-**----***---*--**************************/
#include<stdio.h>
#include<math.h> 

int getInput(long long *); //gets the user input for even odd and long number 
long long evenNumbers(long long); //sorts even numbers 
long long oddNumbers(long long);  //sorts odd numbers
void display(long long, long long, int, long long); //outputs the sorted long number 

int main(void)
{
  //local declerations 
  int num; //User input for odd or even 
  long long longNumber; //User input long number
  long long evenNumber; //sorts even number 
  long long oddNumber;  //sorts odd number

  //function calls
  num = getInput(&longNumber);  //calls for get input function 
  evenNumber = evenNumbers(longNumber);  //calls for even number function 
  oddNumber = oddNumbers(longNumber);  //calls for odd number function 
  display(evenNumber, oddNumber, num, longNumber);  //calls for display outputs function 

  return 0;
}

/*****+******-*--*-***-*-*****--*---*--**-**--*--***************************
*
*  Function Information
*
*  Name of Function:getInput
*
*  Function Return Type:int, long long
*
*  Parameters (long long):
*    1.*longNum  
*    2.
*    3.
*
*  Function Description: allows and gathers the user input data 
*
******+******-*--*-***-*-*****--*---*--**-**--*--**************************/
int getInput(long long *longNum)
{
  int num;  //user input for odd or even 
  do
  {
    printf("Enter (1) for odd (2) for even -> ");  //user inputs for even or odd
    scanf("%d", &num);
    if (num != 1 && num != 2) 
    {
      printf("\nError! Option must be 1 or 2.\n\n");
    }
  } while (num != 1 && num != 2);

  do
  {
  
    printf("Enter a long number -> ");  //user inputs long number
    scanf("%lld", longNum);

    if(*longNum <= 0)
    {
      printf("\nError! Number must be a positive value.\n\n");  //looks for errors and displays if error is caught 
    }
  } while(*longNum <= 0);

  return num;
}

/*****+***-**-*--*-***-*-*****--*---*--**-**--*--***************************
*
*  Function Information
*
*  Name of Function:oddNumbers
*
*  Function Return Type:long long
*
*  Parameters (long long):
*    1.longNum
*    2.
*    3.
*
*  Function Description:sorts for the odd numbers
*
******+***-**-*--*-***-*-*****--*---*--**-**--*--**************************/
long long oddNumbers(long long longNum)
{
  long long temp;  //=longNum 
  long long max = 0;  //maximum value of the integers 
  int i;  //loop variable

  temp = longNum;
  for(i = 0; temp > 0; i++)  //sorts for odd numbers and ranges them from highest to lowest
  {
    if(temp % 10 == 9)
    {
      max = max * 10 + temp % 10;
      temp = temp / 10; 
    }
    else
    {
      temp = temp / 10;  
    }
  }

  temp = longNum;
  for(i = 0; temp > 0; i++)
  {
    if(temp % 10 == 7)
    {
      max = max * 10 + temp % 10;
      temp = temp / 10; 
    }
    else
    {
      temp = temp / 10;  
    }
  }

  temp = longNum;
  for( i = 0; temp > 0; i++)
  {
    if(temp % 10 == 5)
    {
      max = max * 10 + temp % 10;
      temp = temp / 10; 
    }
    else
    {
      temp = temp / 10;  
    }
  }

  temp = longNum;
  for(i = 0; temp > 0; i++)
  {
    if(temp % 10 == 3)
    {
      max = max * 10 + temp % 10;
      temp = temp / 10; 
    }
    else
    {
      temp = temp / 10;  
    }
  }

  temp = longNum;
  for(i = 0; temp > 0; i++)
  {
    if(temp % 10 == 1)
    {
      max = max * 10 + temp % 10;
      temp = temp / 10; 
    }
    else
    {
      temp = temp / 10;  
    }
  }

  return max;
}

/*****+*-***--*--*-***-*-*****--*---*--**-**--*--***************************
*
*  Function Information
*
*  Name of Function:evenNumbers
*
*  Function Return Type:long long
*
*  Parameters (long long):
*    1.longNum 
*    2.
*    3.
*
*  Function Description: sorts even numbers 
*
******+*-***--*--*-***-*-*****--*---*--**-**--*--**************************/
long long evenNumbers(long long longNum) 
{
  long long temp;  //=longNum
  long long max = 0;  //maximum value of integers
  int i;  //loop variable 

  temp = longNum;   
  for(i = 0; temp > 0; i++)  //these sort even numbers and range them from highest to lowest
  {
    if(temp % 10 == 8)
    {
      max = max * 10 + temp % 10;
      temp = temp / 10; 
    }
    else
    {
      temp = temp / 10;  
    }
  }

  temp = longNum;
  for(i = 0; temp > 0; i++)
  {
    if(temp % 10 == 6)
    {
      max = max * 10 + temp % 10;
      temp = temp / 10; 
    }
    else
    {
      temp = temp / 10;  
    }
  }

  temp = longNum;
  for(i = 0; temp > 0; i++)
  {
    if(temp % 10 == 4)
    {
      max = max * 10 + temp % 10;
      temp = temp / 10; 
    }
    else
    {
      temp = temp / 10;  
    }
  }

  temp = longNum;
  for(i = 0; temp > 0; i++)
  { 
    if(temp % 10 == 2)
    {
      max = max * 10 + temp % 10;
      temp = temp / 10; 
    }
    else
    {
      temp = temp / 10;  
    }
  }

  temp = longNum;
  for(i = 0; temp > 0; i++)
  {  
    if(temp % 10 == 0)
    {
      max = max * 10 + temp % 10;
      temp = temp / 10; 
    }
    else
    {
      temp = temp / 10;  
    }
  }

  return max;
}

/*****+*-*-*--*--*-***-*-*****--*---*--**-**--*--***************************
*
*  Function Information
*
*  Name of Function:display 
*
*  Function Return Type:long long, int
*
*  Parameters (long long, long long, int, long long):
*    1.evenNum 
*    2.oddNum
*    3.num
*    4.longNum
*
*  Function Description:displays the sorted long num based on requirment
*
******+*-*-*--*--*-***-*-*****--*---*--**-**--*--**************************/
void display(long long  evenNum, long long oddNum, int num, long long longNum)
{
  if (num == 1 && longNum > 0 && evenNum == 0)  //these sort and chose the display outputted based on the user inputs 
  {
    printf("\nResulting number with odd digits first: %lld\n", oddNum);
  }

  else if (num == 1 && longNum > 0 && oddNum == 0) 
  {
    printf("\nResulting number with odd digits first: %lld\n", evenNum);
  }

  else if (num == 2 && longNum > 0 && evenNum == 0) 
  {
    printf("\nResulting number with even digits first: %lld\n", oddNum);
  }

  else if (num == 2 && longNum > 0 && oddNum == 0)
  {
    printf("\nResulting number with even digits first: %lld\n", evenNum);
  }

  else if (num == 1 && longNum > 0 )
  {
    printf("\nResulting number with odd digits first: %lld%lld\n", oddNum, evenNum);
  }

  else if (num == 2 && longNum > 0)
  {
    printf("\nResulting number with even digits first: %lld%lld\n", evenNum, oddNum);
  }
}
