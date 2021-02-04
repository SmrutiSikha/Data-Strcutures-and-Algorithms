#include "bits/stdc++.h"

using namespace std;

bool comparator(pair<int,int> a,pair<int,int> b)
{
   return a.second < b.second;
}

int main()
{
    int n;
    cin>>n;
    vector<pair<int,int> > meeting(n);
    for(int i = 0 ; i  < n ; i++)
    {
        int x;
        cin>>x;
        meeting[i].first = x;
    }
    for(int i = 0 ; i  < n ; i++)
    {
        int x;
        cin>>x;
        meeting[i].second = x;
    }
    sort(meeting.begin(),meeting.end(),comparator);
    int ans = 1;
    int end = meeting[0].second;
    for(int i = 1 ; i < n ; i++)
    {
        if(meeting[i].first > end)
        {
            ans++;
            end = meeting[i].second;
        }
    }
    cout<<ans<<endl;
}