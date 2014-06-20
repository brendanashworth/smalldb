#include <stdio.h>

static char *color = "\x1B[0m";

/* Prints a line to the console. This includes a new line character. */
void printLine (char *line) {
	printf("%s", line);
	printf("\n");
}

/* Prints text to the console. No new line character. */
void printText (char *line) {
	printf("%s", line);
}

/* Refreshes the color for the terminal. */
void refreshTextColor () {
	printText(color);
}

/* Prints an error to the console. */
void printError (char *line) {
	printText("\x1B[31m");
	printText(line);
	printText(color);
	printText("\n");
}

/* Starts printing colored text. */
void startSystemColor () {
	color = "\x1B[36m";
	refreshTextColor();
}

/* Starts printing regular text. */
void startConsoleColor () {
	color = "\x1B[0m";
	refreshTextColor();
}

/* Reads in a line from the command line. */
void getLine (char *buff, size_t sz)
{
	int ch, extra;


	/* If no input */
	if (fgets(buff, sz, stdin) == NULL)
	{
		return;
	}

	/* This might be too long */
	if (buff[strlen(buff)-1] != '\n')
	{
		extra = 0;
		while (((ch = getchar()) != '\n') && (ch != EOF))
			extra = 1;

		return;
	}

	buff[strlen(buff)-1] = '\0';
	return;

}
