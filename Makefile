all: src/main.c
	 gcc src/main.c -o main

clean:
	rm -f main

.PHONY: all clean
