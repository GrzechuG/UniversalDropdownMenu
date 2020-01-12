#include "menu.h"
#include <iostream>
int main() {
    // Only for testing:
    int input;
    int action = 1;
    while (1) {
        scanf("%d", &input);
        myMenu m = menu(input);
        cout<<"["<<m.title<<"]"<<endl;

        for(int i =0; i<m.options.size(); i++) {
            string t = m.options.at(i);
            if(m.selected_option == i) {
                cout<<">";
            } else {
                cout<<" ";
            }
            cout<<t<<endl;
        }

    }
    return 0;
}
