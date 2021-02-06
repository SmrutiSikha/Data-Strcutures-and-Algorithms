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
        vector<vector<int> > v;
        Node* root;
        Trees()
        {
           root = NULL;
        }
        Node* insert(int d,Node* n);
        void leafpath(Node* n,vector<int> vis);
        
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

void Trees::leafpath(Node* n,vector<int> vis)
{
    if(n==NULL)
    {
        return;
    }
    vis.push_back(n->data);
    if(n->left==NULL&&n->right==NULL)
    {
        v.push_back(vis);
    }
    leafpath(n->left,vis);
    leafpath(n->right,vis);
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
    vector<int> vis;
    t.leafpath(t.root,vis);
    for(int i = 0 ; i < t.v.size() ; i++)
    {
        for(int j = 0 ; j < t.v[i].size() ; j++)
        {
            cout<<t.v[i][j]<<" ";
        }
        cout<<endl;
    }

}