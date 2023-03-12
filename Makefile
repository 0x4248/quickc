# Quick C (main.c)
# A quick C and C++ runner
# Github: https://www.github.com/awesomelewis2007/quickc
#
# Main entry point for the program


# Compiler
CC = g++

# Compiler flags. These are the default flags.
CFLAGS = 
STD = 

# Folder locations
# Source code
SRC = src

# Binary output
BIN = bin

# Library files
LIB = lib

# Output file name
OUTPUT = $(BIN)/quickc

# Keep these includes. They import the configuration files.
include CFLAGS.conf
include STD.conf

all: init compile run

init:
	rm -rf bin
	mkdir bin

compile:
	$(CC) $(CFLAGS) -std=$(STD) $(SRC)/*.cpp -o $(OUTPUT) -I $(LIB)

configure_test:
	cp tests/test_check_hello.c $(BIN)/test_check_hello.c

test: init compile configure_test
	$(OUTPUT) $(BIN)/test_check_hello.c .

clean:
	rm -rf bin

