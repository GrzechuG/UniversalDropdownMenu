#include "menu.h"
//enum act{LEFT=1, RIGHT=0, GO_INTO=2, GO_BACK=3};
int main() {
        // Only for testing:
//        int index=0;
        int input;

        //enum act action;
        int action=1;
//        int layer = 0;
        while(1) {
                scanf("%d", &input);

                //input = getchar();
                //printf("%d",input);
                menu(input);
        }
        return 0;
}
