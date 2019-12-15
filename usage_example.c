#include "menu.h"

int main() {
        // Only for testing:
//        int index=0;
        int input;

        enum act action;
        action=LEFT;
//        int layer = 0;
        while(1) {
                scanf("%d", &input);
                action=input;
                //input = getchar();
                //printf("%d",input);
                menu(action);
        }
        return 0;
}
