#include<bits/stdc++.h>
using namespace std;

int n=4;
//graph which is given
int dist[10][10] = {
    {0,20,42,25},
    {20,0,30,35},
    {42,30,0,10},
    {25,34,10,0},
};
//mask
int VISITED_ALL = (1<<n) -1;
int dp[100][100];
int tsp(int mask,int pos)
{
    //if all cities are visited
    if(mask == VISITED_ALL)
    {
        return dist[pos][0];
    }
    //lookup
    if(dp[mask][pos]!=-1)
    {
        return dp[mask][pos];
    }
    //try to go to non visited cities

    int ans = INT_MAX;
    for(int city=0;city<n;city++)
    {
        //check if current city is not visited the visited it by recursion
        if((mask&(1<<city))==0)
        {
            int newAns = dist[pos][city] + tsp(mask|(1<<city),city);
            ans = min(ans,newAns);
        }
    }

    return dp[mask][pos] = ans;
}
int main()
{
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            dp[i][j]=-1;
        }
    }
    cout<<tsp(1,0)<<endl;
    return 0;
}