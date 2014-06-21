// parser.c
#include "command.c"
#include "../../../lib/internal/strings.c"

char *keywords[][4] = {"PUT", "DROP", "MODIFY", "GET"};
// This is how commands work:
// put: PUT { our json encoded data }
// drop: DROP { json encoded data, of which the data matches }
// modify: MODIFY { json match } { modified data }
// get: GET { json match }

void parser_parse(char *command) {
	// Get the action
	char *split = str_split(command, " ");
	char action = split[0];

	if (strncmp(&action, "PUT", 3) == 0) {
		cli_print_line("Used PUT.");
	} else if (strncmp(&action, "DROP", 4) == 0) {
		cli_print_line("Used DROP.");
	} else if (strncmp(&action, "MODIFY", 6) == 0) {
		cli_print_line("Used MODIFY.");
	} else if (strncmp(&action, "GET", 3) == 0) {
		cli_print_line("Used GET.");
	} else {
		cli_print_error("That command is not recognized.");
	}

	cli_print_line(command);
}