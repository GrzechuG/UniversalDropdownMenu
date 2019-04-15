#include <stdio.h>
#include <string.h>
#define ALL_MENU_ELEMENTS 20

struct MNODE {
   char name[20];
   char dropDown[20][20];
   int index;
   int layer;
};

int main(){
    char input[20];
    scanf("%s", input);
    printf(input);

    return 0;
}


int menu(){
    //char temp[20];
    //scanf("%s" , temp);
    
   // printf(temp);
   
   struct MNODE all[ALL_MENU_ELEMENTS];
   struct MNODE telewizor;
   struct MNODE kuchenka;
   struct MNODE piekarnik;
   
   strcpy(telewizor.name, "C language");
   telewizor.layer=0;
   strcpy(telewizor.name, "telewizor");
   strcpy(kuchenka.name, "kuchenka");
   strcpy(piekarnik.name, "piekarnik");
   
   
   all[0]=telewizor;
   all[1]=kuchenka;
   all[2]=piekarnik;
   int max = 3;
   int selection = 1;
   
   
   
    //printf(all[0].dropDown[0]);
    for(int i=0;i<ALL_MENU_ELEMENTS && i<max;i++){
         
         if(i==selection){
             printf("   >");
         }else{
             printf("    ");
         }
         printf(all[i].name);
         
         printf("\n");
    }
    while(1){
        char result = getchar();
        if(result == 'x')
            printf("X");
    }
    
    
return 0;
}

void drawMenu();






