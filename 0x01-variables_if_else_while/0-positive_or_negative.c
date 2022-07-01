#include <stdlib.h>
#include <time.h>
#include <stdlo.h>

/**
 * *main -> assign a random number to the variable n each time it is executed and printed out
 * *based a condition
 * *Return : always 0
 * */
int main(void)
{
	int n;

	strand(time(0));
	n=rand() - RAND_MAX / 2;
	If (n > 0)
			printf(“%d is positive”, n)
			return (0);
}

