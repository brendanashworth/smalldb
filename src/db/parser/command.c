// command.c

// Action type struct
enum db_command_action { PUT, DROP, MODIFY, GET };

// Command struct
typedef struct db_command {
	// If an error occurs, might as well pass it down.
	char *error;
	enum db_command_action action;
	struct json_value *args;
} db_command;