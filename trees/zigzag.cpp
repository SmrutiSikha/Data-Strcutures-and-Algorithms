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
        void ZigZag();
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

void Trees::ZigZag()
{
    if(root == NULL)
    {
        return;
    }
    stack<Node*> s1,s2;
    s1.push(root);
    while(!s1.empty() || !s2.empty())
    {
        while(!s1.empty())
        {
            Node* temp = s1.top();
            cout<<temp->data<<" ";
            s1.pop();
            if(temp->right!=NULL)
            {
                s2.push(temp->right);
            }
            if(temp->left!=NULL)
            {
                s2.push(temp->left);
            }
        }
         while(!s2.empty())
        {
            Node* temp = s2.top();
            cout<<temp->data<<" ";
            s2.pop();
            if(temp->left!=NULL)
            {
                s1.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                s1.push(temp->right);
            }
        }
    }
    cout<<endl; 
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
    t.ZigZag();
}