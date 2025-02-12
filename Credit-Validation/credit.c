#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string card_check(long card);
int checksum(string card, int length);
char buffer[50];

int main()
{
    long card_number = get_long("Number: ");
    printf("%s", card_check(card_number));
}

string card_check(long card)
{
    string status = "";
    sprintf(buffer, "%li", card);
    int length = strlen(buffer);

    switch (length)
    {
        case 15:
            if ((buffer[0] == '3' && buffer[1] == '7') || (buffer[0] == '3' && buffer[1] == '4'))
            {
                if (checksum(buffer, length) == 0)
                {
                    status = "AMEX\n";
                    break;
                }
            }
            else
            {
                status = "INVALID\n";
                break;
            }

        case 13:
            if (buffer[0] == '4')
            {
                if (checksum(buffer, length) == 0)
                {
                    status = "VISA\n";
                    break;
                }
            }
            else
            {
                status = "INVALID\n";
                break;
            }

        case 16:
            if (buffer[0] == '4')
            {
                if (checksum(buffer, length) == 0)
                {
                    status = "VISA\n";
                    break;
                }
            }
            else if ((buffer[0] == '5' && buffer[1] == '1') ||
                     (buffer[0] == '5' && buffer[1] == '2') ||
                     (buffer[0] == '5' && buffer[1] == '3') ||
                     (buffer[0] == '5' && buffer[1] == '4') ||
                     (buffer[0] == '5' && buffer[1] == '5'))
            {
                if (checksum(buffer, length) == 0)
                {
                    status = "MASTERCARD\n";
                    break;
                }
            }
            else
            {
                status = "INVALID\n";
                break;
            }

        default:
            status = "INVALID\n";
            break;
    }
    return status;
}

int checksum(string card, int length)
{
    int temp_multiply = length - 2;
    int sum_multiply = 0;
    while (temp_multiply >= 0)
    {
        int multiply = (buffer[temp_multiply] - '0') * 2;
        if (multiply > 9)
        {
            int dig1 = multiply / 10;
            int dig2 = multiply % 10;
            sum_multiply = sum_multiply + dig1 + dig2;
        }
        else
        {
            sum_multiply = sum_multiply + multiply;
        }
        temp_multiply -= 2;
    }

    int temp = length - 1;
    int n_sum = 0;

    while (temp >= 0)
    {
        n_sum += (buffer[temp] - '0');
        temp -= 2;
    }

    int sum = sum_multiply + n_sum;

    int valid = sum % 10;

    return valid;
}
