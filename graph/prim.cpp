#include<bits/stdc++.h>
using namespace std;

class Graph {
   int V;
   vector<pair<int,int> > *l;
   public:
   Graph(int n) {
       V=n;
       l = new vector<pair<int,int> >[V];
   }
   void addEdge(int x,int y,int w)
   {
       l[x].push_back({y,w});
       l[y].push_back({x,w});
   }
   int prim_mst() 
   {

       priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > > Q;
       //visited array to store wheather a node is included in MST or not
       bool *visited = new int[V]{0};

       int ans=0;
       //begin
       Q.push({0,0});  //weight,node

       while(!Q.empty())
       {
           auto best = Q.top();
           Q.pop();
           int to = best.first;
           int wt= best.second;
           if(visited[to])
           {
               //discred the edge as alredy visited
               continue;
           }
           //otherwise take that node
           ans += wt;
           visited[to] = 1;
           //add the new edges in the queue
           for(auto x:l[to])
           {
               if(visited[x.first]==0)
               {
                   Q.push({x.second,x.first});
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