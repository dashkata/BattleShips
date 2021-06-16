#include <stdio.h>
#include "BattleShipsConfigurations.h"
struct ship_t{
    int x; 
    int y;
    
    
    int size;
    char dir;

}typedef ship;
//printva boarda
void print_board(char board[11][11]){
    for(int y = 0; y < 11; y++){
        if(y != 10){
            printf(" ");

        }
        else{
            printf("1");
        }
      
        for (int x = 0; x < 11; x++){
            
            
            printf("%c|", board[y][x]);
           
    
        
        }
        printf("\n");   
    }
    printf("\n");
}
//checkva dali e validen koraba
int validation_check(char board[11][11], ship ship){
    //check if size is valid
    if(ship.size == 2 || ship.size == 3 || ship.size == 4 || ship.size == 6){
        //check if coordinates are 1;1 cause the coordinates are dogshit
        if(ship.y != 1 && ship.x != 1){
            if(board[ship.y][ship.x] != '0'){
                printf("There is already a ship on theese coordinates");
                return 0;
            }else if(board[ship.y - 1][ship.x] == '1' || board[ship.y + 1][ship.x] == '1' || board[ship.y][ship.x - 1] == '1' || board[ship.y][ship.x + 1] == '1'){
                printf("There is a ship near the one you are trying to put right now, try again!");
                
                return 0;
                
            }else{
                switch(ship.dir){
                   
                
                    case 'U':
                        if(ship.y - ship.size >= 0){
                            for(int i = 0; i <= ship.size; i++){
                                if(board[ship.y - i][ship.x] == '1'|| board[ship.y - i][ship.x - 1] == '1' || board[ship.y - i][ship.x + 1] == '1'){
                                    printf("There is a ship near the one you are trying to put right now, try again!");
                                    return 0;
                                }
                            }
                        }else{
                            
                            printf("There is a ship near the one you are trying to put right now, try again!");
                            return 0;
            
                        }  
                        break;  
                   

            
                    
                 
                    case 'D':
                        if(ship.y + ship.size <= 11){
                            for(int i = 0; i <= ship.size; i++){
                                if(board[ship.y + i][ship.x] == '1'|| board[ship.y + i][ship.x - 1] == '1' || board[ship.y + i][ship.x + 1] == '1'){
                                    printf("There is a ship near the one you are trying to put right now, try again!");
                                    return 0;
                                    
                                }
                            }
                        }else{
                            printf("Ship is too big to put it here!");
                            return 0;

                        }
                        break;
                 
                
                    case 'R':
                        if(ship.x + ship.size <= 11){
                            for(int i = 0; i <= ship.size; i++){
                                if(board[ship.y][ship.x + i] == '1'|| board[ship.y + 1][ship.x + i] == '1' || board[ship.y - 1][ship.x + i] == '1'){
                                    printf("There is a ship near the one you are trying to put right now, try again!");
                                    return 0;
                                    
                                }   
                            } 
                        }else{
                            printf("Ship is too big to put it here!");
                            return 0;
                   
                        }      
                        break;
                    
                    case 'L':
                        if(ship.x - ship.size >= 0){
                            for(int i = 0; i <= ship.size; i++){
                                if(board[ship.y][ship.x - i] == '1'|| board[ship.y + 1][ship.x - i] == '1' || board[ship.y - 1][ship.x - i] == '1'){
                                    printf("There is a ship near the one you are trying to put right now, try again!");
                                    return 0;
                                    
                                }   
                            }
                        }else{
                            printf("Ship is too big to put it here!");
                            return 0;
                    
                        }
                        break;

                }
                return 1;
                
            }
        }else{
            if(board[ship.y][ship.x + 1] == '1' || board[ship.y + 1][ship.x] == '1'){
                return 0;
            }else{
                switch(ship.dir){
                    case 'U':
                        printf("Ship is too big to put it here!");
                        return 0;
                        break;
                    case 'L':
                        printf("Ship is too big to put it here!");
                        return 0;
                        break;  

                    case 'D':
                        for(int i = 0; i <= ship.size; i++){
                            if(board[ship.y + i][ship.x] == '1'|| board[ship.y + i][ship.x + 1] == '1'){
                                printf("There is a ship near the one you are trying to put right now, try again!");
                                return 0;
                            }
                        }
                            
                        break;
                
                    case 'R':
                        for(int i = 0; i <= ship.size; i++){
                            if(board[ship.y][ship.x + i] == '1'|| board[ship.y + 1][ship.x + i] == '1' || board[ship.y - 1][ship.x + i] == '1'){
                                printf("There is a ship near the one you are trying to put right now, try again!");
                                return 0;
                            }
                        }
                        break;
                

                }
                return 1;
                
            }
            

        }
    }else{
        printf("Invalid ship size");
        return 0;
    }
    
    
    
    
    


}
void set_ship(char board[11][11], ship ship){
     print_board(board);
    
    if(validation_check(board, ship) == 1){
       
        
        switch(ship.dir){
            
            case 'U':
                for(int i = 0; i < ship.size; i++){
                   
                    board[ship.y - i][ship.x] = '1';

                }
                
                print_board(board);
                break;
            
            case 'D':
               
                    for(int i = 0; i < ship.size; i++){
                        
                            
                                
                        board[ship.y + i][ship.x] = '1';

                    }

                        
                    print_board(board);
               
                break;
            
            case 'R':
                
                    for(int i = 0; i < ship.size; i++){
                        
                           
                        board[ship.y][ship.x + i] = '1';

                            

                    }
                    print_board(board);
                
                break;
           
            case 'L':
                
                    for(int i = 0; i < ship.size; i++){
                        
                            
                                
                        board[ship.y][ship.x - i] = '1';

                            

                    }
                print_board(board);
                
                break;

        }
        
    }
    

    

}


int main(){
    char boardarray[11][11] = {
        {' ','A','B','C','D','E','F','G','H','I','J'},
        {'1','0','0','0','0','0','0','0','0','0','0'},
        {'2','0','0','0','0','0','0','0','0','0','0'},
        {'3','0','0','0','0','0','0','0','0','0','0'},
        {'4','0','0','0','0','0','0','0','0','0','0'},
        {'5','0','0','0','0','0','0','1','0','0','0'},
        {'6','0','0','0','0','0','0','0','0','0','0'},
        {'7','0','0','0','0','0','0','0','0','0','0'},
        {'8','0','0','0','0','0','0','0','0','0','0'},
        {'9','0','0','0','0','0','0','0','0','0','0'},
        {'0','0','0','0','0','0','0','0','0','0','0'},
        
    };
   

    
    
    ship ship1 = {5,6,6, 'R'};
    
    set_ship(boardarray, ship1);
    
    
    return 0;
}