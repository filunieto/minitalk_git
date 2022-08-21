#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void 	handle_sigtstp(int sig)
{
	sig = 0;
	printf("Parada no permitida majo");
}

int main()
{
	struct sigaction sa;
	sa.sa_handler = &handle_sigtstp;
	sa.sa_flags = SA_RESTART;
	int	x;

	sigaction(SIGTSTP, &sa, NULL);
	printf("input number: ");
	scanf("%d", &x);
	printf("result %d * 5 = %d\n", x, x * 5);
	return (0);
}