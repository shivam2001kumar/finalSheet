#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int key;
	Node* left, *right;
};

// Function should return the sum of all the elements
// of the binary tree
long int sumBT(Node* root)
{
    // Code here
    if(root==NULL) return 0;
    long sumLeft=0,sumRight=0;
    if(root->left)
        sumLeft=sumBT(root->left);
    if(root->right)
        sumRight=sumBT(root->right);
    int temp=sumLeft+sumRight+root->key;
    return temp;
}