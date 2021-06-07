// left view of a binary tree
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int>v;
   if(root==NULL) return v;
   queue<Node*>q;
   q.push(root);
   while(!q.empty())
   {
       v.push_back(q.front()->data);
       int size=q.size();
       while(size--)
       {
           Node*temp=q.front();
           q.pop();
           if(temp->left) q.push(temp->left);
           if(temp->right) q.push(temp->right);
       }
   }
   return v;
}
int main()
{
    return 0;
}