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


class Solution {
public:
int solve(Node*root,int&res)
{
    //Base Condition
    if(root==NULL)
        return 0;
    
    //Hypothesis    
    int l=solve(root->left,res);
    int r=solve(root->right,res);
    
    //Induction
    int temp=max(l,r)+root->data;
    if(root->left==NULL) return root->data+r;
    if(root->right==NULL) return root->data+l;
    
    int ans=l+r+root->data;
    res=max(res,ans);
    return temp;
    
}

    int maxPathSum(Node* root)
    {
        // code here
        int res=INT_MIN;
    int val=solve(root,res);
    return res==INT_MIN?val:res;
        
    }
};