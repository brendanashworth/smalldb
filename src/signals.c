#include <signal.h>

static int running = 1;

void handleIntSignal(int sig)
{
	running = 0;
}


void delegateSignals()
{
	signal(SIGINT, handleIntSignal);
}

/* Checks whether or not the program is running. */
int isRunning()
{
	return running;
}
