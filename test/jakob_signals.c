#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

void handler(int num)
{
	//num = 0;
	write(STDOUT_FILENO, "i will not die\n", 15);
}

int main(void)
{
	signal(SIGINT, handler);
	signal(SIGTERM, handler);
	signal(SIGKILL, handler);

	while (1)
	{
		printf("malgastando los ciclos.  ID %i\n", getpid());
		sleep(1);
	}
	return (0);
}