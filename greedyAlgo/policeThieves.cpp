#include "bits/stdc++.h"

using namespace std;

void calc(vector<int> thi,vector<int> pol,int n,int k)
{
    int res = 0;
    int l = 0, r = 0; 
    while (l < thi.size() && r < pol.size()) { 
  
        // can be caught 
        if (abs(thi[l] - pol[r]) <= k) { 
            res++; 
            l++; 
            r++; 
        } 
  
        // increment the minimum index 
        else if (thi[l] < pol[r]) 
            l++; 
        else
            r++; 
    } 
    cout<<res<<endl;
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> police;
    vector<int> thieves;
    for(int i = 1 ; i <= n ; i++)
    {
        char c;
        cin>>c;
        if(c=='P')
        {
            police.push_back(i);
        }
        else
        {
            thieves.push_back(i);
        }
    }
    calc(thieves,police,n,k);
}