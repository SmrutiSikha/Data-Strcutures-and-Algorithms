#include"bits/stdc++.h"

using namespace std;

int main()
{
    int x,y,s,t;
    cin>>x>>y>>s>>t;
    int reach = x + y;
    int remaining = t-reach;
    if(remaining > 0)
    {
        if(remaining <= s)
        {
            cout<<((remaining+1)*(remaining+2))/2;
        }
        else if(remaining < 2*s)
        {
            int z= 2*s - remaining;
            cout<<((s+1)*(s+1))-((z*(z+1))/2);
        }
        else
        {
            cout<<((s+1)*(s+1));
        }
        
        
    }
    else if(remaining == 0)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    
}