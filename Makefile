INCLUDE = ./include
BIN = ./bin
SRC = ./src
TEST = ./test
OBJ = ./obj
BOOST = /home/fav/libs/boost/1_44

CC = g++
CFLAGS = -s -O2 -I$(BOOST) -I$(INCLUDE)

all: $(BIN)/test1

objs = $(OBJ)/conv.o $(OBJ)/test1.o
pheader = $(INCLUDE)/spirit.hpp.gch

pheader: $(INCLUDE)/spirit.hpp
	$(CC) $(CFLAGS) -o $(INCLUDE)/spirit.hpp.gch $(INCLUDE)/spirit.hpp

$(OBJ)/conv.o: $(SRC)/conv.cpp $(INCLUDE)/conv.hpp pheader
	$(CC) $(CFLAGS) -c -o $(OBJ)/conv.o $(SRC)/conv.cpp
	
$(OBJ)/test1.o: $(TEST)/test1.cpp
	$(CC) $(CFLAGS) -c -o $(OBJ)/test1.o $(TEST)/test1.cpp
	
$(BIN)/test1: $(OBJ)/test1.o $(OBJ)/conv.o
	$(CC) $(CFLAGS) -o $(BIN)/test1 $(OBJ)/test1.o $(OBJ)/conv.o
