#include<iostream>
using namespace std;
int index1;
#include "Board.h"
#include "Tree.h"



int minimax(bool flag,Tree<Board>* tree)
{
    Tree<Board>* child_tree = new Tree<Board>();
    Board board;
    board = tree->getValue();
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
                    child_tree->setValue(board);
                    tree->addChild(child_tree);
                    value = minimax(false,child_tree);
                    child_tree = new  Tree<Board>();

                }
                else
                {
                    board.setValue(i,'O');
                    child_tree->setValue(board);
                    tree->addChild(child_tree);
                    value = minimax(true,child_tree);
                    child_tree = new  Tree<Board>();

                }
                board.setValue(i,'*');
                tree->setValue(board);
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
{   Tree<Board>* tree;
    tree = new Tree<Board>();
    tree->setValue(*board);
    minimax(true,tree);

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


