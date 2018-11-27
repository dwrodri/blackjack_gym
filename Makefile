# Derek Rodriguez
# A basic Makefile for compiling bjgym 

# Environment Variables
CC = clang
TARGET = blackjack
SRC = src/*.c
CFLAGS = -j -O2 -Wall -Wextra
DEBUG_CFLAGS = -g -O0 -Wall -Wextra

all:
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

debug:
	$(CC) $(DEBUG_CFLAGS) -o $(TARGET) $(SRC)

clean:
	$(RM) $(TARGET)

