#include <string.h>

// Libraries
#ifndef LIB_JSON
	#define LIB_JSON
	#include "../deps/json/json.h"
	#include "../deps/json/json.c"
#endif

#include "db/defs.c"

#include "signals.c"
#include "cli.c"
#include "db/db.c"

int main() {
	database_t *database;
	database = malloc(sizeof(*database));
	database->logger = malloc(sizeof(*database->logger));
	database->logger->color = CLI_SYSTEM;

	cli_print_line("Booting smalldb...");

	signals_delegate();

	cli_print_line("Now running smalldb. ^C ^X enter to quit.");

	cli_color_change(database, CLI_CONSOLE);
	while (main_is_running()) {
		char buff[101];

		cli_print("  Enter command");

		do {
			cli_print("> ");
			cli_get_line(buff, sizeof(buff));
		}
		while (buff[0] == '\0');

		if (!main_is_running()) break;

		// execute
		db_run(database, buff);
		//db_retrieve_table("row_one");
	}

	cli_color_change(database, CLI_SYSTEM);
	cli_print_line("Shutting down...");

	cli_color_change(database, CLI_CONSOLE);

	free(database->logger);
	free(database);

	return 0;
}
