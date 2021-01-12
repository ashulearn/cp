#include<bits/stdc++.h>
using namespace std;
int stringtoInt(char s[],int n)
{
    if(n==0)
    return 0;

    int prevans=stringtoInt(s,n-1);
    int curr = s[n-1]-'0';
    int ans = prevans*10 + curr;

    return ans; 
}
int main()
{

    char s[] = "1234";
    cout<<stringtoInt(s,4);
    return 0;
}