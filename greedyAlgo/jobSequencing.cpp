#include "bits/stdc++.h"

using namespace std;

struct Job{
    int id;
    int dead;
    int profit;
};

bool compare(Job a, Job b)
{
    return a.profit > b.profit;
}

pair<int,int> JobScheduling(Job arr[], int n) 
{ 
    sort(arr,arr+n,compare);
    int ans=0;
    int prof = 0;
    int slot[n];
    for(int i = 0 ; i < n ; i++)
    {
        slot[i] = 0;
    }
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = min(arr[i].dead,n)-1 ; j>=0 ; j--)
        {
            if(slot[j] == 0)
            {
                slot[j] = 1;
                ans++;
                prof += arr[i].profit;
                break;
            }
        }
    }
    return make_pair(ans,prof);
} 

int main()
{
    int n;
    cin>>n;
    Job arr[n];
    for(int i = 0 ; i < n ; i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        arr[i].id = x;
        arr[i].dead = y;
        arr[i].profit = z;
    }
    pair<int,int> ans = JobScheduling(arr,n);
    cout<<ans.first<<" "<<ans.second<<endl;
}