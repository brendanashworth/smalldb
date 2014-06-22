// parser.c
#include "command.c"
#include "../../../deps/internal/strings.c"

#ifndef LIB_JSON
#define LIB_JSON
#include "../../../deps/json/json.h"
#endif

const char *keywords[][4] = {"PUT", "DROP", "MODIFY", "GET"};
// This is how commands work:
// put: PUT { our json encoded data }
// drop: DROP { json encoded data, of which the data matches }
// modify: MODIFY { json match } { modified data }
// get: GET { json match }

db_command parser_parse(char *command) {
	// Get the action
	char **split = str_split(command, " ");

	// Create the command
	struct db_command cmd;

	if (strcmp(split[0], "PUT") == 0) {
		cmd.action = PUT;
		cmd.args[0] = json_parse(split[0], sizeof(split[0]));
		cmd.args[1] = json_parse(split[1], sizeof(split[1]));
	} else if (strcmp(split[0], "DROP") == 0) {
		cmd.action = DROP;
	} else if (strcmp(split[0], "MODIFY") == 0) {
		cmd.action = MODIFY;
	} else if (strcmp(split[0], "GET") == 0) {
		cmd.action = GET;
	} else {
		cmd.error = "That command is not recognized.";
	}

	return cmd;
}
