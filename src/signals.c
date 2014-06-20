#include <signal.h>

static int running = 1;

void signal_handle_int (int sig) {
	running = 0;
}


void signals_delegate () {
	signal(SIGINT, signal_handle_int);
}

/* Checks whether or not the program is running. */
int main_is_running () {
	return running;
}
