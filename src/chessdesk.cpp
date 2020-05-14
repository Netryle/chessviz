#include "chessdesk.h"

using namespace std;

bool Desk::FindChessFigureType()
{
    string FigureType = "KQRNB";
    for (int i; i <(int)notation_step_str.size(); i++)
    {
        if (notation_step_str[char_id] == FigureType[i])
        {
            char_id++;
            figure = FigureType[i];
            return true;
        }
    }

    if ((int)notation_step_str[char_id] <= 104 && (int)notation_step_str[char_id] >= 97)
    {
        figure = 'P';
        return true;
    }
    return false;
}

bool Desk::FindChessCellPosition(char x, char y)
{
    chess_cell_position.good = false;
    for (int i = 1; i < 9; i++) {
        if (desk[0][i] == x) {
            chess_cell_position.y = i;
            chess_cell_position.good = true;
            char_id++;
            break;
        }
    }
    for (int j = 1; j < 9; j++) {
        if (desk[j][0] == y) {
            chess_cell_position.x = j;
            chess_cell_position.good = true;
            char_id++;
            break;
        }
    }

    return chess_cell_position.good;
}

bool Desk::FindChessMoveType()
{
    string MoveType = "-x";
    for (int i; i <(int)notation_step_str.size(); i++)
    {
        if (notation_step_str[char_id] == MoveType[i])
        {
            char_id++;
            if (!FindChessCellPosition(notation_step_str[char_id], notation_step_str[char_id + 1])) 
            {
                std::cout << "Error: The cell position is set incorrectly" << std::endl;
                return false;
            }
            if (MoveType[i] == '-' && desk[chess_cell_position.x][chess_cell_position.y] != ' ') 
            {
                std::cout << "Error: The cell is occupied by a figure";
                return false;
            }
            if (MoveType[i] == 'x' && desk[chess_cell_position.x][chess_cell_position.y] == ' ') {
                std::cout
                        << "Error: The cell is empty";
                return false;
            }
            //ставим на клетку фигуру
            desk[chess_cell_position.x][chess_cell_position.y] = figure;
            return true;
        }
    }
    return false;
}

bool Desk::CheckFigure()
{
    int upper_case = 32;
        if ((int)desk[chess_cell_position.x][chess_cell_position.y] == (int)figure || (int)desk[chess_cell_position.x][chess_cell_position.y] == (int)figure + upper_case) 
        {
        figure = desk[chess_cell_position.x][chess_cell_position.y];
        desk[chess_cell_position.x][chess_cell_position.y] = ' ';

        return true;

         } else {
        std::cout << desk[chess_cell_position.x][chess_cell_position.y] << std::endl;
        std::cout << chess_cell_position.x << "  " << chess_cell_position.y << std::endl;
        std::cout << (int)desk[chess_cell_position.x][chess_cell_position.y] << std::endl;
        std::cout << (int)figure << std::endl;
        return false;
    }
}



bool Desk::CheckNotation(std::string filename)
{
    file.open(filename);
    if(!file.is_open())
    {
        cout << "Error: Failed to open the file";
        return -1;
    }

    while(!file.eof())
    {
        file >> notation_step_str;

        if (!FindChessFigureType()) {
            std::cout << "Error: The wrong figure" << std::endl;
            return false;
        }
        if (!FindChessCellPosition(notation_step_str[char_id], notation_step_str[char_id + 1])) {
            std::cout << "Error: Set the incorrect start cell" << std::endl;
            return false;
        }

        if (!CheckFigure()) {
            std::cout << "Error: Wrong figure in the cage" << std::endl;
            return false;
        }
        if (!FindChessMoveType()) {
            std::cout << "Error: The wrong move" << std::endl;
            return false;
        }

        notation_step_str = "";
        char_id = 0;
        figure = ' ';
        move = ' ';

    }

    file.close();
    return true;
}

void Desk::DrawDesk()
{
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
        cout << desk[i][j] << " ";
        }
        cout << "\n";
    }    
}