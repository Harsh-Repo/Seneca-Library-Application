/*
NAME: harsh patel
Student Number:146315205
Student E-mail Address -hpatel262@myseneca.ca
Section Information Code- NII
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<string>
#include<iomanip>
#include"Utils.h"
#include"Publication.h"
#include"Lib.h"
using namespace std;

namespace sdds
{

    void Publication::setEmpty()
    {
        m_title = nullptr;
        m_shelfId[0] = '\0';
        m_membership = 0;
        m_libRef = -1;
    }

    Publication::Publication()
    {
        setEmpty();
    }

    char Publication::type() const
    {
        return 'P';
    }

    bool Publication::onLoan()const
    {
        return m_membership != 0;
    }

    Date Publication::checkoutDate()const
    {
        return m_date;
    }

    bool Publication :: operator==(const char* title)const
    {
        bool result = false;
        if (strstr(m_title, title) != nullptr)
        {
            result = true;
        }

        return result;
    }

    Publication :: operator const char* ()const
    {
        return m_title;
    }

    int Publication::getRef()const
    {
        return m_libRef;
    }

    void Publication::set(int member_id)
    {
        m_membership = member_id;
    }

    void Publication::setRef(int value)
    {
        m_libRef = value;
    }

    bool Publication::conIO(ios& io)const
    {
        bool result = false;
        if (&io == &cin || &io == &cout)
        {
            result = true;
        }

        return result;
    }

    ostream& Publication::write(ostream& os) const
    {
        if (*this)
        {
            if (conIO(os))
            {
                os << "| " << m_shelfId << " | ";
                os.fill('.');
                os << left << setw(30) << m_title;
                os << " | ";
                if (onLoan())
                {
                    os << m_membership;
                }
                else
                {
                    os << " N/A ";
                }
                os << " | " << m_date << " |";
            }
            else
            {
                os << type() << '\t' << m_libRef << '\t' << m_shelfId << '\t' << m_title << "\t" << m_membership << "\t";
                os << m_date << " |";
            }
        }
        return os;
    }

    istream& Publication::read(istream& istr)
    {
        delete m_title;
        setEmpty();

        string tempShelfId;
        // char* tempTitle = nullptr;
        string tempTitle;
        // tempTitle = new char[SDDS_LIBRARY_TITLE_WIDTH];
        int tempLibRef = m_libRef;
        int tempMembership = m_membership;
        Date tempDate;

        if (conIO(istr))
        {
            cout << "Shelf No: ";
            istr >> tempShelfId;
            // getline(istr, tempShelfId, '\n');
            if (tempShelfId.length() != SDDS_SHELF_ID_LEN)
            {
                istr.setstate(ios::failbit);
            }
            cout << "Title: ";
            istr.ignore();
            getline(istr, tempTitle, '\n');
            cout << "Date: ";
            istr >> tempDate;

            if (tempDate.errCode() != 0)
            {
                istr.setstate(ios::failbit);
            }
        }
        else
        {
            istr >> tempLibRef;
            istr.ignore();
            getline(istr, tempShelfId, '\t');
            // istr.ignore();
            // istr.getline(tempTitle, SDDS_LIBRARY_TITLE_WIDTH, '\t');
            getline(istr, tempTitle, '\t');
            // istr.ignore();

            istr >> tempMembership;
            //  istr.ignore();

            istr >> tempDate;
            if (tempDate.errCode() != 0)
            {
                istr.setstate(ios::failbit);
            }
        }

        if (istr)
        {
            strcpy(m_shelfId, tempShelfId.c_str());
            m_title = new char[tempTitle.length() + 1];
            strcpy(m_title, tempTitle.c_str());
            m_membership = tempMembership;
            m_libRef = tempLibRef;
            m_date = tempDate;
        }
        else
        {
            setEmpty();
        }

        // delete [] tempTitle;
        // tempTitle = nullptr;
        return istr;
    }

    Publication :: operator bool() const
    {
        bool result = false;
        if (m_shelfId[0] != '\0' && m_title != nullptr)
        {
            result = true;
        }

        return result;
    }

    Publication :: ~Publication()
    {
        delete[] m_title;
        m_title = nullptr;
    }

    void Publication::resetDate()
    {
        m_date.reset();
    }


    Publication::Publication(const Publication& source) : Streamable(source)
    {
        m_libRef = source.m_libRef;
        m_membership = source.m_membership;
        if (source.m_title != nullptr)
        {
            m_title = new char[strlen(source.m_title) + 1];
            strcpy(m_title, source.m_title);
        }
        else
        {
            m_title = nullptr;
        }

        if (source.m_shelfId[0] != '\0')
        {
            strcpy(m_shelfId, source.m_shelfId);
        }
    }

    Publication& Publication :: operator=(const Publication& source)
    {
        if (this != &source)
        {
            Streamable::operator =(source);
            delete[] m_title;
            m_libRef = source.m_libRef;
            m_membership = source.m_membership;
            if (source.m_title != nullptr)
            {
                m_title = new char[strlen(source.m_title) + 1];
                strcpy(m_title, source.m_title);
            }
            else
            {
                m_title = nullptr;
            }

            if (source.m_shelfId[0] != '\0')
            {
                strcpy(m_shelfId, source.m_shelfId);
            }
            else
            {
                m_shelfId[0] = '\0';
            }

            m_date = source.m_date;
        }
        return *this;
    }
    // ostream& operator<<(ostream& os, const Streamable& right){
    //     return right.write(os);
    // }

    // istream& operator>>(istream& is, Streamable& right){
    //     return right.read(is);

    // }

}
