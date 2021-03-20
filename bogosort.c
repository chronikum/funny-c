#include <unistd.h>

void ft_putnumber(int n);

/**
 * Swap to numbers 
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * a is the set, n is the size of the set
 */
void write_value(int a[], int n)
{
    write(1, "\n", 1);
    ft_putnumber(a[0]);
    ft_putnumber(a[1]);
    ft_putnumber(a[2]);
    ft_putnumber(a[3]);
}

/**
 * All permutions for a set of a[]
 * a - set
 * size - size
 * n - size
 */
int heap_permutation(int a[], int size, int n)
{
    static int counter = 0;
    int i;

    if (size == 1) {
        counter++;
        write_value(a, n);
        ft_putnumber(counter);
        write(1, "\n", 1);
        return 1;
    }
 
    i = 0;
    while (i < size) {
        heap_permutation(a, size - 1, n);
        if (size % 2 == 1)
            swap(&a[0], &a[size - 1]);
        else
            swap(&a[i], &a[size - 1]);
        i++;
    }
}

/**
 * Generate all permutations
 */
void generate_all_permutations(int a[])
{
    int n = sizeof a / sizeof a[0];
    heap_permutation(a, 4, 4);
}

int main()
{
    int a[4] = {1,2,3,4};
    generate_all_permutations(a);
    return 0;
}