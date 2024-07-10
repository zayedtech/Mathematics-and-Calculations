/*****+******-***--*--**----*-****-----*---**-*--***************************
*
*  Lab #: 05
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Program Description: This program takes a user's loan amount, the annual interest rate on the loan, and the start and end dates of the loan. It then calculates the amount of money to be repaid.
*
******+******-***--*--**----*-****-----*---**-*--**************************/
#include<stdio.h>
#include<math.h>

//FUNCTION DECLARATIONS
float getInput1();
float getInput2();
int getStart(int *, int *, int *);
int endDate(int *, int *, int *);
int yearDiffDays(int, int);
int monthDiffDays(int, int);
int dayDiff(int, int);
float totalYearsFunc(int);
int totalDays(int, int, int);
float repayment(float, float, float);
void displayFunc(float, float, int, float);

int main(void)
{

//LOCAL DECLARATIONS
  float originalLoan; //the original amount of the loan that the user inputs
  float annualInterest; //the annual interest rate of the loan that the user inputs
  int monthS; //the month in which the loan started
  int dayS; //the day on which the loan started
  int yearS; //the year in which the loan started
  int monthE; //the month in which the loan ends
  int dayE; //the day on which the loan ends
  int yearsE; //the year in which the loan ends
  int yearsDays; //the amount of years the loan covers converted to days
  int monthsDays; //the amount of months the loan covers converted to days
  int days; //the amount of days the loan covers
  int totalDays1; //the year to day conversion, month to day conversion, and days all added together
  float totalYears; //all the days added together converted to years
  float repaymentFin; //calculated amount of money that is to be repaid

//EXECUTABLE STATEMENTS
  originalLoan = getInput1();
  annualInterest = getInput2();
  getStart(&monthS, &dayS, &yearS);
  endDate(&monthE, &dayE, &yearsE);
  yearsDays = yearDiffDays(yearS, yearsE);
  monthsDays = monthDiffDays(monthS, monthE);
  days = dayDiff(dayS, dayE);
  totalDays1 = totalDays(monthsDays, days, yearsDays);
  totalYears = totalYearsFunc(totalDays1);
  repaymentFin = repayment(originalLoan, annualInterest, totalYears);
  displayFunc(originalLoan, annualInterest, totalDays1, repaymentFin);
 
  return(0);

}

/*****+*--***-----*-*--**--*-****------*---**-*--***************************
*
*  Function Information
*
*  Name of Function: getInput1
*
*  Function Return Type: float
*
*  Parameters (list data type, name, and comment one per line): N/A
*
*  Function Description: Accepts the user's input of the original amount of their loan.
*
******+*--***-----*-*--**--*-****------*---**-*--**************************/
float getInput1()
{

//LOCAL DECLARATIONS  
  float originalLoan; //user's input of the amount of their original loan

//EXECUTABLE STATEMENTS
  printf("Enter original amount of the loan -> ");
  scanf("%f", &originalLoan);

  return(originalLoan);

}

/*****+**-**------*-*--**--*-****------*---**-*--***************************
*
*  Function Information
*
*  Name of Function: getInput2
*
*  Function Return Type: float
*
*  Parameters (list data type, name, and comment one per line): N/A
*
*  Function Description: Accepts the user's input of the annual interest rate of their loan.
*
******+**-**------*-*--**--*-****------*---**-*--**************************/
float getInput2()
{

//LOCAL DECLARATIONS    
  float annualInterest; //user's input of the annual interest rate on their loan

//EXECUTABLE STATEMENTS
  printf("Enter the annual interest rate -> ");
  scanf("%f", &annualInterest);

  return(annualInterest);

} 

/*****+*---*------*-*--**--*-****------*---**-*--***************************
*
*  Function Information
*
*  Name of Function: getStart
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int *m - holds the value of the user's input of the month in which their loan started
*    2. int *d - holds the value of the user's input of the day in which their loan started
*    3. int *y - holds the value of the user's input of the year in which their loan started
*
*  Function Description: Accepts the user's input of the date their loan started on.
*
******+*---*------*-*--**--*-****------*---**-*--**************************/
int getStart(int *m, int *d, int *y) 
{

//EXECUTABLE STATEMENTS 
  printf("Enter loan start date (mm/dd/yyyy) -> ");
  scanf("%d/", &*m);
  scanf("%d/", &*d);
  scanf("%d", &*y); 

  return(0);

}

