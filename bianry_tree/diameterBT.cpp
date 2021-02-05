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
        int height(Node* n);
        int diameter(Node* n,int& diameter);
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

int Trees::height(Node* n)
{
   if(n == NULL)
   {
       return 0;
   }
   return 1+max(height(n->left),height(n->right));
}

int Trees::diameter(Node* n,int& d)
{
    if(n == NULL)
   {
       return 0;
   }
   int lh = diameter(n->left,d);
   int rh = diameter(n->right,d);
   d = max(d,1+lh+rh);
   return 1+max(lh,rh);
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
    int diam = 0;
    t.diameter(t.root,diam);
    cout<<diam<<endl;
}