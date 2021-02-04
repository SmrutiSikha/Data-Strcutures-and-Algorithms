#include<bits/stdc++.h>
using namespace std;

int calculateCoin(int s[],int sum,int n)
{
    if(sum==0)
    {
        return 1;
    }

    if(sum < 0)
    {
        return 0;
    }
    if(sum>=1 && n<1)
    {
        return 0;
    }

    return calculateCoin(s,sum-s[n-1],n) + calculateCoin(s,sum,n-1);
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