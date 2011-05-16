INCLUDE = ./include
BIN = ./bin
SRC = ./src
TEST = ./test
OBJ = ./obj
BOOST = /home/fav/libs/boost/1_44

CC = g++
CFLAGS = -s -O2 -I$(BOOST) -I$(INCLUDE)

all: $(BIN)/test1 $(BIN)/test2 $(BIN)/test10

objs = $(OBJ)/conv.o $(OBJ)/test1.o $(OBJ)/hl7types.o $(OBJ)/test2.o

objs1 = $(OBJ)/fields.o $(OBJ)/parser.o $(OBJ)/test10.o $(OBJ)/types.o $(OBJ)/typebuilder.o $(OBJ)/factory.o $(OBJ)/out.o $(OBJ)/outbuilder.o

pheader = $(INCLUDE)/spirit.hpp.gch

pheader: $(INCLUDE)/spirit.hpp
	$(CC) $(CFLAGS) -o $(INCLUDE)/spirit.hpp.gch $(INCLUDE)/spirit.hpp

$(OBJ)/conv.o: $(SRC)/conv.cpp $(INCLUDE)/conv.hpp
	$(CC) $(CFLAGS) -c -o $(OBJ)/conv.o $(SRC)/conv.cpp
	
$(OBJ)/hl7types.o: $(SRC)/hl7types.cpp $(INCLUDE)/hl7types.hpp
	$(CC) $(CFLAGS) -c -o $(OBJ)/hl7types.o $(SRC)/hl7types.cpp
	
$(OBJ)/test1.o: $(TEST)/test1.cpp
	$(CC) $(CFLAGS) -c -o $(OBJ)/test1.o $(TEST)/test1.cpp
	
$(OBJ)/test2.o: $(TEST)/test2.cpp $(INCLUDE)/hl7types.hpp
	$(CC) $(CFLAGS) -c -o $(OBJ)/test2.o $(TEST)/test2.cpp
	
$(BIN)/test1: $(OBJ)/conv.o $(OBJ)/test1.o
	$(CC) $(CFLAGS) -o $(BIN)/test1 $(OBJ)/test1.o $(OBJ)/conv.o
	
$(BIN)/test2: $(OBJ)/hl7types.o $(OBJ)/test2.o
	$(CC) $(CFLAGS) -o $(BIN)/test2 $(OBJ)/test2.o $(OBJ)/hl7types.o

$(OBJ)/test10.o: $(TEST)/test10.cpp $(INCLUDE)/types.hpp $(INCLUDE)/fields.hpp
	$(CC) $(CFLAGS) -c -o $(OBJ)/test10.o $(TEST)/test10.cpp

$(OBJ)/parser.o: $(SRC)/parser.cpp $(INCLUDE)/parser.hpp
	$(CC) $(CFLAGS) -c -o $(OBJ)/parser.o $(SRC)/parser.cpp


$(OBJ)/fields.o: $(SRC)/fields.cpp $(INCLUDE)/fields.hpp
	$(CC) $(CFLAGS) -c -o $(OBJ)/fields.o $(SRC)/fields.cpp

$(OBJ)/types.o: $(SRC)/types.cpp $(INCLUDE)/types.hpp
	$(CC) $(CFLAGS) -c -o $(OBJ)/types.o $(SRC)/types.cpp

$(OBJ)/typebuilder.o: $(SRC)/typebuilder.cpp $(INCLUDE)/typebuilder.hpp
	$(CC) $(CFLAGS) -c -o $(OBJ)/typebuilder.o $(SRC)/typebuilder.cpp

$(OBJ)/factory.o: $(SRC)/factory.cpp $(INCLUDE)/factory.hpp
	$(CC) $(CFLAGS) -c -o $(OBJ)/factory.o $(SRC)/factory.cpp

$(OBJ)/out.o: $(SRC)/out.cpp $(INCLUDE)/out.hpp
	$(CC) $(CFLAGS) -c -o $(OBJ)/out.o $(SRC)/out.cpp

$(OBJ)/outbuilder.o: $(SRC)/outbuilder.cpp $(INCLUDE)/outbuilder.hpp
	$(CC) $(CFLAGS) -c -o $(OBJ)/outbuilder.o $(SRC)/outbuilder.cpp

$(BIN)/test10: $(objs1)
	$(CC) $(CFLAGS) -o $(BIN)/test10 $(objs1)
