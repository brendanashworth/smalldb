# Welcome! ^o^
# ------------
# This is the Makefile for smallDB. Here is a small index:
# 1) Compiling the entire program for CLI & network
# 2) Compiling and running tests
# 3) Cleaning the project directory
#
# ------------
# 1) Compiling the entire program for CLI & network
#
# `make` or `make all`
#
# Compiles the program.
#
# 2) Compiling and running tests
#
# `make test`
#
# There are no tests written yet, so this does not do anything.
#
# 3) Cleaning the project directory
#
# `make clean`
# This just removes the 'bin' folder, which contains all the executables.

compiler ?= gcc

# Flags for production, basically optimizes the code.
production_cflags = -O3
# Flags for debugging, which compiles a lot more stuff into the executable.
debugging_cflags = -g

#1
all: src/main.c
	-mkdir bin
	$(compiler) $(production_cflags) src/main.c -o bin/main

debugging: src/main.c
	-mkdir bin
	$(compiler) $(debugging_cflags) src/main.c -o bin/main

# 2
test:
	echo "No tests."

#3
clean:
	rm -rf bin

.PHONY: all clean
