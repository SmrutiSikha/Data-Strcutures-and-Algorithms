#include "bits/stdc++.h"

using namespace std;

void recurse(string s,int length,vector<int> vec,vector<vector<int> >& mainvec)
{
    int ans= 0;
    int j;
    for(j = 1 ; j<= length+1 && j<=s.length() ; j++)
    {
        if(j!=1)
        {
            vec.pop_back();
        }
       string val = s.substr(0,j);
       int value = atoi(val.c_str());
       vec.push_back(value);
       if(j < s.length())
       {
           string news = s.substr(j,s.length()-j);
           recurse(news,length,vec,mainvec);
       }
    }
  mainvec.push_back(vec);
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
    int count = 0;
    vector<vector<int> > mainvec;
    recurse(s,lengthTar,vec,mainvec);
    cout<<"new"<<endl;
    for (int i = 0; i < mainvec.size(); i++) { 
        for (int j = 0; j < mainvec[i].size(); j++) 
            cout << mainvec[i][j] << " "; 
        cout << endl; 
    } 
    return lengthTar;  
    
}

int main()
{
    string s;
    int t;
    cin>>s;
    cin>>t;
    cout<<solve(s,t)<<endl;
}