# ---------------------------------------------------------------
# Makefile for galton
# -- only alter the first part!!
# ---------------------------------------------------------------

all: obj bin bin/galton

bin/galton: \
	obj/galton.o \

#
# -- do not touch the few lines below! --------------------------

CC=gcc
CFLAGS=-O0 -ggdb3 -Wall -Wextra -Werror -g
#CFLAGS=-O2
JDFLAGS=

release:
	$(MAKE) "CFLAGS=-O2"

obj/%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $^

bin/%:
	$(CC) $(LDFLAGS) -o $@ $^ $(LIBS)

bin:
	mkdir -p bin

obj:
	mkdir -p obj

clean:
	rm -rf bin obj
