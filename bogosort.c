#include <time.h>
#include <unistd.h>
#include <stdlib.h>


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
    static int incrementer = 0;
    perms[counter][0] = a[0];
    perms[counter][1] = a[1];
    perms[counter][2] = a[2];
    perms[counter][3] = a[3];
    // log_value(perms[incrementer]);
    incrementer++;
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
    int r = rand() % (count - 1);
    static int perms[24][4];
    int* selected = malloc(sizeof(int*));

    heap_permutation(a, size, size, perms);
    log_value(perms[r]);
    selected = perms[r];
    
    return selected;
}

void setup_random()
{
    time_t t;
    srand((unsigned) time(&t));
}

int main()
{
    int a[4] = {4,3,2,1};

    setup_random();
    shuffle(a, 4);
    // int r = rand() % 24;
    return 0;
}