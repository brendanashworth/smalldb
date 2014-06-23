#include "select.c"
#include "parser/parser.c"

void db_retrieve_table(database_t *db, char *name) {
	db_lib_retrieve_table(db, name);
}

void db_run(database_t *db, char *command) {
	db_command *cmd = parser_parse(command);

	db_retrieve_table(db, "row_one");

	// Free the memory from cmd
	free(cmd->error);
	free(cmd->args);
	free(cmd);
}
