#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1000];
ll dp[1000][1000];

ll sum(int i,int j)
{
    ll ans=0;
    for(int s=i;s<=j;s++)
    {
        ans+=a[s];
        ans=ans%100;
    }
    return ans;

}
ll solve(int i,int j)
{
    if(i>=j)
    {
        return 0;
    }
    //lookup
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    dp[i][j]=INT_MAX;
    for(int k=i;k<=j;k++)
    {
        dp[i][j] = min(dp[i][j],solve(i,k)+solve(k+1,j)+(sum(i,k)*sum(k+1,j)));
    }

    return dp[i][j];

}
int main()
{
    int n=3;
    a[0]=40;
    a[1]=60;
    a[2]=20;
    memset(dp,-1,sizeof(dp));
    cout<<solve(0,n-1)<<endl;
}