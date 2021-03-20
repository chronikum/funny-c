void ft_putnumber(int n);

int ft_sqrt(int n)
{
    int i = 0;
    while (i < n)
    {
        if (i * i == n)
            return i;
        i++;
    }
    return -1;
}


int main()
{
    int t = 100;
    t = ft_sqrt(t);
    ft_putnumber(t);
}