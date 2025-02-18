#include <cs50.h>
#include <stdio.h>

bool check_triangle(int a, int b, int c);

int main(void)
{
    int a = get_int("Length of 1st side: ");
    int b = get_int("Length of 2nd side: ");
    int c = get_int("Length of 3rd side: ");

    bool isTriangle = check_triangle(a, b, c);

    if (isTriangle == true)
    {
        printf("This is a valid triangle.\n");
    }
    else
    {
        printf("This isn't a valid triangle.\n");
    }
}

bool check_triangle(int a, int b, int c)
{
    int sum1 = a + b;
    int sum2 = b + c;
    int sum3 = a + c;
    bool isTriangle = false;

    if (sum1 > c)
    {
        if (sum2 > a)
        {
            if (sum3 > b)
            {
                isTriangle = true;
            }
        }
    }
    else
    {
        isTriangle = false;
    }

    return isTriangle;
}
