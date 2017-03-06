EXEC=hashcrack
NAME=$(EXEC).c

CFLAGS=-std=c99 -g -lssl -lcrypto -lpthread

all: 
	gcc $(NAME) -o $(EXEC) $(CFLAGS)
