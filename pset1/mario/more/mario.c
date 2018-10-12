#include <stdio.h>
#include <cs50.h>

// prints char n times
int repeat(char c, int times)
{
    for (int i = 0; i < times; i++)
    {
        printf("%c", c);
    }

    return 0; // satisfies the need for a function to return something
}

int main(void)
{

    int size = get_int("What should the height of the pyramid be? ");

    if (size <= 23 && size > -1)
    {
        for (int i = 0; i < size; i++)
        {
            repeat(' ', size - (i + 1)); //print padding
            repeat('#', i + 1); //print left side
            repeat(' ', 2); //print gap
            repeat('#', i + 1); //print right side
            printf("\n");
        }
    }
    else
    {
        printf("Hmm that input isn't what I was expecting.\n");
        main();
    }
}


