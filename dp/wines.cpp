#include<bits/stdc++.h>
using namespace std;

int wines_prof(int wines[],int i,int j,int y,int dp[][100])
{
    if(i>j)
    {
        return 0;
    }
    if(dp[i][j]!= 0)
    {
        return dp[i][j];
    }
    int op1 = wines[i]*y + wines_prof(wines,i+1,j,y+1,dp);
    int op2 = wines[j]*y + wines_prof(wines,i,j-1,y+1,dp);
    
    return dp[i][j] = max(op1,op2);
}
int main()
{
    int wines[] ={2,3,5,1,4};
    int n=5;
    int y=1;
    int dp[100][100]={0};
    cout<<wines_prof(wines,0,n-1,y,dp);
    return 0;
}