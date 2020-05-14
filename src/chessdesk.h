
#include <iostream>
#include <fstream>
#include <string>

class Position{
public:
int x, y;
bool good = true;
Position()
    {
    x = 0;
    y = 0;
    }
};

class Desk {
private:
public: 
int yyy;
std::string notation_step_str;
int char_id;
char figure = ' ';
char move = ' ';
std::fstream file;
Position chess_cell_position;
char desk[9][9] = {
            {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'},
            {'8', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
            {'7', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {'5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {'4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {'2', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
            {'1', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
    }; 

bool CheckNotation(std::string filename);
bool FindChessFigureType();
bool FindChessMoveType();
bool FindChessCellPosition(char x, char y);
bool CheckFigure();
void DrawDesk();
};
