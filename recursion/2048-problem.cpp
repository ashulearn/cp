#include<bits/stdc++.h>
using namespace std;

void func(int x)
{
    if(x==0)
    return;

    func(x/10);
    int d= x%10; 
    if(d==0)
    {
        cout<<"zero"<<" ";
    }
    else if(d==1)
    {
        cout<<"one"<<" ";
    }
    else if(d==2)
    {
        cout<<"two"<<" ";        
    }
    else if(d==3)
    {
        cout<<"three"<<" ";        
    }
    else if(d==4)
    {
        cout<<"four"<<" ";        
    }
    else if(d==5)
    {
        cout<<"five"<<" ";        
    }
    else if(d==6)
    {
        cout<<"six"<<" ";        
    }
    else if(d==7)
    {
        cout<<"seven"<<" ";        
    }
    else if(d==8)
    {
        cout<<"eight"<<" ";        
    }
    else if(d==9)
    {
        cout<<"nine"<<" ";        
    }
}
int main()
{
    int x=2048;
    func(x);
    return 0;
}