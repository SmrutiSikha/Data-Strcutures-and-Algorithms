#include "bits/stdc++.h"

using namespace std;

void printFraction(int nr,int dr)
{
   if(nr==1)
   {
       cout<<nr<<"/"<<dr<<" ";
       return;
   }
   int greatest = ceil(float(dr)/float(nr));
   cout<<"1"<<"/"<<greatest<<" ";
   nr = nr*greatest - dr;
   dr = dr*greatest;
   if(dr%nr == 0)
   {
       printFraction(1,dr/nr);
   }
   else
   {
       return printFraction(nr,dr);
   }
}

int main()
{
    int num,dum;
    cin>>num>>dum;
    if(num<dum)
    {
        printFraction(num,dum);
    }
    else
    {
        cout<<"not possible"<<endl;
    }
}