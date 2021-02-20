#include<bits/stdc++.h>
using namespace std;

int minCoins(int n,int coins[],int T,int dp[])
{
    //base
    if(n==0)
    {
        return 0;
    }
    //rec
    //look up
    if(dp[n]!=0)
    {
        return dp[n];
    }
    int ans =INT_MAX;
    for(int i=0;i<T;i++)
    {
        if(n-coins[i]>=0)
        {
            int subproblem = minCoins(n-coins[i],coins,T,dp);
            ans = min(ans,subproblem+1);

        }
    }
    return dp[n]=ans;

}
//bottom up approach
int minCoinsBU(int n,int coins[],int T)
{
    if(n==0)
    {
        return 0;
    }
    int dp[100]={0};
    for(int i=1;i<=n;i++)
    {
        dp[i]=INT_MAX;
        for(int j=0;j<T;j++)
        {            
            if(i-coins[j]>=0)
            {
                int subproblem = dp[i-coins[j]];
                dp[i] = min(dp[i],subproblem+1);
                
            }
        }
    }
    return dp[n];

}
int main()
{
    int n=15;
    int coins[] = {1,7,10};
    int dp[100] = {0};
    cout<<minCoins(n,coins,3,dp);
    cout<<minCoinsBU(n,coins,3);

    return 0;
}