#include<bits/stdc++.h>
using namespace std;

int lower_bound(int a[],int s,int e,int key)
{
    int mid;
    int ans=-1;
    while(s<=e)
    {
        mid=(s+e)/2;
        if(a[mid]==key)
        {
            ans=mid;
            e=mid-1;
        }
        else if(a[mid]>key)
        {
            e=mid-1;
        }
        else if(a[mid]<key)
        {
            s=mid+1;
        }

    }
    return ans;
}

int upper_bound(int a[],int s,int e,int key)
{
    int mid;
    int ans=-1;
    while(s<=e)
    {
        mid=(s+e)/2;
        if(a[mid]==key)
        {
            ans=mid;
            s=mid+1;
        }
        else if(a[mid]>key)
        {
            e=mid-1;
        }
        else if(a[mid]<key)
        {
            s=mid+1;
        }

    }
    return ans;
}
int main()
{
    int a[10]= {1,3,4,8,8,8,8,9,11,22};
    int l = lower_bound(a,0,9,8);
    int u = upper_bound(a,0,9,8);
    cout<<l<<" "<<u<<endl;
    cout<<u-l+1<<endl;
    return 0;
}