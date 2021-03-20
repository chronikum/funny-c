#include <unistd.h>

int main()
{
    int a[4] = {1,5,3,7};

}


void generate_all_permutations(int a[])
{
    int n = sizeof a / sizeof a[0];
    heap_permutation(a, n, n);
}

void write_value()
{

}

/**
 * Swap to numbers 
 */
void swap(int *a, int *b)
{
	int tmp;

	*a = tmp;
	tmp = *b;
	*b = *a;
	*a = tmp;
}

/**
 * All permutions for a set of a[]
 * a - set
 * size - size
 * n - size
 */
void heap_permutation(int a[], int size, int n)
{
    if (size == 1) {
        write_value(a, n);
        return;
    }
 
    for (int i = 0; i < size; i++) {
        heap_permutation(a, size - 1, n);
        if (size % 2 == 1)
            swap(a[0], a[size - 1]);
        else
            swap(a[i], a[size - 1]);
    }
}