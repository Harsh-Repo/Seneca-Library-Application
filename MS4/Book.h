/***********************************************************************
// OOP244 Utils Module
// File	Utils.h
// Version
// Date
// Author
// Description
//
// Revision History
// -----------------------------------------------------------
// Name     Harsh Patel       Date     01/12/2021       Reason		Project MS1
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_BOOK_H__
#define SDDS_BOOK_H__
#include <iostream>
#include "Publication.h"
using namespace std;

namespace sdds {
	class Book : public Publication
	{
		char* m_author{};
	public:
		Book();
		Book(const Book& B);
		Book& operator=(const Book& B);
		~Book();
		virtual char type()const;
		virtual std::ostream& write(std::ostream& os) const;
		virtual std::istream& read(std::istream& istr);
		virtual void set(int member_id);
		virtual operator bool() const;
	};

}
#endif // SDDS_UTILS_H__
