#include<bits/stdc++.h>
using namespace std;

int friendsProblem(int x)
{
    if(x<=0)
    {
        return 0;
    }
    else if(x==1)
    {
        return 1;
    }
    else if(x==2)
    return 2;

    return friendsProblem(x-1)+(x-1)*friendsProblem(x-2);


}
int main()
{
    cout<<friendsProblem(2);
    return 0;
}