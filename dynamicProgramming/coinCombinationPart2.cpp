#include<bits/stdc++.h>
using namespace std;

int calculateCoin(int s[],int sum,int n)
{
    int dp[sum+1][n];
    for(int i = 0 ; i < n ; i++)
    {
        dp[0][i] = 1;
    }
    for(int i = 1 ; i < sum+1 ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            int x =  (i-s[j]>=0) ? dp[i-s[j]][j] : 0;
            int y = (j>0) ? dp[i][j-1] : 0;
            if(x == 0 && y == 0)
            {
                dp[i][j] = 0;
            }
            else if(x!=0 && y!=0)
            {
                dp[i][j] = 1 + min(x,y);
            }
            else if(x!=0)
            {
                dp[i][j] = 1 + x;
            }
            else
            {
                 dp[i][j] = 1 + y;
            }
        }
    }
    return dp[sum][n-1];
}

int main()
{
 int sum;
 cin>>sum;
 int n;
 cin>>n;
 int arr[n];
 for(int i = 0 ; i < n ; i++)
 {
     cin>>arr[i];
 }

cout<<calculateCoin(arr,sum,n);

}