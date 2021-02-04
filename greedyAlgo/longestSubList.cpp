#include "bits/stdc++.h"

using namespace std;

int solve(vector<int>& nums) {
    if(nums.size()==0)
    {
        return 0;
    }
    if(nums.size()==1)
    {
        return 1;
    }
    if(nums.size() == 2)
    {
        if(nums[0]+1==nums[1] ||nums[1]+1==nums[0])
        {
            return 2;
        }
        else
        {
            return 1;
        }
    }
    int ans = 1;
    int maxi = nums[0];
    int min = nums[0];
    int prefix_sum[nums.size()];
    prefix_sum[0] = nums[0];
    for(int i = 1 ; i < nums.size() ; i++)
    {
        prefix_sum[i] = prefix_sum[i-1] + nums[i];
    }
    for(int i = 0 ; i < nums.size() ;i++)
    {
        min = nums[i];
        maxi = nums[i];
        for(int j = i+1 ; j < nums.size() ; j++)
        {
            cout<<i<<" "<<j<<endl;
            if(nums[j]<min)
            {
                min = nums[j];
            }
            else if(nums[j]>maxi)
            {
                maxi = nums[j];
            }
            cout<<"min "<<min<<" max "<<maxi<<endl;
            int sum = 0;
            if(i==0)
            {
                sum = prefix_sum[j];
                cout<<"sum "<<sum<<endl;
            }
            else
            {
                sum = prefix_sum[j] - prefix_sum[i-1];
                cout<<"sum "<<sum<<endl;
            }
            cout<<"calculated sum2 "<<(((maxi*(maxi+1))/2) - ((min*(min+1))/2))+min<<endl;
            if(min == 0)
            {
                cout<<"calculated sum1 "<<((maxi*(maxi+1))/2)<<endl;
                 if(((maxi*(maxi+1))/2) == sum)
                 {
                     ans = max(ans,j-i+1);
                 }
            }
            else if((((maxi*(maxi+1))/2) - ((min*(min+1))/2))+min == sum)
            {
                ans = max(ans,j-i+1);
            }
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> val;
    for(int i = 0 ; i < n ; i++)
    {
        int x;
        cin>>x;
        val.push_back(x);
    }
 cout<<solve(val)<<endl;

}