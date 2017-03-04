CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LFLAGS = 
LIBS = 
SOURCES = main.c
OBJECTS = $(subst .c,.o,$(SOURCES))
EXE = sudoku.exe
.PHONY: clean help

soln.exe : main.c
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

all: $(EXE)

clean:
	rm -f $(OBJECTS) $(EXE) *~

cleanup: 
	rm -f $(OBJECTS) *~