#include<bits/stdc++.h>
using namespace std;

bool isSafe(int board[4][4],int i,int j,int n)
{
    //you can check col
    for(int row=0;row<n;row++)
    {
        if(board[row][j]==1)
        {
            return false;
        }
    }
    //you can check left diagonal
    int x=i;
    int y=j;
    while (x>=0 && y>=0)
    {
        if(board[x][y]==1)
        {
            return false;
        }
        x--;
        y--;
    }
    //check for right diagonal 
    x=i;
    y=j;
    while (x>=0 && y<n)
    {
        if(board[x][y]==1)
        {
            return false;
        }
        x--;
        y++;
    }


    return true;
    
}
bool solveNQueen(int board[4][4],int i,int n)
{
    //base case
    if(i==n)
    {
        //you have sucessfully placed all queens in the board
        //print the board and return
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==1)
                {
                    cout<<"Q"<<" ";
                }
                else
                {
                    cout<<"_"<<" ";
                }
            }
            cout<<endl;
        }
        return true;
    }
    //recursive case
    //try to place the quenns in the crrent row and call further for other rows
    for(int j=0;j<n;j++)
    {
        //I have to check if the queen is safe to place there or not
        if(isSafe(board,i,j,n))
        {
            //place the queen
            board[i][j]=1;
            //check we can place in next grid
            int nextQueenRakhPaaRaheHai = solveNQueen(board,i+1,n);
            if(nextQueenRakhPaaRaheHai)
            {
                return true;
            }
            //we reach here matlab nai rakh paa rahe hai too backtrack karna hai too remove the queen
            board[i][j]=0;
        }
    }
    //you have tried for all positions and you cannot place queen
    return false;
}
int main()
{
    int n;
    int board[4][4]={0};
    solveNQueen(board,0,4);


    return 0;
}