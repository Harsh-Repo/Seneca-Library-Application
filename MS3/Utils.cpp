/*
NAME: harsh patel
Student Number:146315205
Student E-mail Address -hpatel262@myseneca.ca
Section Information Code- NII
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

#include "Utils.h"

using namespace std;
namespace sdds
{

    void extractChar(istream& istr, char ch)
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

    void getFoolproofInt(unsigned int& value, const unsigned int min, const unsigned int max)
    {
        bool isValid = false;
        while (!isValid)
        {
            cin >> value;
            if (value >= min && value <= max && cin)
            {
                isValid = true;
            }
            else
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid Selection, try again: ";
            }
        }
    }
}

