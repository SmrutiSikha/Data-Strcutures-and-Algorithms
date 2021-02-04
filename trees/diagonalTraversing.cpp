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
    private:
        map<int,vector<int> > m;
    public:
        Node* root;
        Trees()
        {
           root = NULL;
        }
        Node* insert(int d,Node* n);
        void DiagonalOrder(Node* n,int diag);
        void inorder(Node* n,int diag);
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

void Trees::DiagonalOrder(Node* n,int diag)
{
    inorder(n,diag);
    map<int,vector<int> >::iterator it;
    for(it = m.begin() ; it!= m.end() ; it++)
    {
        vector<int> v = it->second;
        for(int i = 0 ; i < v.size() ; i++)
        {
            cout<<v[i]<<" ";
        }
    }
    cout<<endl;
       
}

void Trees::inorder(Node* n,int diag)
{
    if(n == NULL)
    {
        return;
    }
    m[diag].push_back(n->data);
    inorder(n->left,diag+1);
    inorder(n->right,diag);   
}

int main()
{
    Trees t;
    t.root = t.insert(5,t.root);
    t.root = t.insert(7,t.root);
    t.root = t.insert(3,t.root);
    t.root = t.insert(6,t.root);
    t.root = t.insert(8,t.root);
    t.root = t.insert(2,t.root);
    t.DiagonalOrder(t.root,0);
}