
#include <iostream>
#include <string>

#include "chessdesk.h"

int main()
{
    int x;
    Desk go;

    if (go.CheckNotation("chessnotation.txt")) {
        std::cout << "Status: Good" << std::endl;
        go.DrawDesk();
    } else {
        std::cout << "Status: Bad" << std::endl;
        std::cout << "Filed the wrong notation: ";
        std::cin >> x;
        return -1;
    }

    std::cin >> x;

    system("PAUSE");
    return 0;
}
