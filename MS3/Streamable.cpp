/*
NAME: harsh patel
Student Number:146315205
Student E-mail Address -hpatel262@myseneca.ca
Section Information Code- NII
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Streamable.h"
using namespace std;

namespace sdds
{

    ostream& operator<<(ostream& os, const Streamable& right)
    {
        return right.write(os);
    }

    istream& operator>>(istream& is, Streamable& right)
    {
        return right.read(is);
    }
}
