#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

void leftT(Node *root,vector<int> &ans)
{
    if(!root) return ;
    if(root->left)
    {
        ans.push_back(root->data);
        leftT(root->left,ans);
    }
    else if(root->right)
    {
        ans.push_back(root->data);
        leftT(root->right,ans);
        
    }
}
void leafT(Node *root,vector<int> &ans)
{
    if(!root) return ;
    leafT(root->left,ans);
    if(root->left==NULL && root->right==NULL)
    {
        ans.push_back(root->data);
    }
    leafT(root->right,ans);
    
}
void rightT(Node *root,vector<int> &ans)
{
    if(!root) return ;
    if(root->right)
    {
        rightT(root->right,ans);
        ans.push_back(root->data);
    }
    else if(root->left)
    {
        rightT(root->left,ans);
        ans.push_back(root->data);
    }
}

vector <int> printBoundary(Node *root)
{
     //Your code here
     vector<int>ans;
     ans.push_back(root->data);
     leftT(root->left,ans);
     leafT(root,ans);
     rightT(root->right,ans);
     return ans;
}