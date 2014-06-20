#include <stdio.h>

static char *color = "\x1B[0m";

/* Prints a line to the console. This includes a new line character. */
void cli_print_line (char *line) {
	printf("%s", line);
	printf("\n");
}

/* Prints text to the console. No new line character. */
void cli_print (char *line) {
	printf("%s", line);
}

/* Refreshes the color for the terminal. */
void cli_color_refresh () {
	cli_print(color);
}

/* Prints an error to the console. */
void cli_print_error (char *line) {
	cli_print("\x1B[31m");
	cli_print(line);
	cli_print(color);
	cli_print("\n");
}

/* Starts printing colored text. */
void cli_color_system () {
	color = "\x1B[36m";
	cli_color_refresh();
}

/* Starts printing regular text. */
void cli_color_console () {
	color = "\x1B[0m";
	cli_color_refresh();
}

/* Reads in a line from the command line. */
void cli_get_line (char *buff, size_t sz)
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
