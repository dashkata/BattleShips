#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user_insert_ships.h"

struct player_t
{
    char board[11][11];
    char name[15];
    char turns[100][4];
};

int counter = 1;
int player1_turns = 0;
int player2_turns = 0;

int start_game(struct player_t* player1, struct player_t* player2)
{
    int game_type = 0;
    int board = 0;
    printf("Welcome to Battleships!\n\nChoose how to play:\n1. 1vs1\n2. Singleplayer\n");
    scanf("%d", &game_type);

    switch(game_type)
    {
        case 1: //gives both of the players the chance to place their boards the way they choose
            printf("\nYou chose to play 1vs1! Let's begin!\n");
            printf("Player 1: ");
            scanf("%s", player1->name);
            printf("Player 2: ");
            scanf("%s", player2->name);

            printf("\nNext step:\n1. Place your ships manually\n2. Use a randomly selected board\n");
            scanf("%d", &board);
            switch(board){
                case 1: 
                    // sam gi podrejda //insert_ship();
                    break;
                case 2: 
                    // random karta - chocho
                    break;
                default: 
                    printf("\nInvalid decision! Please try again!\n");
                    start_game(player1, player2);
                    break;
            }
            break;
        case 2: //loads a ready configuration for the bot and gives the player the chance to choose how to place his board

            printf("\nYou chose to play singleplayer! Let's begin!\nYour name:");
            scanf("%s", player1->name);

            printf("\nNext step:\n1. Place your ships manually\n2. Use a randomly selected board\n");
            scanf("%d", &board);
            switch(board){
                case 1: 
                    // sam gi podrejda // insert_ship();
                    break;
                case 2: 
                    // random karta - chocho
                    break;
                default: 
                    printf("\nInvalid decision! Please try again!\n");
                    start_game(player1, player2);
                    break;
            }
            break;
        default:
            printf("\nInvalid decision! Please try again!\n");
            start_game(player1, player2);
            break;
    }

    return game_type;
}

void previous_strikes(struct player_t* player)
{
    int turn_counter = 0;
    //checks whose turn it is
    if(counter % 2 == 0){
        turn_counter = player2_turns;
    }else{
        turn_counter = player1_turns;
    }
    //prints player's previous strikes
    printf("%s, your previous guesses are:\n", player->name);
    for(int i = 0; i < turn_counter; i++){
        for(int j = 0; j < 4; j++){
            player->turns[i][j];
        }
        putchar('\n');
    }
    
}

int strike(struct player_t* player1, struct player_t* player2)
{
    int turn_decision = 0;
    int strike_decision = 0;
    int strike_success = 0;
    char shot[4];
    char direction[2];
    int turn_counter = 0;

    struct player_t* turn = malloc(sizeof(struct player_t));
    if(counter % 2 == 0){
        strcpy(turn->name, player2->name);
        turn_counter = player2_turns;
        //strcpy(turn->board, player2->board);
        //puts(turn->name);
   }else{
        strcpy(turn->name, player1->name);
        turn_counter = player1_turns;
        //strcpy(turn->board, player1->board);
   }


    printf("Choose an option:\n1.See your previous turns.\n2.Shoot\n");
    scanf("%d", &turn_decision);

    switch(turn_decision){
        case 1: if(counter != 1 && counter != 2){
                    previous_strikes(turn);
                    break;
                }else{
                    printf("This is your first turn! There is no previous ones! Redirecting to shoot!"); // pri uspeshen purvi opit dava greshno suobshtenie
                }      
        case 2:
            printf("\nHow do you want to shoot?\n1. Choose new coordinates\n2. Use your previous shot and choose only a direction to go for.\n");
            scanf("%d", &strike_decision);

            switch(strike_decision)
            {
                case 1: //choose new coordinates
                    printf("OK, %s! Now shoot!(e.g. B4)\n", turn->name);
                    scanf("%s", shot);
                    for(int i = 0; i < 4; i++){
                        turn->turns[turn_counter][i] = shot[i];
                        printf("%c", turn->turns[turn_counter][i]);
                    }
                    printf("%s", turn->turns[1][4]);
                    break;
                case 2: //use the previous box you shot at and choose a direction to go for
                    printf("OK, your previous shot was at neshto.\nChoose a direction to shoot! (Type L for left, R for right, U for up and D for down)\n");
                    scanf("%s", direction);
                    printf("%s", direction);
                    break;
                default:
                    printf("\nUnfortunately you chose something invalid so you need to try again!\n");
                    strike(player1, player2);
                    break;
            }
            break;
        default: printf("Invalid decision! Try again!\n");
                 strike(player1, player2);
                 break;
    }

    // ako opita e uspeshen strike_success = 1;
    return strike_success;
}


void strike_success(int success, struct player_t* player1, struct player_t* player2)
{
    if(success = 1){
        printf("\nGood job mate! You hit something and it's your turn again!\n");
        // ako cql korab e potopen
        // printf("That's not everything tho! Not only did you hit something but you submerged one of your opponent's ships!")
        if(counter % 2 == 0){
            player2_turns++;
        }else{
            player1_turns++;
        }
        strike(player1, player2);
    }
    else{
        printf("\nSorry mate, you didn't hit any of your opponent's ships :(\n");
        counter++; //opponent's turn
    }
}

int main()
{
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

    // print_config(board, 3);

    char turns[100];
    struct player_t player1;
    struct player_t player2;
    int game = start_game(&player1, &player2);
    // printf("%s, %s", player1.name, player2.name); 

    // spored tipa igra da prenasochva kum hodovete suotvetno na igrachite ili igracha i random hod za bota
    int str_succ = strike(&player1, &player2/*&turns*/);
    strike_success(str_succ, &player1, &player2);

    ships ship;

    insert_ships(board);

    return 0;
}