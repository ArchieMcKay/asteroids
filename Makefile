OBJS=main.cpp game.cpp
CC=g++
FLAGS=-Wall
LIBS=-lSDL2

OBJ_NAME=main

all: $(OBJS)
	$(CC) $(OBJS) $(FLAGS) $(LIBS) -o $(OBJ_NAME)
