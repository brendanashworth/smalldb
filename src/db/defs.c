// definitions

/* General database definitions */
typedef enum cli_color {
	CLI_SYSTEM,
	CLI_CONSOLE,
	CLI_ERROR
} cli_color;

typedef struct database_log_t {
	cli_color *color;
} database_log_t;

typedef struct database_t {
	database_log_t *logger;
} database_t;

/* Command specific definitions */
// Action type struct
enum db_command_action { PUT, DROP, MODIFY, GET };

// Command struct
typedef struct db_command {
	// If an error occurs, might as well pass it down.
	char *error;
	enum db_command_action *action;
	json_value *args;
} db_command;

