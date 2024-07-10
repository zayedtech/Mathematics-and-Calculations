/*****+-*-*--**-***-*-*-*-**---*----*--*---**-*--***************************
*
*  Lab # 04: 
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Program Description: creating seperate functions that calculate different information about a trajectory
*
******+-*-*--**-***-*-*-*-**---*----*--*---**-*--**************************/
#include <stdio.h>
#include <math.h>
#define GRAVITY 9.81

double maxHeight_func(double , double); // maximum height of the trajectory function declaration
double direction_func(double , double, double); // direction at impact function declaration
double time_func(double , double, double); // time of flight function declaration
double impact_vel_func(double , double, double); // impact velocity function declaration
double range_func(double , double, double); // range of trajectory function declaration
double velocity_initial_func(void); // initial velocity's function declaration, returns initial velocity
double theta_func(void); // angle function declaration, returns angle in radians
double altitude_func(void); // altitude function declaration, returns altitude
void getOutput(double, double, double, double, double);

int main(void)
{
  double maxHeight; //initialized variable that will store the  value returned from maxHeight_func
  double direction; //initializes variable that  will store the value returned from direction_func
  double time; //initialized variable that will store the value returned from time_func
  double impact_vel; //initializes variable that will store the value returned from impact_vel_func
  double range;  //initializes variable that will store the value returned from range_func
  double velocity_initial;  //initializes variable that will store the value returned from velocity_initial_func
  double theta; //initializes variable that will store the value returned from theta_funcc
  double altitude; //initializes variable that will store the value returned from altitude_func
 
 //function calls
  velocity_initial = velocity_initial_func();
  theta = theta_func();
  altitude = altitude_func();
  time = time_func(velocity_initial, theta, altitude);
  maxHeight = maxHeight_func(velocity_initial,theta);
  range = range_func(time, velocity_initial, theta);
  direction = direction_func(velocity_initial,theta,time);
  impact_vel = impact_vel_func(velocity_initial,theta,time);
  
  getOutput(time, maxHeight, range, direction, impact_vel);

  return(0);
}
/*****+***-**--**-**--**--*----*-*--*--*---**-*--***************************
*
*  Function Information
*
*  Name of Function: veolcity_initial_func
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line): None
*    1.
*    2.
*    3.
*
*  Function Description: Prints text and returns user's input of initial velocity
*
******+***-**--**-**--**--*----*-*--*--*---**-*--**************************/
double velocity_initial_func(void)
{ 
  double velocity_initial; // temporary variables

  printf("Enter initial speed in m/s -> ");
  scanf("%lf", &velocity_initial);

  return(velocity_initial);
}
/*****+*-***---**-**--**--*----*-*--*--*---**-*--***************************
*
*  Function Information
*
*  Name of Function: theta_func
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line): None
*    1.
*    2.
*    3.
*
*  Function Description: Prints text and return's user input of angle in RADIANS
*
******+*-***---**-**--**--*----*-*--*--*---**-*--**************************/
double theta_func(void)
{ 
  
  double theta; //temporary variables
  double radtheta; //temporary variables

  printf("Enter launch angle in degrees -> ");
  scanf("%lf", &theta);

  radtheta = theta * M_PI / 180;

  return(radtheta);
}
/*****+******-**--**--**--*----*-*--*--*---**-*--***************************
*
*  Function Information
*
*  Name of Function: altitude_func
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line): None
*    1.
*    2.
*    3.
*
*  Function Description: Prints text and returns user input of altitude
*
******+******-**--**--**--*----*-*--*--*---**-*--**************************/
double altitude_func(void)
{ 
  double altitude; // temporary variable

  printf("Enter impact altitude in meters -> ");
  scanf("%lf", &altitude);

  return(altitude);
}
/*****+*-****-**--**--**--*----*-*--*--*---**-*--***************************
*
*  Function Information
*
*  Name of Function: maxHeight_func
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double velocity_initial - Initial veolcity used to calculate the maximum height
*    2.double theta - Angle used to calculate maximum height
*    3.
*
*  Function Description: Returns maximum height of the trajectory
*
******+*-****-**--**--**--*----*-*--*--*---**-*--**************************/
double maxHeight_func(double velocity_initial, double theta)
{
  
  double height; //temporary variables
  double height_num; //temporary variables
  height_num = velocity_initial * sin(theta) * velocity_initial * sin(theta);
  height = height_num / (2 * GRAVITY);
  return (height);
}
/*****+*-***--**--**--**--*----*-*--*--*---**-*--***************************
*
*  Function Information
*
*  Name of Function: direction_func
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double velocity_initial - initial velocity to calculate the direction of trajectory
*    2.double theta - Launch angle used to calculate the direction of trajectory
*    3.double time - time of the flight
*
*  Function Description: Returns the direction of the object at impact
*
******+*-***--**--**--**--*----*-*--*--*---**-*--**************************/
double direction_func(double velocity_initial, double theta, double time)
{
  double direction_num; //temporary variables
  double direction_den; //temporary variable
  double direction; //temporary variable

  direction_num = (velocity_initial * sin(theta)) - (GRAVITY * time);
  direction_den = velocity_initial * cos(theta);
  direction = atan(direction_num / direction_den);
  direction = direction * 180 / M_PI;

  return(direction);
}
/*****+*-****--*--**--**--*----*-*--*--*---**-*--***************************
*
*  Function Information
*
*  Name of Function: time_func
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double velocity_initial - uses the initial veolcity to calculate the time
*    2.double theta - uses the launch angle to calculate time
*    3.double altitude - uses the altitude to calculate time
*
*  Function Description: Returns the time taken to complete the flight
*
******+*-****--*--**--**--*----*-*--*--*---**-*--**************************/
double time_func(double velocity_initial, double theta, double altitude)
{
  double time_num; //temporary variable
  double time; //temporary variable

  time_num = velocity_initial * sin(theta) + sqrt(velocity_initial * sin(theta) * velocity_initial * sin(theta) + 2 * GRAVITY * altitude);
  time = time_num / GRAVITY;

  return (time);
}
/*****+*-*-**--*--**--**--*----*-*--*--*---**-*--***************************
*
*  Function Information
*
*  Name of Function: impact_vel_function
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double velocity_initial - uses initial velocity to calculate the impact velocity
*    2.double theta - uses the launch angle to calculate the impact velocity
*    3.double time - uses time of the flight to calculate the impact velocity
*
*  Function Description: Returns the impact velocity
*
******+*-*-**--*--**--**--*----*-*--*--*---**-*--**************************/
double impact_vel_func(double velocity_initial, double theta, double time)
{
  double impact_vel = sqrt(velocity_initial * cos(theta) * velocity_initial * cos(theta) + ((velocity_initial * sin(theta) - GRAVITY * time) * (velocity_initial * sin(theta) - GRAVITY * time))); //temporary variable

  return (impact_vel);
}
/*****+*-***---*--**--**--*----*-*--*--*---**-*--***************************
*
*  Function Information
*
*  Name of Function: range_func
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double time - uses time to calculate range 
*    2.double velocity_initial - uses initial velocity to calculate the range
*    3.double theta - uses launch angle to calculate the range
*
*  Function Description: Returns range of the function
*
******+*-***---*--**--**--*----*-*--*--*---**-*--**************************/
double range_func(double time, double velocity_initial, double theta)
{
  double range; //temporary variable
  range = time * velocity_initial * cos(theta); 

  return (range);
}

/*****+*****--***-**--***-*-*-****-----*---**-*--***************************
*
*  Function Information
*
*  Name of Function: getOutput
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):NONE
*    1.
*    2.
*    3.
*
*  Function Description: Prints the results of each calculation
*
******+*****--***-**--***-*-*-****-----*---**-*--**************************/

void getOutput(double time, double maxHeight, double range, double direction, double impact_vel) 
{
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Time of flight: %13.2lf s\n", time);
  printf("Maximum height: %13.2lf m\n", maxHeight);
  printf("Range of the object: %8.2lf m\n", range);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Direction at impact: %+8.2lf\302\260\n", direction);
  printf("Velocity at impact: %9.2lf m/s\n",impact_vel);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  
  return;
}
