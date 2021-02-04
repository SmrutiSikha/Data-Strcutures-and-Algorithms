#include "bits/stdc++.h"

using namespace std;

int dfs(int v,int& ans,int cd[],int wt[])
{
    if(cd[v] == 0)
    {
        return v;
    }
    ans = min(ans,wt[v]);
    return dfs(cd[v],ans,cd,wt); 
}

void water(int cd[],int rd[], int wt[],int n,int p)
{
    vector<int> start;
    vector<int> end;
    vector<int> dia;
    for(int i = 1 ; i < n+1 ; i++)
    {
        if(rd[i]==0 && cd[i])
        {
            int ans = INT_MAX;
            int e = dfs(i,ans,cd,wt);
            start.push_back(i);
            end.push_back(e);
            dia.push_back(ans);
        }
    }
    cout << start.size() << endl; 
    for (int j = 0; j < start.size(); ++j) 
        cout << start[j] << " " << end[j]  
             << " " << dia[j] << endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,p;
        cin>>n>>p;
        int cd[n+1],rd[n+1],wt[n+1];
        for(int i = 1 ; i < n+1 ; i++)
        {
            cd[i] = 0;
            rd[i] = 0;
            wt[i] = 0;
        }
        for(int i = 0 ; i < p ; i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            cd[a] = b;
            rd[b] = a;
            wt[a] = c;
        }
        water(cd,rd,wt,n,p);
    }
}