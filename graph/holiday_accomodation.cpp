#include<bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    list<pair<int,int> > *l;
    public:
    Graph(int V)
    {
        this->V=V;
        l = new list<pair<int,int> >[V];
    }
    void addEdge(int u,int v,int src)
    {
        l[u].push_back({v,src});
        l[v].push_back({u,src});
    }
    int dfs_helper(int src,bool visited[],int count[],int &ans)
    {
        visited[src] = true;
        count[src] = 1;
        for(auto nbr_pair : l[src])
        {
            int nbr = nbr_pair.first;
            int wt=nbr_pair.second;
            if(!visited[nbr])
            {
                count[src]+=dfs_helper(nbr,visited,count,ans);
                int nx = count[nbr];
                int ny = V-nx;
                ans += 2*min(nx,ny)*wt;
                
            }
        }
        return count[src];
    }
    int dfs()
    {
        bool *visited = new bool[V];
        int *count = new int[V];
        for(int i=0;i<V;i++)
        {
            visited[i]=false;
            count[i]=0;
        }
        int ans=0;
        dfs_helper(0,visited,count,ans);

        return ans;
    }

};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Graph g(n);
        for(int i=0;i<n;i++)
        {
            int u,v,cost;
            cin>>u>>v>>cost;
            g.addEdge(u,v,cost);
        }
        g.dfs();
    }
    // Graph g(4);
    // g.addEdge(0,1,3);
    // g.addEdge(1,2,2);
    // g.addEdge(2,3,2);
    // cout<<g.dfs();

    return 0;
}