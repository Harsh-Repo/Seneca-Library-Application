/*
NAME: harsh patel
Student Number:146315205
Student E-mail Address -hpatel262@myseneca.ca
Section Information Code- NII
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include"Publication.h"

namespace sdds {
	class Book : public Publication {
		char* m_authorname{};
	private:
		void set(const char* authorname);
	public:
		Book();

		// RULE OF THREE
		Book(const Book& bk);
		Book& operator=(const Book& bk);
		~Book();

		char type()const;
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& istr);
		void set(int member_id);
		operator bool()const;
	};
	std::ostream& operator<<(std::ostream& os, const Book& obj);
	std::istream& operator>>(std::istream& is, Book& obj);
}


#endif