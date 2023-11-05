# Directories
SRC=./src
OBJ=./obj
BIN=./bin
UTILS_DIR=$(SRC)/utils
TYPES_DIR=$(SRC)/types

# Build variables
BUILD_OPTIONS=-Wall -lm -g

# Files
HSL_NAME=rgb2hsl
RGB_NAME=hsl2rgb
UTILS=$(wildcard $(UTILS_DIR)/*.c)
UTILS_OBJ=$(patsubst $(UTILS_DIR)/%.c,$(OBJ)/%.o,$(UTILS))

all: build link test

test: test-rgb test-hsl

test-rgb: $(BIN)/$(RGB_NAME)
	$< 206 0.84 0.4902

test-hsl: $(BIN)/$(HSL_NAME)
	$< 20 140 230

build: build-rgb build-hsl

link: build link-rgb link-hsl

link-rgb: build-rgb $(UTILS_OBJ)
	gcc $(BUILD_OPTIONS) $(UTILS_OBJ) $(OBJ)/$(RGB_NAME).o -o $(BIN)/$(RGB_NAME)

link-hsl: build-hsl $(UTILS_OBJ)
	gcc $(BUILD_OPTIONS) $(OBJ)/$(HSL_NAME).o $(UTILS_OBJ) -o $(BIN)/$(HSL_NAME)

build-rgb: $(SRC)/$(RGB_NAME).c
	gcc $(BUILD_OPTIONS) -c $(SRC)/$(RGB_NAME).c -o $(OBJ)/$(RGB_NAME).o

build-hsl: $(SRC)/$(HSL_NAME).c
	gcc $(BUILD_OPTIONS) -c $(SRC)/$(HSL_NAME).c -o $(OBJ)/$(HSL_NAME).o

$(OBJ)/%.o: $(UTILS_DIR)/%.c
	gcc $(BUILD_OPTIONS) -c $< -o $@

clean:
	rm -rf $(OBJ)/*
	rm -rf $(BIN)/*

