#include<bits/stdc++.h>

using namespace std;

int knapsack(int N,int c,int *wt,int *prices)
{
    if(N==0 || c==0)
    {
        return 0;
    }
    int ans=0;
    int inc,exc;
    inc=exc=0;
    if(wt[N-1]<=c)
    {
        // cout<<"a";
        inc =prices[N-1] + knapsack(N-1,c-wt[N-1],wt,prices);
    }
    exc = knapsack(N-1,c,wt,prices);
    ans = max(inc,exc);
    return ans;

}
int main()
{
    int weights[] = {1,2,3,5};
    int prices[] = {40,20,30,100};
    cout<<knapsack(4,7,weights,prices);

    return 0;
}