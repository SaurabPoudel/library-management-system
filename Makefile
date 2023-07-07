CC = gcc
CFLAGS = -Wall -Werror
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
DATA_DIR = data

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))
EXECUTABLE = $(BIN_DIR)/library.exe

.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ_FILES) | $(BIN_DIR) $(DATA_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

$(OBJ_DIR):
	@if not exist "$(OBJ_DIR)" mkdir "$(OBJ_DIR)"

$(BIN_DIR):
	@if not exist "$(BIN_DIR)" mkdir "$(BIN_DIR)"

$(DATA_DIR):
	@if not exist "$(DATA_DIR)" mkdir "$(DATA_DIR)"

#for windows user only
clean:
	rmdir /s /q $(OBJ_DIR)
	rmdir /s /q $(BIN_DIR)
cleandatafolder:
	rmdir /s $(DATA_DIR)
#for linux user uncomment this
#clean:
#	rm -rf $(OBJ_DIR)
#	rm -rf $(BIN_DIR)
