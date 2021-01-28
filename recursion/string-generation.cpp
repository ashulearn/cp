#include<bits/stdc++.h>
using namespace std;

void generateString(char in[],char out[],int i,int j)
{
    //base case
    if(in[i]=='\0')
    {
        out[j]='\0';
        cout<<out<<endl;
        return;
    }
    //one digit
    int digit = in[i]-'0';
    char ch = digit + 'A' - 1;
    out[j]=ch;

    generateString(in,out,i+1,j+1);
    //two digit
    if(in[i+1] != '\0')
    {
        int secondDigit = in[i+1]-'0';
        int no = digit*10 + secondDigit;
        if(no <= 26)
        {
            ch = no +'A' -1;
            out[j] = ch;
            generateString(in,out,i+2,j+1);
        }
    }

}
int main()
{
    char in[] = "1234";
    char out[1000];
    generateString(in,out,0,0);

    return 0;
}