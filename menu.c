#include <stdio.h>
#include <string.h>




int menu_index = 0;
int menu_branch = 0;
int first=1;
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

         struct MNODE * branch_next;
         struct MNODE * branch_prev;

         struct MNODE * node_next;
         struct MNODE * node_prev;


}TNODE;

TNODE * actual;
int menu(int action){



        TNODE null;
        null.title="null";
        //DANE TWORZACE STRUKTURE:

        // Generated using menu generator v1.1 (C) Grzegorz Gajewski Industries

        //Generating nodes 'Objects' and setting up names:
        TNODE MENU;
        MENU.title="MENU";
        TNODE SIEC;
        SIEC.title="SIEC";
        TNODE Numer_IP;
        Numer_IP.title="Numer_IP";
        TNODE RTC_SETUP;
        RTC_SETUP.title="RTC_SETUP";
        TNODE CZAS;
        CZAS.title="CZAS";
        TNODE NTP;
        NTP.title="NTP";
        TNODE GMT;
        GMT.title="GMT";
        TNODE DATA;
        DATA.title="DATA";
        TNODE RS232;
        RS232.title="RS232";
        TNODE BAUD;
        BAUD.title="BAUD";
        TNODE BIT;
        BIT.title="BIT";
        TNODE FLOW;
        FLOW.title="FLOW";
        TNODE EXIT;
        EXIT.title="EXIT";

        //Generating menu node structure:
        MENU.node_next=&null;
        MENU.node_prev=&null;
        SIEC.node_next=&RTC_SETUP;
        SIEC.node_prev=&null;
        RTC_SETUP.node_next=&RS232;
        RTC_SETUP.node_prev=&SIEC;
        RS232.node_next=&EXIT;
        RS232.node_prev=&RTC_SETUP;
        EXIT.node_next=&null;
        EXIT.node_prev=&RS232;
        Numer_IP.node_next=&null;
        Numer_IP.node_prev=&null;
        CZAS.node_next=&DATA;
        CZAS.node_prev=&null;
        DATA.node_next=&null;
        DATA.node_prev=&CZAS;
        NTP.node_next=&GMT;
        NTP.node_prev=&null;
        GMT.node_next=&null;
        GMT.node_prev=&NTP;
        BAUD.node_next=&BIT;
        BAUD.node_prev=&null;
        BIT.node_next=&FLOW;
        BIT.node_prev=&BAUD;
        FLOW.node_next=&null;
        FLOW.node_prev=&BIT;

        //Generating menu branch structure:
        MENU.branch_next=&RTC_SETUP;
        MENU.branch_prev=&null;
        SIEC.branch_next=&Numer_IP;
        SIEC.branch_prev=&MENU;
        Numer_IP.branch_next=&null;
        Numer_IP.branch_prev=&SIEC;
        RTC_SETUP.branch_next=&CZAS;
        RTC_SETUP.branch_prev=&MENU;
        CZAS.branch_next=&NTP;
        CZAS.branch_prev=&RTC_SETUP;
        NTP.branch_next=&null;
        NTP.branch_prev=&CZAS;
        GMT.branch_next=&null;
        GMT.branch_prev=&CZAS;
        DATA.branch_next=&null;
        DATA.branch_prev=&RTC_SETUP;
        RS232.branch_next=&BAUD;
        RS232.branch_prev=&MENU;
        BAUD.branch_next=&null;
        BAUD.branch_prev=&RS232;
        BIT.branch_next=&null;
        BIT.branch_prev=&RS232;
        FLOW.branch_next=&null;
        FLOW.branch_prev=&RS232;
        EXIT.branch_next=&null;
        EXIT.branch_prev=&MENU;


        if(first == 1) {
                actual=&MENU;
                first=0;
        }


        //KONIEC DANYCH TWORZACYCH STRUKTURE

        //LOGIKA MENU:
      //  printf(actual->title);
        if (action == 1) {
                TNODE * temp = actual->node_next;
                if(strcmp(temp -> title, "null"))
                    actual = actual->node_next;

        }
        if(action == 0) {
          TNODE * temp = actual->node_prev;
          if(strcmp(temp -> title, "null"))
                actual=actual->node_prev;

        }
        if(action == 2) {
          TNODE * temp = actual->branch_next;
          if(strcmp(temp -> title, "null"))
                actual = actual->branch_next;
                //menu_branch++;

        }
        if(action == 3) {
          TNODE * temp = actual->branch_prev;
          if(strcmp(temp -> title, "null"))
                actual= actual->branch_prev;

        }

        // MENU DRAWING:

        TNODE * temp = actual->branch_prev;
        printf("[ %s ]\n",temp -> title);

        TNODE * temp2 = actual;
        TNODE * temp3 = temp2;
        TNODE * first = actual;
        while(strcmp(temp2 -> title, "null")){
        //  printf("Test");
          temp3=temp2;
          temp2 = temp2 -> node_prev;
         if(strcmp(temp2 -> title,"null")){
          first = temp3;
          //printf("     %s \n", temp2 -> title);
        }
       }

        temp2 = temp3;

        while(strcmp(temp2 -> title, "null")){
        //  printf("Test");


          if(strcmp(temp2 -> title,"null")){
            if(!strcmp(temp2 -> title,actual -> title)){
              printf("  >  %s\n",actual->title);
            }else{
              printf("     %s \n", temp2 -> title);
            }
        }
        temp2 = temp2 -> node_next;

       }

        //printf(actual->title);





        return 0;
}
