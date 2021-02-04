#include"bits/stdc++.h"

using namespace std;

void tower(int s,int a,int d,int n)
{
 if(n==0)
 {
     return;
 } 
 tower(s,d,a,n-1);
 vector.push_back(make_pair(s,d));
 tower(a,s,d,n);
}


int main()
{
   int n;
   cin>>n;
   vector<pair<int,int>> ans;
   tower(1,2,3,n);
}