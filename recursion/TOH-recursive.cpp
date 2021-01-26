#include<bits/stdc++.h>
using namespace std;

void move(int n,char src,char helper,char dest)
{
    //base case
    if(n==0)
    {
        return ;
    }

    move(n-1,src,dest,helper);
    cout<<"SHIFT DISK"<<n<<" "<<src<<" TO "<<dest<<endl;
    move(n-1,helper,src,dest); 
}
int main()
{
    move(4,'A','B','C');
    return 0;
}