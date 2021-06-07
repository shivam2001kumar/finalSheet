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
vector<int> rightView(Node *root)
{
   // Your code here
   vector<int>v;
   if(root==NULL) return v;
   queue<Node*>q;
   q.push(root);
   while(!q.empty())
   {
       int size=q.size();
       Node*temp;
       while(size--)
       {
           temp=q.front();
           q.pop();
           if(temp->left) q.push(temp->left);
           if(temp->right) q.push(temp->right);
       }
       v.push_back(temp->data);
   }
   return v;
}
int main()
{
    return 0;
}