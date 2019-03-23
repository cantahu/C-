##
CC=gcc
CFLAGS=-Wall

OUT=huja
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

.PHONY:clean all

$(OUT):$(OBJ)
	$(CC) $(CFLAGS) -o $@ $^


%.o:%.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	-rm -f $(OBJ) $(OUT)
