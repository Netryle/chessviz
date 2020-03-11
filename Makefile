all:launch

comp: chessdesk.cpp

	g++ -Wall -o chessdesk chessdesk.cpp

launch: comp
	./chessdesk
