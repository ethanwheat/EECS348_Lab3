#include <stdio.h>
#include <stdbool.h>
#include "football.h"

int main(void)
{
    printf("Enter 0 or 1 to STOP\n");
    while(true)
    {
        int input;
        printf("Enter the NFL score: ");
        if (scanf(" %d", &input) == 1)
        {
            if (input < 2)
                break;
            else
                football_scores(input);
        } else
            printf("Invalid Input\n");
    }
}
