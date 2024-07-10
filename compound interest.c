/*****+**--**---------***--*****--*-*-***-**--*--***************************
 *
 *  Lab #: 06
 *
 *  Academic Integrity Statement:
 *
 *  We have not used source code obtained from any other unauthorized source,
 *  either modified or unmodified.  Neither have we provided access to our code
 *  to another. The effort we are submitting is our own original work.
 *
 *  Program Description: This program asks the user to choose what they want calculated with regards to their future value of an investment using compound interest. Once they decide, the program calculates what the user needs and displays the amount of their initial investment, the annual interest rate on it, the duration of the investment, and its final value.
 *
 ******+**--**---------***--*****--*-*-***-**--*--**************************/
#include <stdio.h>
#include <math.h>

//Function Declarations
void intro(void);
int selectOption(void);
float interestRate(void);
float investmentAmount(void);
float investmentTime(void);
float finalInvestment(void);
float calcInterestRate(float , float , float );
float calcInitialInvestment(float , float , float );
float calcTime(float , float , float );
float calcFinalInvestment(float , float , float );
void selectionFunction(int , float *, float *, float *, float *);
void getOutput(int, float , float , float , float );

int main(void) 
{
//Local Declarations
  int desiredOption; //the option the user chooses
  float totalTime; //the total time of the investment in years
  float initialInvestment; //the amount of money initially invested in USD
  float annualInterest; //the annual interest rate on the user's investment
  float finalAmount; // final amount of investment

//Executable Statements
  intro();
  desiredOption = selectOption();
  selectionFunction(desiredOption, &totalTime, &initialInvestment, &annualInterest, &finalAmount);
  getOutput(desiredOption, initialInvestment, annualInterest, totalTime, finalAmount);

  return(0);
}

/*****+******-***-**---**-----**-**-*-***-**--*--***************************
*
*  Function Information
*
*  Name of Function: intro
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line): N/A
*
*  Function Description: This function prints out the first 4 statements of the program.
*
******+******-***-**---**-----**-**-*-***-**--*--**************************/
void intro(void)
{
//Executable Statements
  printf("1. Find annual interest rate\n");
  printf("2. Find initial investment amount\n");
  printf("3. Find total time of investment\n");
  printf("4. Find final investment amount\n");
}

/*****+**-**--*---*-*--**--*****--*-*-***-**--*--***************************
 *
 *  Function Information
 *
 *  Name of Function: selectOption
 *
 *  Function Return Type: int
 *
 *  Parameters (list data type, name, and comment one per line): N/A
 *
 *  Function Description: This function accepts input from a user regarding which option they would like the program to calculate.
 *
 ******+**-**--*---*-*--**--*****--*-*-***-**--*--**************************/
int selectOption(void)
{
//Local Declarations
  int option; //holds the option the user chooses

//Executable Statements
  printf("\nSelect desired option -> ");
  scanf("%d", &option);

  return(option);
}

/*****+*--***-----*-*--**--*****--*-*-***-**--*--***************************
 *
 *  Function Information
 *
 *  Name of Functiion: interestRate
 *
 *  Function Return Type: float
 *
 *  Parameters (list data type, name, and comment one per line): N/A
 *  
 *  Function Description: This function accepts input from a user regarding what their investment's annual interest rate is.
 *
 ******+*--***-----*-*--**--*****--*-*-***-**--*--**************************/
float interestRate(void)
{
//Local Declarations
  float rate; //holds the user's annual interest rate

//Executable Statements
  printf("Enter annual interest rate -> ");
  scanf("%f", &rate);

  return(rate);
}

/*****+*---**-----*-*--**--*****--*-*-***-**--*--***************************
 *
 *  Function Information
 *
 *  Name of Function: investmentAmount
 *
 *  Function Return Type: float
 *
 *  Parameters (list data type, name, and comment one per line): N/A
 *
 *  Function Description: This function accepts input from a user regarding the amount of their initial investment.
 *
 ******+*---**-----*-*--**--*****--*-*-***-**--*--**************************/
float investmentAmount(void)
{
//Local Declarations
  float investment; //holds the amount of money the user initially invested

//Executable Statements
  printf("Enter initial investment amount (USD) -> ");
  scanf("%f", &investment);

  return(investment);
}

/*****+*---*------*-*--**--*****--*-*-***-**--*--***************************
 *
 *  Function Information
 *
 *  Name of Function: investmentTime
 *
 *  Function Return Type: float
 *
 *  Parameters (list data type, name, and comment one per line): N/A
 *
 *  Function Description: This function accepts input from a user regarding the amount of time their investment will last.
 *
 ******+*---*------*-*--**--*****--*-*-***-**--*--**************************/
float investmentTime(void)
{
//Local Declarations
  float years; //holds the amount of years the user enters

//Executable Statements
  printf("Enter total time of investment (years) -> ");
  scanf("%f", &years);

  return(years);
}

/*****+**--**-*-*---*--**--*****--*-*-***-**--*--***************************
 *
 *  Function Information
 *
 *  Name of Function: finalInvestment
 *
 *  Function Return Type: float
 *
 *  Parameters (list data type, name, and comment one per line): N/A
 *
 *  Function Description: This function accepts input from a user regarding their final investment amount.
 *
 ******+**--**-*-*---*--**--*****--*-*-***-**--*--**************************/
float finalInvestment(void)
{
//Local Declarations
  float finalAmt; //holds the final amount of money the user will have

//Executable Statements
  printf("Enter final investment amount (USD) -> ");
  scanf("%f", &finalAmt);

  return(finalAmt);
}

