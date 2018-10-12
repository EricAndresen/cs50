#include <cs50.h>
#include <stdio.h>

// this is called a prototype that hoists it's declaration
int square(int n);

int main(void)
{
    int x = get_int("Integer: ");

    printf("%i\n", square(x));
}

int square(int n)
{
  return n * n;
}
