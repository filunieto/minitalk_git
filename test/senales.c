#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void	Mysignalhandler(int sig)
{
	printf("signal number is %d \n", sig);
}

int main()
{
	signal(SIGIO, &Mysignalhandler);
	while (1)
	{
		printf("zzzZZZzzz\n");
		sleep(2);
	}
	return (0);
}