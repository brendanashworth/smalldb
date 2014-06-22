// A string library
#import <stdlib.h>

// Counts the occurrences of a delimiter inside a string.
int str_count(char *string, char *delim) {
	int count = 0;
	int i;
	for (i = 0; i < strlen(string); i++) {
		if (strncmp(&string[i], delim, strlen(string))) {
			count++;
		}
	}

	return count;
}

// Splits a string by a delimiter and returns the string.
char *str_split(char *string, char delim) {
	int count;
	int size = str_count(string, delim);
	char *saveptr;
	char *token;
	char *split = malloc(size);

	for (count = 0; count < size; count++) {
		// if 0, provide string, if not, don't provide string
		if (count == 0)
			token = strtok_r(string, delim, &saveptr);
		else
			token = strtok_r(NULL, delim, &saveptr);

		printf("Assigned %s to %i.\n", token, count);
		split[count] = token;
	}

	return split;
}
