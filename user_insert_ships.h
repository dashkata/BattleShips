#include <stdio.h>
#include "configurations.h"

int count_small = 4;
int count_medium = 3;
int count_large = 2;
int count_cruiser = 1;
int remaining_ships = 10;
int what_to_do_next = 0;

int edit_ships(char board[11][11], ships ship[10]){
    // int x = 0;
    // int y = 0;
    // char dir[2];
    // int size = 0;

    // printf("\nWhich ship do you want to edit? Please give its coordinates, direction and size\n");
    // printf("X: ");
    // scanf("%d", &x);
    // printf("Y: ");
    // scanf("%d", &y);
    // printf("Direction: ");
    // scanf("%s", &dir);
    // printf("Choose Size:\n1. Small (2 boxes)\n2. Medium (3 boxes)\n3. Large (4 boxes)\n4. Cruiser (6 boxes)\n");
    // scanf("%d", &size);

    // switch(size){
    //     case '1':
    //         for(int i = 0; i < size; i++){
    //                 board[y - i][x] = 'O';

    //             } break;
    // }
}

int insert_ships(char board[11][11]){    
    
    ships ship[10];

    //printf("\nNow its time to put your ships on the board!\n");
    
    for(int i = 0; i < 11; i++){
        if(remaining_ships == 0){
            printf("\nYou have put all of your ships on the board.");
            return 0;
        }

        here:
        printf("\nPlease now choose the size of the ship you want to put on the board:\n1. Small (2 boxes)\n2. Medium (3 boxes)\n3. Large (4 boxes)\n4. Cruiser (6 boxes)\n");
        scanf("%d", &ship[i].size);
        //printf("ship[i].size = %d\n", ship[i].size);

        switch(ship[i].size){
            case 1:
                if(count_small > 0){
                    ship[i].size = 2;
                    count_small = count_small - 1;
                    remaining_ships =  remaining_ships - 1;
                } else {
                    printf("You don't have more small ships to put!\n");
                    goto here;
                } break;

            case 2:
                if(count_medium > 0){
                    ship[i].size = 2;
                    count_medium = count_medium - 1;
                    remaining_ships =  remaining_ships - 1;
                } else {
                    printf("You don't have more medium ships to put!\n");
                    goto here;
                } break;

            case 3:
                if(count_large > 0){
                    ship[i].size = 2;
                    count_large = count_large - 1;
                    remaining_ships =  remaining_ships - 1;
                } else {
                    printf("You don't have more large ships to put!\n");
                    goto here;
                } break;
            
            case 4:
                if(count_cruiser > 0){
                    ship[i].size = 2;
                    count_cruiser = count_cruiser - 1;
                    remaining_ships =  remaining_ships - 1;
                } else {
                    printf("You don't have more cruiser ships to put!\n");
                    goto here;
                } break;

            default: 
                printf("You have chosen an invalid option! Please choose another...");
                goto here;
        }

        // printf("\n%d %d %d\n", ship[i].size, count_small, remaining_ships);
        // printf("%d %d %d\n", ship[i].size, count_medium, remaining_ships);
        // printf("%d %d %d\n", ship[i].size, count_large, remaining_ships);
        // printf("%d %d %d\n", ship[i].size, count_cruiser, remaining_ships);

        printf("\nOk! Now please give the coordinates and the direction you want to put the ship on:\n");
        printf("X: ");
        scanf("%d", &ship[i].x);
        printf("Y: ");
        scanf("%d", &ship[i].y);
        printf("Direction: ");
        scanf("%s", &ship[i].dir);   

        printf("\nWhat do you want to do next?\n1. Put a new ship\n2. Edit the position of your ships\n3. See your board\n");
        scanf("%d", &what_to_do_next);

        if(what_to_do_next == 1){
            if(validation_check(board, ship[i]) == 1){
                set_ship(board, ship[i]);
            }
        } else if(what_to_do_next == 2){
            edit_ships(board, ship);
        } else if(what_to_do_next == 3){
            print_board(board);
        }


    }
}