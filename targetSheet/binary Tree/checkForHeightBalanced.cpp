#include<bits/stdc++.h>
using namespace std;
int f=1;
int solve(Node*root)
{
    if(root==NULL) return -1;
    int l=solve(root->left);
    int r=solve(root->right);
    if(abs(l-r) > 1) f=0;
    return max(l,r)+1;
}

//Function to check whether a binary tree is balanced or not.
bool isBalanced(Node *root)
{
    //  Your Code here
    f=1;
    solve(root);
    return f;
}
