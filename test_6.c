#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(void);
bool play_game(void);

int main()
{
    srand(time(NULL));
    int win = 0, lose = 0; 
    char ch;

    again:
    while (true)
    {
        if (play_game())
            {
                printf("You win!\n");
                win++;
            }
        else 
            {
                printf("You lose!\n");
                lose++;
            }
        for (;;)
            {
                printf("Play again? ");
                scanf(" %c", &ch);
                if (ch == 'y' || ch == 'Y')
                    goto again;
                else
                    {
                        printf("Wins: %d Losses: %d", win, lose);
                        return 0;
                    }
            }
    }
}

int roll_dice(void)
{
    int num_1 = rand() % 6 + 1;
    int num_2 = rand() % 6 + 1;
    return num_1 + num_2;
}

bool play_game(void)
{
    int i, target, point;

    i = 0;
    
    while (true)
    {
        note:
        target = roll_dice();

        printf("You rolled: %d\n", target);

        
        if (i == 0)
        {
            if (target == 7 || target == 11)
                return true;
            else if (target == 2 || target == 3 || target == 12)
                return false;
            else {
                    point = target;
                    printf("Your point is %d\n", point);
                }
            i++;
            goto note;
        }
        else if (i == 1)
        {
            if (target == point)
                return true;
            else if (target == 7)
                return false;
            goto note;
        }
    }
}   