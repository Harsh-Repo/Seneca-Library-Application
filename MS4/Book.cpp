/***********************************************************************
// OOP244 Utils Module
// File	Utils.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include<iomanip>
#include "Book.h"
#include "Lib.h"
using namespace std;
namespace sdds {
	Book::Book() : Publication()
	{
		delete[] m_author;
		m_author = new char[2];
		m_author[0] = '\0';
	}

	Book::Book(const Book& B) : Publication(B)
	{
		delete[] m_author;
		m_author = nullptr;
		if (B)
		{
			m_author = new char[strlen(B.m_author) + 1];
			strcpy(m_author, B.m_author);
		}
		else
			m_author = nullptr;
	}

	Book& Book::operator=(const Book& B)
	{
		if (this != &B)
		{
			Publication::operator=(B);
			if (B.m_author != nullptr)
			{
				delete[] m_author;
				m_author = new char[strlen(B.m_author) + 1];
				strcpy(m_author, B.m_author);
			}
		}
		return *this;
	}

	Book::~Book()
	{
		delete[] m_author;
		m_author = nullptr;
	}

	char Book::type()const
	{
		return 'B';
	}

	std::ostream& Book::write(std::ostream& os) const
	{
		if (*this)
		{
			Publication::write(os);
			if (Publication::conIO(os))
			{
				os << " ";
				os.setf(ios::left);
				if (strlen(m_author) > SDDS_AUTHOR_WIDTH)
				{
					for (int i = 0; i < SDDS_AUTHOR_WIDTH; i++)
					{
						os << m_author[i];
					}
				}
				else
				{
					os.width(SDDS_AUTHOR_WIDTH);
					os.fill(' ');
					os << m_author;
				}
				os.unsetf(ios::left);
				os << " |";
			}
			else
			{
				os << '\t';
				os << m_author;
			}
		}
		return os;
	}

	std::istream& Book::read(std::istream& istr)
	{
		string name;
		Publication::read(istr);
		delete[] m_author;
		m_author = nullptr;
		if (Publication::conIO(istr))
		{
			Publication::extractChar(istr, '\n');
			cout << "Author: ";
			getline(istr, name, '\n');
			if (name.length() > 256)
			{
				istr.setstate(ios::failbit);
			}

			if (istr)
			{
				m_author = new char[name.length() + 1];
				strcpy(m_author, name.c_str());
			}

			else
				m_author = nullptr;
		}
		else
		{
			Publication::extractChar(istr, '\t');
			char temp[256];
			istr.get(temp, 256, '\n');
			if (istr)
			{
				m_author = new char[strlen(temp) + 1];
				strcpy(m_author, temp);
			}

			else
				m_author = nullptr;
		}

		return istr;
	}

	void Book::set(int member_id)
	{
		Publication::set(member_id);
		Publication::resetDate();
	}

	Book::operator bool() const
	{
		return m_author != nullptr && m_author[0] != '\0' && Publication::operator bool();
	}


}