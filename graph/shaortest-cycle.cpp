#include<bits/stdc++.h>
using namespace std;

const int N = 100005,M=32;
vector<int> graph[N];
void dfs(int src,int n,int &ans)
{
    vector<int> dist(n+1,INT_MAX);
    queue<int> q;
    q.push(src);
    dist[src]=0;
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        for(auto nbr : graph[curr])
        {
            if(dist[nbr] == INT_MAX)
            {
                //not visited till now
                dist[nbr] = dist[curr]+1;
                q.push(nbr);
            }
            else if(dist[nbr]>=dist[curr])
            {
                ans = min(ans,dist[nbr]+dist[curr]+1);
            }
        }
    }
}
int main()
{
    int i,j,n,m,ans=0;
    n=5;m=6;
    graph[1].push_back(2);graph[2].push_back(1);
    graph[1].push_back(3);graph[3].push_back(1);
    graph[2].push_back(4);graph[4].push_back(2);
    graph[2].push_back(5);graph[5].push_back(2);
    graph[4].push_back(5);graph[5].push_back(4);
    graph[5].push_back(3);graph[3].push_back(5);

    ans = n+1;
    for(i=1;i<=n;i++)
    {
        dfs(i,n,ans);
        cout<<ans<<endl;
    }
    if(ans==n+1)
    {
        cout<<"NO";
    }
    else
    {
        cout<<"Yes  "<<ans;
    }
    return 0;
}