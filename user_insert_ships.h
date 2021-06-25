#include <stdio.h>
#include "configurations.h"

void edit_ships(char board[11][11]){
    int x = 0;
    int y = 0;
    char dir[2];
    int size = 0;   

    printf("\nWhich ship do you want to edit? Please give its coordinates, direction and size.\n");
    printf("X: ");
    scanf("%d", &x);
    printf("Y: ");
    scanf("%d", &y);
    printf("Direction: ");
    scanf("%s", &dir);
    printf("Choose the size of the ship you want to edit:\n1. Small (2 boxes)\n2. Medium (3 boxes)\n3. Large (4 boxes)\n4. Cruiser (6 boxes)\n");
    scanf("%d", &size);

    switch(size){

        case 1:

            size = 2;

            switch(dir[0]){

                case 'U':

                    for(int i = 0; i < size; i++){

                        board[y - i][x] = 'O';

                    } break;

                case 'D':

                    for(int i = 0; i < size; i++){

                        board[y + i][x] = 'O';

                    } break;

                case 'R':

                    for(int i = 0; i < size; i++){
                                         
                        board[y][x + i] = 'O';
                        
                    } break;
                
                case 'L':

                    for(int i = 0; i < size; i++){

                        board[y][x - i] = 'O';

                    } break;

            }

            break;
        
        case 2: 

            size = 3;

            switch(dir[0]){

                case 'U':

                    for(int i = 0; i < size; i++){

                        board[y - i][x] = 'O';

                    } break;

                case 'D':

                    for(int i = 0; i < size; i++){
                            
                        board[y + i][x] = 'O';

                    } break;

                case 'R':

                    for(int i = 0; i < size; i++){
                                         
                        board[y][x + i] = 'O';

                    } break;
                
                case 'L':

                    for(int i = 0; i < size; i++){

                        board[y][x - i] = 'O';

                    } break;

            }

            break;

        case 3:

            size = 4;

            switch(dir[0]){

                case 'U':

                    for(int i = 0; i < size; i++){

                        board[y - i][x] = 'O';

                    } break;

                case 'D':

                    for(int i = 0; i < size; i++){
                            
                        board[y + i][x] = 'O';

                    } break;

                case 'R':

                    for(int i = 0; i < size; i++){
                                         
                        board[y][x + i] = 'O';

                    } break;
                
                case 'L':

                    for(int i = 0; i < size; i++){

                        board[y][x - i] = 'O';

                    } break;

            }

            break;

        case 4:

            size = 6;

            switch(dir[0]){

                case 'U':

                    for(int i = 0; i < size; i++){

                        board[y - i][x] = 'O';

                    } break;

                case 'D':

                    for(int i = 0; i < size; i++){
                            
                        board[y + i][x] = 'O';

                    } break;

                case 'R':

                    for(int i = 0; i < size; i++){
                                         
                        board[y][x + i] = 'O';

                    } break;
                
                case 'L':

                    for(int i = 0; i < size; i++){

                        board[y][x - i] = 'O';
                        
                    } break;

            }

            break;
            
    }

    print_board(board);

}

int insert_ships(char board[11][11]){    

    ships ship[10];
    int count_small = 4;
    int count_medium = 3;
    int count_large = 2;
    int count_cruiser = 1;
    int remaining_ships = 10;
    int what_to_do_next = 0;
    
    here:
    flag:
    for(int i = 0; i < 12; i++){

        if(remaining_ships == 0){
            printf("\nYou have put all of your ships on the board.\n");
            return 0;
        }

        printf("\nPlease now choose the size of the ship you want to put on the board:\n1. Small (2 boxes)\n2. Medium (3 boxes)\n3. Large (4 boxes)\n4. Cruiser (6 boxes)\n");
        scanf("%d", &ship[i].size);

        switch(ship[i].size){
            case 1:

                if(count_small > 0){

                    ship[i].size = 2;
                    count_small = count_small - 1;
                    remaining_ships =  remaining_ships - 1;

                } else {

                    printf("\nYou don't have more small ships to put!\n");
                    goto here;

                } break;

            case 2:

                if(count_medium > 0){

                    ship[i].size = 3;
                    count_medium = count_medium - 1;
                    remaining_ships =  remaining_ships - 1;

                } else {

                    printf("\nYou don't have more medium ships to put!\n");
                    goto here;

                } break;

            case 3:

                if(count_large > 0){

                    ship[i].size = 4;
                    count_large = count_large - 1;
                    remaining_ships =  remaining_ships - 1;

                } else {

                    printf("\nYou don't have more large ships to put!\n");
                    goto here;

                } break;
            
            case 4:

                if(count_cruiser > 0){

                    ship[i].size = 6;
                    count_cruiser = count_cruiser - 1;
                    remaining_ships =  remaining_ships - 1;

                } else {

                    printf("\nYou don't have more cruiser ships to put!\n");
                    goto here;

                } break;

            default: 

                printf("\nYou have chosen an invalid option! Please choose another...\n");
                goto here;

        }

        printf("\nOk! Now please give the coordinates and the direction you want to put the ship on:\n");
        printf("X: ");
        scanf("%d", &ship[i].x);
        printf("Y: ");
        scanf("%d", &ship[i].y);
        printf("Direction: ");
        scanf("%s", &ship[i].dir);   

        if(validation_check(board, ship[i]) == 1){

                set_ship(board, ship[i]);

                valid_choice:
                printf("\nWhat do you want to do next?\n1. Put a new ship\n2. Edit the position of your ships\n3. See your board\n");
                scanf("%d", &what_to_do_next);

                if(what_to_do_next == 1){
                    
                    goto flag;

                } else if(what_to_do_next == 2){

                    print_board(board);
                    edit_ships(board);

                    switch(ship[i].size){

                        case 2:

                            count_small++;
                            remaining_ships++;
                            break;

                        case 3:

                            count_medium++;
                            remaining_ships++;
                            break;

                        case 4:

                            count_large++;
                            remaining_ships++;
                            break;

                        case 6:

                            count_cruiser++;
                            remaining_ships++;
                            break;

            }

                } else if(what_to_do_next == 3){

                    print_board(board);

                } else {

                    printf("Invalid choice of next turn, please choose a valid one!");
                    goto valid_choice;

                }

        } else {

            switch(ship[i].size){

                case 2:

                    count_small++;
                    remaining_ships++;
                    break;

                case 3:

                    count_medium++;
                    remaining_ships++;
                    break;

                case 4:

                    count_large++;
                    remaining_ships++;
                    break;

                case 6:

                    count_cruiser++;
                    remaining_ships++;
                    break;

            }
        }
    }

    return 5;
}