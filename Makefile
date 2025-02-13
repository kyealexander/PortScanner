# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -pthread

# Executable name
TARGET = port_scanner

# Directories
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj

# Source files
SRC_FILES = $(SRC_DIR)/main.c \
            $(SRC_DIR)/scanner.c \
            $(SRC_DIR)/threads.c \
            $(SRC_DIR)/bannergrab.c

# Object files (replacing .c with .o)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Default target
all: $(TARGET)

# Linking the final executable
$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

# Compile .c into .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

# Clean up build artifacts
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: all clean