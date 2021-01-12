#include<bits/stdc++.h>
using namespace std;


void bubble_sort(int a[],int n)
{
    if(n==1)
    return;
    for(int j=0;j<n-1;j++)
    {
        if(a[j]>a[j+1])
        {
            swap(a[j],a[j+1]);
        }
    }
    bubble_sort(a,n-1);
}
void bubble_sort_recrsive(int a[],int j,int n)
{
    //base case
    if(n==1)
    return;
    if(j==n-1)
    {
        //single pass is done of the array
        return bubble_sort_recrsive(a,0,n-1);
    }
    //comparsion
    if(a[j]>a[j+1])
    {
        swap(a[j],a[j+1]);
    }
    //recursion call
    bubble_sort_recrsive(a,j+1,n);
    return;
}
int main()
{
    cout<<"a"<<endl;
    int a[5]= {5,4,3,1,2};
    bubble_sort_recrsive(a,0,5);
    for(int i=0;i<5;i++)
    {
        cout<<a[i]<<" ";
    }
}
