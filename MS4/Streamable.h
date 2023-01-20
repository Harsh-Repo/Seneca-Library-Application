/*
NAME: harsh patel
Student Number : 146315205
Student E - mail Address - hpatel262@myseneca.ca
Section Information Code - NII
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

// Final Project Milestone 1 
// Date Module
// File	Date.h
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Fardad             2021/10/29	       Preliminary release
/////////////////////////////////////////////////////////////////
#ifndef SDDS_STREAMABLE_H__
#define SDDS_STREAMABLE_H__
#include <iostream>
namespace sdds
{
	class Streamable
	{
	public:
		virtual std::ostream& write(std::ostream& os) const = 0;
		virtual std::istream& read(std::istream& os) = 0;
		virtual bool conIO(std::ios& ios) const = 0;
		virtual operator bool() const = 0;
		virtual ~Streamable() {}
	};
	std::ostream& operator<<(std::ostream& os, const Streamable& RO);
	std::istream& operator>>(std::istream& is, Streamable& RO);

}
#endif