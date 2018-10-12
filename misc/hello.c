# include <cs50.h>
# include <stdio.h>

// get two ints and print their comparison

int main(void)
{
    int x = get_int("x: ");

    int y = get_int("y: ");

    if (x < y)
    {
        printf("%i is less than %i\n", x, y);
    } else if (x == y) {
        printf("%i is equal to %i\n", x, y);
    } else {
        printf("%i is more than %i\n", x, y);
    };
};

