#include<iostream>
using namespace std;
//top down
int fib(int n,int dp[])
{
    if(n==0 || n==1)
    {
        return dp[n] = n;
    }
    if(dp[n]!=0)
    {
        return dp[n];
    }
    int ans = fib(n-1,dp)+fib(n-2,dp);
    return dp[n] = ans;
}
int fibBU(int n)
{
    int dp[100] = {0};
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
    
}
//space optimization
int fibOp(int n)
{
    if(n==0 || n==1)
    {
        return n;
    }
    int a=0;
    int b=1;
    int c;
    for(int i=2;i<=n;i++)
    {
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}
int main()
{
    int n=5;
    int dp[100]={0};
    cout<<fib(5,dp)<<endl;
    cout<<fibBU(10);

    return 0;
}