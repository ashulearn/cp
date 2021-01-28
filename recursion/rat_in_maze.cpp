#include<bits/stdc++.h>
using namespace std;

bool ratInMaze(char maze[10][10],int soln[10][10],int i,int j,int m,int n)
{
    //base case
    if(i==m && j==n)
    {
        soln[i][j]=1;
        //print the path
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                cout<<soln[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }
    //rat should be inside grid
    if(i>m || j>n)
    {
        return false;
    }
    if(maze[i][j]=='X')
    {
        return false;
    }
    soln[i][j]=1;
    //recursive case
    bool rightSucess = ratInMaze(maze,soln,i,j+1,m,n);
    bool downSucess = ratInMaze(maze,soln,i+1,j,m,n);

    //backtracking
    soln[i][j]=0;
    if(rightSucess || downSucess)
    {
        return true;
    }

    return false;


}
int main()
{
    char maze[10][10] = {
        "0000",
        "00X0",
        "000X",
        "0X00",
    };
    int soln[10][10] = {0};
    int m=4,n=4;
    bool ans = ratInMaze(maze,soln,0,0,m-1,n-1);
    if(ans==false)
    {
        cout<<"no path"<<endl;
    }
    
    return 0;
}