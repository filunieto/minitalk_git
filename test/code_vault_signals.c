#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <signal.h>


int main(void)
{
	int pid = fork();
	if (pid == -1)
	{
		return -1;
	}
	if (pid == 0)
	{
		while (1)
		{
			printf("some text goes here\n");
			sleep(1);
		}

	}
	else
	{
		printf("entra en else\n");
		sleep(5);
		kill(pid, SIGSTOP);
		printf("SISTOP en else\n");
		sleep(3);
		kill(pid, SIGCONT);
		printf("continua en else\n");
		sleep(8);
		kill(pid, 9);
		wait(NULL);
	}
	return (0);
}