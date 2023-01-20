/*
NAME: harsh patel
Student Number:146315205
Student E-mail Address -hpatel262@myseneca.ca
Section Information Code- NII
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef _SDDS_STREAMABLE_H
#define _SDDS_STREAMABLE_H

#include <iostream>

namespace sdds
{

    class Streamable
    {
    public:
        virtual std::ostream& write(std::ostream& os) const = 0;
        virtual std::istream& read(std::istream& is) = 0;
        bool conIO(std::ios& io) const;
        virtual operator bool() const = 0;
        virtual ~Streamable()
        {
        };

    };
    std::ostream& operator<<(std::ostream& os, const Streamable& right);
    std::istream& operator>>(std::istream& is, Streamable& right);
}

#endif

