#include<bits/stdc++.h>
using namespace std;

int ladderProblem(int x)
{
    if(x<=0)
    {
        return 0;
    }
    else if(x==1)
    return 1;
    else if(x==2)
    return 2;
    else if(x==3)
    return 4;

    return ladderProblem(x-1)+ladderProblem(x-2)+ladderProblem(x-3);


}
int main()
{
    int n=4;
    cout<<ladderProblem(n);
    return 0;
}