#include"bits/stdc++.h"

using namespace std;

int sumSequence(int s[],int n)
{
    int dp[n];
    int ans = 1;
    for(int i = 0 ; i < n ; i++)
    {
        dp[i] = 1;
    }
    for(int i = 1 ; i < n ; i++)
    {
       int j= i - 1;
      int maxVal =0;
       while(j>=0)
       {
         if(s[j] < s[i])
         {
             if(dp[j]>maxVal)
             {
                 maxVal = dp[j];
             }
         } 
         j--;  
       }
        dp[i] = maxVal+1;
        ans = max(ans,dp[i]);
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    int sequence[n];
    for(int i = 0 ; i < n ; i++)
    {
        cin>>sequence[i];
    }
    cout<<sumSequence(sequence,n)<<endl;
}