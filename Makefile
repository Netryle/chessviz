all:launch

comp: chessdesk.cpp

	g++ -Wall -Werror -o chessdesk chessdesk.cpp

launch: comp
	./chessdesk
