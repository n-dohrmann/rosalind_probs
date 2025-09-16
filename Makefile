# Top-level Makefile

CC = gcc
CFLAGS = -Wall -Wextra -O2 -Icommon
COMMON_SRC = common/utils.c

PROBLEMS = ba10a ba10c

# Automatically generate paths like build/prob1
EXES = $(addprefix build/, $(PROBLEMS))

# Default target: build all problems
all: $(EXES)

# Rule for building a single problem executable
build/%: %/main.c $(COMMON_SRC) | build
	$(CC) $(CFLAGS) $< $(COMMON_SRC) -o $@

# Ensure build directory exists
build:
	mkdir -p build

# Clean everything
clean:
	rm -rf build

.PHONY: all clean

