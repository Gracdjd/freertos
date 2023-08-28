CC=gcc
CFLAGS = -Wall -O2

LIST_DIR = list
LIST_SRC = $(LIST_DIR)/list.c

TARGET = main
SRCS = main.c $(LIST_SRC) 
OBJS = $(SRCS:.c=.o)
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(TARGET)

.PHONY: all clean