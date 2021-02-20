#include<bits/stdc++.h>
using namespace std;

int minSteps(int n,int dp[])
{
    //base 
    if(n==1)
    {
        return 0;
    }

    //rec
    //look up in the dp array
    if(dp[n]!=0)
    {
        return dp[n];
    }
    int op1,op2,op3;
    op1 = op2 = op3 =INT_MAX;
    if(n%2==0)
    {
        op2=minSteps(n/2,dp);
    }
    if(n%3 == 0)
    {
        op1 = minSteps(n/3,dp);
    }
    op3 = minSteps(n-1,dp);
    int ans = min(min(op1,op2),op3)+1;
    return  dp[n] =ans;

}
int minStepsBU(int n)
{
    if(n==1)
    {
        return 0;
    }
    int dp[100]={0};
    dp[1]=0;
    for(int i=2;i<=n;i++)
    {
        int op1,op2,op3;
        op1 = op2 = op3 =INT_MAX;
        if(i%3 == 0)
        {
            op1 = dp[n/3];
        }
        if(i%2 ==0)
        {
            op2 = dp[i/2];
        }
        op3 = dp[i-1];
        dp[i] = min(min(op1,op2),op3)+1;

    }

    return dp[n];
}
int main()
{
    int n=10;
    int dp[100]={0};
    cout<<minSteps(n,dp)<<endl;
    cout<<minStepsBU(n);
    return 0;
}