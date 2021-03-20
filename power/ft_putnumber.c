#include <unistd.h>

/**
 * It will print the number given using stack.
 * Not taking care of negative numbers (yet), but that is easy to fix.
 */
void ft_putnumber(int n)
{
    int t = 0;
    char c = n + 48;
    if (n > 9)
    {
        t = n % 10;
        n /= 10;
        c = t + 48;
        ft_putnumber(n);
    } 
    else 
    {
        c = n + 48;
    }
    write(1, &c, 1);
}