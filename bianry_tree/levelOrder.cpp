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
        void levelOrder();
        void levelOrderReverse();
        void levelOrderBottom();
        void levelOrderBottomReverse();
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

void Trees::levelOrder()
{
    if(root == NULL)
    {
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* temp = q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left!=NULL)
        {
            q.push(temp->left);
        }
        if(temp->right!=NULL)
        {
            q.push(temp->right);
        }
    }
   cout<<endl;
}

void Trees::levelOrderReverse()
{
    if(root == NULL)
    {
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* temp = q.front();
        cout<<temp->data<<" ";
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
   cout<<endl;
}

void Trees::levelOrderBottom()
{
    if(root == NULL)
    {
        return;
    }
    queue<Node*> q;
    stack<int> s;
    q.push(root);
    while(!q.empty())
    {
        Node* temp = q.front();
        s.push(temp->data);
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
   while(!s.empty())
   {
       cout<<s.top()<<" ";
       s.pop();
   }
   cout<<endl;
}

void Trees::levelOrderBottomReverse()
{
    if(root == NULL)
    {
        return;
    }
    queue<Node*> q;
    stack<int> s;
    q.push(root);
    while(!q.empty())
    {
        Node* temp = q.front();
        s.push(temp->data);
        q.pop();
        if(temp->left!=NULL)
        {
            q.push(temp->left);
        }
        if(temp->right!=NULL)
        {
            q.push(temp->right);
        }
    }
   while(!s.empty())
   {
       cout<<s.top()<<" ";
       s.pop();
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
    t.levelOrder(); //5 3 7 2 6 8
    t.levelOrderReverse(); //5 7 3 8 6 2
    t.levelOrderBottom();  //2 6 8 3 7 5
    t.levelOrderBottomReverse(); //8 6 2 7 3 5
}