/*****+**--**---*---*--**--*****--*-*-***-**--*--***************************
 *
 *  Function Information
 *
 *  Name of Function: calcInterestRate
 *
 *  Function Return Type: float
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. float years - amount of time in years of the investment
 *    2. float initial - amount of money initially invested
 *    3. float finalAmt - final amount of money
 *
 *  Function Description: This function calculates the annual interest rate on an investment.
 *
 ******+**--**---*---*--**--*****--*-*-***-**--*--**************************/
float calcInterestRate(float years, float initial, float finalAmt)
{
  return(100 * (pow((finalAmt / initial), (1 / years)) - 1));
}

/*****+**-**----*---*--**--*****--*-*-***-**--*--***************************
 *
 *  Function Information
 *
 *  Name of Function: calcInitialInvestment
 *
 *  Function Return Type: float
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. float years - amount of time in years of the investment
 *    2. float finalAmt - final amount of money
 *    3. float rate - annual interest rate on the investment
 *
 *  Function Description: This function calculates the amount of money initially invested by the user.
 *
 ******+**-**----*---*--**--*****--*-*-***-**--*--**************************/
float calcInitialInvestment(float years, float finalAmt, float rate)
{
  return(finalAmt / pow(1 + (rate / 100), years));
}

/*****+**--*----*---*--**--*****--*-*-***-**--*--***************************
 *
 *  Function Information
 *
 *  Name of Function: calcTime
 *
 *  Function Return Type: float
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. float initial - amount of money initially invested
 *    2. float finalAmt - final amount of money
 *    3. float rate - annual interest rate on the investment
 *
 *  Function Description: This function calculates the amount of time the investment will last.
 *
 ******+**--*----*---*--**--*****--*-*-***-**--*--**************************/
float calcTime(float initial, float finalAmt, float rate)
{
  return(((log(finalAmt / initial)) / (log(1 + (rate / 100)))));
}

/*****+**-**--*-----*--**--*****--*-*-***-**--*--***************************
 *
 *  Function Information
 *
 *  Name of Function: calcFinalInvestment
 *
 *  Function Return Type: float
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. float years - amount of time in years of the investment
 *    2. float initial - amount of money initially invested
 *    3. float rate - annual interest rate on the investment
 *
 *  Function Description: This function calculates the final amount of the investment.
 *
 ******+**-**--*-----*--**--*****--*-*-***-**--*--**************************/
float calcFinalInvestment(float years, float initial, float rate)
{
  return(initial * pow(1 + (rate / 100), years));
}

/*****+**--*--*-----*--**--*****--*-*-***-**--*--***************************
 *
 *  Function Information
 *
 *  Name of Function: selectionFunction
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int option - the option number that the user chose for the program to calculate
 *    2. float *time - duration of the investment
 *    3. float *investment - initial amount of money invested
 *    4. float *rate - annual interest rate on the investment
 *    5. float *finalAmt - final amount of money
 *
 *  Function Description: This function decides what to output depending on which option the user chooses at the beginning of the program.
 *
 ******+**--*--*-----*--**--*****--*-*-***-**--*--**************************/
void selectionFunction(int option, float *time, float *investment, float *rate, float *finalAmnt) 
{
  if (option == 1)
  {
    *time = investmentTime();
    *investment = investmentAmount();
    *finalAmnt = finalInvestment();
    *rate = calcInterestRate(*time, *investment, *finalAmnt);
  }

  else if (option == 2) 
  {
    *time = investmentTime();
    *finalAmnt = finalInvestment();
    *rate = interestRate();
    *investment = calcInitialInvestment(*time, *finalAmnt, *rate);
  }

  else if (option == 3)
  {
    *investment = investmentAmount();
    *finalAmnt = finalInvestment();
    *rate = interestRate();
    *time = calcTime(*investment, *finalAmnt, *rate);
  }

  else if (option == 4) 
  {
    *time = investmentTime();
    *investment = investmentAmount();
    *rate = interestRate(); 
    *finalAmnt = calcFinalInvestment(*time, *investment, *rate);
  }
}

/*****+*---**-*-*-*----**--*****--*-*-***-**--*--***************************
 *
 *  Function Information
 *
 *  Name of Function: getOutput
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
      1. int option - the option user inputs
 *    2. float initialInv - amount of money the initial investment was
 *    3. float rate - annual interest rate on the investment
 *    4. float invTime - amount of time the investment went over
 *    5. float finalAmt - final amount of money of the investments
 *
 *  Function Description: This function displays all of the results to the user.
 *
 ******+*---**-*-*-*----**--*****--*-*-***-**--*--**************************/
void getOutput(int option, float initialInv, float rate, float invTime, float finalAmt) 
{
  if (option == 4 )
  {
    printf("\nInitial investment - $ %.2f\n", initialInv);
    printf("Annual interest rate - %.2f%%\n", rate);
    printf("Time of investment - %.2f\n", invTime);
    printf("Final value:  $ %.2f\n", finalAmt); 
  }
  else if (option == 3 )
  {
    printf("\nInitial investment - $ %.2f\n", initialInv);
    printf("Annual interest rate - %.2f%%\n", rate);
    printf("Time of investment:  %.2f\n", invTime);
    printf("Final value - $ %.2f\n", finalAmt); 
  }
  else if (option == 2 )
  {
    printf("\nInitial investment:  $ %.2f\n", initialInv);
    printf("Annual interest rate - %.2f%%\n", rate);
    printf("Time of investment - %.2f\n", invTime);
    printf("Final value - $ %.2f\n", finalAmt); 
  }
  else if (option == 1 )
  {
    printf("\nInitial investment - $ %.2f\n", initialInv);
    printf("Annual interest rate:  %.2f%%\n", rate);
    printf("Time of investment - %.2f\n", invTime);
    printf("Final value - $ %.2f\n", finalAmt); 
  }
}

