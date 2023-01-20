/*
NAME: harsh patel
Student Number:146315205
Student E-mail Address -hpatel262@myseneca.ca
Section Information Code- NII
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <cstring>
#include <ctime>
#include "Menu.h"
using namespace std;
namespace sdds
{
    MenuItem::MenuItem()
    {
        p_title = nullptr;
    }

    MenuItem::MenuItem(const char* str)
    {
        if (str != nullptr)
        {
            p_title = new char[strlen(str) + 1];
            strcpy(p_title, str);
        }
        else
            str = nullptr;
    }

    MenuItem::~MenuItem()
    {
        delete[] p_title;
        p_title = nullptr;
    }
    MenuItem::operator bool() const
    {
        return p_title != nullptr;
    }

    MenuItem::operator const char* () const
    {
        return p_title;
    }

    std::ostream& MenuItem::display(std::ostream& os) const
    {
        os << p_title;
        return os;
    }

    Menu::Menu()
    {
        m_title.p_title = nullptr;
        m_menuItem[0] = nullptr;
        numMenuItems = 0;
    }

    Menu::Menu(const char* title)
    {

        if (title != nullptr && title[0] != '\0')
        {
            m_title.p_title = new char[strlen(title) + 1];
            strcpy(m_title.p_title, title);
            for (int i = 0; i < MAX_MENU_ITEMS; i++)
            {
                delete[] m_menuItem[i];
                m_menuItem[i] = nullptr;
            }
            numMenuItems = 0;
        }
    }

    Menu::~Menu()
    {
        delete[] m_title;
        m_title.p_title = nullptr;
        for (int i = 0; i < numMenuItems; i++)
        {
            delete m_menuItem[i];
            m_menuItem[i] = nullptr;
        }
    }

    std::ostream& Menu::displayTitle(std::ostream& os) const
    {
        if (m_title != nullptr)
        {
            os << m_title.p_title;
        }
        return os;
    }

    std::ostream& Menu::displayMenu(std::ostream& os) const
    {
        if (m_title.p_title != nullptr)
            os << m_title.p_title << endl;
        if(numMenuItems > 0)
        {
            for (int i = 0; i < numMenuItems; i++)
            {
                os.setf(ios::right);
                os.width(2);
                os.fill(' ');
                os << i + 1;
                os.unsetf(ios::right);
                os << "- ";
                os << m_menuItem[i]->p_title << endl;
            }
            os << " 0- Exit" << endl << "> ";
        }
        return os;
    }

    int Menu::run() const
    {
        int input = 0;
        displayMenu(std::cout);
        bool ok = false;
        char newline;
        do
        {
            cin >> input;
            newline = cin.get();
            if (cin.fail() || newline != '\n')
            {
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else
            {
                ok = input <= numMenuItems && input >= 0;
            }
        } while (!ok && cout << "Invalid Selection, try again: ");
        return input;
    }

    int Menu::operator~() const
    {
        return run();
    }

    Menu& Menu::operator<<(const char* menuitemConent)
    {
        if (menuitemConent != nullptr && numMenuItems < MAX_MENU_ITEMS)
        {
            m_menuItem[numMenuItems] = new MenuItem(menuitemConent);
            numMenuItems++;
        }
        return *this;
    }

    Menu::operator int() const
    {
        return numMenuItems;
    }

    Menu::operator bool() const
    {
        return m_title != nullptr;
    }

    Menu::operator unsigned int() const
    {
        return numMenuItems;
    }

    const char* Menu::operator[](int index) const
    {
        return *m_menuItem[index % numMenuItems];
    }

    std::ostream& operator<<(std::ostream& os, const Menu& menu)
    {
        return menu.displayTitle(os);
    }
}