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

#1
all: src/main.c
	-mkdir bin
	gcc src/main.c -o bin/main

# 2
test:
	echo "No tests."

#3
clean:
	rm -rf bin

.PHONY: all clean
