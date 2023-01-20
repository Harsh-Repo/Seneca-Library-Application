/*
NAME: harsh patel
Student Number:146315205
Student E-mail Address -hpatel262@myseneca.ca
Section Information Code- NII
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

// Final Project Milestone 1 
// Date Module
// File	Date.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Fardad             2021/10/29		       Preliminary release
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
#include "Streamable.h"
namespace sdds {
	std::ostream& operator<<(std::ostream& os, const Streamable& RO)
	{
		if(RO)
			RO.write(os);
		return os;
	}

	std::istream& operator>>(std::istream& is, Streamable& RO)
	{
		return RO.read(is);
	}

}