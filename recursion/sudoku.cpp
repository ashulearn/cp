#include<bits/stdc++.h>
using namespace std;

bool canPlace(int mat[9][9],int i,int j,int n,int number)
{
    //check in row and col
    for(int x=0;x<n;x++)
    {
        if(mat[i][x]==number || mat[x][j]==number)
        {
            return false;
        }

    }
    //check in subgrid
    int rn = sqrt(n);
        int sx = (i/rn)*rn;
        int sy = (j=rn)*rn;
        for(int x=sx;x<sx+rn;x++)
        {
            for(int y=sy;y<sy+rn;y++)
            {
                if(mat[x][y]==number)
                {
                    return false;
                }
            }
        }

    return true;
}
bool solveSudoku(int mat[9][9],int i,int j,int n)
{
    //base case
    if(i==n)
    {
        //print the matrix
        for(int i=0;i<n;i++)
        {
            for(int j=0;i<n;j++)
            {
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    //case end of row
    if(j==n)
    {
        return solveSudoku(mat,i+1,0,n);
    }
    //skip prefilled cells
    if(mat[i][j] != 0)
    {
        return solveSudoku(mat,i,j+1,n);
    }
    //rec case
    //fill the cell with the available options
    for(int number =1;number <=9;number++)
    {
        if(canPlace(mat,i,j,n,number))
        {
            //assume we can solve
            mat[i][j]=number;
            bool couldWeSolve = solveSudoku(mat,i,j+1,n);
            if(couldWeSolve)
            {
                return true;
            }
            
        }
    }
    //backtrack here
    mat[i][j]=0;
    return false;


}
int main()
{
    int mat[9][9] = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };
    solveSudoku(mat,0,0,9);
    return 0;
}