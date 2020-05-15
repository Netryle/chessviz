.PHONY: all clean install uninstall 

CC = g++
CFLAGS = -std=c++11 -c -MP -MMD -Wall -Werror
SRC = src/main.cpp src/chessdesk.cpp
OBJ = build/src/main.o build/src/chessdesk.o
EXEC = chess.exe

all: $(SRC) $(EXEC) 


$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $@

build/src/%.o: src/%.cpp	
	$(CC) $(CFLAGS) $< -o $@

-include build/*.d

T_EXEC = test.exe
T_SRC = $(SRC:src/main.cpp=test/main.cpp)
TEST_SRC = test/chessdesk_test.cpp
TO_PATH = build/test/
T_OBJ = $(TO_PATH)main.o $(TO_PATH)chessdesk_test.o build/src/chessdesk.o

test: $(T_SRC) $(TEST_SRC) $(T_EXEC)

$(T_EXEC): $(T_OBJ)
	$(CC) $(T_OBJ) -o $@

build/test/%.o: test/%.cpp	
	$(CC) $(CFLAGS) $< -o $@

-include build/test/*.d


clean:  
	rm -rf build/src/*.o build/src/*.d build/test/*.o build/test/*.d