#include<iostream>
using namespace std;

bool isPossible(int arr[],int n,int m,int curr_min)
{
    int studentUsed = 1;
    int pagesRead = 0;
    for(int i=0;i<n;i++)
    {
        if(pagesRead + arr[i] > curr_min)
        {
            studentUsed++;

            pagesRead = arr[i];
            if(studentUsed > m)
            return false;
        }
        else
        {
            pagesRead+=arr[i];
        }

    }

    return true;
}
int findPages(int arr[],int n,int m)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    int s=arr[n-1];
    int e=sum;
    int mid;
    int ans=INT_MAX;
    while(s<=e)
    {
        mid=(s+e)/2;
        if(isPossible(arr,n,m,mid))
        {
            ans=min(ans,mid);
            e=mid-1;
        }
        else 
        {
            //it is not possible to divide
            //so we need to increase the pages
            s=mid+1;
        }
    }
    return ans;
}
int main()
{
    int t;
    // cin>>t;
    t=1;
    while(t--)
    {
        int n,m;
        // cin>>n>>m;
        n==4;m=2;
        int arr[1000]={12,34,67,90};
        /*for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }*/
        
        cout<<findPages(arr,n,m);
    }
    return 0;
}