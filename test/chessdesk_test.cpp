#include "../src/chessdesk.h"
#include "thirdparty/catch.hpp"

using namespace std;

TEST_CASE("FindChessFigureType()", "[]")
{
    Desk desk;
    SECTION("Figures true")
    {
        desk.notation_step_str = "QRNBK";
        for (int i = 0; i < (int)desk.notation_step_str.size();
             i++) { // верно принимает значения/true
            CHECK(desk.FindChessFigureType());
        }
    }
    SECTION("Pawn true")
    {
        desk.notation_step_str = "abcdefgh";
        for (int i = 0; i < (int)desk.notation_step_str.size();
             i++) { // верно принимает значения и выводит true для пешки
            desk.char_id = i;
            CHECK(desk.FindChessFigureType());
        }
    }

    /*SECTION("Incorrect value in string")
    { // не примет неверные значения
        desk.notation_step_str = "w-1g22-2y";
        for (int i = 0; i < (int)desk.notation_step_str.size(); i++) {
            desk.char_id = i;
            CHECK(desk.FindChessFigureType() == false);
        }
    }*/
}

TEST_CASE("MAP : CheckColor()", "[MAP]")
{
    Desk desk;
    SECTION("Moving a figure")
    { // берём правильную фигуру
        desk.chess_cell_position.x = 1;
        desk.chess_cell_position.y = 1;
        desk.figure = 'R';
        char now_fig = desk.desk[desk.chess_cell_position.x]
                                [desk.chess_cell_position.y];
        REQUIRE(desk.CheckColor());
        CHECK(desk.desk[desk.chess_cell_position.x][desk.chess_cell_position.y]
              == ' ');
        CHECK(now_fig == desk.figure);
    }
    SECTION("Wrong moving a figure")
    { // пробуем взять неверную фигуру
        desk.chess_cell_position.x = 2;
        desk.chess_cell_position.y = 1;
        desk.figure = 'K';
        CHECK(!desk.CheckColor());
    }
}

TEST_CASE("MAP : FindChessMoveType()", "[MAP]")
{
    Desk desk;
    SECTION("Capturing an enemy figure") //взятие вражеской фигуру
    {
        desk.char_id = 0;
        desk.figure = 'p';
        desk.notation_step_str = "xh1";
        REQUIRE(desk.FindChessMoveType());
        CHECK(desk.desk[desk.chess_cell_position.x][desk.chess_cell_position.y]
              == 'p');
    }
    SECTION("Move to an empty cell") // перемещение в пустую клетку
    {
        desk.char_id = 0;
        desk.figure = 'p';
        desk.notation_step_str = "-e5";
        REQUIRE(desk.FindChessMoveType());
        CHECK(desk.desk[desk.chess_cell_position.x][desk.chess_cell_position.y]
              == 'p');
    }
    SECTION("Wrong capturing an enemy figure") // пытаемся неправильно забрать
                                               // вражескую фигуру
    {
        desk.char_id = 0;
        desk.figure = 'p';
        desk.notation_step_str = "-h2";
        REQUIRE(!desk.FindChessMoveType());
    }
    SECTION("Wrong move to an empty cell") // пробуем переместится не на пустую
                                           // клетку
    {
        desk.char_id = 0;
        desk.figure = 'p';
        desk.notation_step_str = "xa5";
        REQUIRE(!desk.FindChessMoveType());
    }
}