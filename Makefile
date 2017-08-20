CC = gcc
CPPFLAGS = -DNDEBUG
CFLAGS = -g -Wall -Wvla -Wextra -std=c99
LDFLAGS = -g

VAL = valgrind
VALFLAGS = --leak-check=full --show-possibly-lost=yes --show-reachable=yes --undef-value-errors=yes --log-file=

.PHONY: clean all val tar

all: MyStringExample
	./$<

# Implicit rule
# %: %.o
# 	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@
LineSeparator: LineSeparator.o
MyStringExample: MyStringExample.o MyString.o

# Implicit rule
# %.o: %.c
# 	$(CC) $(CPPFLAGS) $(CFLAGS) $< -o $@
LineSeparator.o: LineSeparator.c LineSeparator.h
MyString.o: MyString.c MyString.h
MyStringExample.o: MyStringExample.c MyString.h

val: valdbg_LineSeparator valdbg_MyString
valdbg_LineSeparator: LineSeparator
	$(VAL) $(VALFLAGS)"$@" $< $<.in
valdbg_MyString: MyStringExample
	$(VAL) $(VALFLAGS)"$@" $<

tar: ex2.tar
ex2.tar: valdbg_LineSeparator valdbg_MyString Makefile MyString.c LineSeparator.c LineSeparator.h
	tar -cvf $@ $^ extension.pdf

clean:
	rm -f *.o LineSeparator MyStringExample MyString valdbg_* ex2.tar