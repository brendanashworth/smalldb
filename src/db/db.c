#include "select.c"
#include "parser/parser.c"

void db_retrieve_table(char *name) {
	db_lib_retrieve_table(name);
}

void db_run(char *command) {
	parser_parse(command);

	db_retrieve_table("row_one");
}