/*****+******-**---*---*--*----*-*--*-***-**--*--***************************
 *
 *  Lab #: 07
 *
 *  Academic Integrity Statement:
 *
 *  We have not used source code obtained from any other unauthorized source,
 *  either modified or unmodified.  Neither have we provided access to our code
 *  to another. The effort we are submitting is our own original work.
 *
 *  Program Description: This program chooses a random number out of one that is provided by the user and makes the random number the amount of days until the user's investment ends. It then calculates the amount of money the user will have to repay and displays the time range of the investment.
 *
 ******+******-**---*---*--*----*-*--*-***-**--*--**************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MIN 30
#define MAX 1800

//Function Declarations
int getSeed(void);
float originalAmt(void);
float annRate(void);
int startDate(int *, int *, int *);
int getDays(int);
float repayAmt(float, float, int);
void getDiffs(int, int*, int*, int*, int, int, int);
void finalDate(int, int, int, int, int, int, int *, int *, int *);
void displayResults(float, float, int, float, int, int, int, int, int, int);

int main(void) 
{
//Local Declarations
  int seed; //seed value
  float investment; //original investment amount
  float rate; //annual interest rate
  int start_month; //starting month of investment
  int start_day; //starting day of investment
  int start_year; //starting year of investment
  int days; //number of days until payoff
  float repay; //repayment amount
  int daysDiff; //amount of days of the investment
  int yearsDiff; //amount of years of the investment
  int monthsDiff; //amount of months of the investment
  int finalYear; //difference in years
  int finalDay; //difference in days
  int finalMonth; //difference in months

//Executable Statements
  seed = getSeed();
  investment = originalAmt();
  rate = annRate();
  startDate(&start_month, &start_day, &start_year);
  days = getDays(seed);
  repay = repayAmt(investment, rate, days);
  getDiffs(days, &yearsDiff, &monthsDiff, &daysDiff, start_year, start_month, start_day);
  finalDate(start_day, start_month, start_year, daysDiff, monthsDiff, yearsDiff, &finalDay, &finalMonth, &finalYear);
  displayResults(investment, rate, days, repay, start_month, start_day, start_year, finalDay, finalMonth, finalYear);

  return 0;
}
/*****+***-**-**---*---*--*----*-*--*-***-**--*--***************************
 *
 *  Function Information
 *
 *  Name of Function: getSeed
 *
 *  Function Return Type: int
 *
 *  Parameters (list data type, name, and comment one per line): N/A
 *
 *  Function Description: This function accepts the user's desired seed value.
 *
 ******+***-**-**---*---*--*----*-*--*-***-**--*--**************************/
int getSeed(void) 
{
  int seed; //seed value

  printf("Enter desired seed value -> ");
  scanf("%d", &seed);

  return(seed);
}

/*****+***-**-**---*---*--*----*-*--*-***-**--*--***************************
 *
 *  Function Information
 *
 *  Name of Function: originalAmt
 *
 *  Function Return Type: float
 *
 *  Parameters (list data type, name, and comment one per line): N/A
 *
 *  Function Description: This function accepts the user's original amount of their investment.
 *
 ******+***-**-**---*---*--*----*-*--*-***-**--*--**************************/
float originalAmt(void) 
{
  float amt; //original investment amount

  printf("Enter original amount of the investment -> ");
  scanf("%f", &amt);

  return(amt);
}

/*****+*-*-**-**---*---*--*----*-*--*-***-**--*--***************************
 *
 *  Function Information
 *
 *  Name of Function: annRate
 *
 *  Function Return Type: float
 *
 *  Parameters (list data type, name, and comment one per line): N/A
 *
 *  Function Description: This function accepts the user's annual interest rate on their investment.
 *
 ******+*-*-**-**---*---*--*----*-*--*-***-**--*--**************************/
float annRate(void)
{
  float rate; //annual interest rate

  printf("Enter the annual interest rate -> ");
  scanf("%f", &rate);  

  return(rate);
}

/*****+*****--**---*---*--*----*-*--*-***-**--*--***************************
 *
 *  Function Information
 *
 *  Name of Function: startDate
 *
 *  Function Return Type: int
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int *month - the start date month is passed by address
 *    2. int *day - the start date day is passed by address
 *    3. int *year - the start date year is passed by address
 *
 *  Function Description: This function accepts the user's input of their investment's start date.
 *
 ******+*****--**---*---*--*----*-*--*-***-**--*--**************************/
int startDate(int *month, int *day, int *year)
{
  printf("Enter investment start date (mm/dd/yyyy) -> ");
  scanf("%d/%d/%d", month, day, year); 

  return(0);
}

/*****+***-*--**---*---*--*----*-*--*-***-**--*--***************************
 *
 *  Function Information
 *
 *  Name of Function: getDays
 *
 *  Function Return Type: int
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int seed - the user's desired seed value
 *
 *  Function Description: This function generates a random number within the user's seed but also between the maximum and minimum limits given in the instructions.
 *
 ******+***-*--**---*---*--*----*-*--*-***-**--*--**************************/
