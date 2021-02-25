#include<bits/stdc++.h>       
using namespace std;

template <typename T>
class Graph {
    unordered_map<T,list<pair<T,int> > > m;
    public:
    void addEdge(T u,T v,int dist,bool bidir=true)
    {
        m[u].push_back(make_pair(v,dist));
        if(bidir)
        {
            m[v].push_back(make_pair(u,dist));
        }

    }
    void printAdj()
    {
        for(auto x:m)
        {
            cout<<x.first<<"==>";
            for(auto l : x.second)
            {
                cout<<"("<<l.first<<","<<l.second<<")";
            }
            cout<<endl;
        }
    }
    void dijikstra(T src)
    {
        unordered_map<T,int> dist;
        //set all the distances to infinity
        for(auto j:m)
        {
            dist[j.first] = INT_MAX;

        }
        //make as set to find the node with minimum distance 
        set<pair<int,T> > s;
        dist[src] = 0;
        s.insert(make_pair(0,src));
        while(!s.empty())
        {
            auto p = *(s.begin());
            T node = p.second;
            int nodeDist = p.first;
            s.erase(s.begin());

            //iterate over the neighbours/children of the current node
            for(auto childPair : m[node])
            {
                if(nodeDist + childPair.second < dist[childPair.first])
                {
                    //we have to update but in set updation is not possible so 
                    //we remmove the old pair and insert new pair
                    T dest = childPair.first;
                    auto f=s.find(make_pair(dist[dest],dest));
                    if(f!=s.end())
                    {
                        s.erase(f);

                    }

                    //insset the new node
                    dist[dest] = nodeDist+childPair.second;
                    s.insert(make_pair(dist[dest],dest));
                }
            }
        }
        for(auto d:dist)
        {
            cout<<d.first<<"is located at "<<d.second<<endl;
        }
    }
};
int main()
{
    Graph<int> g;
    g.addEdge(1,2,1);
    g.addEdge(1,3,4);
    g.addEdge(2,3,1);
    g.addEdge(3,4,2);
    g.addEdge(1,4,7);
    g.dijikstra(1);
    return 0;
}