/*
NAME: harsh patel
Student Number:146315205
Student E-mail Address -hpatel262@myseneca.ca
Section Information Code- NII
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

// Final Project Milestone 2
// LibApp Mockup Module
// File	ms2_tester.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Fardad             2021/11/09		       Preliminary release
/////////////////////////////////////////////////////////////////
#include <iostream>
#include "LibApp.h"
using namespace std;
int main() {
   sdds::LibApp theApp;
   cout << endl << "Testing exiting with no change:" << endl;
   theApp.run();
   cout << endl << "Testing exiting with change and discarding data:" << endl;
   theApp.run();
   cout << endl << "Testing exiting with change and saving data:" << endl;
   theApp.run();
   cout << endl << "Testing all actions:" << endl;
   theApp.run();
   return 0;
}
/* data to be entered:
 1- 1
 2- 0
 3- 0
 4- 2
 5- 1
 6- 0
 7- 0
 8- 1
 9- 3
10- 1
11- 0
12- 1
13- 4
14- 0
15- 2
16- 0
17- 1
*/