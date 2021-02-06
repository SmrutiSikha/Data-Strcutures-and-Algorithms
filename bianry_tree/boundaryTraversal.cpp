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
        vector<int> v;
        Node* root;
        Trees()
        {
           root = NULL;
        }
        Node* insert(int d,Node* n);
        void boundaryTraversal();
        void leftBoundary(Node* n);
        void leafTraversal(Node* n);
        void rightBoundary(Node* n);
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

void Trees::leftBoundary(Node* n)
{
    if(n==NULL)
    {
        return;
    }
    if(n->left!=NULL || n->right!=NULL)
    {
    v.push_back(n->data);
    }
    if(n->left != NULL)
    {
        leftBoundary(n->left);
    }
    else if(n->right != NULL)
    {
        leftBoundary(n->right);
    }
}

void Trees::leafTraversal(Node* n)
{
    if(n == NULL)
    {
        return;
    }
    leafTraversal(n->left);
    if(n->left == NULL && n->right==NULL)
    {
        v.push_back(n->data);
    }
    leafTraversal(n->right);
}

void Trees::rightBoundary(Node* n)
{
    if(n==NULL)
    {
        return;
    }
    if(n->right != NULL)
    {
        rightBoundary(n->right);
    }
    else if(n->left != NULL)
    {
        rightBoundary(n->left);
    }
    if(n->left!=NULL || n->right!=NULL)
    {
    v.push_back(n->data);
    }
}

void Trees::boundaryTraversal()
{
    if(root == NULL)
    {
        return;
    }
    if(root->left == NULL && root->right == NULL)
    {
        cout<<root->data<<" ";
        return;
    }
    v.push_back(root->data);
    leftBoundary(root->left);
    leafTraversal(root);
    rightBoundary(root->right);
    for(int i = 0 ; i < v.size() ; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
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
    t.boundaryTraversal();
}