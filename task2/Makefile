CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Output binary name
TARGET = main.exe

# Source files
SRC = main.c

# Build target
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Clean build files
clean:
	rm -f $(TARGET)
