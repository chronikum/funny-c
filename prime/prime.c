#include <unistd.h>

void ft_putnumber(int n);

int is_prime(int n)
{
    int i = 2;
    int flag = 1;
    int check = 1;
    if (n == 2)
        return 1;

    if (n % 2 == 0)
        return 0;
    while (i < (n / 2))
    {
        if (n % i == 0)
        {
            flag = 0;
            return flag;
        }
        i++;
    }
    return flag;
}

int prime_index(int n)
{
    static int i = 0;
    static int p = 0;
    while (1)
    {
        if (is_prime(i)) {
            if (p == n)
            {
                return i;
            }
            p++;
        }
        i++;
    }
}

int main()
{
    int x = 5000;
    int prime = prime_index(x);
    ft_putnumber(prime);
    return 0;
}