#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>


void 	handle_sigusr1(int sig)
{
	//sig = 0;
	printf("HINT: recuerda que la suma es como multiplicar mas o menos: parametro sig: %i\n", sig);
}

int main()
{	
	int pid = fork();

	if (pid == -1)
		return (-1);

	if (pid == 0)
	{
		sleep (5);
		kill (getppid(), SIGUSR1);
	}
	else //parent process
	{
		int	x;
		struct sigaction sa = {0};
		sa.sa_handler = &handle_sigusr1;
		sa.sa_flags = SA_RESTART;
		sigaction(SIGUSR1, &sa, NULL);


		printf("resultado de 3 * 5: \n");
		scanf("%d", &x);
		if (x == 15)
			printf("correcto\n");
		else	
			printf("nops\n");
		wait (NULL);

	}

	return (0);
}