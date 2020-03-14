all:launch

comp: chessdesk.cpp

	g++ -Wall -Werror -o chessdesk.a chessdesk.cpp

launch: comp
	./chessdesk.a
