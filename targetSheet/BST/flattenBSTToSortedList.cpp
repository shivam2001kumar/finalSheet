#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
void inorder(node*root,node *&prev)
{
    if(root==NULL) return;
    inorder(root->left,prev);
    prev->left=NULL;
    prev->right=root;
    prev=root;
    inorder(root->right,prev);
}
node* flatten(node*root)
{
    
    node*dummy=new node(-1);
    node*prev=dummy;
    inorder(root,prev);
    prev->left=NULL;
    prev->right=NULL;
    node*res=dummy->right;
    delete(dummy);
    return res;
}