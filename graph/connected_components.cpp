#include<bits/stdc++.h>
using namespace std;
class Graph {
    map<int,list<int> > l;
    public:
    void addEdge(int x,int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void dfs_helper(int src,map<int,bool> &visited)
    {
        cout<<src<<" ";
        visited[src] = true;
        for(auto nbr:l[src])
        {
            if(!visited[nbr])
            {
                
                dfs_helper(nbr,visited);
            }
        }
    }
    void dfs()
    {
        map<int,bool> visited;
        for(auto x:l)
        {
            visited[x.first]=false;
        }
        // dfs_helper(src,visited);
        int ans=0;
        for(auto p:l)
        {
            int node = p.first;
            if(!visited[node])
            {
                cout<<"components are :";
                ans++;
                dfs_helper(node,visited);
                cout<<endl;
            }
        }
        cout<<ans<<endl;
    }
 };
int main()
{
    Graph g;
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(0,4);
    g.addEdge(1,2);
    g.addEdge(2,3);
    
    g.addEdge(5,6);
    g.addEdge(6,7);
    
    g.addEdge(8,8);
    // g.bfs(0);
    g.dfs();
    return 0;
}