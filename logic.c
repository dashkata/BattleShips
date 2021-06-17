#include <stdio.h>
#include <stdlib.h>
#include "configurations.h"

int start_game()
{
    int game_type = 0;
    int board = 0;
    printf("Welcome to Battleships!\n\nChoose how to play:\n1. 1vs1\n2. Singleplayer\n");
    scanf("%d", &game_type);

    switch(game_type)
    {
        case 1: //da si izbere kartata
            printf("You chose to play 1vs1! Next step:\n1. Place your ships manually\n2. Use a randomly selected board\n");
            scanf("%d", &board);
            switch(board){
                case 1: 
                    // sam gi podrejda
                    break;
                case 2: 
                    // random karta
                    break;
                default: 
                    printf("\nInvalid decision! Please try again!\n");
                    start_game(&game_type);
                    break;
            }
            break;
        case 2: //zaredi random karta za bota i dai da si izbere karta
            printf("You chose to play singleplayer! Next step:\n1. Place your ships manually\n2. Use a randomly selected board\n");
            scanf("%d", &board);
            switch(board){
                case 1: 
                    // sam gi podrejda
                    break;
                case 2: 
                    // random karta
                    break;
                default: 
                    printf("\nInvalid decision! Please try again!\n");
                    start_game(&game_type);
                    break;
            }
            break;
        default:
            printf("\nInvalid decision! Please try again!\n");
            start_game(&game_type);
            break;
    }

    return game_type;
}

void previous_strikes(/*masiv koito pazi opitite*/)
{
    // printi starite opiti
}

int strike(/*char* board, char* turns*/)
{
    int turn_decision = 0;
    int strike_decision = 0;
    int strike_success = 0;

    printf("Choose an option:\n1.See your previous turns.\n2.Shoot\n");
    scanf("%d", &turn_decision);

    switch(turn_decision){
        case 1: previous_strikes();
                break;
        case 2:
            printf("\nHow do you want to shoot?\n1. Choose new coordinates\n2. Use your previous and choosing only direction to go for.\n");
            scanf("%d", &strike_decision);

            switch(strike_decision)
            {
                case 1: //izbira novi koordinati
                    break;
                case 2: // polzva starata kletka i izbira posoka
                    break;
                default:
                    printf("\nUnfortunately you chose something not valid so you need to try again!\n");
                    strike();
                    break;
            }
            break;
        default: printf("Invalid decision! Try again!\n");
                 strike();
                 break;
    }

    // ako opita e uspeshen strike_success = 1;
    return strike_success;
}

void strike_success(int success)
{
    if(success = 1){
        printf("\nGood job mate! You hit something and it's your turn again!\n");
        // ako cql korab e potopen
        // printf("That's not everything tho! Not only did you hit something but you submerged one of your opponent's ships!")
        strike();
    }
    else{
        printf("\nSorry mate, you didn't hit any of your opponent's ships :(\n");
        // dava na sledvashtiq igrach da igrae
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

    print_config(board, 2);

    //char turns[100];
    int game = start_game();
    // spored tipa igra da prenasochva kum hodovete suotvetno na igrachite ili igracha i random hod za bota
    int str_succ = strike(/*&turns*/);
    strike_success(str_succ);

    return 0;
}