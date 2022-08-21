#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(void)
{
	int id = fork();
	if (id == 0)
	{
		sleep (1);
		printf("Current Id: %d, parent ID %i \n", getpid(), getppid());
		
	}
	else
	{
		
		printf("Este es el padre  %d\n", getpid());
		wait(NULL);
	}
	return (0);
}