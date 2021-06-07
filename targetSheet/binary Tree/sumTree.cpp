#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
}; 

class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    
    int solve(Node*&root)
    {
        if(root==NULL) return 0;
        int l=solve(root->left);
        int r=solve(root->right);
        int x=root->data;
        root->data=l+r;
        return l+r+x;
        
    }
    void toSumTree(Node *node)
    {
        // Your code here
        solve(node);
    }
};
