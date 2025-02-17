# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -pthread

# Main executable name
TARGET = port_scanner

# Directories for main sources
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj

# Source files for main executable
SRC_FILES = $(SRC_DIR)/main.c \
            $(SRC_DIR)/scanner.c \
            $(SRC_DIR)/threads.c \
            $(SRC_DIR)/bannergrab.c

# Object files for main executable (replace .c with .o)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Default target builds the main executable
all: $(TARGET)

# Linking the final executable
$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

# Compile .c into .o for main sources
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

#####################################
# Test configuration
#####################################

# Directories for test sources
TEST_DIR = tests
TEST_OBJ_DIR = obj_tests

# Test source file(s) and corresponding object files
TEST_SRC = $(TEST_DIR)/test_scanner.c
TEST_OBJ = $(TEST_OBJ_DIR)/test_scanner.o

# Test executable name
TEST_TARGET = test_scanner

# Build the test executable by linking test objects with scanner.o
test: $(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJ) $(OBJ_DIR)/scanner.o
	$(CC) $(CFLAGS) -o $@ $^

# Compile .c into .o for test sources
$(TEST_OBJ_DIR)/%.o: $(TEST_DIR)/%.c
	mkdir -p $(TEST_OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

#####################################
# Clean up build artifacts
#####################################

clean:
	rm -rf $(OBJ_DIR) $(TARGET) $(TEST_OBJ_DIR) $(TEST_TARGET)

.PHONY: all clean test