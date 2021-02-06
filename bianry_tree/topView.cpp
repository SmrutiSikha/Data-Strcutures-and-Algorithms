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
        void topview();
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

void Trees::topview()
{
    if(root == NULL)
    {
        return;
    }
    map<int,int> m;
    queue<pair<Node*,int> > q;
    q.push(make_pair(root,0));
    while(!q.empty())
    {
        Node* temp = q.front().first;
        int dist = q.front().second;
        map<int,int>::iterator itr = m.find(dist);
        if(itr == m.end())
        {
            m[dist] = temp->data;
        }
        q.pop();
        if(temp->left!=NULL)
        {
            q.push(make_pair(temp->left,dist-1));
        }
        if(temp->right!=NULL)
        {
            q.push(make_pair(temp->right,dist+1));
        }        
    }
   map<int,int>::iterator it;
   for(it = m.begin() ; it!=m.end() ; it++)
   {
       cout<<it->second<<" ";
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
    t.topview();
}