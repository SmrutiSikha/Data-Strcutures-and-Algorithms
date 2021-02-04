#include"bits/stdc++.h"

using namespace std;

int lengthPalin(string s,int start,int end)
{
    int n = s.length();
    int dp[n][n];

    for(int i = 0 ; i < n ; i++)
    {
        dp[i][i] = 1;
    }

    for(int l = 2 ; l <= n ; l++)
    {
        for(int i = 0 ; i<n-l+1 ; i++)
        {
            int j = i+l -1;
            if(s[i]==s[j] && j == i+1)
            {
                dp[i][j] = 2;
            }
            else if(s[i]==s[j])
            {
                dp[i][j] = 2 + dp[i+1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }
        }
    }
    return dp[0][n-1];
}

int main()
{
    string inp;
    cin>>inp;
    cout<<lengthPalin(inp,0,inp.length()-1)<<endl;
}