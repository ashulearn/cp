#include<bits/stdc++.h>
using namespace std;

class Graph {
    unordered_map<string,list<pair<string,int> > > l;
    public:
    void addEdge(string x,string y,bool isBi,int wt)
    {
        l[x].push_back(make_pair(y,wt));
        if(isBi)
        {
            l[y].push_back(make_pair(x,wt));
        }

    }
    void print()
    {
        for(auto x : l)
        {
            cout<<x.first<<"->";
            for(auto y : x.second)
            {
                cout<<y.first<<" "<<y.second<<", ";
            }
            cout<<endl;
        }
    }
};
int main()
{
    Graph g;
    g.addEdge("A","B",true,20);
    g.addEdge("A","C",true,10);
    g.addEdge("A","D",false,50);
    g.addEdge("B","D",true,30);
    g.addEdge("C","D",true,40);
    g.print();
    return 0;
}