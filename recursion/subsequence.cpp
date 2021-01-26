#include<bits/stdc++.h>
using namespace std;

void generate_subsequence(char *in,char *out,int i,int j)
{
    //base case
    if(in[i]=='\0')
    {
        out[j]=in[i];
        cout<<out<<endl;
        return ;
    }
    //recursive case
    out[j]=in[i];
    generate_subsequence(in,out,i+1,j+1);
    generate_subsequence(in,out,i+1,j);
}
int main()
{
    char in[] ="abc";
    char out[10];
    generate_subsequence(in,out,0,0);
    return 0;
}