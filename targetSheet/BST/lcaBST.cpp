#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node*left,*right;
};

Node* LCA(Node *root, int n1, int n2)
{
   //Your code here
   Node*cur=root;
   while(cur!=NULL)
   {
       if(cur->data > n1 and cur->data > n2)
       {
           cur=cur->left;
       }
       else if(cur->data < n1 and cur->data < n2)
       {
           cur=cur->right;
       }
       else break;
   }
   return cur;
        
}