#include<bits/stdc++.h>
using namespace std;
int max_sum(int arr[],int n)
{
    int dp[100]={0};
    dp[0] = arr[0]>0 ? arr[0] : 0;
    int max_so_far = dp[0];
    for(int i=1;i<n;i++)
    {
        dp[i]=dp[i-1]+arr[i];
        if(dp[i]<0)
        {
            dp[i]=0;
        }
        max_so_far = max(max_so_far,dp[i]);

    }

    return max_so_far;

}
int kadane(int arr[],int n)
{
    int curr_sum=0;
    int max_so_far =0;
    for(int i=0;i<n;i++)
    {
        curr_sum += arr[i];
        if(curr_sum<0)
        {
            curr_sum=0;
        }
        max_so_far = max(max_so_far,curr_sum);
    }

    return max_so_far;
}
int main()
{
    int arr[] = {-3,2,5,-1,6,3,-2,7,-5,2};
    int n= sizeof(arr)/sizeof(int);
    cout<<max_sum(arr,n)<<endl;
    cout<<kadane(arr,n);

    return 0;
}