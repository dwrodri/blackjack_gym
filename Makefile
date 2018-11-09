# Derek Rodriguez
# A basic Makefile for compiling bjgym 

# Environment Variables
CC = clang
TARGET = blackjack
SRC = src/*.c
CFLAGS = -O2 
DEBUG_CFLAGS = -g -O0

all:
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

debug:
	$(CC) $(DEBUG_CFLAGS) -o $(TARGET) $(SRC)

clean:
	$(RM) $(TARGET)

