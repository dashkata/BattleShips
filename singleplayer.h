#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "configurations.h"

 
int map_generator(struct player_t* player){
    int i;
    time_t t;
    
    char board[11][11] = {
        {' ','A','B','C','D','E','F','G','H','I','J'},
        {'1','O','O','O','O','O','O','O','O','O','O'},
        {'2','O','O','O','O','O','O','O','O','O','O'},
        {'3','O','O','O','O','O','O','O','O','O','O'},
        {'4','O','O','O','O','O','O','O','O','O','O'},
        {'5','O','O','O','O','O','O','O','O','O','O'},
        {'6','O','O','O','O','O','O','O','O','O','O'},
        {'7','O','O','O','O','O','O','O','O','O','O'},
        {'8','O','O','O','O','O','O','O','O','O','O'},
        {'9','O','O','O','O','O','O','O','O','O','O'},
        {'0','O','O','O','O','O','O','O','O','O','O'},
        
    };
    
   
   
   srand((unsigned) time(&t));
   
     i =  rand() % 4;
     while (i == 0)
     {
         i = rand() % 4;
     }
     
    printf("%d\n", i);
     print_config(board,i);
   
   
   return(0);
}



char bot_strikes_and_random_ship_placement(struct player_t *player){
    int x;
    char y;
     time_t t;

     srand((unsigned) time(&t)); 
     x = rand() % (10 + 1 - 1) + 1;

     y = rand() % (74 + 1 - 65) + 65;
     
     

}