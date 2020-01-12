#include "menu.h"

int main()
{
    // Only for testing:
    int input;
    int action = 1;
    while (1)
    {
        scanf("%d", &input);
        menu(input);
    }
    return 0;
}
