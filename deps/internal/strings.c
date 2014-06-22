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
char **str_split(char *string, char *delim) {
    uint8_t size = str_count(string, "") + 1, i;
    char** split = malloc(size * sizeof(char*) );

    for (i = 0; i < size; i++) {
        if (i == 0)
            split[i] = strtok(string, delim);
        else
            split[i] = strtok(NULL, delim);
    }

    return split;
}
