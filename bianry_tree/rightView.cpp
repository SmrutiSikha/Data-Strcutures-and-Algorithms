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
        void leftview();
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

void Trees::leftview()
{
    if(root == NULL)
    {
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    bool ispresent = true;
    while(!q.empty())
    {
        Node* temp = q.front();
        if(temp != NULL)
        {
            if(ispresent)
            {
                cout<<temp->data<<" ";
                ispresent = false;
            }
            q.pop();
            if(temp->right!=NULL)
            {
                q.push(temp->right);
            }
            if(temp->left!=NULL)
            {
                q.push(temp->left);
            }
        }
        else
        {
            q.pop();
            if(!q.empty())
            {
                q.push(NULL);
                ispresent = true;
            }
        }
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
    t.leftview();
}