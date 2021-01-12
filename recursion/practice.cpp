#include<bits/stdc++.h>

using namespace std;

void merge(int arr[],int s,int e)
{
    int mid=(s+e)/2;
    int i=s,j=mid;
    int temp[e-s+1];
    while(i<=mid && j<=e)
    {
        
    }
}
void mergesort(int arr[],int s,int e)
{
    if(s<=e)
    return;

    int mid= (s+e)/2;
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);

    merge(arr,s,e);
}
int main()
{
    return 0;
}