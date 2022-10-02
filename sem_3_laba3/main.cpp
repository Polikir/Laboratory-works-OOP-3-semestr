#include <iostream>
#include "Graph.h"
#include <vector>
#include "Board.h"
#include "GUI.h"
//#include "Tests.h"
using namespace std;


int main()
{
    Board board,board1;
    board1 = board;
    cout<<(board1==board);

    //Test();
    gui();
    return 0;
}
