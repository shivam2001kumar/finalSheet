#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
}; 


vector<int> diagonal(Node *root)
{
   // your code here
   vector<int> v;
   if(root==NULL) return v;
   queue<Node*>q;
   q.push(root);
   while(!q.empty())
   {
       Node*temp=q.front();
       q.pop();
       while(temp)
       {
           v.push_back(temp->data);
           if(temp->left)
            q.push(temp->left);
           temp=temp->right;
       }
   }
   return v;
}