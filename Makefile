# Makefile2 for fwt2

# compiler and flags
CC      := gcc
CFLAGS  := -Wall -g -std=c99 -O3
LDLIBS  := -lm
INCLUDE := -I./include

# directories
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

# only list the actual .c files you have
SOURCES := fwt2.c data.c math.c usage.c

# build full paths
SRCS    := $(addprefix $(SRC_DIR)/,$(SOURCES))
OBJS    := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
TARGET  := $(BIN_DIR)/fwt2

.PHONY: all clean install

all: $(TARGET)

# ensure obj/ and bin/ exist
$(OBJ_DIR) $(BIN_DIR):
	mkdir -p $@

# compile each .c → .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

# link everything into bin/fwt2
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS)

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

install: all
	install -d $(PREFIX)/bin
	install $(TARGET) $(PREFIX)/bin

