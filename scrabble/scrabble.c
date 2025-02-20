#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int checkwords(string player1, string player2);

int main(void)
{
    // Get input from both users

    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    // Check words and assign points

    int winner = checkwords(player1, player2);

    // Determine the winner

    if (winner == 1)
    {
        printf("Player 1 wins!\n");
    }
    else if (winner == 2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int checkwords(string player1, string player2)
{
    int points[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int sum_player1 = 0;
    int sum_player2 = 0;

    for (int i = 0; i < strlen(player1); i++)
    {
        int letter = toupper(player1[i]) - 65;
        if (letter >= 0 && letter <= 25)
        {
            sum_player1 = sum_player1 + points[letter];
        }
    }

    for (int i = 0; i < strlen(player2); i++)
    {
        int letter = toupper(player2[i]) - 65;
        if (letter >= 0 && letter <= 25)
        {
            sum_player2 = sum_player2 + points[letter];
        }
    }

    if (sum_player1 > sum_player2)
    {
        return 1;
    }
    else if (sum_player2 > sum_player1)
    {
        return 2;
    }
    else
    {
        return 3;
    }
}
