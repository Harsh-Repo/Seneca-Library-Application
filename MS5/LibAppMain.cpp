/*
NAME: harsh patel
Student Number:146315205
Student E-mail Address -hpatel262@myseneca.ca
Section Information Code- NII
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include "LibApp.h"
#include "Date.h"
int main() {
	sdds::sdds_day = 10;
	sdds::sdds_mon = 12;
	sdds::sdds_year = 2021;
	sdds::sdds_test = true;
	sdds::LibApp theApp("LibRecsSmall.txt");
	theApp.run();
	return 0;
}