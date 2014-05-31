#include <stdio.h>

void retrieveTable (char *name) {
	char base[26];
	strcpy(base, "./data/");
	strcat(base, name);
	strcat(base, "/name.t");

	FILE *file;
	file = fopen(base, "r");

	// if there was an error reading
	if (file == NULL) {
		printError ("Error: could not read ./data/row_one/name.t");
		return;
	}

	char key[51];
	char values[50];

	// read file
	while (fscanf(file, "%s %[^\n]", key, values) == 2) {
		// make it beautiful
		char display[56];
		strcpy(display, "    -> ");
		strcat(display, key);
		strcat(display, " :: ");
		strcat(display, values);

		printLine(display);
	}

	fclose(file);
}
