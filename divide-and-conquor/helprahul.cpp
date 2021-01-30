#include<bits/stdc++.h>
using namespace std;

int find(int a[],int n,int key)
{
    int s=0;
    int e=n-1;
    int mid=(s+e)/2;
    while(s<=e)
    {
        mid=(s+e)/2;
        if(a[mid]==key)
        {
            return mid;
        }
        else if(a[s]<a[mid])
        {
            if(key>=a[s] && key<=a[mid])
            {
                e=mid-1;
            }
            else 
            {
                s=mid+1;
            }
        }
        else
        {
            if(key <= a[e] && key >= a[mid])
            {
                s=mid+1;
            }
            else 
            {
                e=mid-1;
            }
        }
    }
    return -1;
}
int main()
{
    int a[10] = {4,6,8,10,12,15,18,1,2,3};
    cout<<find(a,10,6);
    return 0;
}