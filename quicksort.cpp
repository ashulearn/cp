#include<bits/stdc++.h>
using namespace std;

int partition(int arr[],int s,int e)
{
    int i=s-1;
    int j=s;
    int pivot = arr[e];
    for(j=s;j<=e-1;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }

    }
    swap(arr[i+1],arr[e]);
    return i+1;
}
void quicksort(int arr[],int s,int e)
{
    if(s>e)
    {
        return ;
    }

    int p = partition(arr,s,e);
    quicksort(arr,s,p-1);
    quicksort(arr,p+1,e);
}
int main()
{
    int arr[]= {2,7,8,6,1,5,4};
    quicksort(arr,0,6);
    for(int i=0;i<7;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}