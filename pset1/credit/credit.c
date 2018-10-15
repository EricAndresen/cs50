#include <stdio.h>
#include <cs50.h>
#include <string.h>

int checksum(string creditCardNumber);
int sumDigits(int number);
void classifyCard(string cardNumber);
int firstTwo(string cardNumber);
bool validate(string cardNUmber);

int main(void)
{
    string creditCardNumber = get_string("Credit Card Number: ");

    if( (!validate(creditCardNumber)) || (creditCardNumber[0] == '\0'))
    {
        main();
    }
    // comparing length for validity is a hack, should make this specific to card type
    else if(checksum(creditCardNumber) % 10 != 0 || strlen(creditCardNumber) < 13)
    {
        printf("INVALID\n");
    }
    else
    {
        classifyCard(creditCardNumber);
    }

    return 0;
}


int checksum(string creditCardNumber)
{
    int len = strlen(creditCardNumber);
    int total = 0;

    // count from 0 so that second to last is always odd (easier flow control)
    for(int i = 0; i < len; i++)
    {
        int index = (len - 1) - i;
        int currentNumber = creditCardNumber[index] - '0'; // subtracting by '0' adjusts for ASCII

        if(i % 2 == 0)
        {
            total += currentNumber;
        } else
        {
            total += sumDigits(2 * currentNumber);
        }
    }

    return total;
}


// adds digits of a number (e.g. 14 -> 1 + 4 -> 5)
// takes two digit numbers or less
int sumDigits(int number)
{
    int sum = 0;
    sum += number / 10;
    sum += number % 10;
    return sum;
}


void classifyCard(string creditCardNumber)
{
    int prefix = firstTwo(creditCardNumber);
    switch(prefix){
        case 34:
        case 37:
            printf("AMEX\n");
            break;
        case 51:
        case 52:
        case 53:
        case 54:
        case 55:
            printf("MASTERCARD\n");
            break;
        case 40:
        case 41:
        case 42:
        case 43:
        case 44:
        case 45:
        case 46:
        case 47:
        case 48:
        case 49:
            printf("VISA\n");
            break;
        default:
            printf("INVALID\n");
    }
}


int firstTwo(string creditCardNumber)
{
    int first = creditCardNumber[0] - '0';
    int second = creditCardNumber[1] - '0';

    return (first * 10) + second;
}

bool validate(string cardNumber)
{
    for(int i = 0; i < strlen(cardNumber); i++)
    {
        int ascii = (int)cardNumber[i];

        if( ascii > 57 || ascii < 48)
        {
            return false;
        }
    }

    return true;
}