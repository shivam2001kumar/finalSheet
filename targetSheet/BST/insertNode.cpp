#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node*left,*right;
    Node(int key)
    {
        data=key;
        left=right=NULL;
    }
};
Node* insert(Node* root, int key)
{
    // Your code here
    if(root==NULL)
    {
        Node*temp=new Node(key);
        return temp;
    }
    if(root->data==key) return root;
    if(key < root->data)
        root->left = insert(root->left,key);
    else if(key > root->data)
        root->right = insert(root->right,key);
    return root;
}