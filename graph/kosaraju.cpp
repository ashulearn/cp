#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> graph[],int i,bool *visited,vector<int> &stack)
{
    visited[i] = true;
    for(auto nbr : graph[i])
    {
        if(!visited[nbr])
        {
            dfs(graph,nbr,visited,stack);
        }
    }
    // function call is complete
    stack.push_back(i);
}
void dfs2(vector<int> graph[],int i,bool *visited)
{
    visited[i] = true;
    for(auto nbr : graph[i])
    {
        if(!visited[nbr])
        {
            dfs2(graph,nbr,visited);
        }
    }
        
}
void solve(int N,vector<int> graph[],vector<int> rev_graph[])
{
    bool visited[N];
    memset(visited,0,N);

    vector<int> stack;
    //step 1 store the vetices acc to the finish time
    for(int i=0;i<N;i++)
    {
        if(!visited[i])
        {
            dfs(graph,i,visited,stack);
        }
    }
    //step 2 reverse done
    //step 3
    memset(visited,0,sizeof(visited));
    char component_name = 'A';
    for(int x=stack.size()-1;x>=0;x--)
    {
        int node = stack[x];
        if(!visited[node])
        {
            cout<<"component "<<component_name<<endl;
            dfs2(rev_graph,node,visited);
            component_name++;
        }
    }
}
int main()
{
    int N;
    cin>>N;

    vector<int> graph[N];
    vector<int> rev_graph[N];
    int m;
    cin>>m;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        rev_graph[y].push_back(x);
    }
    solve(N,graph,rev_graph);

    return 0; 
}