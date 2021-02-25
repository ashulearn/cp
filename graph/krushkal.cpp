#include<bits/stdc++.h>
using namespace std;

//DSU data structrue
// Path Compression + Rank Optimization
class DSU {
    int *parent;
    int *rank;
    public :
    DSU(int n)
    {
        parent = new int[n];
        rank = new int[n];
        for(int i=0;i<n;i++)
        {
            parent[i]=-1;
            rank[i]=1;
        }
    }
    //find function
    int find(int i)
    {
        if(parent[i]==-1)
        {
            return i;
        }
        return parent[i] = find(parent[i]);
    }
    //unite function(union)
    void unite(int x,int y)
    {
        int s1 = find(x);
        int s2 = find(y);
        if(s1!=s2)
        {
            if(s1<s2)
            {
                parent[s1] = s2;
                rank[s2]+=rank[s1];
            }
            else
            {
                parent[s2]=s1;
                rank[s1]+=rank[s2];
            }
        }
    }

    
};
class Graph {
    int V;
    vector<vector<int> > edgeList;//this will store the edges with weight eg: [[w0,x0,y0],[w1,x1,y1],[w2,x2,y2]]
    public:
    Graph(int V)
    {
        this->V = V;

    }
    void addEdge(int x,int y,int w)
    {
        edgeList.push_back({w,x,y});
    }
    int krushkal_mst(){
        //step1 sort
        sort(edgeList.begin(),edgeList.end());

        DSU s(V);
        int ans=0;
        for(auto edge : edgeList)
        {
            int w=edge[0];
            int x=edge[1];
            int y=edge[2];

            //take the edge in mst if it does not form a cycle
            if(s.find(x)!=s.find(y))
            {
                s.unite(x,y);
                ans+=w;
            }
        }

        return ans;
    }
};
int main()
{

    Graph g(4);
    g.addEdge(0,1,1);
    g.addEdge(1,3,3);
    g.addEdge(3,2,4);
    g.addEdge(2,0,2);
    g.addEdge(0,3,2);
    g.addEdge(1,2,2);
    cout<<g.krushkal_mst();
    return 0;
}