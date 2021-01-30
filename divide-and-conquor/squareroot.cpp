#include<bits/stdc++.h>
using namespace std;

float squareroot(int n)
{
    int s=0;
    int e=n;
    int mid;
    float ans=-1;
    while(s<=e)
    {
        mid=(s+e)/2;
        if(mid*mid == n)
        {
            return mid;
        }
        else if(mid*mid < n)
        {
            ans=mid;
            s=mid+1;
        }
        else 
        {
            e=mid-1;
        }
    }
    //float value we will apply brute force
    float inc = 0.1;
    for(int i=0;i<5;i++)
    {
        while(ans*ans <= n)
        {
            ans+=inc;
        }
        ans-=inc;
        inc=inc/10;
    }
    return ans;
}
int main()
{
    int n;
    n=50;
    cout<<squareroot(n);
    return 0;
}