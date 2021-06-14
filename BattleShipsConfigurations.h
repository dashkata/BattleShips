#include <stdio.h>
void board(){
    int boardArray[11][11];
    
    for(int i = 0; i < 11; i++){
        if(i != 10){
            printf(" ");
        }
        for(int j = 0; j < 10; j++){
            
            if(i == 0){
                
                
                if(j == 0){
                    printf(" |");
                }
                printf("%c|", 'A' + j );            
            
            
            }else if(j == 0){
                printf("%d|", i);
            }else{
                printf(" |");
            }
        }
        if(i != 0){
            printf(" |");
        }
        printf("\n");
        
        
        
       
    }
    
}