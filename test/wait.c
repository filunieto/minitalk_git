#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>

int main(void)
{
	int id = fork();
	int n;

	//id = fork();
	if (id == 0)
		n = 1;
	else
		n = 6;
	// if (id != 0)
	// 	wait(NULL);
	int i;
	for (i = n; i < n + 5; i++)
	{
		printf("%d ", i);
		fflush(stdout);
	}
	printf("\n");
	return (0);
}