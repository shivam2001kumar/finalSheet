
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

class Solution{
    public:
    int helper(Node*root) // count edges to leaf node
    {
        if(root==NULL) return -1;
        int left = helper(root->left);
        int right = helper(root->right);
        return max(left,right)+1;
    }
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        // code here 
        return helper(node)+1; // +1 to count nodes
    }
};
