#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *l;
    public:
    Graph(int V)
    {
        this->V =V;
        l = new list<int>[V];
    }  
    void addEdge(int x,int y)
    {
        l[x].push_back(y);
    }
    bool cycle_helper(int node, bool *visited,bool *stack)
    {
        //visit that node
        visited[node] = true;
        stack[node] = true;

        for(int nbr : l[node])
        {
            if(stack[nbr])
            {
                return true;
            }
            else if(visited[nbr]!=true)
            {
                bool cycle_mila = cycle_helper(nbr,visited,stack);
                if(cycle_mila==true)
                {
                    return true;
                }
            }
        }

        //leaving from the node
        stack[node] = false;

        return false;
    }
    bool contains_cycle()
    {
        bool *visited = new bool[V];
        bool *stack = new bool[V];
        for(int i=0;i<V;i++)
        {
            visited[i]=stack[i]=false;
        }
        return cycle_helper(0,visited,stack);
    }
};

int main()
{
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,2);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.addEdge(1,5);
    cout<<g.contains_cycle();
    return 0;
}