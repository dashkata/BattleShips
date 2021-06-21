#include <stdio.h>

struct ship_t{
    int x; 
    int y;
    
    
    int size;
    char dir;

}typedef ships;
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
int validation_check(char board[11][11], ships ship){
    //check if size is valid
    if(ship.size == 2 || ship.size == 3 || ship.size == 4 || ship.size == 6){
        
        // if( ship.x != 1 || ship.y != 1 ){
            //check if there is a ship (a 1) set to the coordinates
            if(board[ship.y][ship.x] != 'O'){
                printf("There is already a ship on theese coordinates\n");
                return 0;
            }
            //check if there is a ship near the one you are trying to put
            else if(board[ship.y - 1][ship.x] == 'X' || 
                    board[ship.y + 1][ship.x] == 'X' || 
                    board[ship.y][ship.x - 1] == 'X' || 
                    board[ship.y][ship.x + 1] == 'X' ||
                    board[ship.y - 1][ship.x - 1] == 'X' ||
                    board[ship.y - 1][ship.x + 1] == 'X' ||
                    board[ship.y + 1][ship.x - 1] == 'X' ||
                    board[ship.y + 1][ship.x + 1] == 'X' 
                    ){
                 printf("There is a ship near the one you are trying to put right now, try again!\n");
                
                 return 0;
                
            }else{
                switch(ship.dir){
                   
                
                    case 'U':
                        //this checks if a ship is too big and will go out of the board
                        if(ship.y - ship.size > 0){
                            if(board[ship.y + 1][ship.x + 1] == 'X' || board[ship.y + 1][ship.x - 1] == 'X' || board[ship.y - ship.size][ship.x - 1] == 'X' || board[ship.y - ship.size][ship.x + 1] == 'X'){
                                printf("There is a ship near the one you are trying to put right now, try again!\n");
                                return 0;
                            }else{
                            //this checks if there is ship everytime we go to put a new 1 from the current ship
                                for(int i = 0; i < ship.size; i++){
                                    if(board[ship.y - i][ship.x] == 'X'|| board[ship.y - i][ship.x - 1] == 'X' || board[ship.y - i][ship.x + 1] == 'X'){
                                        printf("There is a ship near the one you are trying to put right now, try again!\n");
                                        return 0;
                                    }
                                }
                            }
                        }else{
                            
                            printf("\nShip is too big to put it here!\n");
                            return 0;
            
                        }  
                        break;  
                   

            
                    
                 
                    case 'D':
                    
                    //this checks if a ship is too big and will go out of the board
                        if(ship.y + ship.size <= 11){
                            //this checks if there is ship everytime we go to put a new 1 from the current ship
                            if(board[ship.y - 1][ship.x + 1] == 'X' || board[ship.y - 1][ship.x - 1] == 'X' || board[ship.y + ship.size][ship.x - 1] == 'X' || board[ship.y + ship.size][ship.x + 1] == 'X'){
                                printf("There is a ship near the one you are trying to put right now, try again!\n");
                                return 0;
                            }else{
                                for(int i = 0; i < ship.size; i++){
                                    if(board[ship.y + i][ship.x] == 'X'|| board[ship.y + i][ship.x - 1] == 'X' || board[ship.y + i][ship.x + 1] == 'X'){
                                        printf("There is a ship near the one you are trying to put right now, try again!\n");
                                        return 0;
                                        
                                    }
                                }
                            }
                        }else{
                            printf("\nShip is too big to put it here!\n");
                            return 0;

                        }
                        break;
                 
                
                    case 'R':
                        //this checks if a ship is too big and will go out of the board
                        

                        if(ship.x + ship.size <= 11){
                            if(board[ship.y + 1][ship.x - 1] == 'X' || board[ship.y - 1][ship.x - 1] == 'X' || board[ship.y - 1][ship.x + ship.size] == 'X' || board[ship.y + 1][ship.x + ship.size] == 'X'){
                                printf("There is a ship near the one you are trying to put right now, try again!\n");
                                return 0;
                            }else{
                            
                                //this checks if there is ship everytime we go to put a new 1 from the current ship
                                for(int i = 0; i < ship.size; i++){
                                    if(board[ship.y][ship.x + i] == 'X'|| board[ship.y + 1][ship.x + i] == 'X' || board[ship.y - 1][ship.x + i] == 'X'){
                                        printf("There is a ship near the one you are trying to put right now, try again!\n");
                                        return 0;
                                        
                                    }   
                                }
                            } 
                        }else{
                            printf("\nShip is too big to put it here!\n");
                            return 0;
                   
                        }      
                        break;
                    
                    case 'L':
                    //this checks if a ship is too big and will go out of the board

                    
                        if(ship.x - ship.size > 0){
                            if(board[ship.y + 1][ship.x + 1] == 'X' || board[ship.y - 1][ship.x + 1] == 'X' || board[ship.y - 1][ship.x - ship.size] == 'X' || board[ship.y + 1][ship.x - ship.size] == 'X'){
                                printf("There is a ship near the one you are trying to put right now, try again!\n");
                                return 0;
                            }else{
                                //this checks if there is ship everytime we go to put a new 1 from the current ship
                                for(int i = 0; i < ship.size; i++){
                                    if(board[ship.y][ship.x - i] == 'X'|| board[ship.y + 1][ship.x - i] == 'X' || board[ship.y - 1][ship.x - i] == 'X'){
                                        printf("There is a ship near the one you are trying to put right now, try again!\n");
                                        return 0;
                                        
                                    }   
                                }
                            }
                        }else{
                            
                            printf("\nShip is too big to put it here!\n");
                            return 0;
                    
                        }
                        break; 

                    default: 
                        printf("\nInvalid direction!\n");
                        return 0;
                }
                return 1;
                
            }
     
    }else{
        printf("Invalid ship size\n");
        return 0;
    }
    
    
    
    
    


}
void set_ship(char board[11][11],ships ship){
    
    
    
    if(validation_check(board, ship) == 1){

        switch(ship.dir){    
            case 'U':
                for(int i = 0; i < ship.size; i++){
                    board[ship.y - i][ship.x] = 'X';

                }
                
                
                break;
            
            case 'D':               
                for(int i = 0; i < ship.size; i++){
                        
                    board[ship.y + i][ship.x] = 'X';
                }
  
                break;
            
            case 'R':
                
                for(int i = 0; i < ship.size; i++){
                                         
                    board[ship.y][ship.x + i] = 'X';
                }                                    
                break;
           
            case 'L':
                
                for(int i = 0; i < ship.size; i++){

                    board[ship.y][ship.x - i] = 'X';
                }
                break;
        }    
    }
    

    

}
int file_selection(char board[11][11], FILE *file){
        if(file == NULL){
                return 1;
            }
            char buffer[200];
            fgets(buffer, 200, file);
            for(int i = 0; i < 10; i++){
                ships ship;
                sscanf(buffer, "%d" "%d" "%d" "%s", &ship.x, &ship.y, &ship.size, &ship.dir);
                
                set_ship(board,ship);
                fgets(buffer, 200, file);
            }
            fclose(file);
            return 0;
}

int configurations(char board[11][11], int config_number){
    if(config_number == 1){
        FILE *file = fopen("config1.txt", "r");
        file_selection(board, file);

    }else if(config_number == 2){
         FILE *file = fopen("config2.txt", "r");
        file_selection(board, file);

    }
   

    
    return 0;
}



void print_config(char board[11][11], int config_number){
    
    configurations(board, config_number);
    print_board(board);
}