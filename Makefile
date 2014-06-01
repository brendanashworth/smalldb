all: src/main.rs
	rustc src/main.rs -o main

internal: src/internal/main.c
	gcc src/internal/main.c -o main

clean:
	rm -f main

.PHONY: all clean internal
