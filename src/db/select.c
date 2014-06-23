void db_lib_retrieve_table (database_t *db, const char *name) {
	char base[26];
	strcpy(base, "./data/");
	strcat(base, name);
	strcat(base, "/name.t");

	FILE *file;
	file = fopen(base, "r");

	// if there was an error reading
	if (file == NULL) {
		cli_print_error(db, "Error: could not read table file");
		return;
	}

	char key[51];
	char valueSet[50];

	// read file
	while (fscanf(file, "%s %[^\n]", key, valueSet) == 2) {
		// get us a returnable data object
		int values[10];

		for (int i = 0; i < strlen(valueSet); i++) {
			if (valueSet[i] != '&')
				values[ (sizeof(values) / sizeof(values[0])) - 1 ] = valueSet[i];
		}

		char display[56];
		strcpy(display, "    -> ");
		strcat(display, key);
		strcat(display, " :: ");
		strcat(display, valueSet);

		cli_print_line(display);
	}

	fclose(file);
}
