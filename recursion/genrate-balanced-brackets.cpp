#include<bits/stdc++.h>
using namespace std;

void generate_brackets(char *out,int n,int idx,int open,int close)
{
    if(idx>=2*n)
    {
        out[idx]='\0';
        cout<<out<<endl;
        return;
    }

    if(open<n)
    {
        out[idx]='(';
        generate_brackets(out,n,idx+1,open+1,close);
    }
    if(open>close)
    {
        out[idx]=')';
        generate_brackets(out,n,idx+1,open,close+1);
    }
}
int main()
{
    char out[10];
    generate_brackets(out,3,0,0,0);
    return 0;
}