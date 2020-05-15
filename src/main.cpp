#include <cstdlib>
#include <iostream>
#include <string>

#include "chessdesk.h"

int main()
{
    Desk desk;
    if (desk.CheckNotation("chessnotation.txt")) {
    } else {
        std::cout << "Error:" << desk.notation_step_str << std::endl;
        return -1;
    }
    return 0;
}