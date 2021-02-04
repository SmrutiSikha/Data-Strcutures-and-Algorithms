#include"bits/stdc++.h"

using namespace std;

stack<int> sudh()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    return s;
}

int main()
{
    stack<int> k;
    k = sudh();
    cout<<k.top();
}