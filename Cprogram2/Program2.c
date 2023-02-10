#include <stdio.h>
#include <stdbool.h>
#include "football.h"

int main(void)
{
    while(true)
    {
        int input;
        printf("Enter a score: ");
        if (scanf(" %d", &input) == 1)
        {
            if (input <= 2)
                break;
            else
                football_scores(input);
        } else
            printf("Invalid Input\n");
    }
}
