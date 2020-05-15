#include "chessdesk.h"

using namespace std;
bool Desk::FindChessFigurePosition(char x, char y)
{
    chess_cell_position.status = false;
    for (int i = 1; i < 9; i++) {
        if (desk[0][i] == x) {
            chess_cell_position.y = i;
            chess_cell_position.status = true;
            char_id++;
            break;
        }
    }
    for (int j = 1; j < 9; j++) {
        if (desk[j][0] == y) {
            chess_cell_position.x = j;
            chess_cell_position.status = true;
            char_id++;
            break;
        }
    }

    return chess_cell_position.status;
}
bool Desk::FindChessFigureType()
{
    std::string typefig = "QRNBK";
    for (int i = 0; i < (int)typefig.size(); i++) {
        if (notation_step_str[char_id] == typefig[i]) {
            char_id++;
            figure = typefig[i];
            return true;
        }
    }
    if ((int)notation_step_str[char_id] >= 97
        && (int)notation_step_str[char_id] <= 104) {
        figure = 'P';
        return true;
    }

    return false;
}
bool Desk::FindChessMoveType()
{
    std::string typemove = "-x";
    for (int i = 0; i < (int)typemove.size(); i++) {
        if (notation_step_str[char_id] == typemove[i]) {
            char_id++;
            if (!FindChessFigurePosition(
                        notation_step_str[char_id],
                        notation_step_str[char_id + 1])) {
                std::cout << "error: cell aim wrong" << std::endl;
                return false;
            }
            if (typemove[i] == '-'
                && desk[chess_cell_position.x][chess_cell_position.y] != ' ') {
                std::cout << "error: cell have figure, need void cell"
                          << std::endl;
                return false;
            }
            if (typemove[i] == 'x'
                && desk[chess_cell_position.x][chess_cell_position.y] == ' ') {
                std::cout << "error: cell dont have figure, need figure in cell"
                          << std::endl;
                return false;
            }
            desk[chess_cell_position.x][chess_cell_position.y] = figure;
            return true;
        }
    }
    return false;
}
bool Desk::CheckColor()
{
    int up_reg = 32;
    if ((int)desk[chess_cell_position.x][chess_cell_position.y] == (int)figure
        || (int)desk[chess_cell_position.x][chess_cell_position.y]
                == (int)figure + up_reg) {
        figure = desk[chess_cell_position.x][chess_cell_position.y];
        desk[chess_cell_position.x][chess_cell_position.y] = ' ';

        return true;
    } else {
        return false;
    }
}

bool Desk::DrawChessDesk()
{
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            std::cout << desk[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "\n\n"
              << " ------------------" << std::endl;
    return true;
}

bool Desk::CheckNotation(std::string filename)
{
    std::fstream fh;
    fstream file;
    file.open(filename, file.in);
    if (!file.is_open()) {
        cout << "Error: Chess notation file not found" << endl;
        return -1;
    }
    while (!file.eof()) {
        file >> notation_step_str;
        if (!FindChessFigureType()) {
            std::cout << "Error: Invalid figure specified" << std::endl;
            return false;
        }
        if (!FindChessFigurePosition(
                    notation_step_str[char_id],
                    notation_step_str[char_id + 1])) {
            std::cout << "Error: The figure position is set incorrectly"
                      << std::endl;
            return false;
        }

        if (!CheckColor()) {
            std::cout << "Error: Wrong color figure in cell" << std::endl;
            return false;
        }
        if (!FindChessMoveType()) {
            std::cout << "Error: The wrong move" << std::endl;
            return false;
        }
        std::cout << std::endl;

        if (!DrawChessDesk()) {
            std::cout << "Error: Failed to display chessboard" << std::endl;
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
