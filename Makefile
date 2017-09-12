AM_CFLAGS := -g -Wall -O2

CC        := gcc
CFLAGS    := $(AM_CFLAGS)

LD        := gcc

APPS      := suffix_arr
OBJS      := $(APPS).o
SRCS      := $(APPS).c

suffix_arr: suffix_arr.o
	$(LD) $(AM_CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -fr $(APPS) *.o *.out
