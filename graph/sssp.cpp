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
    void bfs(int src)
    {
        map<int,int> dist;
        queue<int> q;
        
        for(auto p : l)
        {
            int node = p.first;
            dist[node] = INT_MAX;
        }
        q.push(src);
        dist[src]=0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cout<<node<<" ";
            for(auto nbr : l[node])
            {
                if(dist[nbr] == INT_MAX)
                {
                    q.push(nbr);
                    dist[nbr] = dist[node]+1;
                }


            }
        }
        
    }
 };
int main()
{
    Graph g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.bfs(0);
    return 0;
}