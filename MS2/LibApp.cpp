/*
NAME: harsh patel
Student Number:146315205
Student E-mail Address -hpatel262@myseneca.ca
Section Information Code- NII
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "LibApp.h"
using namespace std;

namespace sdds {
    bool LibApp::confirm(const char* message)
    {
        bool res = false;
        Menu menu(message);
        menu << "Yes";
        if (menu.run() == 1)
            res = true;
        return res;
    }

    void LibApp::load()
    {
        cout << "Loading Data" << endl;
    }

    void LibApp::save()
    {
        cout << "Saving Data" << endl;
    }

    void LibApp::search()
    {
        cout << "Searching for publication" << endl;
    }

    void LibApp::returnPub()
    {
        search();
        cout << "Returning publication" << endl;
        cout << "Publication returned" << endl;
        m_changed = true;
    }

    void LibApp::newPublication()
    {
        cout << "Adding new publication to library" << endl;
        if (confirm("Add this publication to library?"))
        {
            m_changed = true;
            cout << "Publication added" << endl;
        }
    }

    void LibApp::removePublication()
    {
        cout << "Removing publication from library" << endl;
        search();
        if (confirm("Remove this publication from the library?"))
        {
            m_changed = true;
            cout << "Publication removed" << endl;
        }
    }

    void LibApp::checkOutPub()
    {
        search();
        if (confirm("Check out publication?"))
        {
            m_changed = true;
            cout << "Publication checked out" << endl;
        }
    }

    LibApp::LibApp()
    {
        m_changed = false;
        m_mainMenu.~Menu();
        new(&m_mainMenu) Menu("Seneca Library Application");
        m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
        m_exitMenu.~Menu();
        new(&m_exitMenu) Menu("Changes have been made to the data, what would you like to do?");
        m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
        load();
    }

    void LibApp::run()
    {
        int s;
        do
        {
            s = m_mainMenu.run();
            switch (s)
            {
            case 1:
                newPublication();
                break;
            case 2:
                removePublication();
                break;
            case 3:
                checkOutPub();
                break;
            case 4:
                returnPub();
                break;
            case 0:
                if (m_changed)
                {
                    int p = m_exitMenu.run();
                    switch (p)
                    {
                    case 1:
                        save();
                        break;
                    case 2:
                        s = 1;
                        break;
                    case 0:
                        if (confirm("This will discard all the changes are you sure?"))
                        {
                            // do nothing, program terminates automatically
                        }
                        break;
                    }
                }
                break;
            }

            cout << endl;
        } while (s != 0);

        cout << "-------------------------------------------" << endl;
        cout << "Thanks for using Seneca Library Application" << endl;
    }

}
