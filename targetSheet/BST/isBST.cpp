#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left,*right;
};
class Solution
{
    public:
    bool solve(Node*root,int mn,int mx)
    {
        if(root==NULL )return true;
        if((root->data <mx and root->data>mn) and (solve(root->left,mn,root->data))
         and solve(root->right,root->data,mx))
            return true;
        return false;
    }
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) 
    {
        // Your code here
        if(root==NULL) return true;
        return solve(root,INT_MIN,INT_MAX);
    }
};