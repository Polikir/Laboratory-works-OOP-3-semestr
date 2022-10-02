//#include<iostream>
//using namespace std;
//int index1;
//#include "Board.h"
//#include "Graph.h"
//


//int minimax(bool flag,Graph<Board,int>* graph,Board board)
//{
//    Graph<Board,int>* child_tree = new Graph<Board,int>();
//    Board perboard = board;
//    board = tree->getValue();
//    int max_val= -1000,min_val=1000;
//    int i,j,value = 1;
//    if(board.cpu_won() == 1)
//    {return 10;}
//    else if(board.user_won() == 1)
//    {return -10;}
//    else if(board.isFull()== 1)
//    {return 0;}
//    int score[9] = {1,1,1,1,1,1,1,1,1};
//
//
//
//    for(i=0;i<9;i++)
//    {
//        if(board.getValue(i) == '*')
//        {
//            if(min_val>max_val)
//            {
//                if(flag)
//                {
//                    board.setValue(i,'X');
//                    child_tree->setValue(board);
//                    tree->addChild(child_tree);
//                    value = minimax(false,child_tree);
//                    child_tree = new  Tree<Board>();
//
//                }
//                else
//                {
//                    board.setValue(i,'O');
//                    child_tree->setValue(board);
//                    tree->addChild(child_tree);
//                    value = minimax(true,child_tree);
//                    child_tree = new  Tree<Board>();
//
//                }
//                board.setValue(i,'*');
//                tree->setValue(board);
//                score[i] = value;
//            }
//        }
//    }
//
//    if(flag)
//    {
//        max_val = -1000;
//        for(j=0;j<9;j++)
//        {
//            if(score[j] > max_val && score[j] != 1)
//            {
//                max_val = score[j];
//                index1 = j;
//            }
//        }
//
//        return max_val;
//    }
//    else if(flag == false)
//    {
//        min_val = 1000;
//        for(j=0;j<9;j++)
//        {
//            if(score[j] < min_val && score[j] != 1)
//            {
//                min_val = score[j];
//                index1 = j;
//            }
//        }
//
//        return min_val;
//    }
//}
//














#include<iostream>
using namespace std;
int index1;
#include "Board.h"
#include "Graph.h"



int minimax(bool flag,Graph<Board,int>* graph,Board par_board)
{
    Board child_board;
    Board board;
    board = par_board;
    int max_val= -1000,min_val=1000;
    int i,j,value = 1;
    if(board.cpu_won() == 1)
    {return 10;}
    else if(board.user_won() == 1)
    {return -10;}
    else if(board.isFull()== 1)
    {return 0;}
    int score[9] = {1,1,1,1,1,1,1,1,1};



    for(i=0;i<9;i++)
    {
        if(board.getValue(i) == '*')
        {
            if(min_val>max_val)
            {
                if(flag)
                {
                    board.setValue(i,'X');
                    child_board = board;
                    //graph->addVertex(child_board);
                    value = minimax(false,graph,child_board);
                    child_board = Board();

                }
                else
                {
                    board.setValue(i,'O');
                    child_board = board;
                    //graph->addVertex(child_board);
                    value = minimax(true,graph,child_board);
                    child_board = Board();

                }
                board.setValue(i,'*');
                //tree->setValue(board);
                score[i] = value;
            }
        }
    }

    if(flag)
    {
        max_val = -1000;
        for(j=0;j<9;j++)
        {
            if(score[j] > max_val && score[j] != 1)
            {
                max_val = score[j];
                index1 = j;
            }
        }

        return max_val;
    }
    else if(flag == false)
    {
        min_val = 1000;
        for(j=0;j<9;j++)
        {
            if(score[j] < min_val && score[j] != 1)
            {
                min_val = score[j];
                index1 = j;
            }
        }

        return min_val;
    }
}

int comove(Board *board)
{   Graph<Board,int>* graph;
    graph = new Graph<Board,int>();
    graph->addVertex(*board);
    minimax(true,graph,*board);

    board->setValue(index1, 'X');
    if(board->cpu_won()==1)
    {
        return 10+index1;
    }
    if(board->isFull()==1)
    {
        return 10+index1;
    }
    return 0+index1;
}


