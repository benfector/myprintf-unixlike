
TARGET = myprintf

CC = gcc

SRC_DIRS = new-version-reddit/src new-version-reddit/src/types

SRCS = $(wildcard $(addsuffix /*.c, $(SRC_DIRS)))

OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

run: $(TARGET)
	./$(TARGET)

.PHONY: clean run
