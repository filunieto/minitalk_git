#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main()
{
	int	x;

	printf("input number: ");
	scanf("%d", &x);
	printf("result %d * 5 = %d\n", x, x * 5);
	return (0);
}