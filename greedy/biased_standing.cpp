#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s>>a[i];
        }
        sort(a,a+n);
        // for(int i=0;i<n;i++)
        // {
        //     cout<<a[i]<<" ";
        // }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=abs((i+1) - a[i]);
        }
        cout<<ans<<endl;
    }

    return 0;
}