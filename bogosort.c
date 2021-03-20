#include <time.h>
#include <unistd.h>
#include <stdlib.h>


void ft_putnumber(int n);

/**
 * Swap two numbers 
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * Simple logger for an array
 */
void log_value(int a[])
{
    write(1, "\n", 1);
    ft_putnumber(a[0]);
    ft_putnumber(a[1]);
    ft_putnumber(a[2]);
    ft_putnumber(a[3]);
}
/**
 * a is the set, n is the size of the set
 */
void write_value(int a[], int perms[24][4], int counter)
{
    perms[counter][0] = a[0];
    perms[counter][1] = a[1];
    perms[counter][2] = a[2];
    perms[counter][3] = a[3];
}

/**
 * Returns factorial of number given
 */
int factorial(int i) {

    if(i <= 1)
        return 1;
    return (i * factorial(i - 1));
}

/**
 * Returns a random permutation
 */
int heap_permutation(int a[], int size, int n, int perms[24][4])
{
    static int counter = 0;
    int i;

    if (size == 1) {
        write_value(a, perms, counter);
        counter++;
    }
 
    i = 0;
    while (i < size) {
        heap_permutation(a, (size - 1), n, perms);
        if (size % 2 == 1)
            swap(&a[0], &a[size - 1]);
        else
            swap(&a[i], &a[size - 1]);
        i++;
    }
    return 1;
}

/**
 * "Shuffle" (not really though)
 * A - set
 * size - set size
 */
int *shuffle(int a[], int size)
{
    int count = factorial(size);
    int r = arc4random() % (count - 1);
    static int perms[24][4];
    int* selected = malloc(sizeof(int*));

    heap_permutation(a, size, size, perms);
    selected = perms[r];
    
    return selected;
}

/**
 * Check if is sorted ascending
 */
int check_sorted(int a[], int size) {
    int i = 0;
    int sorted = 1;
    int highest = a[0];

    while(i < (size - 1))
    {
        if (highest < a[i + 1])
            highest = a[i + 1];
        else
        {
            sorted = 0;
            return sorted;
        }
        i++;
    }
    return sorted;
}

/**
 * "Sorts" the array
 */
void bogosort(int a[], int size, int sorted[4])
{
    int *rand = shuffle(a, 4);
    if (check_sorted(rand, 4) == 0)
        bogosort(rand, 4, sorted);
    else
    {
        sorted[0] = rand[0];
        sorted[1] = rand[1];
        sorted[2] = rand[2];
        sorted[3] = rand[3];
    }
}

int main()
{
    int i = 0;
    int a[4] = {5,1,3,4};
    int sorted[4];
    bogosort(a, 4, sorted);
    log_value(sorted);
    return 0;
}