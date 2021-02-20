#include<bits/stdc++.h>
using namespace std;
long long solveProblem(int n,int x,int y,int z)
{
    long long dp[n+1];
    memset(dp,0,sizeof(dp));
    dp[0]=0;
    dp[1]=0;
    for(int i=2;i<=n;i++)
    {
        if(i%2==0)
        {
            dp[i]=min(dp[i/2]+x,dp[i-1]+y);
        }
        else
        {
            dp[i]=min(dp[i-1]+y,dp[i/2]+x+z);
        }
    }

    return dp[n];
}
int main()
{
    int n,x,y,z;
    // cin>>n>>x>>y>>z;
    n=5;
    x=2;
    y=1;
    z=3;
    cout<<solveProblem(n,x,y,z);
    return 0;
}