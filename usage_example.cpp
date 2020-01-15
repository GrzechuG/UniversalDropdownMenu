#include "menu.h"
#include <iostream>

int main(void)
{
    MENU_init();
    int input;

    while (true)
    {
        myMenu m = MENU_getStructure();

        cout << "[ " << m.title << " ]" << endl;

        for (int i = 0; i < m.options.size(); i++)
        {
            string t = m.options.at(i);
            if (m.selected_option == i)
                cout << " > ";
            else
                cout << "   ";
            cout << t << endl;
        }

        cin >> input;
        switch (input)
        {
        case 0:
            MENU_selectPrevious();
            break;
        case 1:
            MENU_selectNext();
            break;
        case 2:
            MENU_goInto();
            break;
        case 3:
            MENU_goBack();
            break;
        }
    }
}
