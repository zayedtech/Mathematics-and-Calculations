/*****+*-****-***--**--*--*----*-*--*--*---**-*--***************************
*
*  Homework #: 03
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Program Description: Creating user defined functions to calculate the speed of water in two different hoses.
*
******+*-****-***--**--*--*----*-*--*--*---**-*--**************************/

#include<stdio.h>
#include<math.h>

#define LITERTOM3CONVER 0.001
#define CMTOMETERCONVER 0.01

double getInput1(void); // function declaration for gettting radius 1
double getInput2(void); // function declaration for gettting radius 2
double getInput3(void); // function declaration for getting flow rate
double velocityWater(double, double); // function declaration for calculating flow rate
void getOutput(double, double);
int main(void)
{
  double radius1; // will hold the value of the user's first input
  double radius2; // will hold the value of the user's second input
  double flowRate; // will hold the value of the user's third input
  double velocity1; // will hold the value returned from velocityWater function when radius = radius1
  double velocity2; // will hold the value returned from velocityWater function when radius = radius2

  radius1 = getInput1(); // function call
  radius2 = getInput2(); // function call
  flowRate = getInput3(); // function call
  
  velocity1 = velocityWater(flowRate, radius1); // function call
  velocity2 = velocityWater(flowRate, radius2); // function call
  
  getOutput(velocity1, velocity2);
  return(0);
}
/*****+***-**-***--*--***---*-*****----*---**-*--***************************
*
*  Function Information
*
*  Name of Function: getInput1
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line): None
*    1.
*    2.
*    3.
*
*  Function Description: will return the user's input for radius 1
*
******+***-**-***--*--***---*-*****----*---**-*--**************************/

double getInput1(void)
{
  double radius; // temporary variable to store radius 1

  printf("Enter the radius of hose #1 (cm) -> ");
  scanf("%lf", &radius );

  return(radius);
}
/*****+***-**-***--*--***---*-*****----*---**-*--***************************
*
*  Function Information
*
*  Name of Function: getInput2
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line): None
*    1.
*    2.
*    3.
*
*  Function Description: will return the user's input for radius 2
*
******+***-**-***--*--***---*-*****----*---**-*--**************************/
double getInput2(void)
{
  double radius; // temporary variable to store radius 2
  
  printf("Enter the radius of hose #2 (cm) -> ");
  scanf("%lf", &radius);
  
  return(radius);
}
/*****+*-****--**--*--***---*-*****----*---**-*--***************************
*
*  Function Information
*
*  Name of Function: getInput3
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line): none
*    1.
*    2.
*    3.
*
*  Function Description: Returns the user's input of flowrate
*
******+*-****--**--*--***---*-*****----*---**-*--**************************/

double getInput3(void)
{
  double flowRate; // temporary variable to store the flowrate

  printf("Enter the flow rate (L/s) -> ");
  scanf("%lf", &flowRate);

  return(flowRate);
}
/*****+*****--***-**---**-*---*****----*---**-*--***************************
*
*  Function Information
*
*  Name of Function: velocityWater
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double flow_rate - first operand for velocity of water calculation
*    2.double radius - second operand for velocity of water calculation
*    3.
*
*  Function Description: returns velocity of water
*
******+*****--***-**---**-*---*****----*---**-*--**************************/

double velocityWater(double flow_rate, double radius)
{
  double velocity; // temporary variable to store velocity calculated
  double area; // temporary variable to store area calculated
  
  radius = radius * CMTOMETERCONVER;
  flow_rate = flow_rate * LITERTOM3CONVER;
  area = M_PI * radius * radius;
  velocity = flow_rate / area;

  return(velocity);
}

/*****+***-*--**--**--***-*-*-****-----*---**-*--***************************
*
*  Function Information
*
*  Name of Function: getOutput
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line): NONE
*    1.
*    2.
*    3.
*
*  Function Description: Prints out text and displays the results
*
******+***-*--**--**--***-*-*-****-----*---**-*--**************************/

void getOutput(double vel1, double vel2)
{
  printf("\nThe speed of the water in the hose #1: %.2lf m/s", vel1);
  printf("\nThe speed of the water in the hose #2: %.2lf m/s\n", vel2);
}
