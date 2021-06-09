#include<bits/stdc++.h>
using namespace std;
//Function to count number of nodes in BST that lie in the given range.
struct Node
{
    int data;
    Node*left,*right;
};

int getCount(Node *root, int l, int h)
{
  // your code goes here   
  if(root==NULL) return 0;
  if(root->data==l and root->data==h) return 1;
  if(root->data >=l and root->data<=h) 
  {
      return 1+getCount(root->left,l,h)+getCount(root->right,l,h);
  }
  else if(root->data<l)
  {
      return getCount(root->right,l,h);
  }
  else
    return getCount(root->left,l,h);
}
