#include <stdio.h>

void cli_init(database_t *db) {
	db->logger->color = CLI_SYSTEM;
}

/* Prints a line to the console. This includes a new line character. */
void cli_print_line(char *line) {
	printf("%s", line);
	printf("\n");
}

/* Prints text to the console. No new line character. */
void cli_print(char *line) {
	printf("%s", line);
}

/* Changes the CLI color */
void cli_color_change(database_t *db, cli_color color) {
	db->logger->color = &color;

	if (color == CLI_SYSTEM)
		cli_print("\x1B[36m");
	else if (color == CLI_CONSOLE)
		cli_print("\x1B[0m");
	else if (color == CLI_ERROR)
		cli_print("\x1B[31m");
}

/* Refreshes the color for the terminal. */
void cli_color_refresh(database_t *db) {
	cli_color_change(db, *db->logger->color);
}

/* Prints an error to the console. */
void cli_print_error(database_t *db, char *line) {
	cli_print("\x1B[31m");
	cli_print(line);
	cli_color_refresh(db);
	cli_print("\n");
}

/* Reads in a line from the command line. */
void cli_get_line(char *buff, size_t sz) {
	int ch, extra;

	/* If no input */
	if (fgets(buff, sz, stdin) == NULL) {
		return;
	}

	/* This might be too long */
	if (buff[strlen(buff)-1] != '\n') {
		extra = 0;
		while (((ch = getchar()) != '\n') && (ch != EOF))
			extra = 1;

		return;
	}

	buff[strlen(buff)-1] = '\0';
}
