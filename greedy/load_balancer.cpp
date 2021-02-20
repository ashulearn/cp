#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[9000];
    int n,i,val,diff;
    while(1)
    {
        int max_load = 0,load = 0;
        cin>>n;
        if(n==-1)
        {
            break;
        }
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        //find the load that is to be divided
        for(i=0;i<n;i++)
        {
            load += a[i];
        }
        if(load%n != 0)
        {
            cout<<-1<<endl;
            continue;
        }
        load = load/n;
        //greedy step
        diff= 0;
        for(i=0;i<n;i++)
        {
            diff += (a[i]-load);
            int ans = max(diff,-diff);
            max_load = max(ans,max_load);
        }
        cout<<max_load<<endl;
    }

    return 0;
}