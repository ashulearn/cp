#include<bits/stdc++.h>
using namespace std;

class Graph {
    unordered_map<int,list<int> > l;
    public:
    void addEdge(int x,int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void bfs(int src)
    {
        queue<int> q;
        q.push(src);
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
        }
    }
};
int main()
{


    return 0;
}