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
 


class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
       if(root==NULL) return root;
       if(root->data==n1 or root->data==n2) return root;
       Node*l=lca(root->left,n1,n2);
       Node*r=lca(root->right,n1,n2);
       if(l!=NULL and r!=NULL) return root;
       if(l!=NULL) return l;
       else if(r!=NULL) return r;
       else return NULL;
    }
};