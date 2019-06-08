#include <stdio.h>
#include <string.h>
#define ALL_MENU_ELEMENTS 20
#define ALL_BRANCHES 20



int menu_index = 0;
int menu_branch = 0;

int main() {
        // Only for testing:
        int index=0;
        int input;
        int action = 0;
        int layer = 0;
        while(1) {
                scanf("%d", &input);



                //input = getchar();
                //printf("%d",input);
                menu(input);
        }
        return 0;
}



typedef struct MNODE {
        unsigned char id; //uint8_t
        const char * title;
        unsigned char funct_prop;

        const struct MNODE * branch_next;
        const struct MNODE * branch_prev;

        const struct MNODE * node_next;
        const struct MNODE * node_prev;


}TNODE;

int menu(int action){
        //char temp[20];
        //scanf("%s" , temp);

        // printf(temp);

        TNODE actual;
        TNODE null;

        //DANE TWORZACE STRUKTURE:
        TNODE menu;
        TNODE siec;
        TNODE rtc_setup;
        TNODE rs232;

        TNODE Numer_IP;
        TNODE CZAS;
        TNODE DATA;
        TNODE BAUD;
        TNODE BIT;
        TNODE FLOW;

        TNODE NTP;
        TNODE GMT;

//   telewizor.title="Network";
        siec.title="siec";

        rtc_setup.title="rtc_setup";
        rs232.title="rs232";

        siec.node_next=&rtc_setup;
        siec.node_prev=&rs232;
        siec.node_prev=&rs232;


        //KONIEC DANYCH TWORZACYCH STRUKTURE

        //printf(all[0].dropDown[0]);
        if (action == 1) {
                menu_index=(menu_index+1)%max;

        }
        if(action == 0) {
                menu_index=(menu_index-1)%max;

        }
        if(action == 2) {

                menu_branch++;

        }
        if(action == 3) {
                menu_branch--;

        }




        return 0;
}

void drawMenu();
