# Universal multi layer menu C library for microcontrollers.

## Getting started

This library consists of multiple files. 

### The Python script menu_generator.py
It is a python script for generating menu structure (C code for manual library edition).It creates menu basing on "menu.conf" file. Sub menus are defined by correct indent (each must be multiple of 4 spaces).
     
The code should be inserted into menu.conf manually. 
(In future release this might be changed into something
 more user friendly)
     
 The results are redirected to stdout.
     
### The menu.h C library:
This is the library that can be imported simply by using:
   
         #include "menu.h"
         
It can be used by calling menu(int action), where action can be:
        {LEFT=1, RIGHT=0, GO_INTO=2, GO_BACK=3};
        
 If there is an option that is a menu "dead end", meaning it does not lead to another option listing, 
    
Function that is being run after node selection should be set using:

         [node name].funct_prop=[function name];

where [funcion name] must be of type void.

        
    
    
     
