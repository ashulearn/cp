#include<bits/stdc++.h>
using namespace std;

bool cowsPlaced(int stall[],int n,int cows,int min_sep)
{
    int last_cow = stall[0];
    int cnt=1;
    for(int i=1;i<n;i++)
    {
        if(stall[i]-last_cow >= min_sep)
        {
            last_cow=stall[i];
            cnt++;
        }
        if(cnt==cows)
        {
            return true;
        }
    }

    return false;
}
int main()
{
    int stall[5] = {1,2,4,8,9};
    int n=5;
    int cows =3;
    int s=0;
    int e= stall[n-1]-stall[0];
    int mid;
    int ans=0;
    while(s<=e)
    {
        mid=(s+e)/2;
        bool cowsRakhPaye = cowsPlaced(stall,n,cows,mid);
        if(cowsRakhPaye)
        {
            ans=mid;
            s=mid+1;
        }
        else 
        {
            e=mid-1;
        }

    } 
    cout<<ans<<endl;    
    return 0;
}