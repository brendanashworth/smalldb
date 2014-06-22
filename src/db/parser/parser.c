// parser.c
#include "command.c"
#include "../../../lib/internal/strings.c"

const char *keywords[][4] = {"PUT", "DROP", "MODIFY", "GET"};
// This is how commands work:
// put: PUT { our json encoded data }
// drop: DROP { json encoded data, of which the data matches }
// modify: MODIFY { json match } { modified data }
// get: GET { json match }

void parser_parse(const char *command) {
	// Get the action
	char **split = str_split(command, " ");
	char action = *split[0];

	printf("LA LA %s LA LA\n", &action);


	if (strcmp(&action, "PUT") == 0) {
		cli_print_line("Used PUT.");
	} else if (strcmp(&action, "DROP") == 0) {
		cli_print_line("Used DROP.");
	} else if (strcmp(&action, "MODIFY") == 0) {
		cli_print_line("Used MODIFY.");
	} else if (strcmp(&action, "GET") == 0) {
		cli_print_line("Used GET.");
	} else {
		cli_print_error("That command is not recognized.");
	}

	//cli_print_line(&action);
}
