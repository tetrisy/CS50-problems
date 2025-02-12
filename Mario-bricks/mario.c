#include <cs50.h>
#include <stdio.h>

void print_row(int bricks);
void print_row_reverse(int bricks);
void print_space(int spaces);

int blank = 1;

int main(void)
{
    // Prompt user for input

    int height = 0;

    while (true)
    {
        height = get_int("What is the height of the pyramid? ");

        if (height >= 1 && height <= 8)
        {
            break;
        }
    }

    for (int i = 1; i <= height; i++)
    {
        print_space(height);
        print_row(i);
        printf("  ");
        print_row(i);
        printf("\n");
    }
}

void print_space(int spaces)
{

    for (int i = spaces - blank; i > 0; i--)
    {
        printf(" ");
    }

    blank += 1;
}

void print_row(int bricks)
{
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }
}
