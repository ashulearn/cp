#include<bits/stdc++.h>
using namespace std;

void permutations(char in[],int i)
{
    if(in[i]=='\0')
    {
        cout<<in<<endl;
        return;
    }
    for(int j=i;in[j]!= '\0';j++)
    {
        swap(in[i],in[j]);
        permutations(in,i+1);
        //backtracking step
        swap(in[i],in[j]);
    }
}
int main()
{
    char in[] = "abc";
    permutations(in,0);
    return 0;
}