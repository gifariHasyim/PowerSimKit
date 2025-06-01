# Nama program
TARGET = powersimkit

# Folder
SRC_DIR = src
OBJ_DIR = build
INCLUDE_DIR = include

# Cari semua file .c
SRCS := $(shell find $(SRC_DIR) -name '*.c')
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Compiler flags
CC = gcc
CFLAGS = -Wall -Wextra -g -I$(INCLUDE_DIR)

# Default target
all: $(TARGET)

# Link semua object jadi executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile tiap .c jadi .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

test: $(OBJ_DIR)/tests/test_file_reader.o $(OBJ_DIR)/io/file_reader.o
	$(CC) $(CFLAGS) -o test_file_reader $^

$(OBJ_DIR)/tests/test_file_reader.o: tests/test_file_reader.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean object dan executable
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: all clean
