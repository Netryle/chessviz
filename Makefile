.PHONY: all clean install uninstall 

CC = g++
CFLAGS = -std=c++11 -c -MP -MMD -Wall -Werror
SRC = src/main.cpp src/chessdesk.cpp
OBJ = build/main.o build/chessdesk.o
EXEC = chess.exe

all: $(SRC) $(EXEC) 

-include build/*.d

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $@

build/%.o: src/%.cpp	
	$(CC) $(CFLAGS) $< -o $@


clean:  
	rm -rf build/*.o build/*.d 