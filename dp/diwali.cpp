#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod 1000003
ll n,x;
int dp[105][3][105];

ll f(ll i,ll prev,ll cnt)
{
    
    if(i==n)
    {
        if(cnt==x)
        {
            return 1;
        }
        return 0;
    }
    //lookup
    if(dp[i][prev][cnt] != -1)
    {
        return dp[i][prev][cnt];
    }
    ll ans=0;
    if(prev==1)
    {
        ans+= f(i+1,1,cnt+1);
    }
    else
    {
        ans+=f(i+1,1,cnt);
    }
   
    ans += f(i+1,0,cnt);
    

    return dp[i][prev][cnt] = ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>x;
        memset(dp,-1,sizeof(dp));
        cout<<(f(1,0,0)+f(1,1,0))<<endl;
    }



    return 0;
}