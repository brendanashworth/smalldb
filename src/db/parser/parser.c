// parser.c

char *keywords[] = {"SELECT", "UPDATE", "INSERT INTO", "DELETE"};

void parser_parse(char *command) {
	// Replace spaces inside of apostrophes
	int i;
	int apos = 0;
	for (i = 0; i < strlen(command); i++) {
		if (command[i] == ';') break;

		// If its a space, replace with #.
		if (command[i] == ' ' && apos) {
			command[i] = '#';
		}

		// Negate apos
		if (command[i] == '\'') apos = !apos;
	}

	cli_print_line(command);

	// Split it by spaces
	char *saveptr;
	char *delimiters = strtok_r(command, " ", &saveptr);

	// Parse through the command
	for (i = 0; i < strlen(command); i++) {
		if (command[i] == ';') break;

		// If its a 
	}
}