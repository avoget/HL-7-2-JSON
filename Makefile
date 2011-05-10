INCLUDE = ./include
BIN = ./bin
SRC = ./src
TEST = ./test
OBJ = ./obj
BOOST = /home/fav/libs/boost/1_44

CC = g++
CFLAGS = -s -O2 -I$(BOOST) -I$(INCLUDE)

all: $(BIN)/test1 $(BIN)/test2

objs = $(OBJ)/conv.o $(OBJ)/test1.o $(OBJ)/hl7types.o $(OBJ)/test2.o
pheader = $(INCLUDE)/spirit.hpp.gch

pheader: $(INCLUDE)/spirit.hpp
	$(CC) $(CFLAGS) -o $(INCLUDE)/spirit.hpp.gch $(INCLUDE)/spirit.hpp

$(OBJ)/conv.o: $(SRC)/conv.cpp $(INCLUDE)/conv.hpp
	$(CC) $(CFLAGS) -c -o $(OBJ)/conv.o $(SRC)/conv.cpp
	
$(OBJ)/hl7types.o: $(SRC)/hl7types.cpp $(INCLUDE)/hl7types.hpp
	$(CC) $(CFLAGS) -c -o $(OBJ)/hl7types.o $(SRC)/hl7types.cpp
	
$(OBJ)/test1.o: $(TEST)/test1.cpp
	$(CC) $(CFLAGS) -c -o $(OBJ)/test1.o $(TEST)/test1.cpp
	
$(OBJ)/test2.o: $(TEST)/test2.cpp
	$(CC) $(CFLAGS) -c -o $(OBJ)/test2.o $(TEST)/test2.cpp
	
$(BIN)/test1: $(OBJ)/conv.o $(OBJ)/test1.o
	$(CC) $(CFLAGS) -o $(BIN)/test1 $(OBJ)/test1.o $(OBJ)/conv.o
	
$(BIN)/test2: $(OBJ)/hl7types.o $(OBJ)/test2.o
	$(CC) $(CFLAGS) -o $(BIN)/test2 $(OBJ)/test2.o $(OBJ)/hl7types.o
