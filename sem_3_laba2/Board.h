#pragma once
using namespace std;


class Board
{
public:
    Board()
    {
        for (int i=0;i<9;i++)
        {
            board[i] = '*';
        }
    }
    Board(char* board1)
    {
        for (int i=0;i<9;i++)
        {
            board[i]= board1[i];
        }
    }
    char* getBoard()
    {
        return this->board;
    }
    void setBoard(char* board1)
    {
        for (int i=0;i<9;i++)
        {
            board[i]= board1[i];
        }
    }
    int isFull()
    {
        for(int i =0;i<9;i++)
        {
            if(board[i]!='X')
            {
                if(board[i]!='O')
                {
                    return 0;
                }
            }
        }
        return 1;
    };
    void setValue(int id,char value)
    {
        board[id] = value;
    }
    char getValue(int id)
    {
        return board[id];
    }
    int user_won()
    {
        for(int i=0;i<9;i+=3)
        {
            if((board[i]==board[i+1])&&(board[i+1]==board[i+2])&&(board[i]=='O'))
                return 1;
        }
        for(int i=0;i<3;i++)
        {
            if((board[i]==board[i+3])&&(board[i+3]==board[i+6])&&(board[i]=='O'))
                return 1;
        }
        if((board[0]==board[4])&&(board[4]==board[8])&&(board[0]=='O'))
        {
            return 1;
        }
        if((board[2]==board[4])&&(board[4]==board[6])&&(board[2]=='O'))
        {
            return 1;
        }
        return 0;
    };

    int cpu_won()
    {
        for(int i=0;i<9;i+=3)
        {
            if((board[i]==board[i+1])&&(board[i+1]==board[i+2])&&(board[i]=='X'))
                return 1;
        }
        for(int i=0;i<3;i++)
        {
            if((board[i]==board[i+3])&&(board[i+3]==board[i+6])&&(board[i]=='X'))
                return 1;
        }
        if((board[0]==board[4])&&(board[4]==board[8])&&(board[0]=='X'))
        {
            return 1;
        }
        if((board[2]==board[4])&&(board[4]==board[6])&&(board[2]=='X'))
        {
            return 1;
        }
        return 0;
    };

    void draw_board()
    {
        cout<<endl;
        cout<<board[0]<<"|"<<board[1]<<"|"<<board[2]<<endl;
        cout<<"-----"<<endl;
        cout<<board[3]<<"|"<<board[4]<<"|"<<board[5]<<endl;
        cout<<"-----"<<endl;
        cout<<board[6]<<"|"<<board[7]<<"|"<<board[8]<<endl;
    };
    int get_size()
    {   int size = 0;
        for (int i=0;i<9;i++)
        {
            if (board[i] != '*')
            {
                size+=1;
            }
        }
        return size;
    }


private:
    char board[9];
};



