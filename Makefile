CC=g++
TARGET=main

SRC_DIR=./src
INC_DIR=./include
OBJ_DIR=./obj

SRC_FILES=$(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES=$(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

C_FLAGS=-Wall -I$(INC_DIR)
LD_LIBS=-lSDL2 -lSDL2_image

$(TARGET): $(OBJ_FILES)
	$(CC) $(LD_LIBS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(C_FLAGS) -c -o $@ $<

clean:
	rm $(OBJ_DIR)/* $(TARGET)
