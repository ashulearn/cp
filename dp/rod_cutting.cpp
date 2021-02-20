#include<bits/stdc++.h>
using namespace std;

int max_profit_rec(int prices[],int n)
{
    if(n<=0)
    {
        return 0;
    }
    int max_profit = INT_MIN;
    for(int i=0;i<n;i++)
    {
        int cut = i+1;
        int curr_profit = prices[i] + max_profit_rec(prices,n-cut);
        max_profit = max(max_profit,curr_profit);
    }

    return max_profit;
}
int max_profit_dp(int prices[],int n)
{
    int dp[n+1];
    dp[0] = 0;
    for(int len=1;len<=n;len++)
    {
        int ans = INT_MIN;
        for(int i=0;i<len;i++)
        {
            int cut = i+1;
            int curr_ans = prices[i] + dp[len-cut];
            ans = max(ans,curr_ans);

        }
        dp[len] = ans;
    }
    for(int i=0;i<=n;i++)
    {
        cout<<dp[i]<<" ";
    }
    cout<<endl;
    return dp[n];
}
int main()
{
    int prices[] = {1,5,8,9,10,17,17,20};
    int n = sizeof(prices)/sizeof(int);
    cout<<max_profit_dp(prices,n);
    return 0;
}