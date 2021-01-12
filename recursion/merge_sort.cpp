#include<bits/stdc++.h>
using namespace std;

void merge(int a[],int s,int e)
{
    int mid=(s+e)/2;
    int i=s;
    int j=mid+1;
    int k=0;
    int temp[100];
    while(i<=mid && j <=e)
    {
        if(a[i]<a[j])
        {
            temp[k++]=a[i++];
        }
        else
        {
            temp[k++]=a[j++];
        }
        
    }
    while(i<=mid)
    {
        temp[k++]=a[i++];
    }
    while(j<=e)
    {
        temp[k++]=a[j++];
    }
    for(int x=s;x<=e;x++)
    {
        a[x]=temp[x];
    }
}
void mergeSort(int a[],int s,int e)
{
    //base case
    if(s>=e)
    return;

    //we need to do 3 things
    //1.divide
    //2.sort
    //3.merge

    int mid=(s+e)/2;
    mergeSort(a,s,mid);
    mergeSort(a,mid+1,e);

    //merge
    merge(a,s,e);
}
int main()
{
    int a[]={5,4,1,2,3};
    mergeSort(a,0,4);
    for(int i=0;i<5;i++)
    {
        cout<<a[i]<<" ";
    }
}