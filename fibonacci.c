#include <stdio.h>
#include <stdlib.h>

/* Finds and prints all terms of the Fibonacci sequence up to the i-th */

int *fibp;

int recfibon(int i)
{                   /* A simple recursive implementation */
	if (i == 0)
		return 0;
	if (i == 1)
		return 1;
	return recfibon(i-1) + recfibon(i-2);
}

int iterfibon(int i)
{                  /* An iterative approach */
	int x, y, z, j;
	if (i == 0)
		return 0;
	if (i == 1)
		return 1;
	x = 0;
	y = 1;
	for (j = 2 ; j <= i ; j++) {
		z = x + y;
		x = y;
		y = z;
	}
	return z;
}

int recmemfibon(int i)
{                  /* The recursive function that reuses already computed terms */
	if (fibp[i] >= 0)
		return fibp[i];
	if (fibp[i-1] < 0)
		fibp[i-1] = recmemfibon(i-1);
	if (fibp[i-2] < 0)
		fibp[i-2] = recmemfibon(i-2);
	fibp[i] = fibp[i-1] + fibp[i-2];
	return fibp[i];
}

int memfibon(int i)
{                  /* Recursive implementation with memoization */
	int j, result;
	fibp = malloc((i + 1) * sizeof(int));
	if (fibp == NULL) {
		fprintf(stderr, "Not enough memory\n");
		exit(1);
	}
	fibp[0] = 0;
	if (i > 0)
		fibp[1] = 1;
	for (j = 2 ; j <= i ; j++)
		fibp[j] = -1;
	result = recmemfibon(i);
	free(fibp);
	return result;
}

int main()
{
	int i, maxnum, fib;
	printf("Please, give maximum number: ");
	scanf("%d", &maxnum);
	for (i = 0 ; i <= maxnum ; i++) {
		// fib = recfibon(i);
		// fib = iterfibon(i);
		fib = memfibon(i);
		printf("fib[%d] = %d\n", i, fib);
	}
	return 0;
}

