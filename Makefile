all:launch

comp: chessdesk.cpp

	g++ -Wall -o chessdesk.a chessdesk.cpp

launch: comp
	./chessdesk.a
