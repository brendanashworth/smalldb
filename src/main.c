#include <string.h>

// Libraries
#ifndef LIB_JSON
#define LIB_JSON
#include "../deps/json/json.h"
#endif

#include "cli.c"
#include "signals.c"

#include "db/db.c"

int main() {
	cli_color_system();
	cli_print_line("Booting smalldb...");

	signals_delegate();

	cli_print_line("Now running smalldb. ^C ^X enter to quit.");

	cli_color_console();
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
		db_run(buff);
		//db_retrieve_table("row_one");
	}

	cli_color_system();
	cli_print_line("Shutting down...");

	cli_color_console();
	return 0;
}
