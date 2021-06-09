#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int key;
	struct Node *left, *right;
};


// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
Node* findMin(Node*root)
    {
        if(root==NULL) return NULL;
        Node*curr=root;
        while(curr->left)
        {
            curr=curr->left;
        }
        return curr;
    }
Node* findMax(Node*root)
{
    if(root==NULL) return NULL;
    Node*curr=root;
    while(curr->right)
    {
        curr=curr->right;
    }
    return curr;
    
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    if(root==NULL) return ;
    if(root->key==key)
    {
      if(root->left) 
             pre=findMax(root->left);
      if(root->right)
             suc=findMin(root->right);
      
    }
    
    else if(key<root->key)
    {
        suc=root;
        findPreSuc(root->left,pre,suc,key);
    }
    else 
    {
        pre=root;
        findPreSuc(root->right,pre,suc,key);
    }

}