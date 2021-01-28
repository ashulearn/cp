#include<bits/stdc++.h>
using namespace std;

int tilingProblem(int x)
{
    //base case
    if(x<=3)
    {
        return 1;
    }

    //recursive case
    return tilingProblem(x-1)+tilingProblem(x-4);
}
int main()
{
    int n=10;
    cout<<tilingProblem(4);
    return 0;
}