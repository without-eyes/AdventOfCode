CC = gcc
CFLAGS = -Werror -Wall -g

all: compile run clean

compile:
	$(CC) ./answers/$(year)/$(day).c $(CFLAGS) -o $(day)

run:
	$(day).exe

clean:
	del /f *.exe
