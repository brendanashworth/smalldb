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
# Compiling the entire program is a little bit of a hassle, since the backend database is
# 	written in C and the frontend + network is written in Rust. Due to this, we must
#	interface the C code so that it can be called from Rust.
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
all: src/main.rs
	-mkdir bin
	rustc src/main.rs -o bin/main

internal: src/internal/main.c
	-mkdir bin
	gcc src/internal/main.c -o bin/main

# 2
test:

#3
clean:
	rm -rf bin

.PHONY: all clean internal
