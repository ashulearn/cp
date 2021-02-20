#include<bits/stdc++.h>
using namespace std;
int solve(int n,int dp[])
{
    if(n<=1)
    {
        return 1;
    }
    //lookup
    if(dp[n]!=0)
    {
        return dp[n];
    }
    //rec
    return dp[n] = (solve(n-1,dp) + (n-1)*solve(n-2,dp));
}
int main()
{
    int n=5;
    int dp[100]={0};
    cout<<solve(n,dp)<<endl;


    return 0;
}