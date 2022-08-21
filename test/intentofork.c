#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main(void)
{
	if (fork() == 0)
	{
		printf("soy el hijo y este es mi ID %i\n", getpid());

	}
	else
	{
		printf("soy el padre y mi id es %i\n", getpid());

	}
	return (0);
}