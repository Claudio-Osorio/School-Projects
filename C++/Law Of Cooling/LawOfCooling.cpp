#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
/*
 *
 * Name: Claudio Osorio
 * Date: 09/12/2020
 * Section: Module 3
 * Assignment: Newton's Law of Cooling Formula
 * Due Date: Sep 13 by 11:59pm EST
 * About this project: The user will enter some values to momentarily store them in variables such as time,
 * surrounding temperature, and the cooling constant.The program will then use all the data. It will calculate the
 * temperature at a certain time and the user will receive a final summary.
 * with all the information provided and the results of the calculation.
 * Assumptions:
 * -The user will provide all the inputs in the stated and required units.
 * -The user won't use astronomical numbers.
 *
 * All work below was performed by Claudio Osorio
 *
 */
using namespace std;

int main() {
  const double ME = 2.71828182845904523536;
  string user_name;
  double time; //Time
  double temp_at_t; //Temperature at a certain time
  double surr_temp; //Surrounding temperature
  double start_temp;//Starting Temperature
  double cooling_const; //Cooling Constant


        //Asking for the user's name
  cout << "Please enter your name to continue:  ";
  getline(cin,user_name);

        //Welcome Message and Instructions
  cout << user_name << ", Claudio welcomes you to his Law of Cooling Program! [LCP]"
                          "\n\n\t\t\t\tIMPORTANT NOTE\n"
                         "Make sure you provide the time in seconds (s).\n"
                         "The temperature of your surroundings and of the object must be in Kelvin (K).\n"
                         "The cooling constant must be in units 1/seconds (1/s)." << endl;

        //Input requirement - Time
  cout << "\nPlease Enter The Following:"
          "\nTime:  ";
  cin >> time;

        //Input requirement - Temperature of the surroundings
  cout << "Temperature of the surroundings:  ";
  cin >> surr_temp;

        //Input requirement - Starting temperature of the object
  cout << "Starting temperature of the object:  ";
  cin >> start_temp;

        //Input requirement - Cooling Constant
  cout << "Cooling Constant:  ";
  cin >> cooling_const;

    //Calculation
  temp_at_t = surr_temp + (start_temp - surr_temp) * pow(ME,(- cooling_const * time));

  cout << "======================RESULTS======================" << endl;
    //Printing all the results to the screen
  cout << fixed << setprecision(5);
  cout << "Time (s):                           " << setw(15) << time          << endl;
  cout << "Temperature of the surroundings (K):" << setw(15) << surr_temp     << endl;
  cout << "Starting Temp of the Object (K):    " << setw(15) << start_temp    << endl;
  cout << "Cooling Constant (1/s):             " << setw(15) << cooling_const <<endl;
  cout << "Temperature at a certain time:      " << setw(15) << temp_at_t     << endl;
  cout << "===================================================" << endl;
    //Showing the program exited successfully
  cout << "\nProgram Concluded. No numbers were hurt. Have a nice day!" <<endl;
  return 0;
}
