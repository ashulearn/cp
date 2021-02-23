#include<bits/stdc++.h>
using namespace std;
template <typename T>
class Graph {
    map<T,list<T> > l;
    public:
    void addEdge(T x,T y)
    {
        l[x].push_back(y);
    }
    void dfs_helper(T src,map<T,bool> &visited,list<T> &ordering)
    {
        visited[src] = true;
        for(auto nbr : l[src])
        {
            if(!visited[nbr])
            {
                dfs_helper(nbr,visited,ordering);
            }
            
        }

        ordering.push_front(src);
    }
    void dfs()
    {
        map<T,bool> visited;
        list<T> ordering;
        for(auto p : l)
        {
            T node = p.first;
            visited[node]=false;
        }
        for(auto p : l)
        {
            T node = p.first;
            if(!visited[node])
            dfs_helper(node,visited,ordering);
        }
        for(auto node:ordering)
        {
            cout<<node<<endl;
        }
    }
};
int main()
{
    Graph<string> g;
    g.addEdge("Python","Data Preprocessing");
    g.addEdge("Python","Pytorch");
    g.addEdge("Python","ML basics");
    g.addEdge("Pytorch","DL");
    g.addEdge("ML basics","DL");
    g.addEdge("Data Preprocessing","ML basics");
    g.addEdge("DL","FACE");
    g.addEdge("Dataset","FACE");
    g.dfs();



    return 0;
}