int getDays(int seed) 
{
  int randomNumber; //generates a random number within the seed

  srand(seed);
  randomNumber = rand();

  return(randomNumber % (MAX - MIN + 1) + MIN);
}

/*****+*--***-*---*---***--***-**-*---***-**--*--***************************
*
*  Function Information
*
*  Name of Function: repayAmt
*
*  Function Return Type: float
*
*  Parameters (list data type, name, and comment one per line):
*    1. float principal - original investment amount
*    2. float rate - annual interest rate on investment
*    3. int days - amount of days until the investment is paid off
*
*  Function Description: This function calculates the amount of money the user will have to repay.
*
******+*--***-*---*---***--***-**-*---***-**--*--**************************/
float repayAmt(float principal, float rate, int days)
{
  return(principal + (principal * (rate / 100) * (days / 360.0)));
}

/*****+*-*-*--***-***-***------*-*--*-***-**--*--***************************
 *
 *  Function Information
 *
 *  Name of Function: getDiffs
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int days - amount of days of the user's investment
 *    2. int *yearDiff - amount of years of the investment
 *    3. int *monthDiff - amount of months of the investment
 *    4. int *dayDiff - amount of days of the investment
 *    5. int prevYear - start date's year
 *    6. int prevMonth - start date's month
 *    7. int prevDay - start date's day
 *
 *  Function Description: This function finds the duration of years, months, and days of the investment.
 *
 ******+*-*-*--***-***-***------*-*--*-***-**--*--**************************/
void getDiffs(int days, int *yearDiff, int *monthDiff, int *dayDiff, int prevYear, int prevMonth, int prevDay)
{
  *yearDiff = days / 360;

  if(*yearDiff != 0)
  {  
    *monthDiff = (days / 30) % (*yearDiff * 12);
    if (*monthDiff != 0)
    {
      *dayDiff = days % (*monthDiff * 30);
    }
    else 
    {
      *dayDiff = days % (*yearDiff * 360);   
    }
  }
  else 
  { 
    *monthDiff = days / 30;

    if (*monthDiff != 0)
    {
      *dayDiff = days % (*monthDiff * 30);
    }
    else 
    {
      *dayDiff = days;
    }
  }
}

/*****+*-*-*--***-***-***------*-*--*-***-**--*--***************************
 *
 *  Function Information
 *
 *  Name of Function: finalDate
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int prevDay - start date's day
 *    2. int prevMonth - start date's month
 *    3. int prevYear - start date's year
 *    4. int diffDay - duration of days
 *    5. int diffMonth - duration of months
 *    6. int diffYear - duration of years
 *    7. int *finalDay - end date's day
 *    8. int *finalMonth - end date's month
 *    9. int *finalYear - end date's year
 *
 *  Function Description: This function finds the end date of the user's investment.
 *
 ******+*-*-*--***-***-***------*-*--*-***-**--*--**************************/
void finalDate(int prevDay, int prevMonth, int prevYear, int diffDay, int diffMonth, int diffYear, int *finalDay, int *finalMonth, int *finalYear)
{
  if (prevDay + diffDay > 30)
  {
    *finalMonth = prevMonth + diffMonth + 1;
    *finalDay = diffDay + prevDay - 30;

    if (*finalMonth > 12) 
    {
      *finalYear = prevYear + diffYear + 1;
      *finalMonth = *finalMonth - 12;
    }
    else 
    {
      *finalYear = prevYear + diffYear;
    }
  }
  else if (prevMonth + diffMonth > 12) 
  {
    *finalYear = prevYear + diffYear + 1;
    *finalMonth = diffMonth + prevMonth - 12;
    *finalDay = prevDay + diffDay;
  }
  else 
  {
    *finalDay = prevDay + diffDay;
    *finalMonth = prevMonth + diffMonth;
    *finalYear = prevYear + diffYear;
  }
}

/*****+*-*-*--***-***-***------*-*--*-***-**--*--***************************
 *
 *  Function Information
 *
 *  Name of Function: displayResults
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. float principal - the amount invested
 *    2. float rate - the annual interest rate
 *    3. int days - the number of days invested
 *    4. float repay - the amount repayed after the number of days
 *    5. int start_month - the start month that the user input
 *    6. int start_day - the start day that the user input
 *    7. int start_year - the start year that the user input
 *    8. int finalDay - the end day that the user inputs
 *    9. int finalMonth - the end month that the user inputs
 *   10. int finalYear - the end year that the user inputs
 *
 *  Function Description: This function displays the results of the program.
 *
 ******+*-*-*--***-***-***------*-*--*-***-**--*--**************************/
void displayResults(float principal, float rate, int days, float repay, int start_month, int start_day, int start_year, int finalDay, int finalMonth, int finalYear)
{
  printf("\nInvestment of $ %.2f at %.2f%% (APR) for %d days: $ %.2f\n", principal, rate, days, repay);
  printf("Investment Date Range: %02d/%02d/%4d - %02d/%02d/%4d\n", start_month, start_day, start_year, finalMonth, finalDay, finalYear);
}

