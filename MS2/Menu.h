/*
NAME: harsh patel
Student Number:146315205
Student E-mail Address -hpatel262@myseneca.ca
Section Information Code- NII
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__
#include <iostream>
namespace sdds
{
    class Menu;
    const int MAX_MENU_ITEMS = 20;

    class MenuItem
    {
        char* p_title{};
        friend class Menu;
        MenuItem();
        MenuItem(const char* str);
        MenuItem(const MenuItem&) = delete;
        MenuItem& operator= (const MenuItem&) = delete;
        ~MenuItem();
        operator bool() const;
        operator const char* () const;
        std::ostream& display(std::ostream& os = std::cout)const;
    };


    class Menu
    {
        MenuItem m_title{};

        MenuItem* m_menuItem[MAX_MENU_ITEMS]{};
        int numMenuItems{};
    public:
        Menu();
        Menu(const char* title);
        Menu(const Menu&) = delete;
        Menu& operator= (const Menu&) = delete;
        ~Menu();
        std::ostream& displayTitle(std::ostream& os) const;
        std::ostream& displayMenu(std::ostream& os) const;
        int run() const;
        int operator~() const;
        Menu& operator<<(const char* menuitemConent);
        operator int() const;
        operator bool() const;
        operator unsigned int() const;
        const char* operator[](int index) const;
    };
    std::ostream& operator<<(std::ostream& os, const Menu& menu);
}
#endif