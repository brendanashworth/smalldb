#include <string.h>

#include "cli.c"
#include "signals.c"

#include "db/select.c"

int main()
{
	startSystemColor();
	printLine ("Booting smalldb...");

	delegateSignals();

	printLine ("Now running smalldb. ^C ^X enter to quit.");

	startConsoleColor();
	while (isRunning())
	{
		char buff[101];

		printText ("  Enter command");

		do
		{
			printText ("> ");
			getLine (buff, sizeof(buff));
		}
		while (buff[0] == '\0');

		if (!isRunning()) break;

		// execute
		retrieveTable ("row_one");
	}

	startSystemColor();
	printLine ("Shutting down...");

	startConsoleColor();
	return 0;
}
