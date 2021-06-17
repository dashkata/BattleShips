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
            else if(board[ship.y - 1][ship.x] == 'X' || board[ship.y + 1][ship.x] == 'X' || board[ship.y][ship.x - 1] == 'X' || board[ship.y][ship.x + 1] == 'X'){
                 printf("There is a ship near the one you are trying to put right now, try again!\n");
                
                 return 0;
                
            }else{
                switch(ship.dir){
                   
                
                    case 'U':
                        //this checks if a ship is too big and will go out of the board
                        if(ship.y - ship.size > 0){
                            //this checks if there is ship everytime we go to put a new 1 from the current ship
                            for(int i = 0; i < ship.size; i++){
                                if(board[ship.y - i][ship.x] == 'X'|| board[ship.y - i][ship.x - 1] == 'X' || board[ship.y - i][ship.x + 1] == 'X'){
                                    printf("There is a ship near the one you are trying to put right now, try again!\n");
                                    return 0;
                                }
                            }
                        }else{
                            
                            printf("Ship is too big to put it here!\n");
                            return 0;
            
                        }  
                        break;  
                   

            
                    
                 
                    case 'D':
                    
                    //this checks if a ship is too big and will go out of the board
                        if(ship.y + ship.size <= 11){
                            //this checks if there is ship everytime we go to put a new 1 from the current ship
                            for(int i = 0; i < ship.size; i++){
                                if(board[ship.y + i][ship.x] == 'X'|| board[ship.y + i][ship.x - 1] == 'X' || board[ship.y + i][ship.x + 1] == 'X'){
                                    printf("There is a ship near the one you are trying to put right now, try again!\n");
                                    return 0;
                                    
                                }
                            }
                        }else{
                            printf("Ship is too big to put it here!\n");
                            return 0;

                        }
                        break;
                 
                
                    case 'R':
                        //this checks if a ship is too big and will go out of the board

                        if(ship.x + ship.size <= 11){
                            //this checks if there is ship everytime we go to put a new 1 from the current ship
                            for(int i = 0; i < ship.size; i++){
                                if(board[ship.y][ship.x + i] == 'X'|| board[ship.y + 1][ship.x + i] == 'X' || board[ship.y - 1][ship.x + i] == 'X'){
                                    printf("There is a ship near the one you are trying to put right now, try again!\n");
                                    return 0;
                                    
                                }   
                            } 
                        }else{
                            printf("Ship is too big to put it here!\n");
                            return 0;
                   
                        }      
                        break;
                    
                    case 'L':
                    //this checks if a ship is too big and will go out of the board
                    
                        if(ship.x - ship.size > 0){
                            //this checks if there is ship everytime we go to put a new 1 from the current ship
                            for(int i = 0; i < ship.size; i++){
                                if(board[ship.y][ship.x - i] == 'X'|| board[ship.y + 1][ship.x - i] == 'X' || board[ship.y - 1][ship.x - i] == 'X'){
                                    printf("There is a ship near the one you are trying to put right now, try again!\n");
                                    return 0;
                                    
                                }   
                            }
                        }else{
                            
                            printf("Ship is too big to put it here!\n");
                            return 0;
                    
                        }
                        break;

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

int configurations(char board[11][11]){
    FILE *file = fopen("config1.txt", "r");
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
    fclose;

    
    return 0;
}



int main(){
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
    
    configurations(board);
    print_board(board);
    
    
    return 0;
}