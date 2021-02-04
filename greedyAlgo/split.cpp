#include "bits/stdc++.h"

using namespace std;

void recurse(int i,string s,int length,vector<int> vec,int target,int &ans)
{
    if(i >= s.length())
    {
        int sum = 0;
        for(int k = 0 ; k < vec.size() ; k++)
        {
            sum += vec[k];
        }
        ans = min(ans,abs(sum-target));
        return;
    }
    for(int j = 1 ; j <= length+1 ; j++)
    {
        if(i+j-1 < s.length())
        {
        string val = s.substr(i,j);
        int value = atoi(val.c_str());
        vec.push_back(value);
        recurse(i+j,s,length,vec,target,ans);
        vec.pop_back();
        }
        else
        {
            return;
        }
    }
}

int solve(string s, int target) {
    if(s.length() == 1)
    {
        int val = atoi(s.c_str());
        return abs(val-target);
    }
    int lengthTar = 0;
    int numclone = target;
    while(numclone!=0)
    {
        lengthTar++;
        numclone /= 10;
    }
    if(s.length() < lengthTar)
    {
        int val = atoi(s.c_str());
        return abs(val-target);
    }
    vector<int> vec;
    int ans = INT_MAX;
    recurse(0,s,lengthTar,vec,target,ans);
    // int sum = 0;
    // int ans = INT_MAX;
    // int val = 0;
    // for (int i = 0; i < mainvec.size(); i++) { 
    //     sum = 0;
    //     for (int j = 0; j < mainvec[i].size(); j++) 
    //     {
    //         sum+=mainvec[i][j];
    //         val = abs(sum-target);
    //     }
    //     ans = min(ans,val);
    // } 
    return ans;  
    
}

int main()
{
    string s;
    int t;
    cin>>s;
    cin>>t;
    cout<<solve(s,t)<<endl;
}