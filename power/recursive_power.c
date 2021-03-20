#include <unistd.h>

void ft_putnumber(int n);

int recursive_power(int base, int n)
{
    return (n != 0 ? (base * recursive_power(base, n - 1)) : 1);
}

int main()
{
    int r = recursive_power(5, 2);
    ft_putnumber(r);
}