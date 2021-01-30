#include<bits/stdc++.h>
using namespace std;

int binary_search(int a[],int s,int e,int key)
{
    int mid =(s+e)/2;
    while(s<=e)
    {
        mid =(s+e)/2;
        if(a[mid]==key)
        {
            return mid;
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

    return -1;
}
int main()
{
    int a[10] = {1,3,4,8,9,10,15,16,19,21};
    cout<<binary_search(a,0,9,2)<<endl;
    cout<<binary_search(a,0,9,3)<<endl;
    return 0;
}
