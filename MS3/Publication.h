/*
NAME: harsh patel
Student Number:146315205
Student E-mail Address -hpatel262@myseneca.ca
Section Information Code- NII
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_PUBLICATION_H
#define SDDS_PUBLICATION_H

#include <iostream>
#include "Date.h"
#include "Streamable.h"

//Rule of 3

namespace sdds
{

    // class Streamable{
    // public:
    //     virtual std :: ostream& write(std :: ostream& os) const = 0;
    //     virtual std :: istream& read (std :: istream& is) = 0;
    //     bool conIO(std :: ios& io) const;
    //     virtual operator bool() const = 0;
    //     virtual ~Streamable() {};

    // };

    class Publication : public Streamable
    {
        char* m_title;
        char m_shelfId[5];
        int m_membership;
        int m_libRef;
        Date m_date;

        void setEmpty();

    public:
        Publication();

        //Queries
        virtual char type()const;
        //Returns the character 'P' to identify this object as a "Publication object"
        bool onLoan()const;
        //Returns true is the publication is checkout (membership is non-zero)
        Date checkoutDate()const;
        //Returns the date attribute
        bool operator==(const char* title)const;
        //Returns true if the argument title appears anywhere in the title of the
        //publication. Otherwise, it returns false; (use strstr() function in <cstring>)
        operator const char* ()const;
        //Returns the title attribute
        int getRef()const;
        //Returns the libRef attirbute.

        //Modidiers
        virtual void set(int member_id);
        // Sets the membership attribute to either zero or a five-digit integer.
        void setRef(int value);
        // Sets the **libRef** attribute value
        void resetDate();
        // Sets the date to the current date of the system

        bool conIO(std::ios& io)const;
        virtual std::ostream& write(std::ostream& os) const;
        virtual std::istream& read(std::istream& istr);
        virtual operator bool() const;

        virtual ~Publication();
        Publication(const Publication& source);
        Publication& operator=(const Publication& source);
    };

    // std :: ostream& operator<<(std :: ostream& os, const Streamable& right);
    // std :: istream& operator>>(std :: istream& is, Streamable& right);

}

#endif

