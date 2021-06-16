//vsichko e v maina battleships.c tva ne go gledaite 

#include <stdio.h>
void board(){
    
    
    char boardArray[11][11];
    
    for(int i = 0; i < 11 ;i ++){
        int ok = 0;
    
        if(i != 10){
            printf(" ");
        }
        for(int j = 0; j < 11; j++){
            if(i == 0){
                if(j == 0){
                    printf(" |");

                }
                else{
                    printf("%c|", 'A' + j - 1);
                }

            }else if(j == 0) {
                printf("%d|", i);
            }else{
                
               
                    printf(" |");

                 
                    
                
                       
                  
                
            }

        }
        printf("\n");
    }
}
