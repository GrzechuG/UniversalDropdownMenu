/*
THIS IS UNIVERSAL MENU LIBRARY WRITTEN IN C.

Author: Grzegorz Gajewski.

Function that is being run after node selection should be set using:

    [node name].funct_prop=[function name];

where [funcion name] must be of type void.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEFT 1
#define RIGHT 0
#define GO_INTO 2
#define GO_BACK 3

int menu_branch = 0;
int first = 1;

int menu(int action);

void function_exit()
{
    exit(0);
}

typedef struct MNODE
{
    unsigned char id; //uint8_t
    const char *title;
    void (*funct_prop)();

    struct MNODE *branch_next;
    struct MNODE *branch_prev;

    struct MNODE *node_next;
    struct MNODE *node_prev;

} TNODE;

TNODE *actual;
TNODE *deadEnd;

int menu(int action)
{
    TNODE null;
    null.title = "null";
    // DANE TWORZACE STRUKTURE:

    // Generated using menu generator v1.1 (C) Grzegorz Gajewski Industries

    // Generating nodes 'Objects' and setting up names:
    TNODE MENU_1;
    MENU_1.title = "MENU";
    TNODE SIEC_1;
    SIEC_1.title = "SIEC";
    if (first == 1)
    {
        actual = &SIEC_1;
        deadEnd = &MENU_1;
        first = 0;
    }
    TNODE BACK_1;
    BACK_1.title = "BACK";
    TNODE Numer_IP_1;
    Numer_IP_1.title = "Numer_IP";
    TNODE RTC_SETUP_1;
    RTC_SETUP_1.title = "RTC_SETUP";
    TNODE BACK_2;
    BACK_2.title = "BACK";
    TNODE CZAS_1;
    CZAS_1.title = "CZAS";
    TNODE BACK_3;
    BACK_3.title = "BACK";
    TNODE NTP_1;
    NTP_1.title = "NTP";
    TNODE GMT_1;
    GMT_1.title = "GMT";
    TNODE DATA_1;
    DATA_1.title = "DATA";
    TNODE RS232_1;
    RS232_1.title = "RS232";
    TNODE BACK_4;
    BACK_4.title = "BACK";
    TNODE BAUD_1;
    BAUD_1.title = "BAUD";
    TNODE BIT_1;
    BIT_1.title = "BIT";
    TNODE FLOW_1;
    FLOW_1.title = "FLOW";
    TNODE EXIT_1;
    EXIT_1.title = "EXIT";

    // Generating menu node structure:
    MENU_1.node_next = &null;
    MENU_1.node_prev = &null;
    SIEC_1.node_next = &RTC_SETUP_1;
    SIEC_1.node_prev = &null;
    RTC_SETUP_1.node_next = &RS232_1;
    RTC_SETUP_1.node_prev = &SIEC_1;
    RS232_1.node_next = &EXIT_1;
    RS232_1.node_prev = &RTC_SETUP_1;
    EXIT_1.node_next = &null;
    EXIT_1.node_prev = &RS232_1;
    BACK_1.node_next = &Numer_IP_1;
    BACK_1.node_prev = &null;
    Numer_IP_1.node_next = &null;
    Numer_IP_1.node_prev = &BACK_1;
    BACK_2.node_next = &CZAS_1;
    BACK_2.node_prev = &null;
    CZAS_1.node_next = &DATA_1;
    CZAS_1.node_prev = &BACK_2;
    DATA_1.node_next = &null;
    DATA_1.node_prev = &CZAS_1;
    BACK_3.node_next = &NTP_1;
    BACK_3.node_prev = &null;
    NTP_1.node_next = &GMT_1;
    NTP_1.node_prev = &BACK_3;
    GMT_1.node_next = &null;
    GMT_1.node_prev = &NTP_1;
    BACK_4.node_next = &BAUD_1;
    BACK_4.node_prev = &null;
    BAUD_1.node_next = &BIT_1;
    BAUD_1.node_prev = &BACK_4;
    BIT_1.node_next = &FLOW_1;
    BIT_1.node_prev = &BAUD_1;
    FLOW_1.node_next = &null;
    FLOW_1.node_prev = &BIT_1;

    // Generating menu branch structure:
    MENU_1.branch_next = &RTC_SETUP_1;
    MENU_1.branch_prev = &null;
    SIEC_1.branch_next = &BACK_1;
    SIEC_1.branch_prev = &MENU_1;
    BACK_1.branch_next = &null;
    BACK_1.branch_prev = &SIEC_1;
    Numer_IP_1.branch_next = &null;
    Numer_IP_1.branch_prev = &SIEC_1;
    RTC_SETUP_1.branch_next = &CZAS_1;
    RTC_SETUP_1.branch_prev = &MENU_1;
    BACK_2.branch_next = &null;
    BACK_2.branch_prev = &RTC_SETUP_1;
    CZAS_1.branch_next = &BACK_3;
    CZAS_1.branch_prev = &RTC_SETUP_1;
    BACK_3.branch_next = &null;
    BACK_3.branch_prev = &CZAS_1;
    NTP_1.branch_next = &null;
    NTP_1.branch_prev = &CZAS_1;
    GMT_1.branch_next = &null;
    GMT_1.branch_prev = &CZAS_1;
    DATA_1.branch_next = &null;
    DATA_1.branch_prev = &RTC_SETUP_1;
    RS232_1.branch_next = &BACK_4;
    RS232_1.branch_prev = &MENU_1;
    BACK_4.branch_next = &null;
    BACK_4.branch_prev = &RS232_1;
    BAUD_1.branch_next = &null;
    BAUD_1.branch_prev = &RS232_1;
    BIT_1.branch_next = &null;
    BIT_1.branch_prev = &RS232_1;
    FLOW_1.branch_next = &null;
    FLOW_1.branch_prev = &RS232_1;
    EXIT_1.branch_next = &null;
    EXIT_1.branch_prev = &MENU_1;

    // FUNCTIONS ASSIGNED TO NODES
    EXIT_1.funct_prop = function_exit;

    // KONIEC DANYCH TWORZACYCH STRUKTURE

    // LOGIKA MENU:

    if (action == LEFT)
    {
        TNODE *temp = actual->node_next;
        if (strcmp(temp->title, "null"))
            actual = actual->node_next;
    }

    if (action == RIGHT)
    {
        TNODE *temp = actual->node_prev;

        if (strcmp(temp->title, "null"))
            actual = actual->node_prev;
    }

    if (action == GO_INTO)
    {
        TNODE *temp = actual->branch_next;
        if (strcmp(temp->title, "null"))
        {
            actual = actual->branch_next;
        }
        else
        {
            printf("Function assigned to this node should have been run: %s \n", actual->title);

            // Should run function of actions' pointer.

            // WARNING! Next line is not universal.
            if (!strcmp((actual->title), "BACK"))
            {
                menu(GO_BACK);
            }
            else
            {
                (actual->funct_prop)();
            }
        }
    }

    if (action == GO_BACK)
    {
        TNODE *temp = actual->branch_prev;
        if (strcmp(temp->title, deadEnd->title))
            actual = actual->branch_prev;
    }

    // MENU DRAWING:

    TNODE *temp = actual->branch_prev;
    printf("[ %s ]\n", temp->title);

    TNODE *temp2 = actual;

    while (strcmp(temp2->node_prev->title, "null"))
    {
        temp2 = temp2->node_prev;
    }

    while (strcmp(temp2->title, "null"))
    {
        if (!strcmp(temp2->title, actual->title))
        {
            printf("  >  %s\n", actual->title);
        }
        else
        {
            printf("     %s \n", temp2->title);
        }

        temp2 = temp2->node_next;
    }

    return 0;
}
