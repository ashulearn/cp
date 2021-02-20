#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,int> p1,pair<int,int> p2)
{
    return p1.second<p2.second;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,s,e;
        vector<pair<int,int> > v;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>s>>e;
            v.push_back(make_pair(s,e));
        }
        sort(v.begin(),v.end(),comp);
        // for(int i=0;i<n;i++)
        // {
        //     cout<<v[i].first<<" "<<v[i].second<<endl;
        // }
        int fin=v[0].second;
        int res=1;
        for(int i=1;i<n;i++)
        {
            if(v[i].first >= fin)
            {
                fin = v[i].second;
                res++;
            }
        }
        cout<<res<<endl;
        v.clear();

    }
    return 0;
}