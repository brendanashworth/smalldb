#include <stdio.h>
#include <string.h>

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
	char valueSet[50];

	// read file
	while (fscanf(file, "%s %[^\n]", key, valueSet) == 2) {
		// get us a returnable data object
		int values[10];

		for (int i = 0; i < strlen(valueSet); i++) {
			if (valueSet[i] != '&')
				values[sizeof(values) / sizeof(values[0])] = valueSet[i];
		}

		char display[56];
		strcpy(display, "    -> ");
		strcat(display, key);
		strcat(display, " :: ");
		strcat(display, valueSet);

		printLine(display);
	}

	fclose(file);
}