/*****+*---**-*-*---*--**--*-****------*---**-*--***************************
*
*  Function Information
*
*  Name of Function: endDate
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int *m - holds the value of the user's input of the month in which their loan ends
*    2. int *d - holds the value of the user's input of the day in which their loan ends
*    3. int *y - holds the value of the user's input of the year in which their loan ends
*
*  Function Description: Accepts the users input of the date their loan ends on.
*
******+*---**-*-*---*--**--*-****------*---**-*--**************************/
int endDate(int *m, int *d, int *y) 
{

//EXECUTABLE STATEMENTS
  printf("Enter loan end date (mm/dd/yyyy) -> ");
  scanf("%d/", &*m);
  scanf("%d/", &*d);
  scanf("%d",&*y);

  return(0);

}

/*****+*---**---*---*--**--*-****------*---**-*--***************************
*
*  Function Information
*
*  Name of Function: yearDiffDays
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int yearStart - the year that the loan was started
*    2. int yearEnd - the year that the loan ends
*
*  Function Description: Calculates the difference in years and converts it into days.
*
******+*---**---*---*--**--*-****------*---**-*--**************************/
int yearDiffDays(int yearStart, int yearEnd) 
{

  return((yearEnd - yearStart) * 360);

}

/*****+*--**----*---*--**--*-****------*---**-*--***************************
*
*  Function Information
*
*  Name of Function: monthDiffDays
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int monthStart - the month that the loan was started
*    2. int monthEnd - the month that the loan ends
*
*  Function Description: Calculates the difference in months and converts it into days.
*
******+*--**----*---*--**--*-****------*---**-*--**************************/
int monthDiffDays(int monthStart, int monthEnd) 
{ 

  return((monthEnd - monthStart) * 30);

}

/*****+*---*----*---*--**--*-****------*---**-*--***************************
*
*  Function Information
*
*  Name of Function: dayDiff
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int dayStart - the day that the loan was started
*    2. int dayEnd - the day that the loan ends
*
*  Function Description: Calculates the difference in days.
*
******+*---*----*---*--**--*-****------*---**-*--**************************/
int dayDiff(int dayStart, int dayEnd) 
{

  return (dayEnd - dayStart);

}

/*****+**-**--*-----*--**--*-****------*---**-*--***************************
*
*  Function Information
*
*  Name of Function: totalDays
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int year - amount of years converted to days
*    2. int day - amount of days
*    3. int month - amount of months converted to days
*
*  Function Description: Calculates the total number of days of the loan by adding the years in days, the days, and the months in days.
*
******+**-**--*-----*--**--*-****------*---**-*--**************************/
int totalDays(int year, int day, int month) 
{

  return(year + day + month);

}

/*****+*--***-*-----*--**--*-****------*---**-*--***************************
*
*  Function Information
*
*  Name of Function: totalYearsFunc
*
*  Function Return Type: float
*
*  Parameters (list data type, name, and comment one per line):
*    1. int days - total amount of days of the loan
*
*  Function Description: Converts the entire amount of days of the loan into years.
*
******+*--***-*-----*--**--*-****------*---**-*--**************************/
float totalYearsFunc(int days) 
{

  return((float) days / 360);

}

/*****+*---*--*-----*--**--*-****------*---**-*--***************************
*
*  Function Information
*
*  Name of Function: repayment
*
*  Function Return Type: float
*
*  Parameters (list data type, name, and comment one per line):
*    1. float principal - original amount of the loan that the user inputted
*    2. float rate - annual interest rate of the loan that the user inputted
*    3. float time - amount of time in years that the loan will last
*
*  Function Description: Calculates the amount that the user will have to repay after their loan.
*
******+*---*--*-----*--**--*-****------*---**-*--**************************/
float repayment(float principal, float rate, float time) 
{

  return(principal + (principal * (rate / 100) * time));

}

/*****+**--**-------*--**--*-****------*---**-*--***************************
*
*  Function Information
*
*  Name of Function: displayFunc
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. float principal - original amount of the loan that the user inputted
*    2. float rate - annual interest rate of the loan that the user inputted
*    3. int days - amount of days that the loan will last
*    4. float repayment - amount of money the user will have to repay after their loan
*
*  Function Description: Displays the original amount of the loan, the annual interest rate on it, the amount of days it lasts, and the amount of money the user will have to repay.
*
******+**--**-------*--**--*-****------*---**-*--**************************/
void displayFunc(float principal, float rate, int days, float repayment) 
{

//EXECUTABLE STATEMENTS  
  printf("\nRepayment of $ %.2f at %.2f%% (APR) for %d days: $ %.2f\n", principal, rate , days, repayment);

}

