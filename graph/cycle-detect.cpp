#include<bits/stdc++.h>
using namespace std;
class Graph {
    int V;
    list<int> *l;
    public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }
    void addEdge(int x,int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    bool cycle_helper(int src,bool visited[],int par)
    {
        visited[src] = true;
        for(auto nbr : l[src])
        {
            if(!visited[nbr])
            {
                bool cycle_mila = cycle_helper(nbr,visited,src);
                if(cycle_mila)
                {
                    return true;
                }
            }
            else if(nbr!=par)
            {
                return true;
            }
        }

        return false;
    }
    bool contains_cycle()
    {
        bool *visited = new bool[V];
        for(int i=0;i<V;i++)
        {
            visited[i]=false;
        }
        return cycle_helper(0,visited,-1);
    }
};
int main()
{
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    // g.addEdge(4,0);
    cout<<g.contains_cycle();
    return 0;
}