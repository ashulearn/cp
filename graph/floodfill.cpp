#include<bits/stdc++.h>
using namespace std;
int r,c;
int dx[]= {-1,0,1,0};
int dy[]= {0,-1,0,1};
void floodfill(char mat[][50],int i,int j,char ch,char color)
{
    //base condn
    if(i<0 || j<0 || i>=r || j>=c)
    return ;

    if(mat[i][j]!= ch)
    return;
    //boundry condition

    //rec case
    mat[i][j]= color;
    for(int k=0;k<4;k++)
    {
        floodfill(mat,i+dx[k],j+dy[k],ch,color);
    }
    

}
int main()
{
    
    cin>>r>>c;
    char mat[r][c];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>mat[i][j];
        }
    }


    return 0;
}