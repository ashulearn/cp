#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n=10;
    int a[10]= {1,3,4,8,8,8,8,9,11,22};
    bool present = binary_search(a,a+n,8);
    if(present)
    {
        cout<<"Present"<<endl;
    }
    else 
    {
        cout<<"Absent"<<endl;
    }
    auto l = lower_bound(a,a+n,8);
    cout<<"lower bound of 8 is "<<(l-a)<<endl;
    auto u = upper_bound(a,a+n,8);
    cout<<"upper bound of 8 is "<<(u-a)<<endl;
    cout<<"number of 8 is "<<u-l<<endl;
    return 0;
}