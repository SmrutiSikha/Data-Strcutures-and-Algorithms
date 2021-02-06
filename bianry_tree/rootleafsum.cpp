#include "bits/stdc++.h"

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Trees{
    public:
        Node* root;
        Trees()
        {
           root = NULL;
        }
        Node* insert(int d,Node* n);
        void leafpath(Node* n,int s,bool& present,int sum);
        
};

Node* Trees::insert(int d,Node* node)
{
    if(node==NULL)
    {
        node = new Node(d);
        return node;
    }
    if(d < node->data)
    {
        node->left = insert(d,node->left);
    }
    else if(d > node->data)
    {
        node->right = insert(d,node->right);
    }
    return node;
}

void Trees::leafpath(Node* n,int curr_sum,bool& present,int sum)
{
    if(n==NULL)
    {
        return;
    }
    curr_sum += n->data;
    if(n->left==NULL&&n->right==NULL)
    {
        if(sum == curr_sum)
        {
            present = true;
        }
    }
    leafpath(n->left,curr_sum,present,sum);
    leafpath(n->right,curr_sum,present,sum);
}

int main()
{
    Trees t;
    t.root = t.insert(15,t.root);
    t.root = t.insert(18,t.root);
    t.root = t.insert(3,t.root);
    t.root = t.insert(7,t.root);
    t.root = t.insert(8,t.root);
    t.root = t.insert(9,t.root);
    t.root = t.insert(6,t.root);
    t.root = t.insert(2,t.root);
    t.root = t.insert(1,t.root);
    int curr_sum = 0;
    bool p =false;
    t.leafpath(t.root,curr_sum,p,31);
    cout<<p<<endl;
}