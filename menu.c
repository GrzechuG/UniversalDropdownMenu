#include <stdio.h>
#include <string.h>
#define ALL_MENU_ELEMENTS 20




int main(){
    // Only for testing:
    int input;
    int action = 0;
    int layer = 0;
    while(1){
        
        scanf("%d", &input);
        if(input==-1){
            action=1;
        }
    //input = getchar();
        //printf("%d",input);
        menu(input, action, layer);
        
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

int menu(int selection, int action, int layer){
    //char temp[20];
    //scanf("%s" , temp);
    
   // printf(temp);
   
   TNODE all[ALL_MENU_ELEMENTS];
   
   TNODE siec;
   TNODE rtc_setup;
   TNODE rs232;
   
//   telewizor.title="Network";
   siec.title="siec";
   rtc_setup.title="rtc_setup";
   rs232.title="rs232";
   siec.id=0;
   
   
   
   all[0]=siec;
   all[1]=rtc_setup;
   all[2]=rs232;
   int max = 3;
   
   
   
   
    //printf(all[0].dropDown[0]);
    for(int i=0;i<ALL_MENU_ELEMENTS && i<max;i++){
         
         if(i==selection){
             printf("  > ");
         }else{
             printf("    ");
         }
         printf(all[i].title);
         
         printf("\n");
    }
    
    
return 0;
}

void drawMenu();






