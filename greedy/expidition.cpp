#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,int> p1,pair<int,int> p2)
{
    return p1.first > p2.first;
}
int main()
{
    int n,t,x,d,f,D,F,prev=0;
    cin>>t;
    while(t--)
    {
        int flag=0,ans=0;
        vector<pair<int,int> > v;
        priority_queue<int> pq;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>d>>f;
            v.push_back(make_pair(d,f));
        }
        sort(v.begin(),v.end(),comp);
        cin>>D>>F;
        for(int i=0;i<n;i++)
        {
            v[i].first = D - v[i].first;
        }
        //prev denotes the last city visited
        prev=0;
        x=0; //current city
        while(x<n)
        {
            //if we have enough fuel to visit next city
            if(F >= (v[x].first - prev))
            {
                F = F - (v[x].first - prev);
                pq.push(v[x].second);
                prev = v[x].first;
            }
            else
            {
                //if we are not able to reach next station chaeck for the fuel stations visited in path
                if(pq.empty())
                {
                    flag= 1;
                    break;
                }
                
                    //refuel with a fuel station with higher fuel
                    F+= pq.top();
                    pq.pop();
                    ans++;
                    continue;
            }
                x++;

            }
        
            //all fuel station traveled
            //now reach town from last fuel station

            if(flag ==1)
            {
                cout<<"-1"<<endl;
                continue;
            }
            //we have answer
            D= D-v[n-1].first;
                if(F>=D)
                {
                    cout<<ans<<endl;
                    continue;
                }
            while (F<D)
            {
                if(pq.empty())
                {
                    flag=1;
                    break;
                }
                F += pq.top();
                pq.pop();
                ans++;

            }
            if(flag==1)
        {
            cout<<-1<<endl;
            continue;
        }
        cout<<ans<<endl;
            
        }
        
        

    
    return 0;
}