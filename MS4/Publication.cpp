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
#include <string>
#include<iomanip>
#include"Utils.h"
#include"Lib.h"
#include "Publication.h"
using namespace std;
namespace sdds 
{
	void Publication::extractChar(std::istream& istr, char ch)
	{
		char next;
		next = istr.peek();
		if (next == ch)
		{
			istr.ignore();
		}
		else
		{
			istr.setstate(ios::failbit);
		}
	}

	Publication::Publication()
	{
		m_title = nullptr;
		m_shelfId[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
	}

	void Publication::set(int member_id)
	{
		if (member_id >= 10000 && member_id <= 99999)
			m_membership = member_id;
		else
			m_membership = 0;
	}
	
	void Publication::setRef(int value)
	{
		m_libRef = value;
	}
	
	void Publication::resetDate()
	{
		m_date = Date();
	}

	char Publication::type()const
	{
		return 'P';
	}
	
	bool Publication::onLoan()const
	{
		bool res = false;
		if (m_membership > 0)
			res = true;
		return res;
	}
	
	Date Publication::checkoutDate()const
	{
		return m_date;
	}

	bool Publication::operator==(const char* title)const
	{
		bool res = false;
		if (strstr(m_title, title) != nullptr)
			res = true;
		return res;
	}

	Publication::operator const char* ()const
	{
		return m_title;
	}

	int Publication::getRef()const
	{
		return m_libRef;
	}

	bool Publication::conIO(std::ios& io)const
	{
		bool res = false;
		if (&io == &cin || &io == &cout)
			res = true;
		return res;
	}
	std::ostream& Publication::write(std::ostream& os) const
	{
		if (*this)
		{
			if (conIO(os))
			{
				os << "| " << m_shelfId << " | ";
				os.setf(ios::left);
				if (strlen(m_title) > SDDS_TITLE_WIDTH)
				{
					for (int i = 0; i < SDDS_TITLE_WIDTH; i++)
					{
						os << m_title[i];
					}
				}
				else
				{
					os.width(SDDS_TITLE_WIDTH);
					os.fill('.');
					os << m_title;
				}
				os.unsetf(ios::left);
				os << " | ";
				if (onLoan())
					os << m_membership;
				else
					os << " N/A ";
				os << " | " << m_date << " |";
			}
			else
			{
				os << type() << "\t" << m_libRef << "\t" << m_shelfId << "\t" << m_title << "\t" << m_membership << "\t" << m_date;
			}
		}
		return os;
	}
	std::istream& Publication::read(std::istream& istr)
	{
		delete m_title;
		m_title = nullptr;
		m_shelfId[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
		string title;
		string shelfId;
		int membership = 0;
		int libRef = -1;
		Date date;
		if (conIO(istr))
		{
			cout << "Shelf No: ";
			istr >> shelfId;
			if (shelfId.length() != SDDS_SHELF_ID_LEN)
			{
				istr.setstate(ios::failbit);
			}
			cout << "Title: ";
			istr.ignore();
			getline(istr, title, '\n');
			cout << "Date: ";
			istr >> date;	

		}
		else
		{
			istr >> libRef;
			extractChar(istr, '\t');
			getline(istr, shelfId, '\t');
			getline(istr, title, '\t');
			istr >> membership;
			istr >> date;
		}
		if (date.errCode() != 0)
		{
			istr.setstate(ios::failbit);
		}
		if (istr)
		{
			m_title = new char[title.length() + 1];
			strcpy(m_title, title.c_str());
			strcpy(m_shelfId, shelfId.c_str());
			m_membership = membership;
			m_date = date;
			m_libRef = libRef;
		}
		else
		{
			m_title = nullptr;
			m_shelfId[0] = '\0';
			m_membership = 0;
			m_libRef = -1;
		}
		return istr;
	}
	Publication::operator bool() const
	{
		return m_title != nullptr && m_shelfId[0] != '\0';
	}
	Publication::Publication(const Publication& PU) : Streamable(PU)
	{
		if (PU)
		{
			m_title = new char[strlen(PU.m_title) + 1];
			strcpy(m_title, PU.m_title);
			strcpy(m_shelfId, PU.m_shelfId);
			m_membership = PU.m_membership;
			m_libRef = PU.m_libRef;
			//m_date = PU.m_date;
		}
		else
		{
			m_title = nullptr;
			m_shelfId[0] = '\0';
			m_membership = 0;
			m_libRef = -1;
		}
	}
	Publication& Publication::operator=(const Publication& PU)
	{
		if (this != &PU)
		{
			Streamable::operator =(PU);
			delete[] m_title;
			m_libRef = PU.m_libRef;
			m_membership = PU.m_membership;
			if (PU.m_title != nullptr)
			{
				m_title = new char[strlen(PU.m_title) + 1];
				strcpy(m_title, PU.m_title);
			}
			else
			{
				m_title = nullptr;
			}

			if (PU.m_shelfId[0] != '\0')
			{
				strcpy(m_shelfId, PU.m_shelfId);
			}
			else
			{
				m_shelfId[0] = '\0';
			}

			m_date = PU.m_date;
		}
		
		return *this;
	}
	Publication::~Publication()
	{
		delete[] m_title;
		m_title = nullptr;
	}
}