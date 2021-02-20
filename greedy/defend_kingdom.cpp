#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    int w,h,x,n,y;
    cin>>t;
    int ax[40010],ay[40010];
    while(t--)
    {
        cin>>w>>h>>n;
        for(int i=0;i<n;i++)
        {
            cin>>ax[i]>>ay[i];
        }
        sort(ax,ax+n);
        sort(ay,ay+n);
        int dx= ax[0]-1;
        int dy = ay[0]-1;
        //calc delta x and y
        for(int i=1;i<n;i++)
        {
            dx = max(dx , ax[i]-ax[i-1]-1);
            dy = max(dy , ay[i]-ay[i-1]-1);
        }
        dx = max(dx , w - ax[n-1]);
        dy = max(dy , h - ay[n-1]);

        cout<<dx*dy<<endl;

    }

    return 0;
}