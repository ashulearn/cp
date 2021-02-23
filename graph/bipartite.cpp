#include<bits/stdc++.h>
using namespace std;

bool dfs_helper(vector<int> graph[],int src,int visited[],int parent,int color)
{
    visited[src]=color;
    for(auto nbr : graph[src])
    {
        if(visited[nbr]==0)
        {
            int subprob = dfs_helper(graph,nbr,visited,src,3-color);
            if(subprob==false)
            {
                return false;
            }
        }
        else if(nbr!=parent and color==visited[nbr])
        {
            return false;
        }
    }
    return true;
}
bool checkBipartite(vector<int> graph[],int N)
{
    //maintain a visited array which can have 3 value 0-not visited 1-color1 2-color2
    int visited[N] = {0};
    int color = 1;
    int ans = dfs_helper(graph,0,visited,-1,color);
    return ans;
}
int main()
{
    int N,M;
    cin>>N>>M;
    vector<int> graph[N];
    while(M--)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);

    }
    // bfs or dfs we will use and color (if parent has color 1 then br must have color 2)
    cout<<checkBipartite(graph,N);

    return 0;
}