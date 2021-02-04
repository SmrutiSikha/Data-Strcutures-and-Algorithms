#include"bits/stdc++.h"

using namespace std;

int lengthPalin(string s,int start,int end)
{
    if(start == end)
    {
        return 1;
    }
    if(start>end)
    {
        return 0;
    }
    if(s[start] == s[end])
    {
        return lengthPalin(s,start+1,end-1) + 2;
    }
    else
    {
        return max(lengthPalin(s,start,end-1),lengthPalin(s,start+1,end));
    }
}

int main()
{
    string inp;
    cin>>inp;
    cout<<lengthPalin(inp,0,inp.length()-1)<<endl;
}