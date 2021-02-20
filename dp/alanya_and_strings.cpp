#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[1005][1005][12][2];
string s,t;
ll n,m,k;
ll solve(ll is,ll it,ll rem,ll cont)
{
    if(is==n or it==m)
    {
        return (rem==0)?0:INT_MIN;
    }
    if(rem==0)
    {
        return 0;
    }
    if(dp[is][it][rem][cont]!=-1)
    {
        return dp[is][it][rem][cont];
    }
    ll ret = INT_MIN;
    if(cont==1)
    {
        ret = max(ret,solve(is+1,it,rem-1,0));
        ret = max(ret,solve(is,it+1,rem-1,0));
        if(s[is]==t[it])
        {
            ret = max(ret,1+solve(is+1,it+1,rem,1));
            ret = max(ret,1+solve(is+1,it+1,rem-1,1));
        }
    }
    else
    {
        ret = max(ret,solve(is+1,it,rem,0));
        ret = max(ret,solve(is,it+1,rem,0));
        if(s[is]==t[it])
        {
            ret = max(ret,1+solve(is+1,it+1,rem,1));
            ret = max(ret,1+solve(is+1,it+1,rem-1,1));
        }
    }

    return dp[is][it][rem][cont] = ret;

}
int main()
{
    cin>>n>>m>>k;
    cin>>s>>t;
    memset(dp,-1,sizeof(dp));
    cout<<solve(0,0,k,0);


    return 0;
}